#include "jeulibre.h"
#include <QString>
#include <iostream>
#include <QPixmap>

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

    QPixmap pix(":/img/img/b_accueil.gif");
    QIcon buttonIcon(pix);
    accueil = new QPushButton("Accueil",this);
    accueil->setIcon(buttonIcon);

    accueil->setGeometry(520,5, 50,50);
    accueil->setIconSize(accueil->size());
    accueil->setText("");
    accueil->setStyleSheet("border:none");
    accueil->setFocusPolicy(Qt::NoFocus);


    connect(accueil, SIGNAL(clicked()), this, SLOT(goAccueil()));
}

void JeuLibre::goAccueil(){
    pages->setCurrentIndex(0);
}

JeuLibre::~JeuLibre(){

}


