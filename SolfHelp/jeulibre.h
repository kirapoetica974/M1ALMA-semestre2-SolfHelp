/**
 * \file JeuLibre.h
 * \brief Fenetre de jeu libre
 * \author Rachelle Taochy et Nina Exposito
 * \date 20 mars 2016
 *
 * C'est une fenetre qui permet de jouer librement au piano, sans partition
 *
 */

#ifndef JEULIBRE_H
#define JEULIBRE_H
#include <QWidget>
#include <QStackedWidget>
#include <QPushButton>
#include <QMediaPlayer>
#include "clavierpiano.h"

class JeuLibre : public QWidget
{
    Q_OBJECT
public:

    /**
     * @brief Constructeur
     * @param p la structeur contenant les différentes fenetres
     */
    explicit JeuLibre(QStackedWidget *p);

    ~JeuLibre();



private:
    QStackedWidget *pages;
    ClavierPiano *clavier;
    QPushButton *accueil;
    void ecrireLog(QString s);

public slots:

    /**
     * @fn void goAction()
     * @brief Fonction qui permet de retourner à l'accueil
     */
    void goAccueil();

};

#endif // JEULIBRE_H
