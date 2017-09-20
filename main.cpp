#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;


    QPalette p = w.palette();
    QRect rect = QApplication::desktop()->screenGeometry();
    int height = rect.height();
    int width = rect.width();
    QPixmap bg("images/bg.jpg");
   // bg.scaled(32, 32, Qt::IgnoreAspectRatio, Qt::FastTransformation);
    p.setBrush(QPalette::Background, bg.scaled(width, height, Qt::IgnoreAspectRatio, Qt::FastTransformation));
    w.setPalette(p);
  //  w.setFixedWidth(width);
   // w.setFixedHeight(height);

    w.setWindowIcon(QIcon("images/ico.png"));
    w.showMaximized();
    w.setWindowTitle("Прокат настольныx игр");

    return a.exec();
}
