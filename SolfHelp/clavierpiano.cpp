#include "clavierpiano.h"
#include <QPalette>
#include <QColor>
#include <QSound>

ClavierPiano::ClavierPiano(qreal xTouche, qreal yTouche, qreal largeurTouche, qreal hauteurTouche, QString *chemin, QWidget *widget) : QWidget()
{
    resize(600,500);
    chem = new QString();
    chem->append(chemin);
    w = widget;

    do1 = new QPushButton("do",widget);
    re1 = new QPushButton("re",widget);
    mi1 = new QPushButton("mi",widget);
    fa1 = new QPushButton("fa",widget);
    sol1 = new QPushButton("sol",widget);
    la1 = new QPushButton("la",widget);
    si1 = new QPushButton("si",widget);
    do2 = new QPushButton("do",widget);
    re2 = new QPushButton("re",widget);
    mi2 = new QPushButton("mi",widget);
    fa2 = new QPushButton("fa",widget);
    sol2 = new QPushButton("sol",widget);
    la2 = new QPushButton("la",widget);
    si2 = new QPushButton("si",widget);

    domD = new QPushButton("do#",widget);
    doMD = new QPushButton("do#",widget);
    remD = new QPushButton("re#",widget);
    reMD = new QPushButton("re#",widget);
    famD = new QPushButton("fa#",widget);
    faMD = new QPushButton("fa#",widget);
    solmD = new QPushButton("sol#",widget);
    solMD = new QPushButton("sol#",widget);
    lamD = new QPushButton("la#",widget);
    laMD = new QPushButton("la#",widget);


    do1->setGeometry(xTouche, yTouche, largeurTouche, hauteurTouche);
    re1->setGeometry(xTouche+largeurTouche, yTouche, largeurTouche, hauteurTouche);
    mi1->setGeometry(xTouche+(2*largeurTouche), yTouche, largeurTouche, hauteurTouche);
    fa1->setGeometry(xTouche+(3*largeurTouche), yTouche, largeurTouche, hauteurTouche);
    sol1->setGeometry(xTouche+(4*largeurTouche), yTouche, largeurTouche, hauteurTouche);
    la1->setGeometry(xTouche+(5*largeurTouche), yTouche, largeurTouche, hauteurTouche);
    si1->setGeometry(xTouche+(6*largeurTouche), yTouche, largeurTouche, hauteurTouche);
    do2->setGeometry(xTouche+(7*largeurTouche), yTouche, largeurTouche, hauteurTouche);
    re2->setGeometry(xTouche+(8*largeurTouche), yTouche, largeurTouche, hauteurTouche);
    mi2->setGeometry(xTouche+(9*largeurTouche), yTouche, largeurTouche, hauteurTouche);
    fa2->setGeometry(xTouche+(10*largeurTouche), yTouche, largeurTouche, hauteurTouche);
    sol2->setGeometry(xTouche+(11*largeurTouche), yTouche, largeurTouche, hauteurTouche);
    la2->setGeometry(xTouche+(12*largeurTouche), yTouche, largeurTouche, hauteurTouche);
    si2->setGeometry(xTouche+(13*largeurTouche), yTouche, largeurTouche, hauteurTouche);


    qreal largeurToucheNoire = 0.8*largeurTouche;
    qreal hauteurToucheNoire = 0.6*hauteurTouche;

    // Placement des altérations
    doMD->setGeometry(xTouche+(0.6*largeurTouche),yTouche,largeurToucheNoire, hauteurToucheNoire);
    reMD->setGeometry((xTouche+largeurTouche)+(0.6*largeurTouche), yTouche, largeurToucheNoire, hauteurToucheNoire);
    faMD->setGeometry((xTouche+(3*largeurTouche))+(0.6*largeurTouche), yTouche, largeurToucheNoire, hauteurToucheNoire);
    solMD->setGeometry((xTouche+(4*largeurTouche))+(0.6*largeurTouche), yTouche, largeurToucheNoire, hauteurToucheNoire);
    laMD->setGeometry((xTouche+(5*largeurTouche))+(0.6*largeurTouche), yTouche, largeurToucheNoire, hauteurToucheNoire);
    domD->setGeometry((xTouche+(7*largeurTouche))+(0.6*largeurTouche), yTouche, largeurToucheNoire, hauteurToucheNoire);
    remD->setGeometry((xTouche+(8*largeurTouche))+(0.6*largeurTouche), yTouche, largeurToucheNoire, hauteurToucheNoire);
    famD->setGeometry((xTouche+(10*largeurTouche))+(0.6*largeurTouche), yTouche, largeurToucheNoire, hauteurToucheNoire);
    solmD->setGeometry((xTouche+(11*largeurTouche))+(0.6*largeurTouche), yTouche, largeurToucheNoire, hauteurToucheNoire);
    lamD->setGeometry((xTouche+(12*largeurTouche))+(0.6*largeurTouche), yTouche, largeurToucheNoire, hauteurToucheNoire);


    // Modification des touches
    do1->setFocusPolicy(Qt::NoFocus);
    do1->setStyleSheet("background-color : white");
    do2->setFocusPolicy(Qt::NoFocus);
    do2->setStyleSheet("background-color : white");
    re1->setFocusPolicy(Qt::NoFocus);
    re1->setStyleSheet("background-color : white");
    re2->setFocusPolicy(Qt::NoFocus);
    re2->setStyleSheet("background-color : white");
    mi1->setFocusPolicy(Qt::NoFocus);
    mi1->setStyleSheet("background-color : white");
    mi2->setFocusPolicy(Qt::NoFocus);
    mi2->setStyleSheet("background-color : white");
    fa1->setFocusPolicy(Qt::NoFocus);
    fa1->setStyleSheet("background-color : white");
    fa2->setFocusPolicy(Qt::NoFocus);
    fa2->setStyleSheet("background-color : white");
    sol1->setFocusPolicy(Qt::NoFocus);
    sol1->setStyleSheet("background-color : white");
    sol2->setFocusPolicy(Qt::NoFocus);
    sol2->setStyleSheet("background-color : white");
    la1->setFocusPolicy(Qt::NoFocus);
    la1->setStyleSheet("background-color : white");
    la2->setFocusPolicy(Qt::NoFocus);
    la2->setStyleSheet("background-color : white");
    si1->setFocusPolicy(Qt::NoFocus);
    si1->setStyleSheet("background-color : white");
    si2->setFocusPolicy(Qt::NoFocus);
    si2->setStyleSheet("background-color : white");
    domD->setFocusPolicy(Qt::NoFocus);
    domD->setStyleSheet("background-color : green");
    doMD->setFocusPolicy(Qt::NoFocus);
    doMD->setStyleSheet("background-color : green");
    remD->setFocusPolicy(Qt::NoFocus);
    remD->setStyleSheet("background-color : black");
    reMD->setFocusPolicy(Qt::NoFocus);
    reMD->setStyleSheet("background-color : black");
    famD->setFocusPolicy(Qt::NoFocus);
    famD->setStyleSheet("background-color : black");
    faMD->setFocusPolicy(Qt::NoFocus);
    faMD->setStyleSheet("background-color : black");
    solmD->setFocusPolicy(Qt::NoFocus);
    solmD->setStyleSheet("background-color : black");
    solMD->setFocusPolicy(Qt::NoFocus);
    solMD->setStyleSheet("background-color : black");
    lamD->setFocusPolicy(Qt::NoFocus);
    lamD->setStyleSheet("background-color : black");
    laMD->setFocusPolicy(Qt::NoFocus);
    laMD->setStyleSheet("background-color : black");







    connect(do1, SIGNAL(pressed()),this, SLOT(on_pushButtonDoM_clicked()));
    connect(do2, SIGNAL(pressed()),this, SLOT(on_pushButtonDom_clicked()));
    connect(re1, SIGNAL(pressed()),this, SLOT(on_pushButtonReM_clicked()));
    connect(re2, SIGNAL(pressed()),this, SLOT(on_pushButtonRem_clicked()));
    connect(mi1, SIGNAL(pressed()),this, SLOT(on_pushButtonMiM_clicked()));
    connect(mi2, SIGNAL(pressed()),this, SLOT(on_pushButtonMim_clicked()));
    connect(fa1, SIGNAL(pressed()),this, SLOT(on_pushButtonFaM_clicked()));
    connect(fa2, SIGNAL(pressed()),this, SLOT(on_pushButtonFam_clicked()));
    connect(sol1, SIGNAL(pressed()),this, SLOT(on_pushButtonSolM_clicked()));
    connect(sol2, SIGNAL(pressed()),this, SLOT(on_pushButtonSolm_clicked()));
    connect(la1, SIGNAL(pressed()),this, SLOT(on_pushButtonLaM_clicked()));
    connect(la2, SIGNAL(pressed()),this, SLOT(on_pushButtonLam_clicked()));
    connect(si1, SIGNAL(pressed()),this, SLOT(on_pushButtonSiM_clicked()));
    connect(si2, SIGNAL(pressed()),this, SLOT(on_pushButtonSim_clicked()));

    connect(domD, SIGNAL(pressed()),this, SLOT(on_pushButtonDomD_clicked()));
    connect(doMD, SIGNAL(pressed()),this, SLOT(on_pushButtonDoMD_clicked()));
    connect(remD, SIGNAL(pressed()),this, SLOT(on_pushButtonRemD_clicked()));
    connect(reMD, SIGNAL(pressed()),this, SLOT(on_pushButtonReMD_clicked()));
    connect(famD, SIGNAL(pressed()),this, SLOT(on_pushButtonFamD_clicked()));
    connect(faMD, SIGNAL(pressed()),this, SLOT(on_pushButtonFaMD_clicked()));
    connect(solmD, SIGNAL(pressed()),this, SLOT(on_pushButtonSolmD_clicked()));
    connect(solMD, SIGNAL(pressed()),this, SLOT(on_pushButtonSolMD_clicked()));
    connect(lamD, SIGNAL(pressed()),this, SLOT(on_pushButtonLamD_clicked()));
    connect(laMD, SIGNAL(pressed()),this, SLOT(on_pushButtonLaMD_clicked()));

}

void ClavierPiano::clic(){
    qDebug() << "J'ai cliqué sur la touche";
}

void ClavierPiano::on_pushButtonDom_clicked()
{
    QSound::play("../SonNote/dom.wav");
}

void ClavierPiano::on_pushButtonDoM_clicked(){
    QSound::play("../SonNote/doM.wav");
}

void ClavierPiano::on_pushButtonRem_clicked(){
    QSound::play("../SonNote/rem.wav");
}

void ClavierPiano::on_pushButtonReM_clicked(){
   QSound::play("../SonNote/reM.wav");
}

void ClavierPiano::on_pushButtonMim_clicked(){
    QSound::play("../SonNote/mim.wav");
}

void ClavierPiano::on_pushButtonMiM_clicked(){
    QSound::play("../SonNote/miM.wav");
}

void ClavierPiano::on_pushButtonFam_clicked(){
    QSound::play("../SonNote/fam.wav");
}

void ClavierPiano::on_pushButtonFaM_clicked(){
    QSound::play("../SonNote/faM.wav");
}

void ClavierPiano::on_pushButtonSolm_clicked(){
    QSound::play("../SonNote/solm.wav");
}

void ClavierPiano::on_pushButtonSolM_clicked(){
    QSound::play("../SonNote/solM.wav");
}

void ClavierPiano::on_pushButtonLam_clicked(){
    QSound::play("../SonNote/lam.wav");
}

void ClavierPiano::on_pushButtonLaM_clicked(){
    QSound::play("../SonNote/laM.wav");
}

void ClavierPiano::on_pushButtonSim_clicked(){
    QSound::play("../SonNote/sim.wav");
}

void ClavierPiano::on_pushButtonSiM_clicked(){
    QSound::play("../SonNote/siM.wav");
}

void ClavierPiano::on_pushButtonDomD_clicked(){
    QSound::play("../SonNote/domD.wav");
}

void ClavierPiano::on_pushButtonDoMD_clicked(){
    QSound::play("../SonNote/doMD.wav");
}

void ClavierPiano::on_pushButtonRemD_clicked(){
    QSound::play("../SonNote/remD.wav");
}

void ClavierPiano::on_pushButtonReMD_clicked(){
    QSound::play("../SonNote/reMD.wav");
}

void ClavierPiano::on_pushButtonFamD_clicked(){
    QSound::play("../SonNote/famD.wav");
}

void ClavierPiano::on_pushButtonFaMD_clicked(){
    QSound::play("../SonNote/faMD.wav");
}

void ClavierPiano::on_pushButtonSolmD_clicked(){
    QSound::play("../SonNote/solmD.wav");
}

void ClavierPiano::on_pushButtonSolMD_clicked(){
    QSound::play("../SonNote/solMD.wav");
}

void ClavierPiano::on_pushButtonLamD_clicked(){
    QSound::play("../SonNote/lamD.wav");
}

void ClavierPiano::on_pushButtonLaMD_clicked(){
    QSound::play("../SonNote/laMD.wav");
}


ClavierPiano::~ClavierPiano(){

}
