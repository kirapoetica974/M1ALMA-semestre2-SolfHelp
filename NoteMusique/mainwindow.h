#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPaintEvent>
#include <QPushButton>
#include <QStackedWidget>
#include "fenetresecondaire1.h"
#include "QtMultimedia/QMediaPlayer"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow();
    ~MainWindow();
    QPushButton* retour;

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
    QMediaPlayer* player;

public slots:
    void slotDisplayFen(int fenIndex);
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

private:
    Ui::MainWindow *ui;
    QStackedWidget *stack;
    FenetreSecondaire1 *fen1;

protected:
    void paintEvent(QPaintEvent* e);
};

#endif // MAINWINDOW_H
