#include "databaseproduct.h"

DatabaseProduct::DatabaseProduct()
{

}

void DatabaseProduct::AddProduct(QString art, QString name, QString categ, bool avail, int rub, int pen)
{
	Product prd(art, name, categ, avail, rub, pen);
    database.append(prd);
}

void DatabaseProduct::AddProduct(Product prd)
{
        database.append(prd);
}

void DatabaseProduct::ClearDatabase()
{
        database.clear();
}
/*
void DatabaseProduct::GetDatabase()
{
    bool ok = true;
    bool intOk = true;
	
    QString art;
    QString name;
    QString categ;
    bool avail;
    int rub;
    int pen;
	
	database.clear();
    
    QFile file("xml/database");
    if (!file.open(QFile::ReadOnly | QFile::Text))
        ok = false;
    else {
        QXmlStreamReader xmlReader;
        xmlReader.setDevice(&file);
        xmlReader.readNext();

        while(!xmlReader.atEnd())
        {
           if(xmlReader.isStartElement())
           {
			    if (xmlReader.name() == "products")
					xmlReader.readNext();
                if (xmlReader.name() == "product"){
                    art = ("");
                    name = ("");
                    categ = ("");
                    avail = 0;
                    rub = 0;
					pen = 0;
					xmlReader.readNext();
                }
                if (xmlReader.name() == "article"){
                    art=xmlReader.readElementText();
					xmlReader.readNext();
				}
                if (xmlReader.name() == "name"){
                    name=xmlReader.readElementText();
					xmlReader.readNext();
				}
                if (xmlReader.name() == "category"){
                    categ=xmlReader.readElementText();
					xmlReader.readNext();
				}
                if (xmlReader.name() == "available"){
                    avail=xmlReader.readElementText().toInt(&intOk, 10);
					xmlReader.readNext();
				}
				if (xmlReader.name() == "cost")
					xmlReader.readNext();
                if (xmlReader.name() == "rubles"){
					rub=xmlReader.readElementText().toInt(&intOk, 10);
					xmlReader.readNext();
				}
                if (xmlReader.name() == "pennies"){
                    pen=xmlReader.readElementText().toInt(&intOk, 10);
                    AddProduct(art, name, categ, avail, rub, pen);
                }
           }
           xmlReader.readNext();
        }
        file.close();
    }
	if (ok==true)
		emit SendDatabase(database);
	else
		emit Error();
}*/

void DatabaseProduct::GetDatabase()
{

    Product prd1("00001", "Настолка1", "Категория1", 1, 19, 99);
    Product prd2("00002", "Настолка2", "Категория2", 0, 40, 00);
    Product prd3("00003", "Настолка3", "Категория3", 1, 45, 49);

    ClearDatabase();
    AddProduct(prd1);
    AddProduct(prd2);
    AddProduct(prd3);

    emit SendDatabase(database);
    emit Error();

}
