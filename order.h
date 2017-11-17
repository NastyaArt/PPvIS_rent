#ifndef ORDER_H
#define ORDER_H

#include <QObject>
#include <QDate>
class Order
{
public:
    Order();

    void SetDate(QDate date);
    void SetDays(int days);
    void SetTotalCost(double cost);
    void AddProduct(QString art);
    void Clear();

    QDate GetDate();
    int GetDays();
    double GetTotalCost();
    QStringList GetArticles();

private:

    QStringList articles;
    QDate date;
    int days;
    double totalCost;

};

#endif // ORDER_H
