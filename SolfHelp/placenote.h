#ifndef PLACENOTE_H
#define PLACENOTE_H

#include <QWidget>

class PlaceNote : public QWidget
{
    Q_OBJECT
public:
    explicit PlaceNote(QWidget *w, qreal largeur, qreal hauteur, qreal xDebutLigne, qreal yDebutLigne, qreal xDebutNote, qreal espaceEntreLigne, QString note, QString hauteurN);
    
    void paintEvent(QPaintEvent *);

    qreal l;
    qreal h;
    qreal xLigne;
    qreal yLigne;
    qreal xNote;
    qreal espace;
    QString nom;
    QString hauteur;

    QWidget *widg;
signals:
    
public slots:
    
};

#endif // PLACENOTE_H
