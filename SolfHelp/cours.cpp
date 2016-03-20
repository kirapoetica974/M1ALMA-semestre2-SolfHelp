#include "cours.h"
#include <QLabel>

Cours::Cours(QStackedWidget *pages) :QWidget()
{
    resize(600,500);
    this->pages = pages;

    QLabel *imageLabel = new QLabel;
    QImage image(":/img/img/cours.png");
    //QSize size(500,900);
    //image.scaled(size,Qt::IgnoreAspectRatio,Qt::FastTransformation);
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

    // Ajout du bouton retour
    QPixmap pix2(":/img/img/arrows.png");
    QIcon buttonIcon2(pix2);
    retour = new QPushButton("Retour", this);
    retour->setIcon(buttonIcon2);
    retour->setGeometry(10,5,40,40);
    retour->setIconSize(size);
    retour->setText("");
    //retour->setStyleSheet("border:none");
    //retour->setFocusPolicy(Qt::NoFocus);
    connect(retour,SIGNAL(clicked()),this,SLOT(precedent()));


    connect(accueil, SIGNAL(clicked()), this, SLOT(goAccueil()));
}

void Cours::goAccueil(){
    //ecrireLog("clic sur Accueil");
    pages->setCurrentIndex(0);
}

void Cours::precedent(){
    pages->setCurrentIndex( 0);
}
