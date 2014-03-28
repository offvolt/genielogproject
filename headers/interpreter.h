#ifndef H_INTERPRETER
#define H_INTERPRETER

#include <iostream>
#include <string>

using namespace std;

class Interpreter
{
private:
	string command;
public:
	Interpreter();
	~Interpreter();

	void activeProcess(MatrixManager & matrixManager);	// Traite la commande
	// Et active les fonctions adéquates au manager de matrice.
	/* Exemple :
	Si la commande est C = A * B
	Il va faire matrixManager.multMatrix(matrixManager("A", "B", "C")); */
	
	void setCommand(string &command);	// Permet de donner une commandeà l'interpréteur.
	string getCommand();			// Permet de récupérer la commande de l'interpréteur.
};
