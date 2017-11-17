#ifndef PRODUCT_H
#define PRODUCT_H

#include <QObject>

class Product
{
public:
    Product(QString art, QString nm, QString cat, bool avlbl, double cost);

    QString GetArticle() const;
    QString GetName() const;
    QString GetCategory() const;
    bool GetAvailable() const;
    double GetCost() const;
    bool GetInOrder() const;
    void SetInOrder(bool ok);

private:
    QString article;
    QString name;
    QString category;
    bool available;
    double cost;
    bool inOrder;
};

#endif // PRODUCT_H
