#include "cardsbox.h"

CardsBox::CardsBox()
{

    cardsBox = new QGroupBox;
    cardsBox->setFixedSize(1100, 3000);  //5*(размер одной карточки + немного) - ширина, а по высоте сделать прокрутку
    cardsBox->setStyleSheet("background-color : rgba(127, 255, 212, 0.4);");

    scrollArea = new QScrollArea(this);
    scrollArea->setBackgroundRole(QPalette::Light);
    scrollArea->setWidget(cardsBox);
    scrollArea->setFixedSize(1100, 700);

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

    for (int i=0; i<cardsList.length(); i++)
        layPr->addWidget(cardsList.at(i));

    cardsBox->setFixedSize(1100, cardsList.length()*cardsList.at(1)->height()+cardsList.length()*27);
    cardsBox->setLayout(layPr);


}
