#include <iostream>
#include "interpreter.h"
#include "matrixManager.h"

using namespace std;

int main()
{
<<<<<<< HEAD
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
=======
    bool val;
    Interpreter I;
    string var="";
    while (var != "stop")
    {
        cout << "Taper une commande (stop pour arreter) :" << endl;
        cin >> var;
        if (var !="stop")
        {
            I.setCommand(var);
            val=I.activeProcess();
            if (val == false) { cout << "Erreur de saisie" << endl; }
            cout << "Derniere commande en memoire : " << I.getCommand() << endl;
        }
    }
>>>>>>> f480b592e591abb44b86df7ccf2d7b97a9c84669
}
