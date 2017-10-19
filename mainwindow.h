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

#include "basketwidget.h"
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
    QLabel *mainPage;

  //  QStackedWidget *pages;

    QLabel *lblName;

    CatalogWidget *catalog;
    BasketWidget *basket;

    QPushButton *butCat;
 //   QPushButton *butInf;
  //  QPushButton *butCont;
    QPushButton *butStat;
    QPushButton *butBask;

signals:

    void GetDatabase();

private slots:

    void UpdateCatalog(QList<Product> base);
    void ShowError();
    void GetCatalog();

    void ShowCatalog();
    void ShowStatus();
    void ShowBasket();

};

#endif // MAINWINDOW_H
