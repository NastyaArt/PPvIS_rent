#include "order.h"

Order::Order()
{

}

void Order::SetDate(QDate date)
{
    this->date=date;
}

void Order::SetDays(int days)
{
    this->days=days;
}

void Order::SetTotalCost(double cost)
{
    this->totalCost=cost;
}

void Order::AddProduct(QString art)
{
    articles.append(art);
}

QDate Order::GetDate()
{
    return date;
}

int Order::GetDays()
{
    return days;
}

double Order::GetTotalCost()
{
    return totalCost;
}

QStringList Order::GetArticles()
{
    return articles;
}

void Order::Clear()
{
    articles.clear();
    days=0;
    totalCost=0.00;
}
