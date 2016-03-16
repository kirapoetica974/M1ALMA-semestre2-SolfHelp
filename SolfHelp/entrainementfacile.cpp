#include "entrainementfacile.h"

EntrainementFacile::EntrainementFacile(QStackedWidget *p) : QWidget()
{
    pages = p;
    portee = new Portee(this);
}
