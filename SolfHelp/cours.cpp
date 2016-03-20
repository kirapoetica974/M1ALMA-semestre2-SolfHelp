#include "cours.h"
#include <QLabel>

Cours::Cours(QStackedWidget *pages) :QWidget()
{
    resize(600,500);
    this->pages = pages;

    QLabel *imageLabel = new QLabel;
    QImage image(":/img/img/cours.png");
    imageLabel->setPixmap(QPixmap::fromImage(image).scaled(QSize(550,600),Qt::IgnoreAspectRatio,Qt::FastTransformation));


    area = new QScrollArea(this);
    area->setGeometry(0,50,575,420);
    area->setBackgroundRole(QPalette::Dark);
    area->setWidget(imageLabel);


    QPixmap pix(":/img/img/home.png");
    QIcon buttonIcon(pix);
    accueil = new QPushButton("Accueil",this);
    accueil->setIcon(buttonIcon);

    accueil->setGeometry(530,5, 40,40);
    QSize size(30,30);
    accueil->setIconSize(size);
    accueil->setText("");
    accueil->setToolTip("Accueil");



    connect(accueil, SIGNAL(clicked()), this, SLOT(goAccueil()));
}

void Cours::goAccueil(){
    //ecrireLog("clic sur Accueil");
    pages->setCurrentIndex(0);
}

