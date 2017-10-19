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

    for (int prdId=0; prdId<base.length(); prdId++)
    {
        ProductCard *prdCard = new ProductCard(base.at(prdId));
        cardsList.append(prdCard);
        connect (prdCard, SIGNAL(SendProduct(QString)), this, SLOT(GetProductByArticle(QString)));
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

    for (int cardId=0; cardId<cardsList.length(); cardId++){
        QHBoxLayout *layRow = new QHBoxLayout;
        layRow->setAlignment(Qt::AlignTop);
        for (int cardInRowId=0; cardInRowId<cardsInRow; cardInRowId++)
            if ((cardId+cardInRowId)<cardsList.length())
                layRow->addWidget(cardsList.at(cardId+cardInRowId));
        cardId=cardId+cardsInRow-1;
        layPr->addLayout(layRow);
    }
    //переделать вычисление размеров
    int boxHeight = layPr->count()*(cardsList.at(0)->height()+cardsDist);
//    int boxHeight = cardsList.length()/cardsInRow*cardsList.at(0)->height()+(cardsList.length()/cardsInRow+1)*cardsDist;
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
        for (int prdId=0; prdId<base.length(); prdId++)
        {
            if (base.at(prdId).GetCategory()==categ)
                sortBase.append(base.at(prdId));
        }
    AddCards(sortBase);
    }
}

void CardsBox::CreateCardsByCost(QList<Product> base, int from, int to)
{
    QList<Product> sortBase;

    for (int prdId=0; prdId<base.length(); prdId++)
    {
        //if (base.at(prdId).GetRubles()>=from && (base.at(prdId).GetRubles()< to || (base.at(prdId).GetRubles()<= to && base.at(prdId).GetPennies()== 0)))
        if (base.at(prdId).GetCost()>=from && base.at(prdId).GetCost()<=to)
            sortBase.append(base.at(prdId));
    }

    AddCards(sortBase);

}

void CardsBox::GetProductByArticle(QString article)
{
    emit SendArticleToGetProduct(article);

}
