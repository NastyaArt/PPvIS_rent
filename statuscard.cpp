#include "statuscard.h"

/*StatusCard::StatusCard(QList<Product> prds, int days, double total)
{
    lblInfo = new QLabel;
    date = QDate::currentDate();
    numOfDays = days;
    totalCost = total;

    for (int prdId=0; prdId<prds.length(); prdId++)
    {
        articles.append(prds.at(prdId).GetArticle());
        lblInfo->setText(lblInfo->text() +
                         "<br/><br/><b>" + prds.at(prdId).GetName() +
                         "<br/>Артикул: <b>" + prds.at(prdId).GetArticle() +
                         "<br/></b>Стоимость в сутки:<br/><b>" +
                         QString::number(prds.at(prdId).GetCost(), 'f', 2) +
                         "<br/></b>Категория: <b>" + prds.at(prdId).GetCategory());
    }

    lblInfo->setText(lblInfo->text() +
                     "<br/><br/><b>Дата оформления заказа: " +
                     date.toString("dd/MM/yy") +
                     "<br/>Количество дней: " +
                     QString::number(numOfDays) +
                     "<br/>Итоговая стоимость: " +
                     QString::number(totalCost, 'f', 2));
}

*/

StatusCard::StatusCard(QStringList articles, int days, double total)
{
    setFixedWidth(400);
    lblInfo = new QLabel;
    date = QDate::currentDate();
    numOfDays = days;
    totalCost = total;
    prdArticles=articles;

    lblInfo->setText("<b>Заказ<\b><br/><br/>Товары:");

    for (int artId=0; artId<articles.length(); artId++)
    {
        //articles.append(prds.at(prdId).GetArticle());
        lblInfo->setText(lblInfo->text() +
                         "<br/>" + QString::number(artId+1) + ") Артикул: " + articles.at(artId));
    }

    lblInfo->setText(lblInfo->text() +
                     "<br/><br/><b>Дата оформления заказа: " +
                     date.toString("dd/MM/yy") +
                     "<br/>Количество дней: " +
                     QString::number(numOfDays) +
                     "<br/>Итоговая стоимость: " +
                     QString::number(totalCost, 'f', 2));
    QVBoxLayout *layCard = new QVBoxLayout;
    layCard->addWidget(lblInfo);

    setLayout(layCard);

}
void StatusCard::paintEvent(QPaintEvent *)
{
    QStyleOption opt;
    opt.init(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}
