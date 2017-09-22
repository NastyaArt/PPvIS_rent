#include "catalogwidget.h"

CatalogWidget::CatalogWidget(/*QList<Product> database*/) //формировать карточки не в конструкторе, а функцией
{


    cardsBox = new QGroupBox;
    cardsBox->setFixedSize(1100, 700);  //5*(размер одной карточки + немного) - ширина, а по высоте сделать прокрутку
    cardsBox->setStyleSheet("background-color : rgba(127, 255, 212, 0.4);");

    // создание каталога карточек и расположение их в боксе

  /*  QRect rect = QApplication::desktop()->screenGeometry();
    int height = rect.height();
    int width = rect.width();
    setFixedSize(width-50, heidht-100);
*/
    Product prd1("00001", "Настолка", "Категория", 1, 19, 99);
    ProductCard *prd1Card = new ProductCard(prd1);

    QVBoxLayout *layPr = new QVBoxLayout;
    layPr->addWidget(prd1Card);
    layPr->setAlignment(Qt::AlignTop);
    cardsBox->setLayout(layPr);

    setFixedHeight(700);
    listCateg << "Стратегические игры" << "Игры для вечеринок"
            << "Игры для детей" << "Развивающие игры"
            << "Тематические игры" << "Другое";
    rbutCateg = new QList<QRadioButton*>;
    btGrCateg = new QButtonGroup;

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


    QGroupBox *boxCat = new QGroupBox();
    boxCat->setLayout(layCateg);
    boxCat->setStyleSheet("background-color : rgba(127, 255, 212, 0.4);");

  // boxCat->setFixedHeight(500);
    layCateg->setAlignment(Qt::AlignTop);

    QHBoxLayout *layTop = new QHBoxLayout;
    layTop->addWidget(boxCat);
  //  layTop->addLayout(layCateg);
    layTop->addWidget(cardsBox);  //- добавить бокс карточек

    setLayout(layTop);
}

CatalogWidget::CatalogWidget(QList<Product> database)
{

}

