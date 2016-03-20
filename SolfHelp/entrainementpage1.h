#ifndef ENTRAINEMENTPAGE1_H
#define ENTRAINEMENTPAGE1_H

#include <QWidget>
#include <QStackedWidget>
#include <QPushButton>
#include <QComboBox>
#include <QFile>

class EntrainementPage1 : public QWidget
{
    Q_OBJECT
public:
    explicit EntrainementPage1(QStackedWidget *p);

    void paintEvent(QPaintEvent *);
    
signals:
    
public slots:
    void doFacile();
    void doDifficile();
    void goAccueil();
    void choixPartition();



private:
    QStackedWidget *pages;
    QPushButton *facile;
    QPushButton *difficile;

    QPushButton *accueil;

    QComboBox *listePartition;

    QString comboText;


    void insertFichier(QString s);

    void ecrireLog(QString s);
};

#endif // ENTRAINEMENTPAGE1_H
