#include "clavierpiano.h"
#include <QPalette>
#include <QColor>

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



    connect(do1, SIGNAL(clicked(bool)),this, SLOT(on_pushButtonDoM_clicked()));
    connect(do2, SIGNAL(clicked(bool)),this, SLOT(on_pushButtonDom_clicked()));
    connect(re1, SIGNAL(clicked(bool)),this, SLOT(on_pushButtonReM_clicked()));
    connect(re2, SIGNAL(clicked(bool)),this, SLOT(on_pushButtonRem_clicked()));
    connect(mi1, SIGNAL(clicked(bool)),this, SLOT(on_pushButtonMiM_clicked()));
    connect(mi2, SIGNAL(clicked(bool)),this, SLOT(on_pushButtonMim_clicked()));
    connect(fa1, SIGNAL(clicked(bool)),this, SLOT(on_pushButtonFaM_clicked()));
    connect(fa2, SIGNAL(clicked(bool)),this, SLOT(on_pushButtonFam_clicked()));
    connect(sol1, SIGNAL(clicked(bool)),this, SLOT(on_pushButtonSolM_clicked()));
    connect(sol2, SIGNAL(clicked(bool)),this, SLOT(on_pushButtonSolm_clicked()));
    connect(la1, SIGNAL(clicked(bool)),this, SLOT(on_pushButtonLaM_clicked()));
    connect(la2, SIGNAL(clicked(bool)),this, SLOT(on_pushButtonLam_clicked()));
    connect(si1, SIGNAL(clicked(bool)),this, SLOT(on_pushButtonSiM_clicked()));
    connect(si2, SIGNAL(clicked(bool)),this, SLOT(on_pushButtonSim_clicked()));

    connect(domD, SIGNAL(clicked(bool)),this, SLOT(on_pushButtonDomD_clicked()));
    connect(doMD, SIGNAL(clicked(bool)),this, SLOT(on_pushButtonDoMD_clicked()));
    connect(remD, SIGNAL(clicked(bool)),this, SLOT(on_pushButtonRemD_clicked()));
    connect(reMD, SIGNAL(clicked(bool)),this, SLOT(on_pushButtonReMD_clicked()));
    connect(famD, SIGNAL(clicked(bool)),this, SLOT(on_pushButtonFamD_clicked()));
    connect(faMD, SIGNAL(clicked(bool)),this, SLOT(on_pushButtonFaMD_clicked()));
    connect(solmD, SIGNAL(clicked(bool)),this, SLOT(on_pushButtonSolmD_clicked()));
    connect(solMD, SIGNAL(clicked(bool)),this, SLOT(on_pushButtonSolMD_clicked()));
    connect(lamD, SIGNAL(clicked(bool)),this, SLOT(on_pushButtonLamD_clicked()));
    connect(laMD, SIGNAL(clicked(bool)),this, SLOT(on_pushButtonLaMD_clicked()));

}

void ClavierPiano::clic(){
    qDebug() << "J'ai cliqué sur la touche";
}

void ClavierPiano::on_pushButtonDom_clicked()
{
    QString *chaine = new QString();
    chaine->append(chem);
 player = new QMediaPlayer;

 player->setMedia(QUrl::fromLocalFile(chaine->append("dom.wav")));
 player->setVolume(100);
 player->play();
}

void ClavierPiano::on_pushButtonDoM_clicked(){
    QString *chaine = new QString();
    chaine->append(chem);
    player = new QMediaPlayer;

    player->setMedia(QUrl::fromLocalFile(chaine->append("doM.wav")));
    player->setVolume(100);
    player->play();
}

void ClavierPiano::on_pushButtonRem_clicked(){
    QString *chaine = new QString();
    chaine->append(chem);
    player = new QMediaPlayer;

    player->setMedia(QUrl::fromLocalFile(chaine->append("rem.wav")));
    player->setVolume(100);
    player->play();
}

void ClavierPiano::on_pushButtonReM_clicked(){
    QString *chaine = new QString();
    chaine->append(chem);
    player = new QMediaPlayer;

    player->setMedia(QUrl::fromLocalFile(chaine->append("reM.wav")));
    player->setVolume(100);
    player->play();
}

void ClavierPiano::on_pushButtonMim_clicked(){
    QString *chaine = new QString();
    chaine->append(chem);
    player = new QMediaPlayer;

    player->setMedia(QUrl::fromLocalFile(chaine->append("mim.wav")));
    player->setVolume(100);
    player->play();
}

void ClavierPiano::on_pushButtonMiM_clicked(){
    QString *chaine = new QString();
    chaine->append(chem);
    player = new QMediaPlayer;

    player->setMedia(QUrl::fromLocalFile(chaine->append("miM.wav")));
    player->setVolume(100);
    player->play();
}

void ClavierPiano::on_pushButtonFam_clicked(){
    QString *chaine = new QString();
    chaine->append(chem);
    player = new QMediaPlayer;

    player->setMedia(QUrl::fromLocalFile(chaine->append("fam.wav")));
    player->setVolume(100);
    player->play();
}

void ClavierPiano::on_pushButtonFaM_clicked(){
    QString *chaine = new QString();
    chaine->append(chem);
    player = new QMediaPlayer;

    player->setMedia(QUrl::fromLocalFile(chaine->append("faM.wav")));
    player->setVolume(100);
    player->play();
}

void ClavierPiano::on_pushButtonSolm_clicked(){
    QString *chaine = new QString();
    chaine->append(chem);
    player = new QMediaPlayer;

    player->setMedia(QUrl::fromLocalFile(chaine->append("solm.wav")));
    player->setVolume(100);
    player->play();
}

void ClavierPiano::on_pushButtonSolM_clicked(){
    QString *chaine = new QString();
    chaine->append(chem);
    player = new QMediaPlayer;

    player->setMedia(QUrl::fromLocalFile(chaine->append("solM.wav")));
    player->setVolume(100);
    player->play();
}

void ClavierPiano::on_pushButtonLam_clicked(){
    QString *chaine = new QString();
    chaine->append(chem);
    player = new QMediaPlayer;

    player->setMedia(QUrl::fromLocalFile(chaine->append("lam.wav")));
    player->setVolume(100);
    player->play();
}

void ClavierPiano::on_pushButtonLaM_clicked(){
    QString *chaine = new QString();
    chaine->append(chem);
    player = new QMediaPlayer;

    player->setMedia(QUrl::fromLocalFile(chaine->append("laM.wav")));
    player->setVolume(100);
    player->play();
}

void ClavierPiano::on_pushButtonSim_clicked(){
    QString *chaine = new QString();
    chaine->append(chem);
    player = new QMediaPlayer;

    player->setMedia(QUrl::fromLocalFile(chaine->append("sim.wav")));
    player->setVolume(100);
    player->play();
}

void ClavierPiano::on_pushButtonSiM_clicked(){
    QString *chaine = new QString();
    chaine->append(chem);
    player = new QMediaPlayer;

    player->setMedia(QUrl::fromLocalFile(chaine->append("siM.wav")));
    player->setVolume(100);
    player->play();
}

void ClavierPiano::on_pushButtonDomD_clicked(){
    QString *chaine = new QString();
    chaine->append(chem);
    player = new QMediaPlayer;

    player->setMedia(QUrl::fromLocalFile(chaine->append("domD.wav")));
    player->setVolume(100);
    player->play();
}

void ClavierPiano::on_pushButtonDoMD_clicked(){
    QString *chaine = new QString();
    chaine->append(chem);
    player = new QMediaPlayer;

    player->setMedia(QUrl::fromLocalFile(chaine->append("doMD.wav")));
    player->setVolume(100);
    player->play();
}

void ClavierPiano::on_pushButtonRemD_clicked(){
    QString *chaine = new QString();
    chaine->append(chem);
    player = new QMediaPlayer;

    player->setMedia(QUrl::fromLocalFile(chaine->append("remD.wav")));
    player->setVolume(100);
    player->play();
}

void ClavierPiano::on_pushButtonReMD_clicked(){
    QString *chaine = new QString();
    chaine->append(chem);
    player = new QMediaPlayer;

    player->setMedia(QUrl::fromLocalFile(chaine->append("reMD.wav")));
    player->setVolume(100);
    player->play();
}

void ClavierPiano::on_pushButtonFamD_clicked(){
    QString *chaine = new QString();
    chaine->append(chem);
    player = new QMediaPlayer;

    player->setMedia(QUrl::fromLocalFile(chaine->append("famD.wav")));
    player->setVolume(100);
    player->play();
}

void ClavierPiano::on_pushButtonFaMD_clicked(){
    QString *chaine = new QString();
    chaine->append(chem);
    player = new QMediaPlayer;

    player->setMedia(QUrl::fromLocalFile(chaine->append("faMD.wav")));
    player->setVolume(100);
    player->play();
}

void ClavierPiano::on_pushButtonSolmD_clicked(){
    QString *chaine = new QString();
    chaine->append(chem);
    player = new QMediaPlayer;

    player->setMedia(QUrl::fromLocalFile(chaine->append("solmD.wav")));
    player->setVolume(100);
    player->play();
}

void ClavierPiano::on_pushButtonSolMD_clicked(){
    QString *chaine = new QString();
    chaine->append(chem);
    player = new QMediaPlayer;

    player->setMedia(QUrl::fromLocalFile(chaine->append("solMD.wav")));
    player->setVolume(100);
    player->play();
}

void ClavierPiano::on_pushButtonLamD_clicked(){
    QString *chaine = new QString();
    chaine->append(chem);
    player = new QMediaPlayer;

    player->setMedia(QUrl::fromLocalFile(chaine->append("lamD.wav")));
    player->setVolume(100);
    player->play();
}

void ClavierPiano::on_pushButtonLaMD_clicked(){
    QString *chaine = new QString();
    chaine->append(chem);
    player = new QMediaPlayer;

    player->setMedia(QUrl::fromLocalFile(chaine->append("laMD.wav")));
    player->setVolume(100);
    player->play();
}


ClavierPiano::~ClavierPiano(){

}
