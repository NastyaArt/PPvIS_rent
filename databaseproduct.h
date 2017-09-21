#ifndef DATABASEPRODUCT_H
#define DATABASEPRODUCT_H

#include <QObject>
#include "product.h"

class DatabaseProduct : public QObject
{
    Q_OBJECT
public:

    DatabaseProduct();

private:

    QList<Product> database;
    void AddProduct(Product prd);
  //  QString filename=("database.xml");

signals:

    void SendDatabase(QList<Product> base);

public slots:

    void GetDatabase();

};

#endif // DATABASEPRODUCT_H
