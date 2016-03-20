/**
 * \file EntrainementFacile.h
 * \brief Fenetre de l'entrainement
 * \author Rachelle Taochy et Nina Exposito
 * \date 20 mars 2016
 *
 * C'est la fenetre qui permettra de jouer en mode facile mais aussi en mode difficile
 *
 */

#ifndef ENTRAINEMENTFACILE_H
#define ENTRAINEMENTFACILE_H

#include <QWidget>
#include <QStackedWidget>
#include <clavierpiano.h>
#include <QVector>
#include <note.h>
#include <QGraphicsScene>
#include <QLabel>
#include <QTextEdit>
#include <QTimer>

class EntrainementFacile : public QWidget
{
    Q_OBJECT
public:

    /**
     * \fn EntrainementFacile(QStackedWidget *pages)
     * \brief Constructeur
     *
     * \param pages     Pointeur sur la structure de donnée contenant l'ensemble des fenetre, ne peut etre NULL
     **/
    explicit EntrainementFacile(QStackedWidget *p);


    /**
     * \fn void paintEvent(QPaintEvent* e)
     * \brief Fonction qui dessine en continue les éléments de l'interface
     *
     * \param e Evenement
     **/
    void paintEvent(QPaintEvent* e);


    /**
     * \fn void chargerPartition(QString fichier)
     * \brief Fonction qui transforme le fichier d'entrée en tableau de notes
     *
     * \param fichier Chemin du fichier xml dans lequel se trouve la partition (doit obligatoirement contenir l'extension .xml)
     **/
    void chargerPartition(QString fichier);


    /**
     * \fn void placerNote(QPainter &painter, qreal largeur, qreal hauteur, qreal xDebutLigne, qreal yDebutLigne, qreal xDebutNote, qreal espaceEntreLigne, QString note, QString hauteurN)
     * \brief Fonction qui dessine une note
     *
     * \param &painter      le QPainter sur lequel sera dessiné la note
     * \param largeur       largeur de la fenetre
     * \param hauteur       hauteur de la fenetre
     * \param xDebutLigne   Coordonnée x de la premiere ligne de la portee
     * \param yDebutLigne   Coordonnée y de la premiere ligne de la portee
     * \param xDebutNote    Coordonnée x de la ou va etre dessiné la note
     * \param espaceEntreLigne      Distance entre deux lignes de la portee
     * \param note          Nom de la note à dessiner
     * \param hauteurN      Hauteur de la note à dessiner
     *
     * \return void
     **/
    void placerNote(QPainter &painter, qreal largeur, qreal hauteur, qreal xDebutLigne, qreal yDebutLigne, qreal xDebutNote, qreal espaceEntreLigne, QString note, QString hauteurN);


    /**
     * \fn void deconnectionDesTouches()
     * \brief Fonction qui déconnecte les touches du clavier afin qu'il n'y ai plus d'action au clique de la souris
     *
     * \return void
     **/
    void deconnectionDesTouches();


    /**
     * \fn void partieTerminee()
     * \brief Fonction qui fait la mise à jour de la fenetre lorsque l'entrainement se termine
     *
     * \return void
     **/
    void partieTerminee();


    /**
     * \fn void ecrireLog(QString s)
     * \brief Fonction qui ouvre le fichier de log afin d'y ajouter la chaine de caractère passée en paramètre
     *
     * \param s     une chaine de type QString qui sera écrite dans le fichier log, ne peut etre NULL
     * \return void
     */
    void ecrireLog(QString s);


    /**
     * \fn effacerNomTouche()
     * \brief Fonction qui efface le nom des touches du clavier
     *
     * \return void
     */
    void effacerNomTouche();
    
signals:
    
public slots:
    /**
     * \fn void goAccueil()
     * \brief Fonction qui permet d'aller sur la fenetre d'accueil
     *
     * \param void
     **/
    void goAccueil();


    /**
     * \fn void appuiDo1()
     * \brief Fonction qui déclenche le traitement de la touche do mineur
     *
     * \param void
     **/
    void appuiDo1();


    /**
     * \fn void appuiDo1()
     * \brief Fonction qui déclenche le traitement de la touche do mineur
     *
     * \param void
     **/
    void appuiDo2();


    /**
     * \fn void appuiRe1()
     * \brief Fonction qui déclenche le traitement de la touche re mineur
     *
     * \param void
     **/
    void appuiRe1();


    /**
     * \fn void appuiRe2()
     * \brief Fonction qui déclenche le traitement de la touche re majeur
     *
     * \param void
     **/
    void appuiRe2();


    /**
     * \fn void appuiMi1()
     * \brief Fonction qui déclenche le traitement de la touche mi mineur
     *
     * \param void
     **/
    void appuiMi1();


    /**
     * \fn void appuiMi2()
     * \brief Fonction qui déclenche le traitement de la touche mi majeur
     *
     * \param void
     **/
    void appuiMi2();


    /**
     * \fn void appuiFa1()
     * \brief Fonction qui déclenche le traitement de la touche fa mineur
     *
     * \param void
     **/
    void appuiFa1();


    /**
     * \fn void appuiFa2()
     * \brief Fonction qui déclenche le traitement de la touche fa majeur
     *
     * \param void
     **/
    void appuiFa2();


    /**
     * \fn void appuiSol1()
     * \brief Fonction qui déclenche le traitement de la touche sol mineur
     *
     * \param void
     **/
    void appuiSol1();


    /**
     * \fn void appuiSol2()
     * \brief Fonction qui déclenche le traitement de la touche sol majeur
     *
     * \param void
     **/
    void appuiSol2();


    /**
     * \fn void appuiLa1()
     * \brief Fonction qui déclenche le traitement de la touche la mineur
     *
     * \param void
     **/
    void appuiLa1();


    /**
     * \fn void appuiLa2()
     * \brief Fonction qui déclenche le traitement de la touche la majeur
     *
     * \param void
     **/
    void appuiLa2();


    /**
     * \fn void appuiSi1()
     * \brief Fonction qui déclenche le traitement de la touche si mineur
     *
     * \param void
     **/
    void appuiSi1();


    /**
     * \fn void appuiSi2()
     * \brief Fonction qui déclenche le traitement de la touche si majeur
     *
     * \param void
     **/
    void appuiSi2();


    /**
     * \fn void commencer()
     * \brief Fonction qui met la partie en place
     *
     * \param void
     **/
    void commencer();


    /**
     * \fn void precedent()
     * \brief Fonction qui permet de retourner sur la page précédente
     *
     * \param void
     **/
    void precedent();



    /**
     * \fn void compter()
     * \brief Fonction qui permet le compte à rebours
     *
     * \param void
     **/
    void compter();


private:
    QStackedWidget *pages;

    ClavierPiano *piano;

    QTextEdit *labelReponse;
    QPushButton *accueil;
    QPushButton *go;
    QPushButton *retour;
    QPushButton *imgTimer;

    QVector<Note*> *tabNotes; //!< tableau des bonnes réponses
    QVector<Note*> *tabReponse; //!< tableau des réponses de l'utilisateur
    bool enJeu;

    QString nomPartition;
    QString difficulte;

    QTimer *timer; //!< Timer qui permet de compter en seconde
    QLabel *labelTimer; //!< Zone de texte qui contiendra le compte à rebours
    int tempsRestant; //!< Temps restant en mode difficile
    int tempsReel;
    int nbBonneReponses; //!< Nombre de bonnes réponses de l'utilisateur


};

#endif // ENTRAINEMENTFACILE_H
