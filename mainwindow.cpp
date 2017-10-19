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
    butCat->setCheckable(true);

    butStat = new QPushButton("Статус заказов");
    butStat ->setFixedSize(120,30);
    butStat->setCheckable(true);

    butBask = new QPushButton("Корзина");
    butBask ->setFixedSize(120,30);
    butBask->setCheckable(true);

    butns = new QButtonGroup;
    butns->addButton(butCat);
    butns->addButton(butStat);
    butns->addButton(butBask);

    catalog = new CatalogWidget;    
    status = new StatusWidget;
    basket = new BasketWidget;

    pages = new QStackedWidget;
    pages->addWidget(catalog);
    pages->addWidget(status);
    pages->addWidget(basket);

    QHBoxLayout *layBut = new QHBoxLayout;
    layBut->addWidget(butCat);
    layBut->addWidget(butStat);
    layBut->addWidget(butBask);

    QVBoxLayout *layHead = new QVBoxLayout;
    layHead->addWidget(lblName);
    layHead->addLayout(layBut);


    QVBoxLayout *layAll = new QVBoxLayout;
    layAll->addLayout(layHead);
    layAll->addWidget(pages);

    group->setLayout(layAll);

    setCentralWidget(group);    

    connect (butCat, SIGNAL(toggled(bool)), this, SLOT(ShowCatalog(bool)));
    connect (butStat, SIGNAL(toggled(bool)), this, SLOT(ShowStatus(bool)));
    connect (butBask, SIGNAL(toggled(bool)), this, SLOT(ShowBasket(bool)));
    connect (catalog, SIGNAL(SendArticleToGetProduct(QString)), this, SLOT(GetProductByArticle(QString)));
  //  connect (basket, SIGNAL(GetProduct(QString)), basket, SLOT(AddProduct(QString)));

    butCat->toggle();
}

void MainWindow::GetCatalog()
{
    emit GetDatabase();
}

void MainWindow::GetProductByArticle(QString article)
{
    emit SendArticleToGetProduct(article);

}

void MainWindow::SendProduct(Product prd)
{
    basket->AddProductCard(prd);
}

void MainWindow::UpdateCatalog(QList<Product> base)
{
    catalog->CreateCatalog(base);
}

void MainWindow::ShowError()
{
    QMessageBox::warning(this, "Ошибка", "Не удалось загрузить базу данных", QMessageBox::Ok);
}

void MainWindow::ShowCatalog(bool on)
{
    if (on)
        pages->setCurrentWidget(catalog);
}

void MainWindow::ShowStatus(bool on)
{
    if (on)
        pages->setCurrentWidget(status);
}

void MainWindow::ShowBasket(bool on)
{
    if (on)
        pages->setCurrentWidget(basket);
}

MainWindow::~MainWindow()
{
    delete ui;
}
