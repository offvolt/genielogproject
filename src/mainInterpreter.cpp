#include <iostream>
#include "interpreter.h"
#include "matrixManager.h"

using namespace std;

int main()
{
	MatrixManager m;
	bool val;
    	string var="";
    	cout << "Taper une commande" << endl;
   	cin >> var;
    	Interpreter I;
   	I.setCommand(var);
    	val=I.activeProcess(m);
    	if (val == false) { cout << "Erreur de saisie" << endl; }
    		cout << "Derniere commande en memoire : " << I.getCommand() << endl;
}
