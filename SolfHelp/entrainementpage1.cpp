#include "entrainementpage1.h"
#include <QDebug>
#include "entrainementfacile.h"

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

    //liste déroulante correspondant au choix de la partition
    listePartition = new QComboBox(this);
    //listePartition->addItem("Choix de la partition");
    listePartition->addItem("Demo1");
    listePartition->addItem("Demo2");
    listePartition->addItem("Demo3");
    listePartition->setCurrentIndex(0);
    connect(listePartition, SIGNAL(activated(int)),this,SLOT(choixPartition()));



//    //Lecture du fichier
//    fichierTemporaire.open(QIODevice::ReadOnly | QIODevice::Text);
//    QTextStream flux(fichierTemporaire);
//    QString tout = flux.readAll();
//    qDebug() << tout;






    // Boutons correspondants aux modes de jeu
    facile = new QPushButton("Facile", this);
    difficile =new QPushButton("Difficile", this);

    facile->setGeometry(xBouton, yBouton, largeurBouton, hauteurBouton);
    difficile->setGeometry(xBouton, yBouton+hauteurBouton, largeurBouton, hauteurBouton);

    facile->setEnabled(false);
    difficile->setEnabled(false);

    connect(facile, SIGNAL(clicked()), this, SLOT(doFacile()));
    connect(difficile, SIGNAL(clicked()), this, SLOT(doDifficile()));


    // Bouton d'accueil
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



void EntrainementPage1::insertFichier(QString s){
    // Copie de données dans un fichier temporaire
    QFile *fichier = new QFile("temp.txt");
    if(!fichier->open(QIODevice::WriteOnly | QIODevice::Text)){
        qDebug() << "Fichier temporaire non trouvé ou créé";
        return;
    }

    QTextStream flux(fichier);
    flux.setCodec("UTF-8");
    flux << s;
}



void EntrainementPage1::choixPartition(){

    facile->setEnabled(true);
    difficile->setEnabled(true);

    comboText = listePartition->currentText();
    insertFichier(comboText);

    QString fileName = "temp.txt";
    QFile fichier(fileName);
    fichier.open(QIODevice::ReadOnly | QIODevice::Text);
    QTextStream flux(&fichier);
    QString tout = flux.readAll();
    qDebug() <<tout;


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


void EntrainementPage1::paintEvent(QPaintEvent *){
    //listePartition->setCurrentIndex(0);
}
