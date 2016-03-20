/**
 * \file Cours.h
 * \brief Fenetre de cours
 * \author Rachelle Taochy et Nina Exposito
 * \date 20 mars 2016
 *
 * C'est la fenetre sur laquelle se trouvera le cours sur le solfège
 *
 */

#ifndef COURS_H
#define COURS_H

#include <QWidget>
#include <QScrollArea>
#include <QStackedWidget>
#include <QPushButton>

class Cours : public QWidget
{
    Q_OBJECT
public:

    /**
     * \fn Cours(QStackedWidget *pages)
     * \brief Constructeur
     *
     * \param pages     Pointeur sur la structure de donnée contenant l'ensemble des fenetre, ne peut etre NULL
     **/
    explicit Cours(QStackedWidget *pages);
    
signals:
    
public slots:

    /**
     * \fn void goAccueil()
     * \brief Fonction qui permet d'aller sur la fenetre d'accueil
     *
     * \param void
     **/
    void goAccueil();



private:
    QScrollArea *area;
    QPushButton *accueil;
    QStackedWidget * pages;
    
};

#endif // COURS_H
