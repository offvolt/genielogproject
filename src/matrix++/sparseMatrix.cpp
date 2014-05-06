#include "sparseMatrix.h"


// ******************** CONSTRUCTORS AND DESTRUCTORS *************************** //
SparseMatrix::SparseMatrix()
{
	fileName = "";
	name = "";
	width = 0;
	height = 0;
}

SparseMatrix::SparseMatrix(string const& name, string const&fileName)
{
	init(name, fileName);
}

SparseMatrix::~SparseMatrix(){}

void SparseMatrix::init(string const& name, string const& fileName)
{
	unsigned int value = 0;
	this->fileName = fileName;
	bool stoped = false;

	// On crée le fichier binaire s'il est en txt
	string copyFileName = fileName;
	if(!SparseMatrix::isTypeBin(fileName))
	{
		Converter::convert(fileName, SparseMatrix::replaceExtension(copyFileName));
	}

	// Ensuite on récupère hauteur et largeur du fichier
    ifstream file(copyFileName);
    if(file)
    {
	    if(file.read((char*)&value, sizeof(int)))
	    	setwidth(value);
	    else
	    	stoped = true;
	    if(file.read((char*)&value, sizeof(int)) && !stoped)
	    	setHeight(value);
	    else
	    	stoped = true;
	    if(stoped)
	    {
	    	setWidth(0);
	    	setHeight(0);
   	 		cout << "ERREUR: Pendant la lecture du fichier. Vérifiez bien que le fichier ne soit pas corrompu." << endl;
	    	return;
	    }
	    else
	    {
	    	setFileName(copyFileName);
	    	setName(name);
	    }
    }
	else
	{
   	 	cout << "ERREUR: Impossible d'ouvrir le fichier \"" << fileName << "\" en lecture." << endl;
	}	
}


bool SparseMatrix::newMatrix(unsigned int &width, unsigned int &height, string &fileName)
{

	// On doit d'abord vérifier si le nom du fichier existe.

	// Si non, on crée ce fichier.

	// On y écrit le width et le height

	// Cette fonction ne sera que très peu utilisée !
}







// ************************* MANY FUNCTIONS ************************** //

void SparseMatrix::random(unsigned const& int min, unsigned int const& max)
{

	// On prend le fichier 

	// On le vide 

	// On boucle sur height
		// On boucle sur width
			// Si on n'est pas en dessous des 80% de 0
			// On prend une valeur aléatoire et on l'ajoute à cette case.
	// Fin de la boucle

	// Pas obligé de la faire mais permet de tester

}

void SparseMatrix::renameFile(string const&fileName)
{

    rename(this->fileName.c_str(), fileName.c_srt());
}

bool SparseMatrix::isSet()
{
	if(fileName == "")
		return false;
	return true;
}






// ************************** ACCESSORS AND MUTATORS ************************* //

unsigned int SparseMatrix::getWidth()const
{
	return width;
}
	
unsigned int SparseMatrix::getHeight()const
{
	return height;
}	

string SparseMatrix::getFileName()const
{
	return fileName;
}

string SparseMatrix::getName() const
{
	return name;
}


void SparseMatrix::setFileName(string const& fileName)
{
	this->fileName = fileName; 
	/* 
		Il faut aujouter le fait que l'on doit lire le nouveau fichier associé.
	*/
}

void SparseMatrix::setName(string const& name)
{
	this->name = name;
}





// ************************ STATIC UTILITIES *************************** //
bool SparseMatrix::isBinType(string const& fileName)
{
	string binExtension = ".mat";

	bool extension = false;
	string extension_s = "";

	for(unsigned int i = 0; i < fileName.size(); i++)
	{
		if(fileName[i] == '.')
		{
			extension = true;
			extension_s.clear();
			extension_s.pushback(fileName[i]);
		}
		if(extension)
		{
			extension_s.pushback(fileName[i]);
		}
	}
	if(extension_s == binExtension);
}

void SparseMatrix::replaceExtension(string &fileName)
{
	string binExtension = ".mat";

	unsigned int indicePointExt = 0;

	for(unsigned int i = 0; i < fileName.size(); i++)
	{
		if(fileName[i] == '.')
		{
			indicePointExt = 0;
		}
	}

	if(indicePointExt == 0)												// S'il n'y a pas d'extension
		fileName = fileName + binExtension;
	else																// Sinon on remplace.
		fileName = fileName.substr(0, indicePointExt) + binExtension;

}




// ******************** PRIVATE SETTERS ************************* //
void SparseMatrix::setWidth(unsigned int const& width)
{
	this->width = width;
}

void SparseMatrix::setHeight(unsigned int const& height)
{
	this->height = height;
}