#include "mainwindow.h"
#include "databaseproduct.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    DatabaseProduct base;
    MainWindow w;


    QObject::connect(w.catalog, SIGNAL(GetDatabase()), &base, SLOT(GetDatabase()));
    QObject::connect(&base, SIGNAL(SendDatabase(QList<Product*>)), w.catalog, SLOT(CreateCatalog(QList<Product*>)));
    QObject::connect (w.catalog, SIGNAL(GetProductsByCategory(QString)), &base, SLOT(GetProductsByCategory(QString)));
    QObject::connect (w.catalog, SIGNAL(GetProductsByCost(int, int)), &base, SLOT(GetProductsByCost(int, int)));
    QObject::connect(&base, SIGNAL(SendProducts(QList<Product*>)), w.catalog, SLOT(CreateCards(QList<Product*>)));
    QObject::connect (w.catalog, SIGNAL(SendProductToOrder(QString)), &base, SLOT(AddProductToOrder(QString)));

    QObject::connect(&base, SIGNAL(Error()), &w, SLOT(ShowError()));


    QObject::connect(&base, SIGNAL(SendProductToBasket(Product*)), w.basket, SLOT(AddProductCard(Product*)));
    QObject::connect (w.basket, SIGNAL(ClearOrder()), &base, SLOT(ClearOrder()));
    QObject::connect (w.basket, SIGNAL(OrderHasBeenPaid(int,double)), &base, SLOT(OrderHasBeenPaid(int, double)));

    QObject::connect(&base, SIGNAL(SendOrderToStatus(Order*)), w.status, SLOT(AddOrder(Order*)));


    w.setMinimumSize(800, 600);
    w.catalog->GetDatabase();

    QPalette p = w.palette();
    QRect rect = QApplication::desktop()->screenGeometry();
    int height = rect.height();
    int width = rect.width();
    QPixmap bg("images/bg.jpg");
    p.setBrush(QPalette::Background, bg.scaled(width, height, Qt::IgnoreAspectRatio, Qt::FastTransformation));
    w.setPalette(p);

    w.setWindowIcon(QIcon("images/ico.png"));
    w.setWindowTitle("Прокат настольныx игр");
    w.showMaximized();    

    return a.exec();
}
