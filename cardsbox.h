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
    void CreateCards(QList<Product> base);
    void CreateCardsByCategory(QList<Product> base, QString categ);

private:

    QVBoxLayout *layPr;
    QScrollArea *scrollArea;
    QGroupBox *cardsBox;
    const int cardsDist = 10;

    void AddCards(QList<Product> base);
    void PlaceCards(QList<ProductCard*> cardsList);


signals:

public slots:
};

#endif // CARDSBOX_H
