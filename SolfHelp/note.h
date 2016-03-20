/**
 * \file Note.h
 * \brief Structure correspondant à une note
 * \author Rachelle Taochy et Nina Exposito
 * \date 20 mars 2016
 *
 * Cette classe permet de crééer des objets note
 *
 */

#ifndef NOTE_H
#define NOTE_H
#include <QString>

class Note
{
public:

    /**
     * @fn Note(QString nom, QString hauteur)
     * @brief Constructeur
     * @param nom   Nom de la note, ne peut etre NULL
     * @param hauteur Hauteur de la note (mineur ou majeur), ne peut etre NULL
     */
    Note(QString nom, QString hauteur);


    QString nom; //!< Chaine de caractère contenant le nom de la note
    QString hauteur; //!< Chaine de caractère contenant la hauteur de la note

private:

};

#endif // NOTE_H
