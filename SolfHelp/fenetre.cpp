#include "fenetre.h"
#include <QGridLayout>
#include <QDateTime>
#include <QDate>

Fenetre::Fenetre(QWidget *parent): QWidget()
{
    QString fileName = "../log.txt";
    QFile fichier(fileName);
    if (!fichier.open(QIODevice::Append | QIODevice::Text)){
        qDebug() << "impossible d'ouvir le fichier";
        return;
    }



    QTextStream flux(&fichier);

    QDateTime d = QDateTime::currentDateTime();
    QString s = d.toString("dd-MM-yyyy  hh:mm:ss  ");
    qDebug() << s;
    flux << "\n"<< s << " Ouverture de l'application.";
    fichier.close();


    if (!fichier.open(QIODevice::ReadOnly | QIODevice::Text)){
        qDebug() << "impossible d'ouvir le fichier";
        return;
    }
    QTextStream t(&fichier);
    QString a = t.readAll();
    qDebug() << a;



    resize(600,500);
    setFixedSize(600,500);
    QGridLayout *layout = new QGridLayout( this );

    pages = new QStackedWidget();
    layout->addWidget( pages);

    // Dans la table pages :
    //      0 : Accueil
    //      1 : Entrainement Libre
    //      2 : Choix du mode d'entrainement
    //      3 : Entrainement (Jouer)

    pages->addWidget( accueil = new Accueil( pages ) );
    pages->addWidget( jeuLibre = new JeuLibre( pages ) );
    pages->addWidget( ent1 = new EntrainementPage1( pages ) );
    pages->addWidget( entFacile = new EntrainementFacile( pages ) );



}

Fenetre::~Fenetre()
{

}
