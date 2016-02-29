#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QRectF>
#include <QPainter>
#include <QPoint>
#include <QSize>
#include <QDesktopWidget>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{


    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *e){
    // rectangle.x() ==> permet de donner la position x du rectangle
    // rectangle.y() ==> permet de donne la position y du rectangle
    // rectangle.height() ==> permet de donner la hauteur du rectangle
    // rectangle.width() ==> permet de donner la largeur du rectangle


    // Largeur de la fenetre de l'application
    int largeur = size().width();

    // hauteur de la fenetre de l'application
    int hauteur = size().height();

    QWidget *window = new QWidget;


    // Dessin de la portée

    //Coordonnées du début de la ligne
    qreal xDebutLigne = (largeur*10)/100;;
    qreal yDebutLigne = (largeur*10)/100;

    // longueur de la ligne en fonction de l'ecran
    qreal longueurLigne = largeur-50;
    qreal espaceEntreLigne = (largeur*3)/100;
    QPainter painter(this);
    for (int i = 1; i < 7; i++) {
        painter.drawLine(xDebutLigne,yDebutLigne+(espaceEntreLigne*i),longueurLigne,yDebutLigne+(espaceEntreLigne*i));
    }


    // Dessin de la note
    QRectF rectangle(QPoint(largeur/2, yDebutLigne+2*espaceEntreLigne), QSize(espaceEntreLigne+(espaceEntreLigne/4), espaceEntreLigne));
    //QPainter painter(this);
    painter.drawEllipse(rectangle);
    painter.setBackgroundMode(Qt::OpaqueMode);
    qreal x = rectangle.x()+rectangle.width();
    qreal y = rectangle.y()+(rectangle.width()/2);
    painter.drawLine(x, y, x, y-(espaceEntreLigne*3));

}
