#include "catalogwidget.h"

CatalogWidget::CatalogWidget(/*QList<Product> database*/)
{


    // создание каталога карточек и расположение их в боксе
    lblCatalog = new QLabel();
    lblCatalog->setFixedSize(1100, 700);  //5*(размер одной карточки + немного) - ширина, а по высоте сделать прокрутку
    lblCatalog->setStyleSheet("background-color : rgba(127, 255, 212, 0.4);");

  /*  QRect rect = QApplication::desktop()->screenGeometry();
    int height = rect.height();
    int width = rect.width();
    setFixedSize(width-50, heidht-100);
*/


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
    layTop->addWidget(lblCatalog);  //- добавить бокс карточек

    setLayout(layTop);
}

CatalogWidget::CatalogWidget(QList<Product> database)
{

}

