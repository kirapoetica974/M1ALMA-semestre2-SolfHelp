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



    // Largeur de la fenetre de l'application
    qreal largeur = size().width();

    // hauteur de la fenetre de l'application
    qreal hauteur = size().height();

    qreal largeurDeTouche = (largeur - 60)/14;
    qreal hauteurDeTouche = (hauteur*40)/100;
    qreal xTouche = 20;
    qreal yTouche = hauteur/2;
    QString *chemin = new QString();
    chemin->append("/home/rachelle/Documents/M1ALMA/IHM/M1ALMA-semestre2-SolfHelp/NoteMusique/SonNote/");


    piano = new ClavierPiano(xTouche,yTouche,largeurDeTouche,hauteurDeTouche,chemin, this);

    accueil = new QPushButton("Accueil",this);
    accueil->setGeometry(520,5, 50,50);

    connect(accueil, SIGNAL(clicked()), this, SLOT(goAccueil()));
    QSvgWidget *cleSol = new QSvgWidget(":/img/G-clef.svg", this);
    cleSol->setGeometry(70,56,60,120);




}



void EntrainementFacile::goAccueil(){
    pages->setCurrentIndex(0);
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
}

void EntrainementFacile::paintEvent(QPaintEvent* e){
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

    qreal xDebutNote = 300;
    placerNote(painter,largeur,hauteur,xDebutLigne,yDebutLigne,xDebutNote,espaceEntreLigne,"do");

}

void EntrainementFacile::placerNote(QPainter &painter,qreal largeur, qreal hauteur, qreal xDebutLigne,qreal yDebutLigne, qreal xDebutNote, qreal espaceEntreLigne,QString note){
    QRectF rectangle;
    if (note == "do") {
        rectangle = QRectF(QPoint(xDebutNote, yDebutLigne+5.5*espaceEntreLigne), QSize(espaceEntreLigne+(espaceEntreLigne/4), espaceEntreLigne));
        qreal xl = xDebutNote - rectangle.width();
        qreal xl2 = xDebutNote + (2*rectangle.width());
        painter.drawLine(xl,yDebutLigne+(espaceEntreLigne*6),xl2,yDebutLigne+(espaceEntreLigne*6));

    } else {
    }
    painter.drawEllipse(rectangle);
    qreal x = rectangle.x()+rectangle.width();
    qreal y = rectangle.y()+(rectangle.width()/2);
    painter.drawLine(x, y, x, y-(espaceEntreLigne*3));
}

