#include "productcard.h"

ProductCard::ProductCard(Product prd)
{

    setFixedSize(200, 200);

    name = new QLabel(prd.GetName());
    info = new QLabel(); 
    info->setText("Артикул: <b>" + prd.GetArticle() + "<br/></b>Стоимость в сутки:<br/><b>" +
                  QString::number(prd.GetRubles()) + "." + QString::number(prd.GetPennies()) +
                  "<br/></b>Категория: <b>" + prd.GetCategory());
    info->setAlignment(Qt::AlignLeft);

    if (prd.GetAvailable()==true)
        setStyleSheet("background-color:#69F0AE;");
	else 
        setStyleSheet("background-color:#DCDCDC;");
	
    QVBoxLayout *card = new QVBoxLayout;
    card->addWidget(name);
    card->addWidget(info);

    setLayout(card);
}


void ProductCard::paintEvent(QPaintEvent *)
{
	QStyleOption opt;
	opt.init(this);
	QPainter p(this);
	style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}
