#ifndef PRODUCT_H
#define PRODUCT_H

#include <QObject>

class Product
{
public:
    Product(QString art, QString nm, QString cat, bool avlbl, int rub, int pen);

    QString GetArticle() const;
    QString GetName() const;
    QString GetCategory() const;
    bool GetAvailable() const;
    int GetRubles() const;
    int GetPennies() const;

private:
    QString article;
    QString name;
    QString category;
    bool available;
    int rubles;
    int pennies;

};

#endif // PRODUCT_H
