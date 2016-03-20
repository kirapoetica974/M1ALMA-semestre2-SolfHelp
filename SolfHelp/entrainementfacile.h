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
    explicit EntrainementFacile(QStackedWidget *p);
    
signals:
    
public slots:
    void goAccueil();


    void appuiDo1();
    void appuiDo2();
    void appuiRe1();
    void appuiRe2();
    void appuiMi1();
    void appuiMi2();
    void appuiFa1();
    void appuiFa2();
    void appuiSol1();
    void appuiSol2();
    void appuiLa1();
    void appuiLa2();
    void appuiSi1();
    void appuiSi2();

    void commencer();

    void precedent();
    void compter();

    //void demarreTimer();


private:
    QStackedWidget *pages;

    ClavierPiano *piano;

    QTextEdit *labelReponse;
    QPushButton *accueil;
    QPushButton *go;
    QPushButton *retour;
    QPushButton *imgTimer;

    QVector<Note*> *tabNotes;
    QVector<Note*> *tabReponse;
    bool enJeu;

    QString nomPartition;
    QString difficulte;

    QTimer *timer;
    QLabel *labelTimer;
    int tempsRestant;
    int tempsReel;
    int nbBonneReponses;

    void paintEvent(QPaintEvent* e);

    void chargerPartition(QString fichier);

    void placerNote(QPainter &painter, qreal largeur, qreal hauteur, qreal xDebutLigne, qreal yDebutLigne, qreal xDebutNote, qreal espaceEntreLigne, QString note, QString hauteurN);

    void deconnectionDesTouches();

    void partieTerminee();

    void ecrireLog(QString s);

    void effacerNomTouche();
};

#endif // ENTRAINEMENTFACILE_H
