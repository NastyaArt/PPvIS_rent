#include "statuscard.h"

StatusCard::StatusCard(Order *ord)
{
    setFixedWidth(400);
    lblInfo = new QLabel;

    lblInfo->setText("<b>Заказ<\b><br/><br/>Товары:");

    for (int artId=0; artId<ord->GetArticles().length(); artId++)
    {
        lblInfo->setText(lblInfo->text() +
                         "<br/>" + QString::number(artId+1) + ") Артикул: " + ord->GetArticles().at(artId));
    }

    lblInfo->setText(lblInfo->text() +
                     "<br/><br/><b>Дата оформления заказа: " +
                     ord->GetDate().toString("dd/MM/yy") +
                     "<br/>Количество дней: " +
                     QString::number(ord->GetDays()) +
                     "<br/>Итоговая стоимость: " +
                     QString::number(ord->GetTotalCost(), 'f', 2));
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
