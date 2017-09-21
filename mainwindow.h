#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGroupBox>
#include <QStringList>
#include <QDesktopWidget>
#include "catalogwidget.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

    QGroupBox *group;

    QLabel *lblName;

    CatalogWidget *catalog;

    QPushButton *butCat;
    QPushButton *butInf;
    QPushButton *butCont;
    QPushButton *butStat;
    QPushButton *butBask;

};

#endif // MAINWINDOW_H
