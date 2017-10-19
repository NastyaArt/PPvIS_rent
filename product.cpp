#include "product.h"

Product::Product(QString art, QString nm, QString cat, bool avlbl, double cst)
{
    article = art;
    name = nm;
    category = cat;
    available = avlbl;
    cost = cst;
//    rubles = rub;
//    pennies = pen;
}

QString Product::GetArticle() const
{
    return article;
}

QString Product::GetName() const
{
    return name;
}

QString Product::GetCategory() const
{
    return category;
}

bool Product::GetAvailable() const
{
    return available;
}

double Product::GetCost() const
{
    return cost;
}

/*
int Product::GetRubles() const
{
    return rubles;
}

int Product::GetPennies() const
{
    return pennies;
}
*/
