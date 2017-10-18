#include "basketcard.h"

BasketCard::BasketCard(Product prd, int numDays)
{
    setFixedSize(400, 200);
    setStyleSheet("background-color:#BDFCC1;  font-size: 11pt;");

    double cost = (prd.GetRubles() + (double)prd.GetPennies()/100)*numDays;

    lblInfo = new QLabel("Наименование: " +  prd.GetName() +
                         "<br/>Артикул: " + prd.GetArticle()+
                         "<br/>Количество дней: " + QString::number(numDays) +
                         "<br/></b>Стоимость в сутки:<br/><b>" +
                         QString::number(prd.GetRubles()) + "." +
                         QString::number(prd.GetPennies()) +
                         "<br/>Итого: <b>" + QString::number(cost)
                         );
    butDel = new QPushButton("Удалить товар");
    butDel->setStyleSheet("background-color : #ADD8E6");

    QVBoxLayout *layCard = new QVBoxLayout;
    layCard->addWidget(lblInfo);
    layCard->addWidget(butDel);

    setLayout(layCard);

}

