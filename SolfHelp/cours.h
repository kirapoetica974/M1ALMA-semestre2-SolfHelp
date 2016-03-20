#ifndef COURS_H
#define COURS_H

#include <QWidget>
#include <QScrollArea>
#include <QStackedWidget>
#include <QPushButton>

class Cours : public QWidget
{
    Q_OBJECT
public:
    explicit Cours(QStackedWidget *pages);
    
signals:
    
public slots:
    void goAccueil();
    void precedent();

private:
    QScrollArea *area;
    QPushButton *accueil;
    QPushButton *retour;
    QStackedWidget * pages;
    
};

#endif // COURS_H
