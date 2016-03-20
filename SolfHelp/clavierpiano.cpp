#include "clavierpiano.h"
#include <QPalette>
#include <QColor>
#include <QSound>

#include <QFile>
#include <QDateTime>

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

    domD = new QPushButton("",widget);
    doMD = new QPushButton("",widget);
    remD = new QPushButton("",widget);
    reMD = new QPushButton("",widget);
    famD = new QPushButton("",widget);
    faMD = new QPushButton("",widget);
    solmD = new QPushButton("",widget);
    solMD = new QPushButton("",widget);
    lamD = new QPushButton("",widget);
    laMD = new QPushButton("",widget);


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
    qreal hauteurToucheNoire = 0.45*hauteurTouche;

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


    //raccourci pour les notes
    do1->setShortcut((tr("a")));
    re1->setShortcut((tr("z")));
    mi1->setShortcut((tr("e")));
    fa1->setShortcut((tr("r")));
    sol1->setShortcut((tr("t")));
    la1->setShortcut((tr("y")));
    si1->setShortcut((tr("u")));
    do2->setShortcut((tr("q")));
    re2->setShortcut((tr("s")));
    mi2->setShortcut((tr("d")));
    fa2->setShortcut((tr("f")));
    sol2->setShortcut((tr("g")));
    la2->setShortcut((tr("h")));
    si2->setShortcut((tr("j")));


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
    domD->setStyleSheet("background-color : black");
    doMD->setFocusPolicy(Qt::NoFocus);
    doMD->setStyleSheet("background-color : black");
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
    ecrireLog("clic sur Dom");
}

void ClavierPiano::on_pushButtonDoM_clicked(){
    QSound::play("../SonNote/doM.wav");
    ecrireLog("clic sur DoM");
}

void ClavierPiano::on_pushButtonRem_clicked(){
    QSound::play("../SonNote/rem.wav");
    ecrireLog("clic sur Rem");
}

void ClavierPiano::on_pushButtonReM_clicked(){
   QSound::play("../SonNote/reM.wav");
   ecrireLog("clic sur ReM");
}

void ClavierPiano::on_pushButtonMim_clicked(){
    QSound::play("../SonNote/mim.wav");
    ecrireLog("clic sur Mim");
}

void ClavierPiano::on_pushButtonMiM_clicked(){
    QSound::play("../SonNote/miM.wav");
    ecrireLog("clic sur MiM");
}

void ClavierPiano::on_pushButtonFam_clicked(){
    QSound::play("../SonNote/fam.wav");
    ecrireLog("clic sur Fam");
}

void ClavierPiano::on_pushButtonFaM_clicked(){
    QSound::play("../SonNote/faM.wav");
    ecrireLog("clic sur FaM");
}

void ClavierPiano::on_pushButtonSolm_clicked(){
    QSound::play("../SonNote/solm.wav");
    ecrireLog("clic sur Solm");
}

void ClavierPiano::on_pushButtonSolM_clicked(){
    QSound::play("../SonNote/solM.wav");
    ecrireLog("clic sur SolM");
}

void ClavierPiano::on_pushButtonLam_clicked(){
    QSound::play("../SonNote/lam.wav");
    ecrireLog("clic sur Lam");
}

void ClavierPiano::on_pushButtonLaM_clicked(){
    QSound::play("../SonNote/laM.wav");
    ecrireLog("clic sur LaM");
}

void ClavierPiano::on_pushButtonSim_clicked(){
    QSound::play("../SonNote/sim.wav");
    ecrireLog("clic sur Sim");
}

void ClavierPiano::on_pushButtonSiM_clicked(){
    QSound::play("../SonNote/siM.wav");
    ecrireLog("clic sur SiM");
}

void ClavierPiano::on_pushButtonDomD_clicked(){
    QSound::play("../SonNote/domD.wav");
    ecrireLog("clic sur DomD");
}

void ClavierPiano::on_pushButtonDoMD_clicked(){
    QSound::play("../SonNote/doMD.wav");
    ecrireLog("clic sur DoMD");
}

void ClavierPiano::on_pushButtonRemD_clicked(){
    QSound::play("../SonNote/remD.wav");
    ecrireLog("clic sur RemD");
}

void ClavierPiano::on_pushButtonReMD_clicked(){
    QSound::play("../SonNote/reMD.wav");
    ecrireLog("clic sur ReMD");
}

void ClavierPiano::on_pushButtonFamD_clicked(){
    QSound::play("../SonNote/famD.wav");
    ecrireLog("clic sur FamD");
}

void ClavierPiano::on_pushButtonFaMD_clicked(){
    QSound::play("../SonNote/faMD.wav");
    ecrireLog("clic sur FaMD");
}

void ClavierPiano::on_pushButtonSolmD_clicked(){
    QSound::play("../SonNote/solmD.wav");
    ecrireLog("clic sur SolmD");
}

void ClavierPiano::on_pushButtonSolMD_clicked(){
    QSound::play("../SonNote/solMD.wav");
    ecrireLog("clic sur SolMD");
}

void ClavierPiano::on_pushButtonLamD_clicked(){
    QSound::play("../SonNote/lamD.wav");
}

void ClavierPiano::on_pushButtonLaMD_clicked(){
    QSound::play("../SonNote/laMD.wav");
    ecrireLog("clic sur LaMD");
}


ClavierPiano::~ClavierPiano(){

}

void ClavierPiano::ecrireLog(QString s){
    QString fileName = "../log.txt";
    QFile file(fileName);
    if (!file.open(QIODevice::Append | QIODevice::Text)){
        qDebug() << "impossible d'ouvir le fichier";
        return;
    }

    QDateTime d = QDateTime::currentDateTime();
    QString st = d.toString("dd-MM-yyyy  hh:mm:ss  ");

    QTextStream flux(&file);
    flux << "\n"<< st << s;

    file.close();
}
