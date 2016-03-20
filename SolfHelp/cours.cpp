#include "cours.h"

Cours::Cours(QStackedWidget *pages) :QWidget()
{
    resize(600,500);
    area = new QScrollArea(this);
    area->setGeometry(0,0,600,800);
}
