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
    QLabel *mainPage;

  //  QStackedWidget *pages;

    QLabel *lblName;

    CatalogWidget *catalog;

    QPushButton *butCat;
    QPushButton *butInf;
    QPushButton *butCont;
    QPushButton *butStat;
    QPushButton *butBask;

signals:

    void GetDatabase();

private slots:

    void UpdateCatalog(QList<Product> base);
    void ShowError();
    void GetCatalog();

};

#endif // MAINWINDOW_H
