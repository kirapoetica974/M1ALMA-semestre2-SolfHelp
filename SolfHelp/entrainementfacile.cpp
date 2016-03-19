#include "entrainementfacile.h"
#include <QPainter>

#include <QtSvg>
#include <QtXml>
#include <iostream>
#include <QDebug>
#include "placenote.h"
#include <QGraphicsScene>
#include <QGraphicsView>


EntrainementFacile::EntrainementFacile(QStackedWidget *p) : QWidget()
{

    resize(600,500);
    pages = p;
    portee = new Portee(this);

    // Initialisation des tableau de notes
    tabNotes = new QVector<Note*>();
    tabReponse = new QVector<Note*>();

    //La valiable enJeu sera à vrai quand l'utilisateur aura cliqué sur "commencer"
    enJeu = false;



    // Largeur de la fenetre de l'application
    qreal largeur = size().width();
    // hauteur de la fenetre de l'application
    qreal hauteur = size().height();

    qreal largeurDeTouche = (largeur - 60)/14;
    qreal hauteurDeTouche = (hauteur*40)/100;
    qreal xTouche = 20;
    qreal yTouche = hauteur/2;


    // Insertion du piano avec les touches non cliquables
    QString *chemin = new QString();
    piano = new ClavierPiano(xTouche,yTouche,largeurDeTouche,hauteurDeTouche,chemin, this);
    piano->setEnabled(false);
    piano->do1->setEnabled(false);
    piano->do2->setEnabled(false);
    piano->domD->setEnabled(false);
    piano->doMD->setEnabled(false);
    piano->re1->setEnabled(false);
    piano->re2->setEnabled(false);
    piano->remD->setEnabled(false);
    piano->reMD->setEnabled(false);
    piano->mi1->setEnabled(false);
    piano->mi2->setEnabled(false);
    piano->fa1->setEnabled(false);
    piano->fa2->setEnabled(false);
    piano->famD->setEnabled(false);
    piano->faMD->setEnabled(false);
    piano->sol1->setEnabled(false);
    piano->sol2->setEnabled(false);
    piano->solmD->setEnabled(false);
    piano->solMD->setEnabled(false);
    piano->la1->setEnabled(false);
    piano->la2->setEnabled(false);
    piano->lamD->setEnabled(false);
    piano->laMD->setEnabled(false);
    piano->si1->setEnabled(false);
    piano->si2->setEnabled(false);


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


    // Ajout du label ou sera écrit les réponses (il sera invisible jusqu'à la fin)
    labelReponse = new QTextEdit(this);
    labelReponse->setGeometry(10,175,largeur-20,60);
    labelReponse->setVisible(false);
    labelReponse->setEnabled(false);


    //ajout de la clé de sol a la portée
    QSvgWidget *cleSol = new QSvgWidget(":/img/G-clef.svg", this);
    cleSol->setGeometry(70,56,60,120);


    //Ajout du bouton commencer
    go = new QPushButton("Commencer",this);
    go->setGeometry(250, 0, 100, 40);
    connect(go,SIGNAL(pressed()),this,SLOT(commencer()));
}

void EntrainementFacile::commencer(){
    labelReponse->setVisible(false);
    tabNotes = new QVector<Note*>();
    tabReponse = new QVector<Note*>();
    deconnectionDesTouches();

    // Le bouton commencer devient non cliquable
    go->setEnabled(false);

    //le jeu ayant commencé, la variable enJeu est a true
    enJeu = true;
    qDebug() << "Partie commencée !!";

    // On charge le fichier de partition dans le tableau prévu à cet effet
    chargerPartition(nomPartition);


    // Les touches du clavier deviennt donc cliquables
    piano->setEnabled(true);
    piano->do1->setEnabled(true);
    piano->do2->setEnabled(true);
    piano->domD->setEnabled(true);
    piano->doMD->setEnabled(true);
    piano->re1->setEnabled(true);
    piano->re2->setEnabled(true);
    piano->remD->setEnabled(true);
    piano->reMD->setEnabled(true);
    piano->mi1->setEnabled(true);
    piano->mi2->setEnabled(true);
    piano->fa1->setEnabled(true);
    piano->fa2->setEnabled(true);
    piano->famD->setEnabled(true);
    piano->faMD->setEnabled(true);
    piano->sol1->setEnabled(true);
    piano->sol2->setEnabled(true);
    piano->solmD->setEnabled(true);
    piano->solMD->setEnabled(true);
    piano->la1->setEnabled(true);
    piano->la2->setEnabled(true);
    piano->lamD->setEnabled(true);
    piano->laMD->setEnabled(true);
    piano->si1->setEnabled(true);
    piano->si2->setEnabled(true);

    // Connection entre les touches et leur action
    connect(piano->do1,SIGNAL(clicked()),this,SLOT(appuiDo1()));
    connect(piano->do2,SIGNAL(clicked()),this,SLOT(appuiDo2()));
    connect(piano->re1,SIGNAL(clicked()),this,SLOT(appuiRe1()));
    connect(piano->re2,SIGNAL(clicked()),this,SLOT(appuiRe2()));
    connect(piano->mi1,SIGNAL(clicked()),this,SLOT(appuiMi1()));
    connect(piano->mi2,SIGNAL(clicked()),this,SLOT(appuiMi2()));
    connect(piano->fa1,SIGNAL(clicked()),this,SLOT(appuiFa1()));
    connect(piano->fa2,SIGNAL(clicked()),this,SLOT(appuiFa2()));
    connect(piano->sol1,SIGNAL(clicked()),this,SLOT(appuiSol1()));
    connect(piano->sol2,SIGNAL(clicked()),this,SLOT(appuiSol2()));
    connect(piano->la1,SIGNAL(clicked()),this,SLOT(appuiLa1()));
    connect(piano->la2,SIGNAL(clicked()),this,SLOT(appuiLa2()));
    connect(piano->si1,SIGNAL(clicked()),this,SLOT(appuiSi1()));
    connect(piano->si2,SIGNAL(clicked()),this,SLOT(appuiSi2()));
}


void EntrainementFacile::appuiDo1(){
    Note *note = new Note("do","majeur");
    tabReponse->append(note);
    qDebug() << "J'ai tapé sur un do";
    update();

}

void EntrainementFacile::appuiDo2(){
    Note *note = new Note("do","mineur");
    tabReponse->append(note);
    qDebug() << "J'ai tapé sur un do";
    update();
}

void EntrainementFacile::appuiRe1(){
    Note *note = new Note("re","majeur");
    tabReponse->append(note);
    qDebug() << "J'ai tapé sur un re";
    update();
}

void EntrainementFacile::appuiRe2(){
    Note *note = new Note("re","mineur");
    tabReponse->append(note);
    qDebug() << "J'ai tapé sur un re";
}

void EntrainementFacile::appuiMi1(){
    Note *note = new Note("mi","majeur");
    tabReponse->append(note);
    qDebug() << "J'ai tapé sur un mi";
}

void EntrainementFacile::appuiMi2(){
    Note *note = new Note("mi","mineur");
    tabReponse->append(note);
    qDebug() << "J'ai tapé sur un mi";
}

void EntrainementFacile::appuiFa1(){
    Note *note = new Note("fa","majeur");
    tabReponse->append(note);
    qDebug() << "J'ai tapé sur un fa";
}

void EntrainementFacile::appuiFa2(){
    Note *note = new Note("fa","mineur");
    tabReponse->append(note);
    qDebug() << "J'ai tapé sur un fa";
}

void EntrainementFacile::appuiSol1(){
    Note *note = new Note("sol","majeur");
    tabReponse->append(note);
    qDebug() << "J'ai tapé sur un sol";
}

void EntrainementFacile::appuiSol2(){
    Note *note = new Note("sol","mineur");
    tabReponse->append(note);
    qDebug() << "J'ai tapé sur un sol";
}

void EntrainementFacile::appuiLa1(){
    Note *note = new Note("la","majeur");
    tabReponse->append(note);
    qDebug() << "J'ai tapé sur un la";
}

void EntrainementFacile::appuiLa2(){
    Note *note = new Note("la","mineur");
    tabReponse->append(note);
    qDebug() << "J'ai tapé sur un la";
}

void EntrainementFacile::appuiSi1(){
    Note *note = new Note("si","majeur");
    tabReponse->append(note);
    qDebug() << "J'ai tapé sur un si";
}

void EntrainementFacile::appuiSi2(){
    Note *note = new Note("si","mineur");
    tabReponse->append(note);
    qDebug() << "J'ai tapé sur un si";
}

void EntrainementFacile::goAccueil(){
    enJeu = false;
    deconnectionDesTouches();
    labelReponse->setVisible(false);
    update();
    tabReponse = new QVector<Note*>();
    go->setEnabled(true);
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
            //qDebug() << e.attribute("nom");
           // qDebug() << e.attribute("hauteur");
            QString nom = e.attribute("nom");
            QString hauteur = e.attribute("hauteur");
            n = new Note(nom, hauteur);
            tabNotes->append(n);

        }
    }
    qDebug() << "----------- Nombres de notes dans la partition ";
    qDebug() << tabNotes->size();

}



void EntrainementFacile::paintEvent(QPaintEvent* e){
    //labelReponse->setVisible(false);
    update();

    QString fileName = "temp.txt";
    QFile fichier(fileName);
    fichier.open(QIODevice::ReadOnly | QIODevice::Text);
    QTextStream flux(&fichier);
    QString nom = flux.readAll();
    nomPartition = nom;

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



    if(enJeu){
        if(tabReponse->size() != tabNotes->size()){
            int numeroNote = tabReponse->size();
            painter.drawLine(160+(numeroNote*60),180,160+(numeroNote*60),210);
            painter.drawLine(154+(numeroNote*60),190,160+(numeroNote*60),180);
            painter.drawLine(160+(numeroNote*60),180,166+(numeroNote*60),190);

        }

        for (int i = 0; i < tabNotes->size(); ++i) {
            QString nNom = tabNotes->at(i)->nom;
            QString nHauteur = tabNotes->at(i)->hauteur;
            placerNote(painter,largeur,hauteur,xDebutLigne,yDebutLigne,150+(i*60),espaceEntreLigne,nNom,nHauteur);
        }
        update();

           //Dans le cas ou la partie est terminée
        if(tabReponse->size()>=tabNotes->size()){
            enJeu = false;

            piano->setEnabled(false);
            piano->do1->setEnabled(false);
            piano->do2->setEnabled(false);
            piano->domD->setEnabled(false);
            piano->doMD->setEnabled(false);
            piano->re1->setEnabled(false);
            piano->re2->setEnabled(false);
            piano->remD->setEnabled(false);
            piano->reMD->setEnabled(false);
            piano->mi1->setEnabled(false);
            piano->mi2->setEnabled(false);
            piano->fa1->setEnabled(false);
            piano->fa2->setEnabled(false);
            piano->famD->setEnabled(false);
            piano->faMD->setEnabled(false);
            piano->sol1->setEnabled(false);
            piano->sol2->setEnabled(false);
            piano->solmD->setEnabled(false);
            piano->solMD->setEnabled(false);
            piano->la1->setEnabled(false);
            piano->la2->setEnabled(false);
            piano->lamD->setEnabled(false);
            piano->laMD->setEnabled(false);
            piano->si1->setEnabled(false);
            piano->si2->setEnabled(false);

            QString userRep = "";
            QString goodRep = "";
            int nbBonneReponses = 0;

            // Vérification des bonnes et mauvaises notes
            for (int j = 0; j < tabNotes->size(); ++j) {
                userRep = userRep + tabReponse->at(j)->nom + "(" + tabReponse->at(j)->hauteur.at(0) + ") ";
                goodRep = goodRep + tabNotes->at(j)->nom + "(" + tabNotes->at(j)->hauteur.at(0) + ") ";
                if((tabReponse->at(j)->nom == tabNotes->at(j)->nom) && (tabReponse->at(j)->hauteur == tabNotes->at(j)->hauteur)){
                    nbBonneReponses++;
                }
            }


            QString lab = "<center>La partie est terminée. Vous avez "+QString::number(nbBonneReponses)+" bonnes réponses sur "+QString::number(tabNotes->size())+"<br/>Réponses attendues : "+goodRep+"<br/>Vos réponses : "+userRep+"</p></center>";
            labelReponse->setText(lab);
            labelReponse->setReadOnly(true);
            labelReponse->setVisible(true);

            go->setText("Rejouer");
            go->setEnabled(true);



        }
        else{
            labelReponse->setVisible(false);
            update();
        }


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

void EntrainementFacile::deconnectionDesTouches(){
    disconnect(piano->do1,SIGNAL(clicked()),this,SLOT(appuiDo1()));
    disconnect(piano->do2,SIGNAL(clicked()),this,SLOT(appuiDo2()));
    disconnect(piano->re1,SIGNAL(clicked()),this,SLOT(appuiRe1()));
    disconnect(piano->re2,SIGNAL(clicked()),this,SLOT(appuiRe2()));
    disconnect(piano->mi1,SIGNAL(clicked()),this,SLOT(appuiMi1()));
    disconnect(piano->mi2,SIGNAL(clicked()),this,SLOT(appuiMi2()));
    disconnect(piano->fa1,SIGNAL(clicked()),this,SLOT(appuiFa1()));
    disconnect(piano->fa2,SIGNAL(clicked()),this,SLOT(appuiFa2()));
    disconnect(piano->sol1,SIGNAL(clicked()),this,SLOT(appuiSol1()));
    disconnect(piano->sol2,SIGNAL(clicked()),this,SLOT(appuiSol2()));
    disconnect(piano->la1,SIGNAL(clicked()),this,SLOT(appuiLa1()));
    disconnect(piano->la2,SIGNAL(clicked()),this,SLOT(appuiLa2()));
    disconnect(piano->si1,SIGNAL(clicked()),this,SLOT(appuiSi1()));
    disconnect(piano->si2,SIGNAL(clicked()),this,SLOT(appuiSi2()));
}


