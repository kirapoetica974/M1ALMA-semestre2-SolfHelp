#ifndef COURS_H
#define COURS_H

#include <QWidget>
#include <QScrollArea>
#include <QStackedWidget>

class Cours : public QWidget
{
    Q_OBJECT
public:
    explicit Cours(QStackedWidget *pages);
    
signals:
    
public slots:


private:
    QScrollArea *area;
    
};

#endif // COURS_H
