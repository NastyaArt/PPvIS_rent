#ifndef STATUSCARD_H
#define STATUSCARD_H

#include <QWidget>
#include <QLabel>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QStyleOption>
#include <QPainter>
#include <QDate>
#include "order.h"

class StatusCard : public QWidget
{
    Q_OBJECT
public:

    StatusCard(Order *ord);

private:

    QLabel *lblInfo;

    void paintEvent(QPaintEvent *);

signals:

public slots:
};

#endif // STATUSCARD_H
