#include "entrainementpage1.h"
#include <QDebug>
#include "entrainementfacile.h"
#include <QFile>
#include <QDateTime>
#include <QPixmap>

EntrainementPage1::EntrainementPage1(QStackedWidget *p) :QWidget()
{
    this->resize(600,500);
    pages = p;


    QPixmap pic(":/img/img/logo.png");
    QLabel *label = new QLabel(this);
    QPixmap pix2=pic.scaled(QSize(276,150),Qt::IgnoreAspectRatio);
    label->setPixmap(pix2);
    label->setGeometry(150,0,276,150);

    //INITIALISATION DE CONSTANTES POUR LA DIMENSION DES BOUTONS
    // Largeur de la fenetre de l'application
    qreal largeur = size().width();

    // hauteur de la fenetre de l'application
    qreal hauteur = size().height();

    qreal xBouton = 100;
    qreal yBouton = (largeur*30)/100;
    qreal largeurBouton = largeur - 220;
    qreal hauteurBouton = (hauteur*10)/100;


    labelChoix = new QLabel("Choix de la partition : ",this);
    labelChoix->setGeometry(xBouton+120, yBouton-40, largeurBouton, hauteurBouton);

    //liste déroulante correspondant au choix de la partition
    listePartition = new QComboBox(this);
    //listePartition->addItem("Choix de la partition");
    listePartition->addItem("Demo1");
    listePartition->addItem("Demo2");
    listePartition->addItem("Demo3");
    listePartition->addItem("Demo4");
    listePartition->addItem("Demo5");
    listePartition->addItem("Demo6");
    listePartition->addItem("Demo7");
    listePartition->addItem("Demo8");
    listePartition->addItem("Demo9");
    listePartition->addItem("Demo10");

    listePartition->setCurrentIndex(0);

    listePartition->setGeometry(xBouton, yBouton, largeurBouton, hauteurBouton);
    connect(listePartition, SIGNAL(activated(int)),this,SLOT(choixPartition()));



    labelDifficulte = new QLabel("Choix de la difficulté :", this);
    labelDifficulte->setGeometry(xBouton+120, (yBouton+(2.5*hauteurBouton))-40, largeurBouton, hauteurBouton);

    // Boutons correspondants aux modes de jeu
    facile = new QPushButton("Facile", this);
    difficile =new QPushButton("Difficile", this);

    facile->setGeometry(xBouton, yBouton+(2.5*hauteurBouton), largeurBouton, hauteurBouton);
    difficile->setGeometry(xBouton, yBouton+(3.5*hauteurBouton), largeurBouton, hauteurBouton);

    facile->setEnabled(false);
    difficile->setEnabled(false);

    connect(facile, SIGNAL(clicked()), this, SLOT(doFacile()));
    connect(difficile, SIGNAL(clicked()), this, SLOT(doDifficile()));


    // Bouton d'accueil
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


// fonction qui insère dans un fihcier texte temporaire le choix de la partition
void EntrainementPage1::choixPartition(){

    facile->setEnabled(true);
    difficile->setEnabled(true);
}

void EntrainementPage1::doFacile(){
    comboText = listePartition->currentText();
    QString chaine = comboText + "\nfacile";
    insertFichier(chaine);

    QString fileName = "temp.txt";
    QFile fichier(fileName);
    fichier.open(QIODevice::ReadOnly | QIODevice::Text);
    QTextStream flux(&fichier);
    QString tout = flux.readAll();
    qDebug() <<tout;

    pages->setCurrentIndex(3);
    ecrireLog(comboText + " : Entrainement en mode facile");
    qDebug() << "Je veux jouer en mode Facile";



}

void EntrainementPage1::doDifficile(){
    comboText = listePartition->currentText();
    QString chaine = comboText + "\ndifficile";
    insertFichier(chaine);

    QString fileName = "temp.txt";
    QFile fichier(fileName);
    fichier.open(QIODevice::ReadOnly | QIODevice::Text);
    QTextStream flux(&fichier);
    QString tout = flux.readAll();
    qDebug() <<tout;

    pages->setCurrentIndex(3);
    ecrireLog(comboText + " : Entrainement en mode Difficile");
    qDebug() << "Je veux jouer en mode Difficile";
}

void EntrainementPage1::goAccueil(){
    ecrireLog("clic sur Accueil");
    pages->setCurrentIndex(0);
}


void EntrainementPage1::paintEvent(QPaintEvent *){
    //listePartition->setCurrentIndex(0);
}

void EntrainementPage1::ecrireLog(QString s){
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

}
