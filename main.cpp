#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    w.showMaximized();
    w.setWindowTitle("Прокат настольный игр");

    return a.exec();
}
