#include "statuswidget.h"

StatusWidget::StatusWidget()
{    
    boxHeight = 70;
    cardsBox = new QGroupBox;
    cardsBox->setFixedSize(1320, 573);
    cardsBox->setStyleSheet("background-color : rgba(127, 255, 212, 0.4);");

    scrollArea = new QScrollArea(this);
    scrollArea->setBackgroundRole(QPalette::Light);
    scrollArea->setWidget(cardsBox);
    scrollArea->setFixedSize(1340, 575);

    layCards = new QVBoxLayout;
    layCards->setAlignment(Qt::AlignTop);

    cardsBox->setLayout(layCards);

}


void StatusWidget::AddOrder(Order *ord)
{
    StatusCard *card = new StatusCard(ord);
    layCards->addWidget(card);
    boxHeight+=card->height()+cardsDist;

    for (int wdgId = 0; wdgId<layCards->count(); wdgId++)
    {
        boxHeight+=(layCards->itemAt(wdgId)->widget()->height()+cardsDist);
    }
    if (boxHeight > scrollArea->height())
        cardsBox->setFixedHeight(boxHeight);
    else
        cardsBox->setFixedHeight(scrollArea->height()-2);
}
