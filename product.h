#ifndef PRODUCT_H
#define PRODUCT_H

#include <QObject>

class Product
{
public:
    Product(int art, QString nm, QString cat, bool avlbl, int rub, int pen);

    int GetArticle();
    QString GetName();
    QString GetCategory();
    bool GetAvailable();
    int GetRubles();
    int GetPennies();

private:
    int article;
    QString name;
    QString category;
    bool available;
    int rubles;
    int pennies;

};

#endif // PRODUCT_H
