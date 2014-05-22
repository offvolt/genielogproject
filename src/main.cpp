#include <iostream>
#include "interpreter.h"
#include <sstream>

void help();
bool cinNumber(unsigned int & input);

using namespace std;

int main()
{
	cout << "************ APPLICATION TEST DE MATRIX++ *************" << endl;

	Interpreter interpreter;
	unsigned int input = 100;
	string input2 = "";
	MatrixManager matrixManager;
	do
	{
		cout << "MENU : " << endl;
		cout << "1- Passer en mode Exec" << endl;
		cout << "2- Help" << endl;
		cout << "0- Quitter" << endl;
		do
		{
			cout << "Entree : ";
		}while(!cinNumber(input));
		switch(input)
		{
			case 1:
				cout << endl;
				cout << endl;
				do
				{
					cout << "Exec : ";
					cin >> input2;
					if(input2 == "help")
					{
						help();
						cout << endl;
						cout << endl;
					}
					if(input2 == "exit")
					{
						cout << "RETOUR AU MENU" << endl << endl;
					}
					else
					{
						interpreter.setCommand(input2);
						interpreter.activeProcess(matrixManager);
					}
				}while(input2 != "exit");
			break;
			case 2:
				help();
				cout << endl;
				cout << endl;
			break;
		}
	}while(input != 0);
	return 0;
}


void help()
{
	cout << "********** Help du logiciel **********" << endl;
	cout << "** Mode Exec" << endl;
	cout << "Le mode execution attend de vous une commande." << endl << endl;
	cout << "** Commandes irregulieres" << endl;
	cout << "help : Affiche l'aide que vous lisez." << endl;
	cout << "exit : quitte le mode d'execution." << endl << endl;
	cout << "** Systeme de commandes" << endl;
	cout << "---- Commandes de base" << endl;
	cout << "X < [filePath] : lie le fichier a la variable X. Si la variable X n'existe pas, elle est cree. Sinon, elle delie le fichier auquel X est lie pour le lie au fichier donne." << endl;
	cout << "X=Y : met les valeurs du fichier lie à Y dans le fichier lie a X." << endl;
	cout << "---- Operations" << endl;
	cout << "X+Y : Additionne X et Y, met le resultat dans un fichier temporaire et l'affiche." << endl;
	cout << "X-Y : Soustrait Y a X, met le resultat dans un fichier temporaire et l'affiche." << endl; 
	cout << "X*Y : Multiplie Y a X, met le resultat dans un fichier temporaire et l'affiche." << endl;
	cout << "X^-1 : Inverse X, met le resultat dans un fichier temporaire et l'affiche." << endl;
	cout << "X^a : Met X a la puissance de a, met le resultat dans un fichier temporaire et l'affiche." << endl;
	cout << "X^t : Transpose X, met le resultat dans un fichier temporaire et l'affiche." << endl;
	cout << "---- Operations + egalite" << endl;
	cout << "X=[operation] : Fait l'operation demander et met le resultat dans le fichier lie a X. Le resultat n'est pas affiche." << endl;
	cout << "********* Fin Help du logiciel *********" << endl;
}

bool cinNumber(unsigned int & input)
{
	string input_s;
	cin >> input_s;
	int i=0, test;
	istringstream iss;
	while (input_s[i] != '\0')
	{
		test=0;
		for (char j = '0' ; j <= '9' ; j++){ if (input_s[i] == j) { test=1;} }
		if (test == 0) { return false; } // On a pas pu convertir.
		i++;
	}
	iss.str(input_s);
	iss >> input;
	return true; // On a bien converti;
}
