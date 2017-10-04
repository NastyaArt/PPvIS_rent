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
    void AddProduct(QString art, QString name, QString categ, bool avail, int rub, int pen);
    void AddProduct(Product prd);
    void ClearDatabase();
  //  QString filename=("database.xml");

signals:

    void SendDatabase(QList<Product>);
	void Error();

private slots:

    void GetDatabase();

};

#endif // DATABASEPRODUCT_H
