#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QPushButton>
#include <QRadioButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGroupBox>
#include <QStringList>


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

    QLabel *lblCatalog;

    QStringList listCat;
    QButtonGroup *btGrCat;

    QPushButton *butCat;
    QPushButton *butInf;
    QPushButton *butCont;
    QPushButton *butStat;
    QPushButton *butBask;

    QList<QRadioButton*> *rbutCat;
};

#endif // MAINWINDOW_H
