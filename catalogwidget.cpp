#include "catalogwidget.h"

CatalogWidget::CatalogWidget()
{
    setFixedHeight(600);

    boxSearch = new QGroupBox;

    cardsBox = new CardsBox;

    boxCat = new QGroupBox("Категория");
    layCateg = new QVBoxLayout;
    boxCat->setLayout(layCateg);
    layCateg->setAlignment(Qt::AlignTop);

    rbutCateg = new QList<QRadioButton*>;
    btGrCateg = new QButtonGroup;

    boxCost =  new QGroupBox("Поиск по стоимости");
    lblCost =  new QLabel("Стоимость (руб. в сутки):");
    ldlCostFrom =  new QLabel(" От ");
    lineCostFrom = new QLineEdit;
    lblCostTo =  new QLabel(" До ");
    lineCostTo = new QLineEdit;
    butSearchByCost =  new QPushButton("Найти");

    boxCost->setStyleSheet("QPushButton {background-color : #ADD8E6} QLineEdit {background-color: #F0FFFF}");

    QHBoxLayout *layCostInput = new QHBoxLayout;
    layCostInput->addWidget(ldlCostFrom);
    layCostInput->addWidget(lineCostFrom);
    layCostInput->addWidget(lblCostTo);
    layCostInput->addWidget(lineCostTo);

    QVBoxLayout *layCostSrch = new QVBoxLayout;
    layCostSrch->addWidget(lblCost);
    layCostSrch->addLayout(layCostInput);
    layCostSrch->addWidget(butSearchByCost);

    boxCost->setLayout(layCostSrch);

    QVBoxLayout *laySrch = new QVBoxLayout;
    laySrch->addWidget(boxCat);
    laySrch->addWidget(boxCost);
    laySrch->setAlignment(Qt::AlignTop);

    boxSearch->setLayout(laySrch);
    boxSearch->setFixedWidth(250);
    boxSearch->setStyleSheet("background-color : rgba(127, 255, 212, 0.4);");

    QHBoxLayout *layAll = new QHBoxLayout;
    layAll->addWidget(boxSearch);
    layAll->addWidget(cardsBox);
    setLayout(layAll);

    connect(btGrCateg, SIGNAL(buttonPressed(int)), this, SLOT(GetCardsByCategory(int)));
    connect(butSearchByCost, SIGNAL(clicked(bool)), this, SLOT(GetCardsByCost()));
    connect(cardsBox, SIGNAL(SendArticleToGetProduct(QString)), this, SLOT(GetProductByArticle(QString)));
}

void CatalogWidget::CreateCatalog(QList<Product> base)
{
    database=base;
    cardsBox->CreateCards(base);

    GetCategories(base);

    while (QLayoutItem* item = layCateg->takeAt(0)) {
            delete item->widget();
            delete item;
        }

    rbutCateg->clear();

    for (int butId = 0; butId < btGrCateg->buttons().length(); butId++) {
        btGrCateg->removeButton(btGrCateg->buttons().at(butId));
    }


    for (int categId = 0; categId < listCateg.length(); categId++) {
        QRadioButton* rbut = new QRadioButton(listCateg.at(categId));
        rbut->setStyleSheet("background-color : rgb(176, 224, 230); font-size: 11pt;");
        rbutCateg->append(rbut);
        btGrCateg->addButton(rbutCateg->at(categId));
    }

    for (int butId = 0; butId < rbutCateg->length(); butId++) {
        layCateg->addWidget(rbutCateg->at(butId));
    }


  /*  while (QLayoutItem* item = boxCat->layout()->takeAt(0)) {
        delete item->widget();
        delete item;
    }
    boxCat->layout()->addWidget();
   */

    btGrCateg->button(-2)->setChecked(true);
}

void CatalogWidget::GetCategories(QList<Product> base)
{
    listCateg.clear();
    listCateg << "Все категории";
    for (int prdId = 0; prdId< base.length(); prdId++){
        if (listCateg.contains(base.at(prdId).GetCategory())==false)
            listCateg << base.at(prdId).GetCategory();
    }

}

void CatalogWidget::GetCardsByCategory(int id)
{

    cardsBox->CreateCardsByCategory(database, btGrCateg->button(id)->text());

}

void CatalogWidget::GetCardsByCost()
{
    bool ok1 = true, ok2 = true;
    int from, to;
    from = lineCostFrom->text().toInt(&ok1, 10);
    to = lineCostTo->text().toInt(&ok2, 10);
    if (ok1==true && ok2==true && from<=to && from>=0 && to>0)
        cardsBox->CreateCardsByCost(database, from, to);
    else
        QMessageBox::warning(this, "Ошибка", "Введены некорректные данные!", QMessageBox::Ok);
}

void CatalogWidget::GetProductByArticle(QString article)
{
    emit SendArticleToGetProduct(article);

}

