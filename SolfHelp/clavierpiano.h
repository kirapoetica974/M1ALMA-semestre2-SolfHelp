/**
 * \file ClavierPiano.h
 * \brief Classe qui dessine le piano
 * \author Rachelle Taochy et Nina Exposito
 * \date 20 mars 2016
 *
 * Cette classe dessine un clavier sur une fenetre
 *
 */



#ifndef CLAVIERPIANO_H
#define CLAVIERPIANO_H
#include <QString>
#include <QPushButton>
#include <QMediaPlayer>
#include <QStackedWidget>
#include <iostream>
#include <QWidget>

class ClavierPiano : public QWidget
{
    Q_OBJECT
public:
    /**
     * \fn ClavierPiano(qreal xTouche, qreal yTouche, qreal largeurTouche, qreal hauteurTouche, QWidget *widget)
     * \brief Constructeur
     *
     * \param xTouche     Coordonnée x de la premiere touche du clavier, ne peut etre NULL
     * \param yTouche     Coordonnée y de la premiere touche du clavier, ne peut etre NULL
     * \param largeurTouche     Largeur d'une touche, ne peut etre NULL
     * \param hauteurTouche     Hauteur d'une touche, ne peut etre NULL
     * \param widget     Pointeur sur le widget ou le clavier sera dessiné, ne peut etre NULL
     */
    explicit ClavierPiano(qreal xTouche, qreal yTouche, qreal largeurTouche, qreal hauteurTouche, QWidget *widget);

    /**
     * \fn ~ClavierPiano();
     * \brief Destructeur
     *
     **/
    ~ClavierPiano();

    QPushButton* do1; //!< Bouton correspondant à la touche do mineur
    QPushButton* re1; //!< Bouton correspondant à la touche re mineur
    QPushButton* mi1; //!< Bouton correspondant à la touche mi mineur
    QPushButton* fa1; //!< Bouton correspondant à la touche fa mineur
    QPushButton* sol1; //!< Bouton correspondant à la touche sol mineur
    QPushButton* la1; //!< Bouton correspondant à la touche la mineur
    QPushButton* si1; //!< Bouton correspondant à la touche si mineur
    QPushButton* do2; //!< Bouton correspondant à la touche do majeur
    QPushButton* re2; //!< Bouton correspondant à la touche re majeur
    QPushButton* mi2; //!< Bouton correspondant à la touche mi majeur
    QPushButton* fa2; //!< Bouton correspondant à la touche fa majeur
    QPushButton* sol2; //!< Bouton correspondant à la touche sol majeur
    QPushButton* la2; //!< Bouton correspondant à la touche la majeur
    QPushButton* si2; //!< Bouton correspondant à la touche si majeur

    QPushButton *domD; //!< Bouton correspondant à la touche do mineur diese
    QPushButton *doMD; //!< Bouton correspondant à la touche do majeur diese
    QPushButton *remD; //!< Bouton correspondant à la touche re mineur diese
    QPushButton *reMD; //!< Bouton correspondant à la touche re majeur diese
    QPushButton *famD; //!< Bouton correspondant à la touche fa mineur diese
    QPushButton *faMD; //!< Bouton correspondant à la touche fa majeur diese
    QPushButton *solmD; //!< Bouton correspondant à la touche sol mineur diese
    QPushButton *solMD; //!< Bouton correspondant à la touche sol majeur diese
    QPushButton *lamD; //!< Bouton correspondant à la touche la mineur diese
    QPushButton *laMD; //!< Bouton correspondant à la touche la majeur diese


    QMediaPlayer* player; //!< Player qui permet de jouer le son des notes

    QWidget *w; //!< fenetre dans laquelle sera placee le piano


public slots:
    /**
     * \fn void on_pushButtonDom_clicked()
     * \brief Fonction qui déclenche le son joué par la touche Do mineur
     *
     * \return void
     */
    void on_pushButtonDom_clicked();


    /**
     * \fn void on_pushButtonDoM_clicked()
     * \brief Fonction qui déclenche le son joué par la touche Do majeur
     *
     * \return void
     */
    void on_pushButtonDoM_clicked();



    /**
     * \fn void on_pushButtonRem_clicked()
     * \brief Fonction qui déclenche le son joué par la touche Ré mineur
     *
     * \return void
     */
    void on_pushButtonRem_clicked();


    /**
     * \fn void on_pushButtonReM_clicked()
     * \brief Fonction qui déclenche le son joué par la touche Ré majeur
     *
     * \return void
     */
    void on_pushButtonReM_clicked();


    /**
     * \fn void on_pushButtonMim_clicked()
     * \brief Fonction qui déclenche le son joué par la touche mi mineur
     *
     * \return void
     */
    void on_pushButtonMim_clicked();


    /**
     * \fn void on_pushButtonMiM_clicked()
     * \brief Fonction qui déclenche le son joué par la touche mi majeur
     *
     * \return void
     */
    void on_pushButtonMiM_clicked();


    /**
     * \fn void on_pushButtonFam_clicked()
     * \brief Fonction qui déclenche le son joué par la touche fa mineur
     *
     * \return void
     */
    void on_pushButtonFam_clicked();


    /**
     * \fn void on_pushButtonFaM_clicked()
     * \brief Fonction qui déclenche le son joué par la touche fa majeur
     *
     * \return void
     */
    void on_pushButtonFaM_clicked();


    /**
     * \fn void on_pushButtonSolm_clicked()
     * \brief Fonction qui déclenche le son joué par la touche sol mineur
     *
     * \return void
     */
    void on_pushButtonSolm_clicked();


    /**
     * \fn void on_pushButtonSolM_clicked()
     * \brief Fonction qui déclenche le son joué par la touche sol majeur
     *
     * \return void
     */
    void on_pushButtonSolM_clicked();


    /**
     * \fn void on_pushButtonLam_clicked()
     * \brief Fonction qui déclenche le son joué par la touche la mineur
     *
     * \return void
     */
    void on_pushButtonLam_clicked();


    /**
     * \fn void on_pushButtonLaM_clicked()
     * \brief Fonction qui déclenche le son joué par la touche la majeur
     *
     * \return void
     */
    void on_pushButtonLaM_clicked();


    /**
     * \fn void on_pushButtonSim_clicked()
     * \brief Fonction qui déclenche le son joué par la touche si mineur
     *
     * \return void
     */
    void on_pushButtonSim_clicked();


    /**
     * \fn void on_pushButtonSiM_clicked()
     * \brief Fonction qui déclenche le son joué par la touche si majeur
     *
     * \return void
     */
    void on_pushButtonSiM_clicked();


    /**
     * \fn void on_pushButtonDomD_clicked()
     * \brief Fonction qui déclenche le son joué par la touche do mineur diese
     *
     * \return void
     */
    void on_pushButtonDomD_clicked();


    /**
     * \fn void on_pushButtonDoMD_clicked()
     * \brief Fonction qui déclenche le son joué par la touche do majeur diese
     *
     * \return void
     */
    void on_pushButtonDoMD_clicked();


    /**
     * \fn void on_pushButtonRemD_clicked()
     * \brief Fonction qui déclenche le son joué par la touche ré mineur diese
     *
     * \return void
     */
    void on_pushButtonRemD_clicked();


    /**
     * \fn void on_pushButtonReMD_clicked()
     * \brief Fonction qui déclenche le son joué par la touche ré majeur diese
     *
     * \return void
     */
    void on_pushButtonReMD_clicked();


    /**
     * \fn void on_pushButtonFamD_clicked()
     * \brief Fonction qui déclenche le son joué par la touche fa mineur diese
     *
     * \return void
     */
    void on_pushButtonFamD_clicked();


    /**
     * \fn void on_pushButtonFaMD_clicked()
     * \brief Fonction qui déclenche le son joué par la touche fa majeur diese
     *
     * \return void
     */
    void on_pushButtonFaMD_clicked();


    /**
     * \fn void on_pushButtonSolmD_clicked()
     * \brief Fonction qui déclenche le son joué par la touche sol mineur diese
     *
     * \return void
     */
    void on_pushButtonSolmD_clicked();


    /**
     * \fn void on_pushButtonSolMD_clicked()
     * \brief Fonction qui déclenche le son joué par la touche sol majeur diese
     *
     * \return void
     */
    void on_pushButtonSolMD_clicked();


    /**
     * \fn void on_pushButtonLamD_clicked()
     * \brief Fonction qui déclenche le son joué par la touche la mineur diese
     *
     * \return void
     */
    void on_pushButtonLamD_clicked();


    /**
     * \fn void on_pushButtonLaMD_clicked()
     * \brief Fonction qui déclenche le son joué par la touche la majeur diese
     *
     * \return void
     */
    void on_pushButtonLaMD_clicked();

private:

    /**
     * \fn void ecrireLog(QString s)
     * \brief Fonction qui ouvre le fichier de log afin d'y ajouter la chaine de caractère passée en paramètre
     *
     * \param s     une chaine de type QString qui sera écrite dans le fichier log, ne peut etre NULL
     * \return void
     */
    void ecrireLog(QString s);


};

#endif // CLAVIERPIANO_H
