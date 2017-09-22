#ifndef PRODUCTCARD_H
#define PRODUCTCARD_H

#include <QWidget>
#include <QLabel>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QStyleOption>
#include <QPainter>
#include "product.h"

class ProductCard : public QWidget
{
    Q_OBJECT
public:
    ProductCard(Product prd);

private:

    QLabel *name;
    QLabel *info;
	
	void paintEvent(QPaintEvent *);

signals:

public slots:
};

#endif // PRODUCTCARD_H
