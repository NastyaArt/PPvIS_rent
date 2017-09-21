#include "productcard.h"

ProductCard::ProductCard(Product prd)
{

    setFixedSize(100, 200);

    name = new QLabel(prd.GetName());
    info = new QLabel();
    info->setText("Артикул: <b>" + QString::number(prd.GetArticle()) + "<br/></b>Стоимость в сутки:<br/><b>" +
                  QString::number(prd.GetRubles()) + "." + QString::number(prd.GetPennies()) +
                  "<br/></b>Категория: <b>" + prd.GetCategory());
    info->setAlignment(Qt::AlignLeft);

    QVBoxLayout *card = new QVBoxLayout;
    card->addWidget(name);
    card->addWidget(info);

    setLayout(card);
}

