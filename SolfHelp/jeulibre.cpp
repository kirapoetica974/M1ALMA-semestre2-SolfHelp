#include "jeulibre.h"
#include <QString>
#include <iostream>

JeuLibre::JeuLibre(QStackedWidget *p) : QWidget()
{
    qDebug() << "Je suis arrivé sur cette page !!";

    resize(600,500);
   // On récupère le tableau de pages
    pages = p;

    // Largeur de la fenetre de l'application
    qreal largeur = size().width();

    // hauteur de la fenetre de l'application
    qreal hauteur = size().height();

    qreal largeurDeTouche = (largeur - 60)/14;
    qreal hauteurDeTouche = (hauteur*40)/100;
    qreal xTouche = 20;
    qreal yTouche = hauteur/3;
    QString *chemin = new QString();
    chemin->append("/home/rachelle/Documents/M1ALMA/IHM/M1ALMA-semestre2-SolfHelp/NoteMusique/SonNote/");


    // On insère le clavier
    clavier = new ClavierPiano(xTouche,yTouche,largeurDeTouche,hauteurDeTouche,chemin, this);

    accueil = new QPushButton("Accueil",this);
    accueil->setGeometry(520,5, 50,50);

    connect(accueil, SIGNAL(clicked()), this, SLOT(goAccueil()));
}

void JeuLibre::goAccueil(){
    pages->setCurrentIndex(0);
}

JeuLibre::~JeuLibre(){

}


