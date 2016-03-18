#include "placenote.h"
#include <QPen>
#include <QPainter>

PlaceNote::PlaceNote(QWidget *w,qreal largeur, qreal hauteur, qreal xDebutLigne, qreal yDebutLigne, qreal xDebutNote, qreal espaceEntreLigne, QString note, QString hauteurN) :
    QWidget()
{

    this->l = largeur;
    this->h= hauteur;
    this->xLigne = xDebutLigne;
    this->yLigne = yDebutLigne;
    this->xNote = xDebutNote;
    this->espace = espaceEntreLigne;
    this->nom = note;
    this->hauteur = hauteurN;
    this->widg = w;
}

void PlaceNote::paintEvent(QPaintEvent *){
    QPainter painter(widg);
    QPen pen;
    pen.setWidth(2);
    painter.setPen(pen);
    painter.setBrush(Qt::BrushStyle(Qt::SolidPattern));

    QRectF rectangle;

    qreal x = xNote;
    qreal y = 0;
    qreal larg = espace+(espace/4);
    qreal haut = espace;
    if ((nom == "do") && (hauteur == "majeur")) {
        y = yLigne+(5.5*espace);
        qreal xl = xNote - rectangle.width();
        qreal xl2 = xNote + (2*rectangle.width());
        painter.drawLine(xl,yLigne+(espace*6),xl2,yLigne+(espace*6));

    }

    else if ((nom == "re") && (hauteur == "majeur")){
        y = yLigne+(5*espace);
    }

    else if ((nom == "mi") && (hauteur == "majeur")){
        y = yLigne+(4.5*espace);
    }

    else if ((nom == "fa") && (hauteur == "majeur")){
        y = yLigne+(4*espace);
    }

    else if ((nom == "sol") && (hauteur == "majeur")){
        y = yLigne+(3.5*espace);
    }
    else if ((nom == "la") && (hauteur == "majeur")){
        y = yLigne+(3*espace);
    }

    else if ((nom == "si") && (hauteur == "majeur")){
        y = yLigne+(2.5*espace);
    }

    else if ((nom == "do") && (hauteur == "mineur")) {
        y = yLigne+(2*espace);
    }

    else if ((nom == "re") && (hauteur == "mineur")){
        y = yLigne+(1.5*espace);
    }

    else if ((nom == "mi") && (hauteur == "mineur")){
        y = yLigne+(1*espace);
    }

    else if ((nom == "fa") && (hauteur == "mineur")){
        y = yLigne+(0.5*espace);
    }

    else if ((nom == "sol") && (hauteur == "mineur")){
        y = yLigne+(0*espace);
    }
    else if ((nom == "la") && (hauteur == "mineur")){
        y = yLigne+((-0.5)*espace);
    }

    else if ((nom == "si") && (hauteur == "mineur")){
        y = yLigne+((-1)*espace);
    }

    rectangle = QRectF(QPoint(x, y), QSize(larg, haut));
    painter.drawEllipse(rectangle);
    qreal xl = rectangle.x()+rectangle.width();
    qreal yl = rectangle.y()+(rectangle.width()/2);
    painter.drawLine(xl, yl, xl, yl-(espace*3));
}
