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

    qreal largeurDeTouche = (largeur - (2*(largeur/10)))/14;
    qreal hauteurDeTouche = (hauteur*30)/100;
    qreal xTouche = largeur/10;
    qreal yTouche = hauteur/2;
    QString *chemin = new QString();
    chemin->append("/home/rachelle/Documents/M1ALMA/IHM/M1ALMA-semestre2-SolfHelp/NoteMusique/SonNote/");


    // On insère le clavier
    clavier = new ClavierPiano(xTouche,yTouche,largeurDeTouche,hauteurDeTouche,chemin, this);

    accueil = new QPushButton("Accueil",this);
    accueil->setGeometry(largeur-((largeur*10)/100)-(largeur/10),(hauteur*0.05), (largeur*10)/100,(hauteur*10)/100);

    connect(accueil, SIGNAL(clicked()), this, SLOT(goAccueil()));
}

void JeuLibre::goAccueil(){
    pages->setCurrentIndex(0);
}

JeuLibre::~JeuLibre(){

}


