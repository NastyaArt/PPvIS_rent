#ifndef STATUSWIDGET_H
#define STATUSWIDGET_H

#include <QWidget>

class StatusWidget : public QWidget
{
    Q_OBJECT
public:
    explicit StatusWidget(QWidget *parent = 0);

signals:

   // void SaveOrders(); ??? сохранять в базе и оттуда же считывать (м.б. список векторов типа <QStringList articles, int numOfDays, double total>

public slots:

    void AddOrder(QStringList articles, int numOfDays, double total);
    //void UploadOrders(); ???
};

#endif // STATUSWIDGET_H
