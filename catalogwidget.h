#ifndef CATALOGWIDGET_H
#define CATALOGWIDGET_H

#include <QWidget>
#include <QRadioButton>
#include <QButtonGroup>
#include <QGroupBox>
#include "productcard.h"

class CatalogWidget : public QWidget
{
    Q_OBJECT
public:
    CatalogWidget();
    CatalogWidget(QList<Product> database);

private:

    QGroupBox *cardsBox;
    QStringList listCateg;
    QButtonGroup *btGrCateg;

    QList<QRadioButton*> *rbutCateg;
    QList<ProductCard> cards;

};

#endif // CATALOGWIDGET_H
