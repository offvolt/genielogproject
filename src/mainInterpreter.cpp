#include <iostream>
#include "interpreter.h"
#include "matrixManager.h"

using namespace std;

int main()
{
	MatrixManager m;
	SparseMatrix m1("A", "mat.txt");
	SparseMatrix m2("B", "mat2.txt");
	m.add(m1);
	m.add(m2);
	bool val;
    	string var="";
    	cout << "Taper une commande" << endl;
   	cin >> var;
    	Interpreter I;
   	I.setCommand(var);
    	val=I.activeProcess(m);
    	if (val == false) { cout << "Erreur de saisie" << endl; }
    		cout << "Derniere commande en memoire : " << I.getCommand() << endl;

    string tmp = ".tmp";
    string txt = ".txt";
    Converter::convert(tmp, txt);
}
