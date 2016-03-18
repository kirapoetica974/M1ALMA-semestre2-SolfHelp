#include "entrainementfacile.h"
#include <QPainter>

#include <QtSvg>
#include <QtXml>
#include <iostream>


EntrainementFacile::EntrainementFacile(QStackedWidget *p) : QWidget()
{
    resize(600,500);
    pages = p;
    portee = new Portee(this);

    tabNotes = new QVector<Note*>();
    tabReponse = new QVector<Note*>();



    // Largeur de la fenetre de l'application
    qreal largeur = size().width();
    // hauteur de la fenetre de l'application
    qreal hauteur = size().height();

    qreal largeurDeTouche = (largeur - 60)/14;
    qreal hauteurDeTouche = (hauteur*40)/100;
    qreal xTouche = 20;
    qreal yTouche = hauteur/2;

    QString *chemin = new QString();


    // Insertion du piano
    piano = new ClavierPiano(xTouche,yTouche,largeurDeTouche,hauteurDeTouche,chemin, this);

    // Ajout du bouton d'accueil
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


    //ajout de la clé de sol a la portée
    QSvgWidget *cleSol = new QSvgWidget(":/img/G-clef.svg", this);
    cleSol->setGeometry(70,56,60,120);

}



void EntrainementFacile::goAccueil(){
    pages->setCurrentIndex(0);
    tabNotes = new QVector<Note*>();
}


void EntrainementFacile::chargerPartition(QString fichier){
    QDomDocument document;
    QString fich = "../SolfHelp/partitions/"+ fichier + ".xml";

    // Open a file for reading
    QFile file(fich);
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qDebug() << "Failed to open the file for reading.";
    }
    else
    {
        // loading
        if(!document.setContent(&file))
        {
            qDebug() << "Failed to load the file for reading.";
        }
        file.close();
    }

    QDomNode noeud = document.firstChild();
    QDomElement element = noeud.toElement();

    Note *n;

    QDomNodeList tab = element.childNodes();
    for(int i = 0; i < tab.count(); i++)
    {
        QDomNode elm = tab.at(i);
        if(elm.isElement())
        {
            QDomElement e = elm.toElement();
            qDebug() << e.attribute("nom");
            qDebug() << e.attribute("hauteur");
            QString nom = e.attribute("nom");
            QString hauteur = e.attribute("hauteur");
            n = new Note(nom, hauteur);
            tabNotes->append(n);

        }
    }
    //repaint();

}



void EntrainementFacile::paintEvent(QPaintEvent* e){
    QString fileName = "temp.txt";
    QFile fichier(fileName);
    fichier.open(QIODevice::ReadOnly | QIODevice::Text);
    QTextStream flux(&fichier);
    QString nom = flux.readAll();
    nomPartition = nom;

    chargerPartition(nomPartition);

    // Largeur de la fenetre de l'application
    qreal largeur = size().width();

    // hauteur de la fenetre de l'application
    qreal hauteur = size().height();


    // Dessin de la portée

    //Coordonnées du début de la ligne
    qreal xDebutLigne = (largeur*10)/100;
    qreal yDebutLigne = (largeur*10)/100;

    // longueur de la ligne en fonction de l'ecran
    qreal longueurLigne = largeur-((largeur*10)/100);
    qreal espaceEntreLigne = (largeur*3)/100;
    QPainter painter(this);
    QPen pen;
    pen.setWidth(2);
    painter.setPen(pen);
    painter.setBrush(Qt::BrushStyle(Qt::SolidPattern));
    for (int i = 1; i < 6; i++) {
        painter.drawLine(xDebutLigne,yDebutLigne+(espaceEntreLigne*i),longueurLigne,yDebutLigne+(espaceEntreLigne*i));
    }

//    qreal xDebutNote = 300;
//    placerNote(painter,largeur,hauteur,xDebutLigne,yDebutLigne,100,espaceEntreLigne,"do","mineur");
//    placerNote(painter,largeur,hauteur,xDebutLigne,yDebutLigne,150,espaceEntreLigne,"re","mineur");
//    placerNote(painter,largeur,hauteur,xDebutLigne,yDebutLigne,200,espaceEntreLigne,"mi","mineur");
//    placerNote(painter,largeur,hauteur,xDebutLigne,yDebutLigne,250,espaceEntreLigne,"fa","mineur");
//    placerNote(painter,largeur,hauteur,xDebutLigne,yDebutLigne,300,espaceEntreLigne,"sol","mineur");
//    placerNote(painter,largeur,hauteur,xDebutLigne,yDebutLigne,350,espaceEntreLigne,"la","mineur");
//    placerNote(painter,largeur,hauteur,xDebutLigne,yDebutLigne,400,espaceEntreLigne,"si","mineur");

    for (int i = 0; i < tabNotes->size(); ++i) {
        QString nNom = tabNotes->at(i)->nom;
        QString nHauteur = tabNotes->at(i)->hauteur;
        placerNote(painter,largeur,hauteur,xDebutLigne,yDebutLigne,150+(i*60),espaceEntreLigne,nNom,nHauteur);

    }


}

void EntrainementFacile::placerNote(QPainter &painter,qreal largeur, qreal hauteur, qreal xDebutLigne,qreal yDebutLigne, qreal xDebutNote, qreal espaceEntreLigne,QString note,QString hauteurN){

    QRectF rectangle;

    qreal x = xDebutNote;
    qreal y = 0;
    qreal larg = espaceEntreLigne+(espaceEntreLigne/4);
    qreal haut = espaceEntreLigne;
    if ((note == "do") && (hauteurN == "majeur")) {
        y = yDebutLigne+(5.5*espaceEntreLigne);
        qreal xl = xDebutNote - rectangle.width();
        qreal xl2 = xDebutNote + (2*rectangle.width());
        painter.drawLine(xl,yDebutLigne+(espaceEntreLigne*6),xl2,yDebutLigne+(espaceEntreLigne*6));

    }

    else if ((note == "re") && (hauteurN == "majeur")){
        y = yDebutLigne+(5*espaceEntreLigne);
    }

    else if ((note == "mi") && (hauteurN == "majeur")){
        y = yDebutLigne+(4.5*espaceEntreLigne);
    }

    else if ((note == "fa") && (hauteurN == "majeur")){
        y = yDebutLigne+(4*espaceEntreLigne);
    }

    else if ((note == "sol") && (hauteurN == "majeur")){
        y = yDebutLigne+(3.5*espaceEntreLigne);
    }
    else if ((note == "la") && (hauteurN == "majeur")){
        y = yDebutLigne+(3*espaceEntreLigne);
    }

    else if ((note == "si") && (hauteurN == "majeur")){
        y = yDebutLigne+(2.5*espaceEntreLigne);
    }

    else if ((note == "do") && (hauteurN == "mineur")) {
        y = yDebutLigne+(2*espaceEntreLigne);
    }

    else if ((note == "re") && (hauteurN == "mineur")){
        y = yDebutLigne+(1.5*espaceEntreLigne);
    }

    else if ((note == "mi") && (hauteurN == "mineur")){
        y = yDebutLigne+(1*espaceEntreLigne);
    }

    else if ((note == "fa") && (hauteurN == "mineur")){
        y = yDebutLigne+(0.5*espaceEntreLigne);
    }

    else if ((note == "sol") && (hauteurN == "mineur")){
        y = yDebutLigne+(0*espaceEntreLigne);
    }
    else if ((note == "la") && (hauteurN == "mineur")){
        y = yDebutLigne+((-0.5)*espaceEntreLigne);
    }

    else if ((note == "si") && (hauteurN == "mineur")){
        y = yDebutLigne+((-1)*espaceEntreLigne);
    }

    rectangle = QRectF(QPoint(x, y), QSize(larg, haut));
    painter.drawEllipse(rectangle);
    qreal xl = rectangle.x()+rectangle.width();
    qreal yl = rectangle.y()+(rectangle.width()/2);
    painter.drawLine(xl, yl, xl, yl-(espaceEntreLigne*3));
}

void EntrainementFacile::refresh(){
    QString fileName = "temp.txt";
    QFile fichier(fileName);
    fichier.open(QIODevice::ReadOnly | QIODevice::Text);
    QTextStream flux(&fichier);
    QString nom = flux.readAll();
    nomPartition = nom;


    chargerPartition(nomPartition);
}

