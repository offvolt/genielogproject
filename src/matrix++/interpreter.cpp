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


bool Interpreter::activeProcess(MatrixManager &matrixManager)
{
    string c="", matrix1="", matrix2="", matrixOut="", op="";
    int i=0, compt=0, n=0;
    while (command[i] != '\0')
    {
        if (!matrixName(i, c)) { return false; }
        if ((command[i] == '\0') && (matrix1 == ""))
        {
          op="aff";
          matrix1=command;
          return operation(op, matrix1, matrix2, matrixOut, n, matrixManager);
        }
        if (i == 0) { return false; }
        if (command[i] == '<') { matrixOut=c; i++; c=""; if (!verifFileName(i, c)) { return false; } op="<"; matrix1=c; }
        else
        {
            if (command[i] != '\0') { if (!sign(i)) { return false; } }
            if (command[i] == '=') { if (compt == 0) { matrixOut=c; compt++; } else { return false; } }
            else if (command[i] != '\0')
            {
                op+=command[i];
                if (op == "^") { if (!controlExp(i, op, n)) { return false; } }
            }
            if (command[i] != '=')
            {
                if ((compt == 0) || (compt == 1)) { matrix1=c; compt=2; }
                else { matrix2=c; }
            }
        }
        if (command[i] != '\0') { i++; }
        c="";
    }
    return operation(op, matrix1, matrix2, matrixOut, n, matrixManager);
}

bool Interpreter::matrixName(int &i, string &c)
{
    char l;
    int verif=0;
    while ((command[i] != '+') && (command[i] != '-') && (command[i] != '*') && (command[i] != '=') && (command[i] != '^') && (command[i] != '\0') && (command[i] != '<'))
    {
        verif=0;
        c+=command[i];
        for (l = 'a' ; l <= 'z' ; l++) { if (command[i] == l) { verif=1; } }
        for (l = 'A' ; l <= 'Z' ; l++) { if (command[i] == l) { verif=1; } }
        for (l = '0' ; l <= '9' ; l++) { if (command[i] == l) { verif=1;  } }
        if (verif == 0) { return false; }
        i++;
    }
    return true;
}

bool Interpreter::sign(int &i)
{
    if ((command[i+1] == '+') || (command[i+1] == '*') || (command[i+1] == '=') || (command[i+1] == '^') || (command[i+1] == '<')) { return false; }
    if (command[i+1] == '-')
    {
        if (command[i] != '^') { return false; }
        else { if (command[i+2] != '1') { return false; } }
    }
    return true;
}

bool Interpreter::controlExp(int &i, string &op, int &n)
{
    int verif=0;
    char l;
    string puiss="";
    istringstream iss;
    if (command[i+1] == '\0') { return false; }
    if ((command[i+1] == '-') || (command[i+1] == 't')) { i++; op+=command[i]; if (op == "^-") { i++; op+=command[i]; } }
    else
    {
        i++;
        while (command[i] != '\0')
        {
            verif=0;
            for (l = '0' ; l <= '9' ; l++) { if (command[i] == l) { verif=1; } }
            puiss+=command[i];
            i++;
            if (verif == 0) { return false; }
        }
        iss.str(puiss);
        iss >> n;
        i--;
    }
    return true;
}

bool Interpreter::verifFileName(int &i, string &c)
{
    while ((command[i] != '.') && (command[i] != '\0')) { c+=command[i]; i++; }
    if (command[i] == '\0') { return false; }
    c+=command[i]; i++;
    if (command[i] == '\0') { return false; }
    while (command[i] != '\0') { if (command[i] == '.') { return false; } else { c+=command[i]; i++; } }
    return true;
}

// ERROR : Je ne les ai toujours pas implémentées. (equalMatrix et setName)
bool Interpreter::operation(string &op, string &matrix1, string &matrix2, string &matrixOut, int &n, MatrixManager &matrixManager)
{
    //if (op == "") { if ((matrixOut != "") && (matrix1 != "")) { return matrixManager.equalMatrix(matrixOut, matrix1); } else { return false; } }
    if (op == "<") { matrixManager.add(matrixOut, matrix1); return true; }
    else if (op == "+") { return matrixManager.addMatrix(matrix1, matrix2, matrixOut); }
    else if (op == "-") { return true; /*matrixManager.subMatrix(matrix1, matrix2, matrixOut);*/ }
    else if (op == "*") { return matrixManager.multMatrix(matrix1, matrix2, matrixOut); }
    else if (op == "^-1") { return true; /*matrixManager.inverseMatrix(matrix1, matrixOut);*/ }
    else if (op == "^") { return true;/*matrixManager.puisMatrix(matrix1, n, matrixOut);*/ }
    else if (op == "^t") { return true;/*matrixManager.transpMatrix(matrix1, matrixOut);*/ }
    else if (op =="aff") { return matrixManager.display(matrix1); }
    return false;
}
