#include "cardsbox.h"

CardsBox::CardsBox()
{

    cardsBox = new QGroupBox;
    cardsBox->setFixedSize(1050, 575);  //5*(размер одной карточки + немного) - ширина, а по высоте сделать прокрутку
    cardsBox->setStyleSheet("background-color : rgba(127, 255, 212, 0.4);");

    scrollArea = new QScrollArea(this);
    scrollArea->setBackgroundRole(QPalette::Light);
    scrollArea->setWidget(cardsBox);
    scrollArea->setFixedSize(1070, 575);

}

void CardsBox::AddCards(QList<Product> base)
{


    QList<ProductCard*> cardsList;
    for (int i=0; i<base.length(); i++)
    {
        ProductCard *prdCard = new ProductCard(base.at(i));
        cardsList.append(prdCard);
        //layPr->addWidget(prdCard);
    }

    PlaceCards(cardsList);

//    cardsBox->setFixedSize(1100, base.length()*);

}


void CardsBox::PlaceCards(QList<ProductCard*> cardsList)
{
    QVBoxLayout *layPr = new QVBoxLayout;
    layPr->setAlignment(Qt::AlignTop);

    //вычисление количества исходя из размеров экрана
    int cardsInRow = 3;

/*    for (int i=0; i<cardsList.length(); i++)
        layPr->addWidget(cardsList.at(i));
*/
    for (int i=0; i<cardsList.length(); i++){
        QHBoxLayout *layRow = new QHBoxLayout;
        layRow->setAlignment(Qt::AlignTop);
        for (int j=0; j<cardsInRow; j++)
            if (i+j<cardsList.length())
                layRow->addWidget(cardsList.at(i+j));
        i=i+cardsInRow-1;
        layPr->addLayout(layRow);
    }
    //переделать вычисление размеров
    cardsBox->setFixedHeight(cardsList.length()/cardsInRow*cardsList.at(1)->height()+(cardsList.length()/cardsInRow+1)*cardsDist);
    cardsBox->setLayout(layPr);


}
