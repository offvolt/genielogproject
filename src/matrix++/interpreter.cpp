/*!
 * \file interpreter.cpp
 * \brief Interprète les commandes entrés par l'utilisateur
 */

#include <iostream>
#include "interpreter.h"

using namespace std;

Interpreter::Interpreter()
{
  command="";
}

Interpreter::~Interpreter()
{

}

void Interpreter::setCommand(string &command)
{
    this->command=command;
}

string Interpreter::getCommand()
{
  if (command == "") { return "Aucune commande en memoire"; }
  else { return command; }
}

void Interpreter::activeProcess(MatrixManager &matrixManager)
{
    string c="";
    char l;
    int i=0,test=0, verif=0;
    while ((command[i] != '\0') && (test == 0))
    {
        while ((command[i] != '+') && (command[i] != '-') && (command[i] != '*') && (command[i] != '=') && (command[i] != '^') && (command[i] != '\0') && (test == 0))
        {
            verif=0;
            c+=command[i];
            for (l = 'a' ; l <= 'z' ; l++) { if (command[i] == l) { verif=1; } }
            for (l = 'A' ; l <= 'Z' ; l++) { if (command[i] == l) { verif=1; } }
            for (l = '0' ; l <= '9' ; l++) { if (command[i] == l) { verif=1; } }
            if (verif == 0) { test=1; cout << "Erreur, commande incorrecte" << endl; }
            i++;
        }
        if (i == 0) { test=1; cout << "Erreur, commande incorrecte" << endl; }

    }
}
