#include "basketwidget.h"

BasketWidget::BasketWidget()
{
    sum = 0.0;
    numOfDays = maxNumOfDays;
    baskIsEmpty = new QLabel("Корзина пуста");
    baskIsEmpty->setStyleSheet("background-color:#E6E6FA;  font-size: 24pt;");
    baskIsEmpty->setAlignment(Qt::AlignCenter);

    //QStringList cardsArticles ;
    cardsBox = new QGroupBox;
    cardsBox->setFixedSize(1320, 573);
    cardsBox->setStyleSheet("background-color : rgba(127, 255, 212, 0.4);");

    scrollArea = new QScrollArea(this);
    scrollArea->setBackgroundRole(QPalette::Light);
    scrollArea->setWidget(cardsBox);
    scrollArea->setFixedSize(1340, 575);

    butPay = new QPushButton("Оформить заказ");
    butPay->setFixedSize(120, 30);
    butPay->setStyleSheet("background-color:#E6E6FA;");
    butClear = new QPushButton("Очистить заказ");
    butClear->setFixedSize(120, 30);
    butClear->setStyleSheet("background-color:#E6E6FA;");
    lblnumOfDays = new QLabel("Количество дней: ");
    lblnumOfDays->setFixedWidth(100);
    lnnumOfDays = new QLineEdit;
    lnnumOfDays->setText(QString::number(maxNumOfDays));
    lnnumOfDays->setFixedWidth(70);
    lnnumOfDays->setStyleSheet("background-color:#F0FFFF;");

    lbltotalCost = new QLabel("<b>Итоговая стоимость: <\b>");
    lbltotalCost->setFixedWidth(140);
    lbltotalSum = new QLabel("0.00");
    lbltotalSum->setFixedWidth(70);

    QHBoxLayout *layTotal = new QHBoxLayout;
    layTotal->addWidget(lblnumOfDays);
    layTotal->addWidget(lnnumOfDays);
    layTotal->addWidget(lbltotalCost);
    layTotal->addWidget(lbltotalSum);
    layTotal->addWidget(butPay);
    layTotal->addWidget(butClear);
    layTotal->setAlignment(Qt::AlignCenter);

    boxTotal = new QGroupBox;
    boxTotal->setLayout(layTotal);
    boxTotal->setStyleSheet("background-color:#AFEEEE;");
    boxTotal->hide();

    layCards = new QVBoxLayout;
    layCards->setAlignment(Qt::AlignCenter);

    QVBoxLayout *layBask = new QVBoxLayout;
    layBask->addWidget(baskIsEmpty);
    layBask->addLayout(layCards);
    layBask->addWidget(boxTotal);
    layBask->setAlignment(Qt::AlignTop);

    cardsBox->setLayout(layBask);

    connect (butPay, SIGNAL(clicked()), this, SLOT(ButPayOrder()));
    connect (butClear, SIGNAL(clicked()), this, SLOT(ClearBasket()));
    connect (lnnumOfDays, SIGNAL(textChanged(QString)), this, SLOT(SetNumOfDays(QString)));
}
/*
void BasketWidget::AddProduct(QString article)
{
    cardsArticles->append(article);
    emit GetProductByArticle(article);
}
*/
void BasketWidget::AddProductCard(Product prd)
{
    boxTotal->show();
    baskIsEmpty->hide();
    cardsArticles.append(prd.GetArticle());
    BasketCard *card = new BasketCard(prd);
    layCards->addWidget(card);
    int boxHeight = (layCards->count())*(card->height()+cardsDist)+70;
    if (boxHeight > scrollArea->height())
        cardsBox->setFixedHeight(boxHeight);
    else
        cardsBox->setFixedHeight(scrollArea->height()-2);
    sum+=prd.GetCost();
   // lbltotalSum->setText(QString::number(sum*numDays));
  /*
    int numOfDays;
    double totalCost;
    */
    SetNumOfDays(lnnumOfDays->text());
}

void BasketWidget::ClearBasket()
{
    boxTotal->hide();
    baskIsEmpty->show();

    cardsArticles.clear();
    sum = 0.0;

    while (QLayoutItem* item = layCards->takeAt(0)) {
        delete item->widget();
        delete item;
    }
    cardsBox->setFixedHeight(scrollArea->height()-2);
    emit UploadCatalog();
}

void BasketWidget::ButPayOrder()
{
    bool ok = true;
    int days = lnnumOfDays->text().toInt(&ok, 10);
    if (lnnumOfDays->text()==NULL || ok==false){
        QMessageBox::warning(this, "Неправильно введены данные", "Введите количество дней от 1 до 3!", QMessageBox::Ok);
        return;
    }

    if (days>maxNumOfDays || days<=0){
        QMessageBox::warning(this, "Неправильно введены данные", "Количество дней не может быть больше <b>3 дней</b>!", QMessageBox::Ok);
        return;
    }

    while (QLayoutItem* item = layCards->takeAt(0)) {
        delete item->widget();
        delete item;
    }
    boxTotal->hide();
    baskIsEmpty->show();
    cardsBox->setFixedHeight(scrollArea->height()-2);
    emit OrderHasBeenPaid(cardsArticles, 3, 20.0);
    emit UploadCatalog();
//изменить на использование функции очистки корзины
    sum = 0.0;

    cardsArticles.clear();

}

QStringList BasketWidget::GetProductInBasket()
{
    return cardsArticles;
}

void BasketWidget::SetNumOfDays(QString text)
{
    bool ok = true;
    int days = text.toInt(&ok, 10);
    if (text==NULL || ok==false){
        QMessageBox::warning(this, "Неправильно введены данные", "Введите количество дней от 1 до 3!", QMessageBox::Ok);
        return;
    }

    if (days>maxNumOfDays || days<=0){
        QMessageBox::warning(this, "Неправильно введены данные", "Количество дней не может быть больше <b>3 дней</b>!", QMessageBox::Ok);
        return;
    }
    numOfDays = days;
    totalCost = sum * numOfDays;
    lbltotalSum->setText(QString::number(totalCost, 'f', 2));

}
