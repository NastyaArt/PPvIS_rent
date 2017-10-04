#ifndef CATALOGWIDGET_H
#define CATALOGWIDGET_H

#include <QWidget>
#include <QRadioButton>
#include <QButtonGroup>
#include <QGroupBox>
#include <QMessageBox>
#include "productcard.h"

class CatalogWidget : public QWidget
{
    Q_OBJECT
public:
    CatalogWidget();
    CatalogWidget(QList<Product> database);
    void CreateCatalog(QList<Product> base);

private:

    QGroupBox *cardsBox;
    QStringList listCateg;
    QButtonGroup *btGrCateg;

    QList<QRadioButton*> *rbutCateg;
    QList<ProductCard> cards;

};

#endif // CATALOGWIDGET_H
