/*!
 * \file MatrixManager.h
 * \brief class qui permet de gere les matrices.
 * \version 1.0
 */



#ifndef MATRIXMANAGER_H_INCLUDED
#define MATRIXMANAGER_H_INCLUDED

#include "sparseMatrix.h"
#include "matrixCase.h"
#include <fstream>
#include <vector>
#include <list>
using namespace std;



/*! \class MatrixManager
 * \brief class qui permet de gere les matrices.
 */
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
    void add(string const& name, string const& fileName);   // Cr�e la sparseMatrix dans la m�moire et l'ajoute avec la fonction add.
    void add(SparseMatrix const& sparseMatrix);             // Ajoute une matrix � la liste.
    void del(SparseMatrix const& sparseMatrix);             // Supprime une matrix de la liste.
	bool isSet(string const& matrixName);                   // V�rifie si une matrice existe d�j�.
	bool display(string const& name);			// Affiche une matrice.
    // MATRIX FUNCTIONS
	bool addMatrix(string const& matrixA, string const& matrixB, string const& matrixOut);	// On fait A+B et on met �a dans matrixOut.
	bool subMatrix(string const& matrixA, string const& matrixB, string const& matrixOut);	// On fait A-B et on met �a dans matrixOut.
	bool multMatrix(string const& matrixA, string const& matrixB, string const& matrixOut);	// On fait A*B et on met �a dans matrixOut.
	/*bool inverseMatrix(string const& matrixA, string const& matrixOut);			        // On inverse A et on met �a dans matrixOut.
	bool puisMatrix(string const& matrixA, unsigned int const& n, string const& matrixOut);	// On fait A^n et on met �a dans matrixOut.
	bool transpMatrix(string const& MatrixA, string const& matrixOut);			        // On fait la transpos�e de A et on met �a dans matrixOut.
	*/
	// A savoir : string &matrix[X] est le nom d'une matrice.
	// A savoir : si MatrixOut n'existe pas, on cr�e un nouveau fichier.
	// A ajouter les m�mes fonctionnalit�s pas rapport � des noms de fichier et non pas des noms de matrice. ???

	void setMatrix(SparseMatrix const& matrixOut);					// Cr�e une nouvelle matrix si jamais elle n'existe pas.
	SparseMatrix getMatrix(string const& name);					// R�cup�re une matrice gr�ce � son nom.
};


#endif // MATRIXMANAGER_H_INCLUDED
