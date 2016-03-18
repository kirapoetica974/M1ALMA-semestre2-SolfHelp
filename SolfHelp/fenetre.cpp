#include "fenetre.h"
#include <QGridLayout>

Fenetre::Fenetre(QWidget *parent): QWidget()
{
    update();
    resize(600,500);
    setFixedSize(600,500);
    QGridLayout *layout = new QGridLayout( this );

    pages = new QStackedWidget();
    layout->addWidget( pages);

    // Dans la table pages :
    //      0 : Accueil
    //      1 : Entrainement Libre
    //      2 : Choix du mode d'entrainement
    //      3 : Entrainement Facile (Jouer)

    pages->addWidget( accueil = new Accueil( pages ) );
    pages->addWidget( jeuLibre = new JeuLibre( pages ) );
    pages->addWidget( ent1 = new EntrainementPage1( pages) );
    pages->addWidget( entFacile = new EntrainementFacile( pages) );
}

Fenetre::~Fenetre()
{

}
