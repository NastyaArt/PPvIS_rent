#ifndef CATALOGWIDGET_H
#define CATALOGWIDGET_H

#include <QWidget>
#include <QRadioButton>
#include <QButtonGroup>
#include <QGroupBox>
#include <QMessageBox>
#include <QPushButton>
#include <QLineEdit>
#include "cardsbox.h"

class CatalogWidget : public QWidget
{
    Q_OBJECT
public:
    CatalogWidget();
    void CreateCatalog(QList<Product> base);
    QList<Product> database;

private:
    CardsBox *cardsBox;

    QGroupBox *boxSearch;

    QGroupBox *boxCat;
    QStringList listCateg;
    QButtonGroup *btGrCateg;

    QGroupBox *boxCost;
    QLabel *lblCost;
    QLabel *ldlCostFrom;
    QLineEdit *lineCostFrom;
    QLabel *lblCostTo;
    QLineEdit*lineCostTo;
    QPushButton *butSearchByCost;

    QList<QRadioButton*> *rbutCateg;
    QList<ProductCard> cards;

    void GetCategories(QList<Product> base);

public slots:
    void GetCardsByCategory(int id);
    void GetCardsByCost();

};

#endif // CATALOGWIDGET_H
