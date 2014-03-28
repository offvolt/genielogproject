#include <iostream>
#include "interpreter.h"

using namespace std;

Interpreter::Interpreter()
{
  command="";
}

Interpreteur::~Interpreter()
{
  
}

void Interpreter::setCommand(string &command)
{
  this.command=command;
}

string Interpreter::getCommand()
{
  if (command == "") { return "Aucune commande en memoire" }
  else { return command; }
}

void Interpreter::activeProcess(MatrixManager &matrixManager)
{
  
}
