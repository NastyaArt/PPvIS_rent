#include "databaseproduct.h"

DatabaseProduct::DatabaseProduct()
{
    order = new Order;
}

void DatabaseProduct::AddProduct(QString art, QString name, QString categ, bool avail, double cst)
{
    Product *prd = new Product(art, name, categ, avail, cst);
    database.append(prd);
}

void DatabaseProduct::AddProduct(Product *prd)
{
        database.append(prd);
}

void DatabaseProduct::ClearDatabase()
{
        database.clear();
}

void DatabaseProduct::GetDatabase()
{
    if (database.length()!=0){
        emit SendDatabase(database);
        return;
    }

    bool ok = true;
    bool intOk = true;
    bool doubleOk = true;
	
    QString art;
    QString name;
    QString categ;
    bool avail;
    double cost;
	
    ClearDatabase();
    
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
                    cost = 0.0;
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
                if (xmlReader.name() == "cost"){
                    cost=xmlReader.readElementText().toDouble(&doubleOk);
                    AddProduct(art, name, categ, avail, cost);
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
                  if (database.at(prd1Id)->GetAvailable() < database.at(prd2Id)->GetAvailable()) {
                  database.swap(prd1Id, prd2Id);
              }
}



void DatabaseProduct::GetProductsByCategory(QString cat)
{
    QList<Product*> base;
    if (cat=="Все категории")
        emit SendProducts(database);
    else{
        for (int prdId = 0; prdId < database.length(); prdId++)
        {
            if (database.at(prdId)->GetCategory()==cat)
            {
                base.append(database.at(prdId));
            }
        }
        emit SendProducts(base);
    }

}

void DatabaseProduct::GetProductsByCost(int from, int to)
{
    QList<Product*> base;
    for (int prdId = 0; prdId < database.length(); prdId++)
    {
        if (database.at(prdId)->GetCost()>=from && database.at(prdId)->GetCost()<=to)
        {
            base.append(database.at(prdId));
        }
    }
    emit SendProducts(base);
}

void DatabaseProduct::ClearOrder()
{
    order->Clear();
    for (int prdId = 0; prdId < database.length(); prdId++)
    {
        database.at(prdId)->SetInOrder(false);
    }
    emit SendDatabase(database);
}

void DatabaseProduct::AddProductToOrder(QString art)
{
    order->AddProduct(art);
    for (int prdId = 0; prdId < database.length(); prdId++)
    {
        if (database.at(prdId)->GetArticle()==art)
        {
            database.at(prdId)->SetInOrder(true);
            emit SendProductToBasket(database.at(prdId));
            return;
        }
    }

}

void DatabaseProduct::OrderHasBeenPaid(int days, double cost)
{
    order->SetDate(QDate::currentDate());
    order->SetDays(days);
    order->SetTotalCost(cost);
    emit SendOrderToStatus(order);
    ClearOrder();

}

