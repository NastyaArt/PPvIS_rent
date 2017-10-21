#ifndef BASKETWIDGET_H
#define BASKETWIDGET_H

#include <QWidget>
#include <QScrollArea>
#include <QScrollBar>
#include <QGroupBox>
#include <QStringList>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QMessageBox>
#include "basketcard.h"

class BasketWidget : public QWidget
{
    Q_OBJECT
public:
    BasketWidget();
private:

    QStringList cardsArticles; //список артикулов

    QVBoxLayout *layCards;
    QScrollArea *scrollArea;
    QGroupBox *cardsBox;
    QGroupBox *payBox;
    QGroupBox *boxTotal;
    QLabel *baskIsEmpty;
    const int cardsDist = 10;
    const int maxNumOfDays = 3;
    double sum;
    double totalCost;
    int numOfDays;
    QPushButton *butPay;
    QPushButton *butClear;
    QLabel *lblnumOfDays;
    QLineEdit *lnnumOfDays;
    QLabel *lbltotalCost;
    QLabel *lbltotalSum;


signals:
    void GetProductByArticle(QString article);
    void OrderHasBeenPaid(QStringList articles, int numOfDays, double total);
    void UploadCatalog();

public slots:

    void ButPayOrder();
   // void AddProduct(QString article);
    void AddProductCard(Product prd);
    void ClearBasket();
    void SetNumOfDays(QString text);

    QStringList GetProductInBasket();
};

#endif // BASKETWIDGET_H
