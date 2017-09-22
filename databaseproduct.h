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
  //  QString filename=("database.xml");

signals:

    void SendDatabase(QList<Product> base);
	void Error();

public slots:

    void GetDatabase();

};

#endif // DATABASEPRODUCT_H
