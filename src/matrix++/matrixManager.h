#ifndef H_MATRIXMANAGER
#define H_MATRIXMANAGER

using namespace std;
class MatrixManager
{
private:
	SparseMatrix * matrix;
public:
	MatrixManager();
	~MatrixManager();

	bool isSet(string & matrixA);						// Vérifie que la matrice A existe.
	
	bool addMatrix(string &matrixA, string &matrixB, string &matrixOut);	// On fait A+B et on met ça dans matrixOut.
	bool subMatrix(string &matrixA, string &matrixB, string &matrixOut);	// On fait A-B et on met ça dans matrixOut.
	bool multMatrix(string &matrixA, string &matrixB, string &matrixOut);	// On fait A*B et on met ça dans matrixOut.
	bool inverseMatrix(string &matrixA, string &matrixOut);			// On inverse A et on met ça dans matrixOut.
	bool puisMatrix(string &matrixA, unsigned int n, string &matrixOut);	// On fait A^n et on met ça dans matrixOut.
	bool transpMatrix(string &MatrixA, string &matrixOut);			// On fait la transposée de A et on met ça dans matrixOut.

	// A savoir : string &matrix[X] est le nom d'une matrice.
	// A savoir : si MatrixOut n'existe pas, on crée un nouveau fichier.
	// A ajouter les mêmes fonctionnalités pas rapport à des noms de fichier et non pas des noms de matrice. ???
	
	void setMatrix(ParseMatrix &matrixOut);					// Crée une nouvelle matrix si jamais elle n'existe pas.
	ParseMatrix getMatrix(string &matrix);					// Récupère une matrice grâce à son nom.
};

