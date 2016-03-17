#include "entrainementpage1.h"
#include <QDebug>

EntrainementPage1::EntrainementPage1(QStackedWidget *p) :QWidget()
{
    resize(600,500);
    pages = p;

    //INITIALISATION DE CONSTANTES POUR LA DIMENSION DES BOUTONS
    // Largeur de la fenetre de l'application
    qreal largeur = size().width();

    // hauteur de la fenetre de l'application
    qreal hauteur = size().height();

    qreal xBouton = (largeur*20)/100;
    qreal yBouton = (largeur*30)/100;
    qreal largeurBouton = largeur - 2*(xBouton);
    qreal hauteurBouton = (hauteur*10)/100;


    facile = new QPushButton("Facile", this);
    difficile =new QPushButton("Difficile", this);

    facile->setGeometry(xBouton, yBouton, largeurBouton, hauteurBouton);
    difficile->setGeometry(xBouton, yBouton+hauteurBouton, largeurBouton, hauteurBouton);

    connect(facile, SIGNAL(clicked()), this, SLOT(doFacile()));
    connect(difficile, SIGNAL(clicked()), this, SLOT(doDifficile()));

    accueil = new QPushButton("Accueil",this);
    accueil->setGeometry(520,5, 50,50);

    connect(accueil, SIGNAL(clicked()), this, SLOT(goAccueil()));
}

void EntrainementPage1::doFacile(){
    pages->setCurrentIndex(3);
    qDebug() << "Je veux jouer en mode Facile";
}

void EntrainementPage1::doDifficile(){
    qDebug() << "Je veux jouer en mode Difficile";
}

void EntrainementPage1::goAccueil(){
    pages->setCurrentIndex(0);
}
