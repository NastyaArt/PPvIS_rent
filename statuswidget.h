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

    QVBoxLayout *layCards;
    QScrollArea *scrollArea;
    QGroupBox *cardsBox;
    const int cardsDist = 10;
    int boxHeight;

signals:

public slots:

    void AddOrder(Order *ord);

};

#endif // STATUSWIDGET_H
