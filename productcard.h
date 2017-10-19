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

    QString article;
    QLabel *lblname;
    QLabel *lblinfo;
    QPushButton *butBuy;
	
	void paintEvent(QPaintEvent *);

signals:
    void SendProduct(QString article);

public slots:
    void BuyProduct();
};

#endif // PRODUCTCARD_H
