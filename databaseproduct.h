#ifndef DATABASEPRODUCT_H
#define DATABASEPRODUCT_H

#include <QObject>
#include <QXmlStreamReader>
#include <QXmlStreamAttribute>
#include <QFile>
#include "product.h"
#include "order.h"

class DatabaseProduct : public QObject
{
    Q_OBJECT
public:

    DatabaseProduct();

private:

    QList<Product*> database;
    Order *order;
    const QString filename=("xml/database.xml");

    void AddProduct(QString art, QString name, QString categ, bool avail, double cst);
    void ClearDatabase();
    void SortByAvailable();

signals:
    void SendProduct(Product *prd);
    void SendProductToBasket(Product *prd);
    void SendProducts(QList<Product*> base);
    void SendDatabase(QList<Product*> base);
    void SendOrderToStatus(Order *ord);
	void Error();

private slots:

    void ClearOrder();
    void GetDatabase();
    void GetProductsByCategory(QString cat);
    void GetProductsByCost(int from, int to);
    void AddProductToOrder(QString art);
    void OrderHasBeenPaid(int days, double cost);

};

#endif // DATABASEPRODUCT_H
