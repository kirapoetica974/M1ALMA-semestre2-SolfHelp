#ifndef FENETRE_H
#define FENETRE_H

#include <QWidget>
#include <QStackedWidget>
#include "accueil.h"
#include "jeulibre.h"
#include "entrainementpage1.h"
#include "entrainementfacile.h"

class Fenetre : public QWidget
{
    Q_OBJECT
public:
    explicit Fenetre(QWidget *parent = 0);
    ~Fenetre();

private:
    QStackedWidget *pages;

    Accueil *accueil;
    JeuLibre *jeuLibre;
    EntrainementPage1 *ent1;
    EntrainementFacile *entFacile;
};

#endif // FENETRE_H
