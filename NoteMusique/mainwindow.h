#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPaintEvent>
#include <QPushButton>
#include <QStackedWidget>
#include "fenetresecondaire1.h"

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

public slots:
    void slotDisplayFen(int fenIndex);

private:
    Ui::MainWindow *ui;
    QStackedWidget *stack;
    FenetreSecondaire1 *fen1;

protected:
    void paintEvent(QPaintEvent* e);
};

#endif // MAINWINDOW_H
