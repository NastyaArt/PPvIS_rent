#include "catalogwidget.h"

CatalogWidget::CatalogWidget()
{

 /*   cardsBox = new QGroupBox;
    cardsBox->setFixedSize(1100, 700);  //5*(размер одной карточки + немного) - ширина, а по высоте сделать прокрутку
    cardsBox->setStyleSheet("background-color : rgba(127, 255, 212, 0.4);");
*/
    //вынести CardsBox еще одним классом, подавать в него список карточек, учесть расстановку карточек с изменением размеров окна
    //и вынести в него формирование карточек


  /*  QRect rect = QApplication::desktop()->screenGeometry();
    int height = rect.height();
    int width = rect.width();
    setFixedSize(width-50, heidht-100);
*/

    cardsBox = new CardsBox;

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

// создание каталога карточек и расположение их в боксе
void CatalogWidget::CreateCatalog(QList<Product> base)
{
/*    //цикл с созданием добавлением карточек на поле
    QVBoxLayout *layPr = new QVBoxLayout;
   // layPr->addWidget(prd1Card);
    layPr->setAlignment(Qt::AlignTop);
   // cardsBox->setLayout(layPr);

    for (int i=0; i<base.length(); i++)
    {
        ProductCard *prdCard = new ProductCard(base.at(i));
        layPr->addWidget(prdCard);
    }
*/
    cardsBox->setLayout(layPr);

}

