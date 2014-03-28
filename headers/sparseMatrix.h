#ifndef H_SPARSEMATRIX
#define H_SPARSEMATRIX

#include <string>

using namespace std;
class SparseMatrix
{
private:
	string fileName;
	string name;
	unsigned int width;
	unsigned int height;

public:
	SparseMatrix();						// Constructeur et mise à 0.
	~SparseMatrix(string &fileName);			// Constructure faisant référence à un fichier, elle en récupère ses champs.
	bool newMatrix(unsigned int &width, unsigned int &height, string &fileName);	// Crée une nouvelle matrice ayant pour nom du fichier: fileName.
	void random();						// On remplie la matrice aléatoirement. 
	void renameFile(string &fileName);			// Renomme le fichier.

	// ACCESSEURS MUTATEURS
	unsigned int getWidth()const;				// Récupère la largeur.
	unsigned int getHeight()const;				// Modifie la largeur.
	string getFileName()const;					// On récupère le nom du fichier.
	string getName() const;					// Récupère le nom.	

	void setFileName(string &fileName);			// On modifie le nom du fichier et on récupère ses valeurs.
	void setName(string &fileName);				// On modifie le nom de la matrice.
};
