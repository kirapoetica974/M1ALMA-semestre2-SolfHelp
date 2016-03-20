/**
 * \file Accueil.h
 * \brief Fenetre d'accueil
 * \author Rachelle Taochy et Nina Exposito
 * \date 20 mars 2016
 *
 * C'est la première fenetre sur laquelle arrivera l'utilisateur quand il lance le programme
 *
 */

#ifndef ACCUEIL_H
#define ACCUEIL_H
#include <QWidget>
#include <QPushButton>
#include <QStackedWidget>
#include <QTextStream>
#include <QFile>

class Accueil : public QWidget
{
    Q_OBJECT
public:
    /**
     * \fn void Accueil(QStackedWidget *p)
     * \brief Constructeur
     *
     * \param p     Pointeur sur la structure de donnée contenant l'ensemble des fenetre, ne peut etre NULL
     */
    Accueil(QStackedWidget *p);


    /**
     * \fn void ecrireLog(QString s)
     * \brief Fonction qui ouvre le fichier de log afin d'y ajouter la chaine de caractère passée en paramètre
     *
     * \param s     une chaine de type QString qui sera écrite dans le fichier log, ne peut etre NULL
     * \return void
     */
    void ecrireLog(QString s);

private:

    QStackedWidget *pages; //!< Structure contenant l'ensemble des fenetre

    QPushButton *boutonCours; //!< Bouton qui permet d'aller sur le cours

    QPushButton *boutonEntrainement; //!< Bouton qui permet d'aller sur les entrainements

    QPushButton *boutonLibre; //!< Bouton qui permet de jouer librement

    QFile *logFile; //!< Fichier dans lequel se trouvera les logs

public slots:
    /**
     * \fn void doCours()
     * \brief Fonction qui permet d'accéder à la fenetre de cours
     *
     * \return void
     */
    void doCours();


    /**
     * \fn void doEntrainement()
     * \brief Fonction qui permet d'accéder à la fen^etre d'entrainement
     *
     * \return void
     */
    void doEntrainement();


    /**
     * \fn void doLibre()
     * \brief Fonction qui permet d'accéder à la fenetre de jeu libre
     *
     * \return void
     */
    void doLibre();
};

#endif // ACCUEIL_H
