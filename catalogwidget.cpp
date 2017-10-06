#include "catalogwidget.h"

CatalogWidget::CatalogWidget()
{
    cardsBox = new CardsBox;

    setFixedHeight(600);

    rbutCateg = new QList<QRadioButton*>;
    btGrCateg = new QButtonGroup;

    boxCat = new QGroupBox();

    boxCat->setFixedWidth(250);
    boxCat->setStyleSheet("background-color : rgba(127, 255, 212, 0.4);");

    QHBoxLayout *layTop = new QHBoxLayout;
    layTop->addWidget(boxCat);
    layTop->addWidget(cardsBox);
    setLayout(layTop);



    //добавить коннекты для выбора категорий
    connect(btGrCateg, SIGNAL(buttonPressed(int)), this, SLOT(GetCardsByCategory(int)));
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
