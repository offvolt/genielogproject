#ifndef MATRIXMANAGER_H_INCLUDED
#define MATRIXMANAGER_H_INCLUDED

#include "sparseMatrix.h"
#include "matrixCase.h"
#include <fstream>
#include <vector>
#include <list>
using namespace std;
class MatrixManager
{
private:
	list<SparseMatrix> matrix;                              // Tableau de matrices

	SparseMatrix searchMatrix(string &name);

    // UTILITIES
    static bool readCase(ifstream &file, MatrixCase & matrixCase);
    static bool writeCase(ofstream &file, MatrixCase & matrixCase);
    static bool getNextLine(ifstream &file, vector<MatrixCase> & line);
    static void getCol(unsigned int const& col, ifstream & file, vector<MatrixCase> & colV, vector<MatrixCase> & lineV);
    static int prodScal(vector<MatrixCase> & line, vector<MatrixCase> & col);
public:
    // DESTRUCTOR
	MatrixManager();
	~MatrixManager();
	void init();
	void clear();

    // MANAGER
    void add(string const& name, string const& fileName);   // Crée la sparseMatrix dans la mémoire et l'ajoute avec la fonction add.
    void add(SparseMatrix const& sparseMatrix);             // Ajoute une matrix à la liste.
    void del(SparseMatrix const& sparseMatrix);             // Supprime une matrix de la liste.
	bool isSet(string const& matrixName);                   // Vérifie si une matrice existe déjà.

    // MATRIX FUNCTIONS
	bool addMatrix(string const& matrixA, string const& matrixB, string const& matrixOut);	// On fait A+B et on met ça dans matrixOut.
	//bool subMatrix(string const& matrixA, string const& matrixB, string const& matrixOut);	// On fait A-B et on met ça dans matrixOut.
	bool multMatrix(string const& matrixA, string const& matrixB, string const& matrixOut);	// On fait A*B et on met ça dans matrixOut.
	/*bool inverseMatrix(string const& matrixA, string const& matrixOut);			        // On inverse A et on met ça dans matrixOut.
	bool puisMatrix(string const& matrixA, unsigned int const& n, string const& matrixOut);	// On fait A^n et on met ça dans matrixOut.
	bool transpMatrix(string const& MatrixA, string const& matrixOut);			        // On fait la transposée de A et on met ça dans matrixOut.
	*/
	// A savoir : string &matrix[X] est le nom d'une matrice.
	// A savoir : si MatrixOut n'existe pas, on crée un nouveau fichier.
	// A ajouter les mêmes fonctionnalités pas rapport à des noms de fichier et non pas des noms de matrice. ???

	void setMatrix(SparseMatrix const& matrixOut);					// Crée une nouvelle matrix si jamais elle n'existe pas.
	SparseMatrix getMatrix(string const& name);					// Récupère une matrice grâce à son nom.
};


#endif // MATRIXMANAGER_H_INCLUDED
