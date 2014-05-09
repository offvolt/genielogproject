#ifndef MATRIXMANAGER_H_INCLUDED
#define MATRIXMANAGER_H_INCLUDED

#include "sparseMatrix.h"
using namespace std;
class MatrixManager
{
private:
	SparseMatrix * matrix;
public:
	MatrixManager();
	~MatrixManager();

	bool isSet(string & matrixA);						// V�rifie que la matrice A existe.

	bool addMatrix(string &matrixA, string &matrixB, string &matrixOut);	// On fait A+B et on met �a dans matrixOut.
	bool subMatrix(string &matrixA, string &matrixB, string &matrixOut);	// On fait A-B et on met �a dans matrixOut.
	bool multMatrix(string &matrixA, string &matrixB, string &matrixOut);	// On fait A*B et on met �a dans matrixOut.
	bool inverseMatrix(string &matrixA, string &matrixOut);			// On inverse A et on met �a dans matrixOut.
	bool puisMatrix(string &matrixA, unsigned int n, string &matrixOut);	// On fait A^n et on met �a dans matrixOut.
	bool transpMatrix(string &MatrixA, string &matrixOut);			// On fait la transpos�e de A et on met �a dans matrixOut.

	// A savoir : string &matrix[X] est le nom d'une matrice.
	// A savoir : si MatrixOut n'existe pas, on cr�e un nouveau fichier.
	// A ajouter les m�mes fonctionnalit�s pas rapport � des noms de fichier et non pas des noms de matrice. ???

	void setMatrix(SparseMatrix &matrixOut);					// Cr�e une nouvelle matrix si jamais elle n'existe pas.
	SparseMatrix getMatrix(string &matrix);					// R�cup�re une matrice gr�ce � son nom.
};


#endif // MATRIXMANAGER_H_INCLUDED
