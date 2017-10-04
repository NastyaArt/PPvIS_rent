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

    butCat = new QPushButton("Категории");
    butCat ->setFixedSize(120,30);

    butInf = new QPushButton("Оплата и доставка");
    butInf ->setFixedSize(120,30);

    butCont = new QPushButton("Контакты");
    butCont ->setFixedSize(120,30);

    butStat = new QPushButton("Статус заказов");
    butStat ->setFixedSize(120,30);

    butBask = new QPushButton("Корзина");
    butBask ->setFixedSize(120,30);

    catalog = new CatalogWidget;

    QHBoxLayout *layBut = new QHBoxLayout;
    layBut->addWidget(butCat);
    layBut->addWidget(butInf);
    layBut->addWidget(butCont);
    layBut->addWidget(butStat);
    layBut->addWidget(butBask);

    QVBoxLayout *layHead = new QVBoxLayout;
    layHead->addWidget(lblName);
    layHead->addLayout(layBut);

    QVBoxLayout *layAll = new QVBoxLayout;
    layAll->addLayout(layHead);
    layAll->addWidget(catalog);

    group->setLayout(layAll);

    setCentralWidget(group);


    connect (butCat, SIGNAL(clicked()), this, SLOT(GetCatalog()));
}

void MainWindow::GetCatalog()
{
    emit GetDatabase();
}

void MainWindow::UpdateCatalog(QList<Product> base)
{
    catalog->CreateCatalog(base);
}

void MainWindow::ShowError()
{
    QMessageBox::warning(this, "Ошибка", "Не удалось загрузить базу данных", QMessageBox::Ok);
}

MainWindow::~MainWindow()
{
    delete ui;
}
