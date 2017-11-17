#include "basketcard.h"

BasketCard::BasketCard(Product *prd)
{
    setFixedSize(400, 100);
    setStyleSheet("background-color:#7FFFD4; font-size: 11pt;");

    lblInfo = new QLabel("Наименование: " +  prd->GetName() +
                         "<br/>Артикул: " + prd->GetArticle()+
                         "<br/></b>Стоимость в сутки:<br/><b>" +
                         QString::number(prd->GetCost(), 'f', 2));

    QVBoxLayout *layCard = new QVBoxLayout;
    layCard->addWidget(lblInfo);

    setLayout(layCard);

}

void BasketCard::paintEvent(QPaintEvent *)
{
    QStyleOption opt;
    opt.init(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}
