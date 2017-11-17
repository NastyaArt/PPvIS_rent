#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QPushButton>
#include <QButtonGroup>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGroupBox>
#include <QStringList>
#include <QDesktopWidget>
#include <QStackedWidget>

#include "basketwidget.h"
#include "statuswidget.h"
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

    CatalogWidget *catalog;
    StatusWidget *status;
    BasketWidget *basket;

private:
    Ui::MainWindow *ui;    

    QStackedWidget *pages;

    QLabel *lblName;
    QGroupBox *group;

    QPushButton *butCat;
    QPushButton *butStat;
    QPushButton *butBask;

    QButtonGroup *butns;

signals:

public slots:

    void ShowError();

    void ShowCatalog(bool on);
    void ShowStatus(bool on);
    void ShowBasket(bool on);

};

#endif // MAINWINDOW_H
