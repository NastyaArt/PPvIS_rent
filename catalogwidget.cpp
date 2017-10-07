#include "catalogwidget.h"

CatalogWidget::CatalogWidget()
{
    setFixedHeight(600);

    boxSearch = new QGroupBox;

    cardsBox = new CardsBox;

    boxCat = new QGroupBox("Категория");

    rbutCateg = new QList<QRadioButton*>;
    btGrCateg = new QButtonGroup;

    boxCost =  new QGroupBox("Поиск по стоимости");
    lblCost =  new QLabel("Стоимость в сутки:");
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
}

void CatalogWidget::CreateCatalog(QList<Product> base)
{
    database=base;
    cardsBox->CreateCards(base);

    GetCategories(base);

    rbutCateg->clear();

    for (int i = 0; i < btGrCateg->buttons().length(); i++) {
        btGrCateg->removeButton(btGrCateg->buttons().at(i));
    }


    for (int i = 0; i < listCateg.length(); i++) {
        QRadioButton* rbut = new QRadioButton(listCateg.at(i));
        rbut->setStyleSheet("background-color : rgb(176, 224, 230); font-size: 11pt;");
        rbutCateg->append(rbut);
        btGrCateg->addButton(rbutCateg->at(i));
    }

    QVBoxLayout *layCateg = new QVBoxLayout;
    for (int i = 0; i < rbutCateg->length(); i++) {
        layCateg->addWidget(rbutCateg->at(i));
    }
    layCateg->setAlignment(Qt::AlignTop);
    boxCat->setLayout(layCateg);

    btGrCateg->button(-2)->setChecked(true);
}

void CatalogWidget::GetCategories(QList<Product> base)
{
    listCateg.clear();
    listCateg << "Все категории";
    for (int i = 0; i< base.length(); i++){
        if (listCateg.contains(base.at(i).GetCategory())==false)
            listCateg << base.at(i).GetCategory();
    }

}

void CatalogWidget::GetCardsByCategory(int id)
{

    cardsBox->CreateCardsByCategory(database, btGrCateg->button(id)->text());

}
