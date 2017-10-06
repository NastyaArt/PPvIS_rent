#ifndef CATALOGWIDGET_H
#define CATALOGWIDGET_H

#include <QWidget>
#include <QRadioButton>
#include <QButtonGroup>
#include <QGroupBox>
#include <QMessageBox>
//#include "productcard.h"
#include "cardsbox.h"

class CatalogWidget : public QWidget
{
    Q_OBJECT
public:
    CatalogWidget();
    void CreateCatalog(QList<Product> base);
    QList<Product> database;

private:

    QGroupBox *boxCat;
    CardsBox *cardsBox;
    QStringList listCateg;
    QButtonGroup *btGrCateg;

    QList<QRadioButton*> *rbutCateg;
    QList<ProductCard> cards;

    void GetCategories(QList<Product> base);

public slots:
    void GetCardsByCategory(int id);

};

#endif // CATALOGWIDGET_H
