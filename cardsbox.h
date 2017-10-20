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
    void CreateCardsByCost(QList<Product> base, int from, int to);
    void ShowCardsByCategory(QString categ);

private:

    QList<ProductCard*> *cardsList;
    QVBoxLayout *layPr;
    QScrollArea *scrollArea;
    QGroupBox *cardsBox;
    const int cardsDist = 10;
    //вычисление количества исходя из размеров экрана доделать
    const int cardsInRow = 5;


    void AddCards(QList<Product> base);
    void PlaceCards(QList<ProductCard*> *cardsList);



signals:    
    void SendArticleToGetProduct(QString article);

public slots:
    void GetProductByArticle(QString article);

};

#endif // CARDSBOX_H
