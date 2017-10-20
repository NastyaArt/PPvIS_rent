#include "statuswidget.h"

StatusWidget::StatusWidget()
{    
    cardsBox = new QGroupBox;
    cardsBox->setFixedSize(1320, 573);
    cardsBox->setStyleSheet("background-color : rgba(127, 255, 212, 0.4);");

    scrollArea = new QScrollArea(this);
    scrollArea->setBackgroundRole(QPalette::Light);
    scrollArea->setWidget(cardsBox);
    scrollArea->setFixedSize(1340, 575);

    layCards = new QVBoxLayout;
    layCards->setAlignment(Qt::AlignCenter);

    cardsBox->setLayout(layCards);

}


void StatusWidget::AddOrder(QStringList articles, int numOfDays, double total)
{
    StatusCard *card = new StatusCard(articles, numOfDays, total);
    layCards->addWidget(card);
    //emit SendArticlesToGetProducts(articles);

}
