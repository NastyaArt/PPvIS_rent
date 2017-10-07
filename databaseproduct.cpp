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
    
    QFile file(filename);
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
    SortByAvailable();
	if (ok==true)
		emit SendDatabase(database);
	else
		emit Error();
}

void DatabaseProduct::SortByAvailable()
{
    for (int prd1Id = 0; prd1Id <database.length()-1; prd1Id++)
          for (int prd2Id = prd1Id+1; prd2Id < database.length(); prd2Id++)
                  if (database.at(prd1Id).GetAvailable() < database.at(prd2Id).GetAvailable()) {
                  database.swap(prd1Id, prd2Id);
              }
}


