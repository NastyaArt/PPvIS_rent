#include "productcard.h"

ProductCard::ProductCard(Product prd)
{

    setFixedSize(200, 200);

    lblname = new QLabel(prd.GetName());
    lblinfo = new QLabel();
    lblinfo->setText("Артикул: <b>" + prd.GetArticle() + "<br/></b>Стоимость в сутки:<br/><b>" +
                  QString::number(prd.GetRubles()) + "." + QString::number(prd.GetPennies()) +
                  "<br/></b>Категория: <b>" + prd.GetCategory());
    lblinfo->setAlignment(Qt::AlignLeft);
    lblinfo->setWordWrap(true);
    lblnumOfDays = new QLabel("Количество дней: ");
    lnnumOfDays = new QLineEdit;
    lnnumOfDays->setStyleSheet("background-color:#F0FFFF;");
    butBuy = new QPushButton("Заказать");
    butBuy->setStyleSheet("background-color : #ADD8E6");

    if (prd.GetAvailable()==true)
        setStyleSheet("background-color:#BDFCC1;");
    else {
        butBuy->setEnabled(false);
        butBuy->setText("Нет в наличии");
        setStyleSheet("background-color:#DCDCDC;");
    }
	
    QHBoxLayout *layDays = new QHBoxLayout;
    layDays->addWidget(lblnumOfDays);
    layDays->addWidget(lnnumOfDays);

    QVBoxLayout *layCard = new QVBoxLayout;
    layCard->addWidget(lblname);
    layCard->addWidget(lblinfo);
    layCard->addLayout(layDays);
    layCard->addWidget(butBuy);

    setLayout(layCard);
}


void ProductCard::paintEvent(QPaintEvent *)
{
	QStyleOption opt;
	opt.init(this);
	QPainter p(this);
	style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}
