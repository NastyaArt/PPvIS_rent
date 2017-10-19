#include "basketwidget.h"

BasketWidget::BasketWidget()
{

    cardsBox = new QGroupBox;
    cardsBox->setFixedSize(1050, 573);
    cardsBox->setStyleSheet("background-color : rgba(127, 255, 212, 0.4);");

    scrollArea = new QScrollArea(this);
    scrollArea->setBackgroundRole(QPalette::Light);
    scrollArea->setWidget(cardsBox);
    scrollArea->setFixedSize(1070, 575);

    butPay = new QPushButton("Оплатить заказ");
    butPay->setFixedSize(120, 30);
    butPay->setStyleSheet("background-color:#E6E6FA;");
    lblnumOfDays = new QLabel("Количество дней: ");
    lblnumOfDays->setFixedWidth(100);
    lnnumOfDays = new QLineEdit;
    lnnumOfDays->setFixedWidth(70);
    lnnumOfDays->setStyleSheet("background-color:#F0FFFF;");

    QHBoxLayout *layTotal = new QHBoxLayout;
    layTotal->addWidget(lblnumOfDays);
    layTotal->addWidget(lnnumOfDays);
    layTotal->addWidget(butPay);
    layTotal->setAlignment(Qt::AlignCenter);

    QGroupBox *boxTotal = new QGroupBox;
    boxTotal->setLayout(layTotal);
    boxTotal->setStyleSheet("background-color:#AFEEEE;");

    layCards = new QVBoxLayout;
    layCards->setAlignment(Qt::AlignCenter);

    QVBoxLayout *layBask = new QVBoxLayout;
    layBask->addLayout(layCards);
    layBask->addWidget(boxTotal);
    layBask->setAlignment(Qt::AlignTop);

    cardsBox->setLayout(layBask);

    connect (butPay, SIGNAL(clicked()), this, SLOT(ButPayOrder()));
}

void BasketWidget::AddProduct(QString article)
{
    emit GetProductByArticle(article);
}

void BasketWidget::AddProductCard(Product prd)
{
    BasketCard *card = new BasketCard(prd);
    layCards->addWidget(card);
    int boxHeight = (layCards->count())*(card->height()+cardsDist)+70;
    if (boxHeight > scrollArea->height())
        cardsBox->setFixedHeight(boxHeight);
    else
        cardsBox->setFixedHeight(scrollArea->height()-2);

}
void BasketWidget::ButPayOrder()
{
   // emit OrderHasBeenPaid(QStringList articles, int numOfDays, double total);

}

