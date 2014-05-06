/*!
 * \file converter.h
 * \brief Convertisseur de matrice (en format .txt par exemple) en fichier binaire avec tous les chiffres a la suite 
 * et de binaire en fichier (txt  par exemple) sous forme de matrice
 * Deplus on une fonction de verification de la matrice.
 * \return Rien - Arrêt normal du programme.
 * \author SERRE Jeremy
 * \version 1.0
 */


#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Converter
{
    private:
    
    public:
    Converter();
    static void convertbin(string &fileName1,string &fileName2); // Fichier "lisible" vers binaire
    /*!
    * \brief Convertisseur de matrice (en format .txt par exemple) en fichier binaire avec tous les chiffres à la suite 
    * \param FileName1 :Chaîne de caractere (string) qui est le fichier de lecture,
    *        FileName2 :Chaîne de caractere (string) qui est le fichier de d'ecriture soit de destination.
    * Si le fichier de destination n'existe pas il le crée automatiquement au nom donnée.
    * FileName1 et FileName2 ne peuvent pas être nul.
    */

    static void convert(string &fileName1,string &fileName2); // Fichier binaire vers un fichier "lisible"
    /*!
    * \brief Convertisseur de fichier ecrit en binaire vers un fichier sous forme de matrice (en format .txt par exemple) 
    * \param FileName1 :Chaîne de caractere (string) qui est le fichier de lecture,
    *        FileName2 :Chaîne de caractere (string) qui est le fichier de d'ecriture soit de destination.
    * Si le fichier de destination n'existe pas il le crée automatiquement au nom donnée.
    * FileName1 et FileName2 ne peuvent pas être nul.
    */   
    
    static bool verif(string &fileName); // Fonction de verification
   /*!
    * \brief Est une fonction de Verification que la matrice respecte les conditions qui sont les suivantes:
    *    - Il faut que les colonnes dans la matrice soit dans l'ordre croissant
    *    - Il faut que les lignes de la matrice dans le fichier soit dans l'ordre croissante
    *    - Il faut que le fichier ne garde que les valeurs differente de zero matrice[i][j]!=0
    *    - Il faut que chaque colonne est au moins une valeur differente de zero c'est une condition
    * Si il y a un probleme l'utilisateur sera avertie d'ou vien le probleme dans le fichier.
    * \param FileName :Chaîne de caractere (string) qui est le fichier de lecture.
    *        FileName ne peuvent pas être nul sinon il ce passera rien
    *\return true si la fichier et correcte sinon il retourne false
    
};

