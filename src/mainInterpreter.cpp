#include <iostream>
#include "interpreter.h"

using namespace std;

int main()
{
    bool val;
    string var="";
    cout << "Taper une commande" << endl;
    cin >> var;
    Interpreter I;
    I.setCommand(var);
    val=I.activeProcess();
    if (val == false) { cout << "Erreur de saisie" << endl; }
    cout << "Derniere commande en memoire : " << I.getCommand() << endl;
}
