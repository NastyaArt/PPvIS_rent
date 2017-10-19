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
    void SendProduct(Product prd);
    void SendDatabase(QList<Product> base);
	void Error();

private slots:

    void GetDatabase();
    void GetProductByArticle(QString article);

};

#endif // DATABASEPRODUCT_H
