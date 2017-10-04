#ifndef CARDSBOX_H
#define CARDSBOX_H

#include <QWidget>
#include <QScrollArea>
#include <QScrollBar>
#include <QGroupBox>
#include "productcard.h"

class CardsBox : public QWidget
{
    Q_OBJECT
public:
    CardsBox();
    void AddCards(QList<Product> base);
private:
    QScrollArea *scrollArea;
    QGroupBox *cardsBox;


signals:

public slots:
};

#endif // CARDSBOX_H
