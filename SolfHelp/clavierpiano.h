#ifndef CLAVIERPIANO_H
#define CLAVIERPIANO_H
#include <QString>
#include <QPushButton>
#include <QMediaPlayer>
#include <QStackedWidget>
#include <iostream>
#include <QWidget>

class ClavierPiano : public QWidget
{
    Q_OBJECT
public:
    explicit ClavierPiano(qreal xTouche, qreal yTouche, qreal largeurTouche, qreal hauteurTouche, QString *chemin, QWidget *widget);
    ~ClavierPiano();

    QPushButton* do1;
    QPushButton* re1;
    QPushButton* mi1;
    QPushButton* fa1;
    QPushButton* sol1;
    QPushButton* la1;
    QPushButton* si1;
    QPushButton* do2;
    QPushButton* re2;
    QPushButton* mi2;
    QPushButton* fa2;
    QPushButton* sol2;
    QPushButton* la2;
    QPushButton* si2;

    QPushButton *domD;
    QPushButton *doMD;
    QPushButton *remD;
    QPushButton *reMD;
    QPushButton *famD;
    QPushButton *faMD;
    QPushButton *solmD;
    QPushButton *solMD;
    QPushButton *lamD;
    QPushButton *laMD;


    QMediaPlayer* player;

    QString *chem;

    QWidget *w;

public slots:
    void clic();
    void on_pushButtonDom_clicked();
    void on_pushButtonDoM_clicked();
    void on_pushButtonRem_clicked();
    void on_pushButtonReM_clicked();
    void on_pushButtonMim_clicked();
    void on_pushButtonMiM_clicked();
    void on_pushButtonFam_clicked();
    void on_pushButtonFaM_clicked();
    void on_pushButtonSolm_clicked();
    void on_pushButtonSolM_clicked();
    void on_pushButtonLam_clicked();
    void on_pushButtonLaM_clicked();
    void on_pushButtonSim_clicked();
    void on_pushButtonSiM_clicked();
    void on_pushButtonDomD_clicked();
    void on_pushButtonDoMD_clicked();
    void on_pushButtonRemD_clicked();
    void on_pushButtonReMD_clicked();
    void on_pushButtonFamD_clicked();
    void on_pushButtonFaMD_clicked();
    void on_pushButtonSolmD_clicked();
    void on_pushButtonSolMD_clicked();
    void on_pushButtonLamD_clicked();
    void on_pushButtonLaMD_clicked();

private:
    // Mode de jeu :
    //      - 0 : Libre
    //      - 1 : Facile
    //      - 2 : Difficile
    qreal modeJeu;

    void ecrireLog(QString s);


};

#endif // CLAVIERPIANO_H
