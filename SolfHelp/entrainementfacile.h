#ifndef ENTRAINEMENTFACILE_H
#define ENTRAINEMENTFACILE_H

#include <QWidget>
#include <QStackedWidget>
#include <portee.h>
#include <clavierpiano.h>
#include <QVector>
#include <note.h>

class EntrainementFacile : public QWidget
{
    Q_OBJECT
public:
    explicit EntrainementFacile(QStackedWidget *p);
    
signals:
    
public slots:
    void goAccueil();

private:
    QStackedWidget *pages;
    Portee *portee;

    ClavierPiano *piano;

    QPushButton *accueil;
    QVector<Note*> *tabNotes;

    void paintEvent(QPaintEvent* e);

    void chargerPartition(QString fichier);

    void placerNote(QPainter &painter, qreal largeur, qreal hauteur, qreal xDebutLigne, qreal yDebutLigne, qreal espaceEntreLigne, QString note);

    
};

#endif // ENTRAINEMENTFACILE_H
