#include "jeulibre.h"
#include <QString>
#include <iostream>
#include <QPixmap>
#include <QFile>
#include <QDateTime>

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

    QPixmap pix(":/img/img/home.png");
    QIcon buttonIcon(pix);
    accueil = new QPushButton("Accueil",this);
    accueil->setIcon(buttonIcon);

    accueil->setGeometry(530,5, 40,40);
    QSize size(30,30);
    accueil->setIconSize(size);
    accueil->setText("");


    connect(accueil, SIGNAL(clicked()), this, SLOT(goAccueil()));
}

void JeuLibre::goAccueil(){
    ecrireLog("Clic sur Accueil");
    pages->setCurrentIndex(0);
}

JeuLibre::~JeuLibre(){

}

void JeuLibre::ecrireLog(QString s){
    QString fileName = "../log.txt";
    QFile file(fileName);
    if (!file.open(QIODevice::Append | QIODevice::Text)){
        qDebug() << "impossible d'ouvir le fichier";
        return;
    }

    QDateTime d = QDateTime::currentDateTime();
    QString st = d.toString("dd-MM-yyyy  hh:mm:ss  ");

    QTextStream flux(&file);
    flux << "\n"<< st << s;

    file.close();
}


