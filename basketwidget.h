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

    double sumCost;
    double totalCost;
    int numOfDays;

    QVBoxLayout *layCards;
    QScrollArea *scrollArea;
    QGroupBox *cardsBox;
    QGroupBox *payBox;
    QGroupBox *boxTotal;
    QLabel *baskIsEmpty;
    const int cardsDist = 10;
    const int maxNumOfDays = 3;

    QPushButton *butPay;
    QPushButton *butClear;
    QLabel *lblnumOfDays;
    QLineEdit *lnnumOfDays;
    QLabel *lbltotalCost;
    QLabel *lbltotalSum;


signals:
    void OrderHasBeenPaid(int numOfDays, double total);
    void ClearOrder();

public slots:

    void ButPayOrder();
    void AddProductCard(Product *prd);
    void ClearBasket();
    void SetNumOfDays(QString text);
};

#endif // BASKETWIDGET_H
