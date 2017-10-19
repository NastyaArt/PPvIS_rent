#ifndef DATABASEPRODUCT_H
#define DATABASEPRODUCT_H

#include <QObject>
#include <QXmlStreamReader>
#include <QXmlStreamAttribute>
#include <QFile>
#include "product.h"

class DatabaseProduct : public QObject
{
    Q_OBJECT
public:

    DatabaseProduct();



private:

    QList<Product> database;
    void AddProduct(QString art, QString name, QString categ, bool avail, double cst);
    void AddProduct(Product prd);
    void ClearDatabase();
    void SortByAvailable();

    const QString filename=("xml/database.xml");



signals:

    void SendDatabase(QList<Product>);
	void Error();

private slots:

    void GetDatabase();
    void GetProductByArticle();

};

#endif // DATABASEPRODUCT_H
