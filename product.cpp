#include "product.h"

Product::Product(QString art, QString nm, QString cat, bool avlbl, int rub, int pen)
{
    article = art;
    name = nm;
    category = cat;
    available = avlbl;
    rubles = rub;
    pennies = pen;
}

QString Product::GetArticle()
{
    return article;
}

QString Product::GetName()
{
    return name;
}

QString Product::GetCategory()
{
    return category;
}

bool Product::GetAvailable()
{
    return available;
}

int Product::GetRubles()
{
    return rubles;
}

int Product::GetPennies()
{
    return pennies;
}