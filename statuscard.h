#ifndef STATUSCARD_H
#define STATUSCARD_H

#include <QWidget>
#include <QLabel>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QStyleOption>
#include <QPainter>
#include <QDate>
#include "product.h"

class StatusCard : public QWidget
{
    Q_OBJECT
public:
 //   StatusCard(QList<Product> prds, int days, double total);
    StatusCard(QStringList articles, int days, double total);

private:

    QStringList prdArticles;
    QLabel *lblInfo;
    int numOfDays;
    double totalCost;
    QDate date;

    void paintEvent(QPaintEvent *);

signals:

public slots:
};

#endif // STATUSCARD_H
