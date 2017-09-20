#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QList<QToolBar *> toolbars = this->findChildren<QToolBar *>();
    for (int i = 0; i < toolbars.length(); i++)
        toolbars.at(i)->hide();



    group = new QGroupBox();

    lblName = new QLabel();
    lblName->setPixmap(QPixmap("images/head.png"));
    lblName->setAlignment(Qt::AlignCenter);

    butCat = new QPushButton();
    butCat ->setFixedSize(120,30);
    butCat ->setText("Категории");

    butInf = new QPushButton();
    butInf ->setFixedSize(120,30);
    butInf ->setText("Оплата и доставка");

    butCont = new QPushButton();
    butCont ->setFixedSize(120,30);
    butCont ->setText("Контакты");

    butStat = new QPushButton();
    butStat ->setFixedSize(120,30);
    butStat ->setText("Статус заказов");

    butBask = new QPushButton();
    butBask ->setFixedSize(120,30);
    butBask ->setText("Корзина");

    lblCatalog = new QLabel();
    lblCatalog->setFixedSize(700, 700);

    listCat << "Стратегические игры" << "Игры для вечеринок" << "Игры для детей" << "Развивающие игры" << "Тематические игры" << "Другое";
    rbutCat = new QList<QRadioButton*>;
    btGrCat = new QButtonGroup;

    for (int i = 0; i < listCat.length(); i++) {
        QRadioButton* rbut = new QRadioButton(listCat.at(i));
        rbutCat->append(rbut);
        btGrCat->addButton(rbutCat->at(i));
    }


    QHBoxLayout *layBut = new QHBoxLayout;
    layBut->addWidget(butCat);
    layBut->addWidget(butInf);
    layBut->addWidget(butCont);
    layBut->addWidget(butStat);
    layBut->addWidget(butBask);


    QVBoxLayout *layHead = new QVBoxLayout;
    layHead->addWidget(lblName);
    layHead->addLayout(layBut);

    QVBoxLayout *layCat = new QVBoxLayout;
    for (int i = 0; i < rbutCat->length(); i++) {
        layCat->addWidget(rbutCat->at(i));
    }

    QHBoxLayout *layTop = new QHBoxLayout;
    layTop->addLayout(layCat);
    layTop->addWidget(lblCatalog);

    QVBoxLayout *layAll = new QVBoxLayout;
    layAll->addLayout(layHead);
    layAll->addLayout(layTop);

    group->setLayout(layAll);
//    setStyleSheet("background-image: url(images/bg.jpg) none;");

    setCentralWidget(group);
}

MainWindow::~MainWindow()
{
    delete ui;
}
