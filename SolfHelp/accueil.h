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
    Accueil(QStackedWidget *p);

private:
    QStackedWidget *pages;

    QPushButton *boutonCours;
    QPushButton *boutonEntrainement;
    QPushButton *boutonLibre;

    QFile *logFile;

    void ecrireLog(QString s);

public slots:
    void doCours();
    void doEntrainement();
    void doLibre();
};

#endif // ACCUEIL_H
