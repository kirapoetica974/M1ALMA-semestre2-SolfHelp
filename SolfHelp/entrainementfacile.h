#ifndef ENTRAINEMENTFACILE_H
#define ENTRAINEMENTFACILE_H

#include <QWidget>
#include <QStackedWidget>
#include <portee.h>

class EntrainementFacile : public QWidget
{
    Q_OBJECT
public:
    explicit EntrainementFacile(QStackedWidget *p);
    
signals:
    
public slots:


private:
    QStackedWidget *pages;
    Portee *portee;
    
};

#endif // ENTRAINEMENTFACILE_H
