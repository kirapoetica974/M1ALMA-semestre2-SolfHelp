#include "accueil.h"
#include <QDebug>
#include <QLabel>
#include <QFile>
#include <QDateTime>

Accueil::Accueil(QStackedWidget *p) : QWidget()
{

    resize(600,500);

    //INITIALISATION DE CONSTANTES POUR LA DIMENSION DES BOUTONS
    // Largeur de la fenetre de l'application
    qreal largeur = size().width();

    // hauteur de la fenetre de l'application
    qreal hauteur = size().height();

    qreal xBouton = 100;
    qreal yBouton = (largeur*30)/100;
    qreal largeurBouton = largeur - 220;
    qreal hauteurBouton = (hauteur*10)/100;



    // On récupère le tableau de pages
    pages = p;

    QPixmap pix(":/img/img/logo.png");
    QLabel *label = new QLabel(this);
    QPixmap pix2=pix.scaled(QSize(276,150),Qt::IgnoreAspectRatio);
    label->setPixmap(pix2);
    label->setGeometry(150,0,276,150);
    //label->setStyleSheet("background:transparent;");



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
    ecrireLog("Cours");
    pages->setCurrentIndex(4);
}

void Accueil::doEntrainement(){
    ecrireLog("Entrainement");
    pages->setCurrentIndex(2);
    qDebug() << "J'ai cliqué sur Entrainement";

}

void Accueil::doLibre(){
    ecrireLog("Entrainement Libre");
    pages->setCurrentIndex(1);
    qDebug() << "j'ai cliclé sur Entrainement libre";
}

void Accueil::ecrireLog(QString s){
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
