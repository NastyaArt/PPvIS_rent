#ifndef CARDSBOX_H
#define CARDSBOX_H

#include <QWidget>
#include <QScrollArea>
#include <QScrollBar>
#include <QGroupBox>
#include <QList>
#include "productcard.h"

class CardsBox : public QWidget
{
    Q_OBJECT
public:
    CardsBox();
    void AddCards(QList<Product> base);
    void PlaceCards(QList<ProductCard*> cardsList);
private:
    QScrollArea *scrollArea;
    QGroupBox *cardsBox;


signals:

public slots:
};

#endif // CARDSBOX_H
