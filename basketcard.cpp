#include "basketcard.h"

BasketCard::BasketCard(Product prd)
{
    setFixedSize(400, 200);
    setStyleSheet("background-color:#7FFFD4; font-size: 11pt;");

    lblInfo = new QLabel("Наименование: " +  prd.GetName() +
                         "<br/>Артикул: " + prd.GetArticle()+
                         "<br/></b>Стоимость в сутки:<br/><b>" +
                         QString::number(prd.GetCost(), 'f', 2));
    butDel = new QPushButton("Удалить товар");
    butDel->setStyleSheet("background-color : #ADD8E6");
    butDel->setFixedSize(120, 30);

    QVBoxLayout *layCard = new QVBoxLayout;
    layCard->addWidget(lblInfo);
    layCard->addWidget(butDel);

    setLayout(layCard);

}

void BasketCard::paintEvent(QPaintEvent *)
{
    QStyleOption opt;
    opt.init(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}
