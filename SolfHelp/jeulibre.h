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
    explicit JeuLibre(QStackedWidget *p);
    ~JeuLibre();



private:
    QStackedWidget *pages;
    ClavierPiano *clavier;
    QPushButton *accueil;

public slots:
    void goAccueil();

};

#endif // JEULIBRE_H
