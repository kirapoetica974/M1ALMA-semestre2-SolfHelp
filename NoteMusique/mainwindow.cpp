#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QRectF>
#include <QPainter>
#include <QPoint>
#include <QSize>
#include <QDesktopWidget>
#include <QDebug>
#include <QStackedWidget>



MainWindow::MainWindow()
{

    // Redimension de la fenetre d'origine
    resize(700,500);


    // Largeur de la fenetre de l'application
    int largeur = size().width();

    // hauteur de la fenetre de l'application
    int hauteur = size().height();


    // Création du bouton retour
    retour = new QPushButton("Retour",this);
    retour->setGeometry((largeur*10)/100,hauteur-((hauteur*20)/100),(largeur*20)/100,(hauteur*10)/100);//positionH, positionV, tailleH, tailleV
    //retour->deleteLater();
    retour->show();

    /*stack = new QStackedWidget(this);
    fen1 = new FenetreSecondaire1();

    stack->addWidget(fen1);

    this->setCentralWidget(stack);
    statck->setCurrentIndex(0); // on affiche la première fenêtre à l'ouverture du programme

    connect(fen1, SIGNAL(askDisplayFen(int)), this, SLOT(slotDisplayFen(int)));*/


    // Insertion du clavier sur la fenetre
    do1 = new QPushButton("do",this);
    re1 = new QPushButton("re",this);
    mi1 = new QPushButton("mi",this);
    fa1 = new QPushButton("fa",this);
    sol1 = new QPushButton("sol",this);
    la1 = new QPushButton("la",this);
    si1 = new QPushButton("si",this);
    do2 = new QPushButton("do",this);
    re2 = new QPushButton("re",this);
    mi2 = new QPushButton("mi",this);
    fa2 = new QPushButton("fa",this);
    sol2 = new QPushButton("sol",this);
    la2 = new QPushButton("la",this);
    si2 = new QPushButton("si",this);


    // Modification de la forme et du placement des boutons.
    int largeurDeTouche = (largeur*5)/100;
    int hauteurDeTouche = (hauteur*30)/100;
    int xTouche = (largeur*10)/100;
    int yTouche = hauteur/3;

    do1->setGeometry(xTouche, yTouche, largeurDeTouche, hauteurDeTouche);
    re1->setGeometry(xTouche+largeurDeTouche, yTouche, largeurDeTouche, hauteurDeTouche);
    mi1->setGeometry(xTouche+(2*largeurDeTouche), yTouche, largeurDeTouche, hauteurDeTouche);
    fa1->setGeometry(xTouche+(3*largeurDeTouche), yTouche, largeurDeTouche, hauteurDeTouche);
    sol1->setGeometry(xTouche+(4*largeurDeTouche), yTouche, largeurDeTouche, hauteurDeTouche);
    la1->setGeometry(xTouche+(5*largeurDeTouche), yTouche, largeurDeTouche, hauteurDeTouche);
    si1->setGeometry(xTouche+(6*largeurDeTouche), yTouche, largeurDeTouche, hauteurDeTouche);
    do2->setGeometry(xTouche+(7*largeurDeTouche), yTouche, largeurDeTouche, hauteurDeTouche);
    re2->setGeometry(xTouche+(8*largeurDeTouche), yTouche, largeurDeTouche, hauteurDeTouche);
    mi2->setGeometry(xTouche+(9*largeurDeTouche), yTouche, largeurDeTouche, hauteurDeTouche);
    fa2->setGeometry(xTouche+(10*largeurDeTouche), yTouche, largeurDeTouche, hauteurDeTouche);
    sol2->setGeometry(xTouche+(11*largeurDeTouche), yTouche, largeurDeTouche, hauteurDeTouche);
    la2->setGeometry(xTouche+(12*largeurDeTouche), yTouche, largeurDeTouche, hauteurDeTouche);
    si2->setGeometry(xTouche+(13*largeurDeTouche), yTouche, largeurDeTouche, hauteurDeTouche);
}

MainWindow::~MainWindow()
{
}

void MainWindow::slotDisplayFen(int fenIndex)
{
    if ((fenIndex < 0) || (fenIndex > 3)) {return;}
    stack->setCurrentIndex(fenIndex);
}

void MainWindow::paintEvent(QPaintEvent *e){
    // rectangle.x() ==> permet de donner la position x du rectangle
    // rectangle.y() ==> permet de donne la position y du rectangle
    // rectangle.height() ==> permet de donner la hauteur du rectangle
    // rectangle.width() ==> permet de donner la largeur du rectangle

    // Largeur de la fenetre de l'application
    int largeur = size().width();

    // hauteur de la fenetre de l'application
    int hauteur = size().height();


   /* retour = new QPushButton("Retour",this);
    retour->setGeometry((largeur*10)/100,hauteur-((hauteur*20)/100),(largeur*20)/100,(hauteur*10)/100);//positionH, positionV, tailleH, tailleV
    retour->deleteLater();
    retour->show();*/


    QWidget *window = new QWidget;


    // Dessin de la portée

    //Coordonnées du début de la ligne
    qreal xDebutLigne = (largeur*10)/100;
    qreal yDebutLigne = (largeur*10)/100;

    // longueur de la ligne en fonction de l'ecran
    qreal longueurLigne = largeur-((largeur*10)/100);
    qreal espaceEntreLigne = (largeur*3)/100;
    QPainter painter(this);
    for (int i = 1; i < 7; i++) {
        painter.drawLine(xDebutLigne,yDebutLigne+(espaceEntreLigne*i),longueurLigne,yDebutLigne+(espaceEntreLigne*i));
    }


    // Dessin de la note
    QRectF rectangle(QPoint(largeur/2, yDebutLigne+1*espaceEntreLigne), QSize(espaceEntreLigne+(espaceEntreLigne/4), espaceEntreLigne));
    //QPainter painter(this);
    painter.drawEllipse(rectangle);
    painter.setBackgroundMode(Qt::OpaqueMode);
    qreal x = rectangle.x()+rectangle.width();
    qreal y = rectangle.y()+(rectangle.width()/2);
    painter.drawLine(x, y, x, y-(espaceEntreLigne*3));

}
