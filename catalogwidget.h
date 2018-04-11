#ifndef CATALOGWIDGET_H
#define CATALOGWIDGET_H

#include <QWidget>
#include <QRadioButton>
#include <QButtonGroup>
#include <QGroupBox>
#include <QMessageBox>
#include <QPushButton>
#include <QLineEdit>
#include <QList>
#include <QScrollArea>
#include "productcard.h"

class CatalogWidget : public QWidget
{
    Q_OBJECT
public:
    CatalogWidget();


private:

    QGroupBox *boxSearch;
    QGroupBox *boxCat;
    QVBoxLayout *layCateg;
    QStringList listCateg;
    QButtonGroup *btGrCateg;

    QGroupBox *boxCost;
    QLabel *lblCost;
    QLabel *ldlCostFrom;
    QLineEdit *lineCostFrom;
    QLabel *lblCostTo;
    QLineEdit *lineCostTo;
    QPushButton *butSearchByCost;

    QList<QRadioButton*> *rbutCateg;

    QGroupBox *cardsBox;
    QVBoxLayout *layPr;
    QScrollArea *scrollArea;
    const int cardsDist = 10;
    const int cardsInRow = 5;

    void GetCategories(QList<Product*> base);
    void PlaceCards(QList<ProductCard*> *cardsList);
    void ClearCatalog();

signals:
    void GetProductsByCategory(QString cat);
    void GetProductsByCost(int from, int to);
    void GetDatabase();
    void SendProductToOrder(QString art);

public slots:

    void CreateCatalog(QList<Product*> base);
    void CreateCards(QList<Product*> base);
    void GetCardsByCategory(int id);
    void GetCardsByCost();
    void GetProductToOrder(QString art);

};

#endif // CATALOGWIDGET_H
