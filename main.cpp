#include "mainwindow.h"
#include "databaseproduct.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    DatabaseProduct base;

    QObject::connect(&w, SIGNAL(GetDatabase()), &base, SLOT(GetDatabase()));
    QObject::connect(&base, SIGNAL(SendDatabase(QList<Product>)), &w, SLOT(UpdateCatalog(QList<Product>)));
    QObject::connect(&base, SIGNAL(Error()), &w, SLOT(ShowError()));

    w.setMinimumSize(800, 600);

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
