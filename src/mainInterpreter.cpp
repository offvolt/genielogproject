#include <iostream>
#include "interpreter.h"

using namespace std;

int main()
{
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
}
