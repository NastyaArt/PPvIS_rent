#include "cardsbox.h"

CardsBox::CardsBox()
{

    cardsBox = new QGroupBox;
    cardsBox->setFixedSize(1100, 1000);  //5*(размер одной карточки + немного) - ширина, а по высоте сделать прокрутку
    cardsBox->setStyleSheet("background-color : rgba(127, 255, 212, 0.4);");

    scrollArea = new QScrollArea(this);
    scrollArea->setBackgroundRole(QPalette::Light);
    scrollArea->setWidget(cardsBox);
    scrollArea->setFixedSize(1100, 700);

}

void CardsBox::AddCards(QList<Product> base)
{
    //цикл с созданием добавлением карточек на поле
    QVBoxLayout *layPr = new QVBoxLayout;
   // layPr->addWidget(prd1Card);
    layPr->setAlignment(Qt::AlignTop);
   // cardsBox->setLayout(layPr);

    for (int i=0; i<base.length(); i++)
    {
        ProductCard *prdCard = new ProductCard(base.at(i));
        layPr->addWidget(prdCard);
    }

    cardsBox->setLayout(layPr);

}
