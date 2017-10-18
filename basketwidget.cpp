#include "basketwidget.h"

BasketWidget::BasketWidget()
{
    cardsBox = new QGroupBox;
    cardsBox->setFixedSize(600, 573);
    cardsBox->setStyleSheet("background-color : rgba(127, 255, 212, 0.4);");

    scrollArea = new QScrollArea(this);
    scrollArea->setBackgroundRole(QPalette::Light);
    scrollArea->setWidget(cardsBox);
    scrollArea->setFixedSize(600, 575);

    butPay = new QPushButton("Оплатить заказ");
    lblnumOfDays = new QLabel("Количество дней: ");
    lnnumOfDays = new QLineEdit;
    lnnumOfDays->setStyleSheet("background-color:#F0FFFF;");

    QHBoxLayout *layDays = new QHBoxLayout;
    layDays->addWidget(lblnumOfDays);
    layDays->addWidget(lnnumOfDays);

    layBask = new QVBoxLayout;
    layBask->setAlignment(Qt::AlignTop);

    cardsBox->setLayout(layBask);

    connect (butPay, SIGNAL(clicked()), this, SLOT(ButPayOrder()));
}

void BasketWidget::ButPayOrder()
{
   // emit OrderHasBeenPaid();

}
