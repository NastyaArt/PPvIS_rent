#ifndef STATUSWIDGET_H
#define STATUSWIDGET_H

#include <QWidget>
#include <QScrollArea>
#include <QScrollBar>
#include <QGroupBox>
#include <QStringList>
#include <QLabel>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QMessageBox>
#include "statuscard.h"

class StatusWidget : public QWidget
{
    Q_OBJECT
public:
    StatusWidget();

private:
   // QStringList *cardsArticles; //список артикулов (список заказов)

    QVBoxLayout *layCards;
    QScrollArea *scrollArea;
    QGroupBox *cardsBox;
    const int cardsDist = 10;
signals:

    void SendArticlesToGetProducts(QStringList articles);
   // void SaveOrders(); ??? сохранять в базе и оттуда же считывать (м.б. список векторов типа <QStringList articles, int numOfDays, double total>

public slots:

    void AddOrder(QStringList articles, int numOfDays, double total);
    //void UploadOrders(); ???
};

#endif // STATUSWIDGET_H
