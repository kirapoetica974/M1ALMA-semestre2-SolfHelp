#ifndef NOTE_H
#define NOTE_H
#include <QString>

class Note
{
public:
    Note(QString *nom, QString *hauteur, QString *alteration);

private:
    QString *nom;
    QString *hauteur;
    QString *alteration;
};

#endif // NOTE_H
