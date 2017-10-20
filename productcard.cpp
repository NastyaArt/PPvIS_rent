#include "productcard.h"

ProductCard::ProductCard(Product prd)
{

    setFixedSize(200, 200);

    article = prd.GetArticle();
    category = prd.GetCategory();
    cost = prd.GetCost();

    lblname = new QLabel(prd.GetName());
    lblinfo = new QLabel();
    lblinfo->setText("Артикул: <b>" + prd.GetArticle() + "<br/></b>Стоимость в сутки:<br/><b>" +
                  QString::number(prd.GetCost(), 'f', 2) +
                  "<br/></b>Категория: <b>" + prd.GetCategory());
    lblinfo->setAlignment(Qt::AlignLeft);
    lblinfo->setWordWrap(true);

    butBuy = new QPushButton("Заказать");
    butBuy->setStyleSheet("background-color : #ADD8E6");

    if (prd.GetAvailable()==true)
        setStyleSheet("background-color:#7FFFD4;");
    else {
        butBuy->setEnabled(false);
        butBuy->setText("Нет в наличии");
        setStyleSheet("background-color:#D3D3D3;");
    }
	
    QVBoxLayout *layCard = new QVBoxLayout;
    layCard->addWidget(lblname);
    layCard->addWidget(lblinfo);
    layCard->addWidget(butBuy);

    setLayout(layCard);

    connect (butBuy, SIGNAL(clicked()), this, SLOT(BuyProduct()));
}

void ProductCard::BuyProduct()
{
    butBuy->setEnabled(false);
    butBuy->setText("Добавлено в корзину");
    emit SendProduct(article);
}

void ProductCard::paintEvent(QPaintEvent *)
{
	QStyleOption opt;
	opt.init(this);
	QPainter p(this);
	style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}

