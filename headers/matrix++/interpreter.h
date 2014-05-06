/*!
 * \file interpreter.h
 * \brief Interprète les commandes entrés par l'utilisateur
 */

#ifndef H_INTERPRETER
#define H_INTERPRETER


#include <iostream>
#include <string>

using namespace std;


/*! \class Interpreter
   * \brief classe representant l'interpreteur
   *
   *  La classe gere le traitement d'une commande entré par l'utilisateur
   */
class Interpreter
{
private:
    string command; /*!< Commande entré par l'utilisateur*/

    /*!
     *  \brief Vérifie les noms de matrice présents dans la commande entrée par l'utilisateur
     *
     *  Methode qui permet de vérifier qu'il n'y a pas d'erreurs au niveau des nom de matrices présents dans la commande entrée par l'utilisateur
     *  Exemple :
     *  Si la commande est `@ = A * B
     *  Il sera signalé à l'utilisateur que la commande qu'il a entré est erronée
     *
     *  \param i : indice signalant la position actuel dans le string représentant la commande entré par l'utilisateur
     *          c : string servant à récupérer les noms de matrice
     *  \return true si il n'y a pas de problème avec les noms de matrices
     *  false sinon
     */
    bool matrixName(int &i, string &c);

    /*!
     *  \brief verification des caractères suivant un symbole
     *
     *  Methode qui permet de vérifier que deux symboles ne se suivent pas, et qui vérifie ce qui suit le symbole ^
     *  Exemple :
     *  Si la commande est C = A *+ B
     *  Il sera signalé à l'utilisateur que la commande qu'il a entré est erronée
     *  De même si l'on a A^-2 ou A^B , etc ...
     *
     *  \param i : indice signalant la position actuel dans le string représentant la commande entré par l'utilisateur
     *  \return true si il n'y a pas de problème avec les opérateurs
     *  false sinon
     */
    bool sign(int &i);

    /*!
     *  \brief traitement des caractères se trouvant après le symbole ^
     *
     *  Methode qui permet de traiter les caractères se trouvant après le symbole ^
     *  Exemple :
     *  Si la commande est A^2
     *  le caractère 2 sera récupéré et convertit en int afin de pouvoir faire les opérations
     *
     *  \param i : indice signalant la position actuel dans le string représentant la commande entré par l'utilisateur
     *         op : string contenant l'opération à réaliser
     *         n : int dans lequel sera récupérer les nombres éventuellement nécessaire aux opérations
     *  \return true si il n'y a pas de problème avec les caractères suivant le symbole ^
     *  false sinon
     */
    bool controlExp(int &i, string &op, int &n);

    /*!
     *  \brief appel des fonctions de calcul
     *
     *  Methode qui permet d'appeler les fonctions de calcul
     *
     *  \param op : string contenant l'opération à réaliser
     *         matrix1 : string contenant le nom d'une des matrices sur laquelle l'opération est effectué
     *         matrix2 : string contenant le nom d'une des matrices sur laquelle l'opération est effectué
     *         matrixOut : string contenant le nom de la matrice qui contiendra le resultat de l'opération
     *         matrixManager : contient les fonctions de calculs
     *  \return true si il n'y a pas de problème avec l'appel des fonctions et leur execution
     *  false sinon
     */
    bool operation(string &op, string &matrix1, string &matrix2, string &matrixOut, int &n, MatrixManager &matrixManager);

     /*!
     *  \brief verifie un nom de fichier
     *
     *  Methode qui permet de verifier qu'un string est bien de la forme "nomDeficheir.mat"
     *
     *  \param i : indice signalant la position actuel dans le string représentant la commande entré par l'utilisateur
     *         c : string servant à récupérer lenom du fichier
     *  \return true si il n'y a pas de problème avec l'appel des fonctions et leur execution
     *  false sinon
     */
    bool verifFileName(int &i, string &c);

public:
    /*!
     *  \brief Constructeur
     *
     *  Constructeur de la classe Interpreter
     *
     */
    Interpreter();

    /*!
     *  \brief Destructeur
     *
     *  Destructeur de la classe Interpreter
     */
    ~Interpreter();

    /*!
     *  \brief traitement de la commande en mémoire
     *
     *  Methode qui permet de lancer les différentes fonctions de calculs nécessaires au traitement de la demande de l'utilisateur
     *  Exemple :
     *  Si la commande est C = A * B
     *  Il va faire matrixManager.multMatrix(matrixManager("A", "B", "C"));
     *
     *  \param matrixManager : le matrixManager contenant les fonctions de calculs
     *  \return true si la demande de l'utilisateur est correctement traité
     *  false sinon
     */
    bool activeProcess(MatrixManager & matrixManager);

    /*!
     *  \brief récupération d'un string contenant une commande tapé par l'utilisateur
     *
     *  Méthode permettant de mettre en mémoire un string contenant une commande tapé par l'utilisateur
     *
     *  \param command : le string contenant la commande tapé par l'utilisateur
     */
    void setCommand(string &command);

     /*!
     *  \brief Donne la commande en mémoire actuellement (donc la dernière commande tapé)
     *
     *  Méthode permettant de retourner sous forme de string la commande actuellement en mémoire
     *
     *  \return le string contenant la commande en mémoire
     */
    string getCommand();

};

#endif
