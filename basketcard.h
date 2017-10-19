#ifndef BASKETCARD_H
#define BASKETCARD_H

#include <QWidget>
#include <QLabel>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QStyleOption>
#include <QPainter>
#include <QPushButton>
#include "product.h"

class BasketCard : public QWidget
{
    Q_OBJECT
public:
    BasketCard(Product prd);

private:
    QLabel *lblInfo;
    QPushButton *butDel;

signals:

public slots:
};

#endif // BASKETCARD_H
