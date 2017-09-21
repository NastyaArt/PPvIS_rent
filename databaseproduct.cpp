#include "databaseproduct.h"

DatabaseProduct::DatabaseProduct()
{

}

void DatabaseProduct::AddProduct(Product prd)
{
    database.append(prd);
}

void DatabaseProduct::GetDatabase()
{
    // считывание с файла товаров
    emit SendDatabase(database);
}
