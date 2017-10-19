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
#include "basketcard.h"

class BasketWidget : public QWidget
{
    Q_OBJECT
public:
    BasketWidget();
private:

    QStringList *cardsArticles; //список артикулов

    QVBoxLayout *layCards;
    QScrollArea *scrollArea;
    QGroupBox *cardsBox;
    QGroupBox *payBox;
    const int cardsDist = 10;
    const int maxNumOfDays = 3;
    QPushButton *butPay;
    QLabel *lblnumOfDays;
    QLineEdit *lnnumOfDays;


signals:
    void GetProductByArticle(QString article);
    void OrderHasBeenPaid(QStringList articles, int numOfDays, double total);

public slots:

    void ButPayOrder();
    void AddProduct(QString article);
    void AddProductCard(Product prd);
};

#endif // BASKETWIDGET_H
