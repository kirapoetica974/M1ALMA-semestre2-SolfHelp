/**
 * \file EntrainementPage1.h
 * \brief Premiere fenetre qui apparait quand on appui sur entrainement
 * \author Rachelle Taochy et Nina Exposito
 * \date 20 mars 2016
 *
 * Fenetre qui permet de choisir la partition et le mode de jeu
 *
 */

#ifndef ENTRAINEMENTPAGE1_H
#define ENTRAINEMENTPAGE1_H

#include <QWidget>
#include <QStackedWidget>
#include <QPushButton>
#include <QComboBox>
#include <QFile>
#include <QLabel>

class EntrainementPage1 : public QWidget
{
    Q_OBJECT
public:
    /**
     * @brief Constructeur
     * @param p
     */
    explicit EntrainementPage1(QStackedWidget *p);

    /**
     * @fn void paintEvent(QPaintEvent *e)
     * @brief Fonction qui dessine les éléments graphiques
     * @param e un évènement
     */
    void paintEvent(QPaintEvent *e);
    
signals:
    
public slots:

    /**
     * @fn void doFacile()
     * @brief Fonction qui permet d'aller à la fenetre d'entrainement en mode facile
     */
    void doFacile();

    /**
     * @fn void doDifficile()
     * @brief Fonction qui permet d'aller à la fenetre d'entrainement en mode difficile
     */
    void doDifficile();

    /**
     * @fn void goAccueil()
     * @brief Fonction qui permet de retourner à l'accueil
     */
    void goAccueil();

    /**
     * @fn void choixPartition()
     * @brief fonction qui permet l'entrainement possible après sélection de la partition
     */
    void choixPartition();


    /**
     * @fn void insertFichier(QString s)
     * @brief Permet d'ajouter dans un fichier une chaine de caractère
     * @param chaine de caractère à insérer
     */
    void insertFichier(QString s);


    /**
     * \fn void ecrireLog(QString s)
     * \brief Fonction qui ouvre le fichier de log afin d'y ajouter la chaine de caractère passée en paramètre
     *
     * \param s     une chaine de type QString qui sera écrite dans le fichier log, ne peut etre NULL
     * \return void
     */
    void ecrireLog(QString s);



private:
    QStackedWidget *pages;
    QPushButton *facile;
    QPushButton *difficile;

    QPushButton *accueil;

    QComboBox *listePartition;

    QString comboText;

    QLabel *labelChoix;
    QLabel *labelDifficulte;
};

#endif // ENTRAINEMENTPAGE1_H
