#ifndef NOTE_H
#define NOTE_H
#include <QString>

class Note
{
public:
    Note(QString nom, QString hauteur);

private:
    QString nom;
    QString hauteur;
};

#endif // NOTE_H
