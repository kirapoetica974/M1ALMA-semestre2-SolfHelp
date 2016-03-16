#ifndef ENTRAINEMENTPAGE1_H
#define ENTRAINEMENTPAGE1_H

#include <QWidget>
#include <QStackedWidget>
#include <QPushButton>

class EntrainementPage1 : public QWidget
{
    Q_OBJECT
public:
    explicit EntrainementPage1(QStackedWidget *p);
    
signals:
    
public slots:
    void doFacile();
    void doDifficile();
    void goAccueil();

private:
    QStackedWidget *pages;
    QPushButton *facile;
    QPushButton *difficile;

    QPushButton *accueil;
};

#endif // ENTRAINEMENTPAGE1_H
