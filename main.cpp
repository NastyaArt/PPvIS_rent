#include "mainwindow.h"
#include "databaseproduct.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    DatabaseProduct base;
    MainWindow w;

    QObject::connect(&w, SIGNAL(GetDatabase()), &base, SLOT(GetDatabase()));
    QObject::connect(&base, SIGNAL(SendDatabase(QList<Product>)), &w, SLOT(UpdateCatalog(QList<Product>)));
    QObject::connect(&base, SIGNAL(Error()), &w, SLOT(ShowError()));
    QObject::connect(&w, SIGNAL(SendArticleToGetProduct(QString)), &base, SLOT(GetProductByArticle(QString)));
    QObject::connect(&base, SIGNAL(SendProduct(Product)), &w, SLOT(SendProductToBasket(Product)));


    w.setMinimumSize(800, 600);
    w.GetCatalog();

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
