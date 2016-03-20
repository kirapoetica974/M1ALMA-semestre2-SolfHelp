/**
 * \file Fenetre.h
 * \brief Fenetre princiale
 * \author Rachelle Taochy et Nina Exposito
 * \date 20 mars 2016
 *
 * La Fenetre dans laquelle se trouvera toutes les fenetres du widget.
 *
 */


#ifndef FENETRE_H
#define FENETRE_H

#include <QWidget>
#include <QStackedWidget>
#include "accueil.h"
#include "jeulibre.h"
#include "entrainementpage1.h"
#include "entrainementfacile.h"
#include "cours.h"

class Fenetre : public QWidget
{
    Q_OBJECT
public:

    /**
     * @fn Fenetre(QWidget *parent = 0)
     * @brief Constructeur
     * @param parent
     */
    explicit Fenetre(QWidget *parent = 0);
    ~Fenetre();

private:
    QStackedWidget *pages;

    Accueil *accueil;
    JeuLibre *jeuLibre;
    EntrainementPage1 *ent1;
    EntrainementFacile *entFacile;
    Cours *cours;

    QString choixPartition;
};

#endif // FENETRE_H
