#include "sparseMatrix.h"

///
/// \brief	Constructeur d'un objet SparseMatrix vide.
///
/// Ce constructeur ne se base sur aucun fichier et créer une
/// instance qui ne pourra pas être utilisée tant qu'elle ne sera
/// liée à aucun fichier.
///
SparseMatrix::SparseMatrix()
{
	fileName = "";
	name = "";
	width = 0;
	height = 0;
}

SparseMatrix::SparseMatrix(string &fileName)
{
	unsigned int value = 0;
	this->fileName = fileName;

	/// On doit récupérer les champs width et height dans le fichier texte approprié.
	fstream monFlux(fileName); 	///< Ouverture d'un fichier en lecture
	if(monFlux)
	{
   		monFlux >> value;	///< On récupère la première valeur width.
		setWidth(value);
		monFlux >> value; 	///< On récupère la deuxième valeur height.
		setHeight(value);
	}
	else
	{
   	 	cout << "ERREUR: Impossible d'ouvrir le fichier en lecture." << endl;
	}
}

SparseMatrix::~SparseMatrix(){}

bool SparseMatrix::newMatrix(unsigned int &width, unsigned int &height, string &fileName)
{

}

bool SparseMatrix::isSet()
{
	if(fileName == "")
		return false;
	return true;
}
