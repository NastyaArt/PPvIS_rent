#ifndef PRODUCTCARD_H
#define PRODUCTCARD_H

#include <QWidget>
#include <QLabel>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QStyleOption>
#include <QPainter>
#include <QPushButton>
#include <QLineEdit>
#include "product.h"

class ProductCard : public QWidget
{
    Q_OBJECT
public:
    ProductCard(Product prd);

private:

    QLabel *lblname;
    QLabel *lblinfo;
    QLabel *lblnumOfDays;
    QLineEdit *lnnumOfDays;
    QPushButton *butBuy;
	
	void paintEvent(QPaintEvent *);

signals:

public slots:
};

#endif // PRODUCTCARD_H
