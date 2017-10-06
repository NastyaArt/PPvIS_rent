#include "cardsbox.h"

CardsBox::CardsBox()
{

    cardsBox = new QGroupBox;
    cardsBox->setFixedSize(1050, 573);  //5*(размер одной карточки + немного) - ширина, а по высоте сделать прокрутку
    cardsBox->setStyleSheet("background-color : rgba(127, 255, 212, 0.4);");

    scrollArea = new QScrollArea(this);
    scrollArea->setBackgroundRole(QPalette::Light);
    scrollArea->setWidget(cardsBox);
    scrollArea->setFixedSize(1070, 575);


    layPr = new QVBoxLayout;
    layPr->setAlignment(Qt::AlignTop);

    cardsBox->setLayout(layPr);

}

void CardsBox::CreateCards(QList<Product> base)
{
     AddCards(base);
}

void CardsBox::AddCards(QList<Product> base)
{
    QList<ProductCard*> cardsList;

    for (int i=0; i<base.length(); i++)
    {
        ProductCard *prdCard = new ProductCard(base.at(i));
        cardsList.append(prdCard);
    }

    PlaceCards(cardsList);
}

void CardsBox::PlaceCards(QList<ProductCard*> cardsList)
{
    if (cardsList.length()==0)
        return;

    while (QLayoutItem* item = layPr->takeAt(0)) {        
        while (QLayoutItem* item1 = item->layout()->takeAt(0)) {
            delete item1->widget();
            delete item1;
        }
        delete item;
    }

    //вычисление количества исходя из размеров экрана
    int cardsInRow = 5;

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
    int boxHeight = cardsList.length()/cardsInRow*cardsList.at(0)->height()+(cardsList.length()/cardsInRow+1)*cardsDist;
    if (boxHeight > scrollArea->height())
        cardsBox->setFixedHeight(boxHeight);
    else
        cardsBox->setFixedHeight(scrollArea->height()-2);

}

void CardsBox::CreateCardsByCategory(QList<Product> base, QString categ)
{
    QList<Product> sortBase;
    if (categ == "Все категории")
         AddCards(base);
    else
    {

    for (int i=0; i<base.length(); i++)
    {
        if (base.at(i).GetCategory()==categ)
            sortBase.append(base.at(i));
    }

    AddCards(sortBase);
    }
}
