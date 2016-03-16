#include "accueil.h"
#include <QDebug>

Accueil::Accueil(QStackedWidget *p) : QWidget()
{
    resize(600,500);

    //INITIALISATION DE CONSTANTES POUR LA DIMENSION DES BOUTONS
    // Largeur de la fenetre de l'application
    qreal largeur = size().width();

    // hauteur de la fenetre de l'application
    qreal hauteur = size().height();

    qreal xBouton = (largeur*20)/100;
    qreal yBouton = (largeur*30)/100;
    qreal largeurBouton = largeur - 2*(xBouton);
    qreal hauteurBouton = (hauteur*10)/100;


    // On récupère le tableau de pages
    pages = p;


    // Chaque bouton correspondra aux différents modes d'utilisation
    boutonCours = new QPushButton("Cours",this);
    boutonEntrainement = new QPushButton("Entrainement", this);
    boutonLibre = new QPushButton("Entrainement libre", this);

    boutonCours->setGeometry(xBouton, yBouton, largeurBouton, hauteurBouton);
    boutonEntrainement->setGeometry(xBouton ,(yBouton+hauteurBouton), largeurBouton, hauteurBouton);
    boutonLibre->setGeometry(xBouton, yBouton+2*hauteurBouton, largeurBouton, hauteurBouton);

    connect(boutonLibre, SIGNAL(clicked()), this, SLOT(doLibre()));
    connect(boutonEntrainement, SIGNAL(clicked()), this, SLOT(doEntrainement()));
    connect(boutonCours, SIGNAL(clicked()), this, SLOT(doCours()));
}

void Accueil::doCours(){
    qDebug() << "J'ai cliqué sur cours";
}

void Accueil::doEntrainement(){
    pages->setCurrentIndex(2);
    qDebug() << "J'ai cliqué sur Entrainement";
}

void Accueil::doLibre(){
    pages->setCurrentIndex(1);
    qDebug() << "j'ai cliclé sur Entrainement libre";
}
