#ifndef PRODUCTCARD_H
#define PRODUCTCARD_H

#include <QWidget>
#include <QLabel>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include "product.h"

class ProductCard : public QWidget
{
    Q_OBJECT
public:
    ProductCard(Product prd);

private:

    QLabel *name;
    QLabel *info;

signals:

public slots:
};

#endif // PRODUCTCARD_H
