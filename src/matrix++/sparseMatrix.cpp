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
	string fileName_copy = fileName;
	bool stoped = false;

	// On crée le fichier binaire si le fichier lié est un txt.
	if(!SparseMatrix::isBinType(fileName))
	{
	    cout << "Conversion du fichier " << endl;
        SparseMatrix::replaceExtension(this->fileName);
		Converter::convertbin(fileName_copy, this->fileName);
	}

	// Ensuite on récupère hauteur et largeur du fichier
    ifstream file(this->fileName.c_str());
    if(file)
    {
	    if(file.read((char*)&value, sizeof(int)))
	    	setWidth(value);
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
	    	setFileName("");
   	 		cout << "ERREUR: Pendant la lecture du fichier. Vérifiez bien que le fichier ne soit pas corrompu." << endl;
	    	return;
	    }
	    else
	    {
	    	setFileName(this->fileName);
	    	setName(name);
	    }
    }
	else
	{
   	 	cout << "ERREUR: Impossible d'ouvrir le fichier \"" << fileName << "\" en lecture." << endl;
	}
}


void SparseMatrix::newMatrix(unsigned int const& width, unsigned int const& height, string const& fileName, string const& name)
{
    bool stoped = false;
    ofstream file (fileName.c_str(), ios::out | ios::binary);
    if(!file)
        stoped = true;
    else if(!file.write ((char *)&width, sizeof(unsigned int)))
        stoped = true;
    else if(!file.write ((char *)&height, sizeof(unsigned int)))
        stoped = true;
    if(stoped)
        cout << "ERREUR SURVENUE LORS DE L'ECRITURE DANS LE FICHIER : " << fileName << endl;
    else
    {
        this->fileName = fileName;
        this->width = width;
        this->height = height;
        this->name = name;
    }
}







// ************************* MANY FUNCTIONS ************************** //

void SparseMatrix::random(unsigned int const& min, unsigned int const& max)
{
    bool stoped = false;
    ofstream file (fileName.c_str(), ios::out | ios::binary);
    srand (time(NULL));
    if(!file)
        stoped = true;
    else if(!file.write ((char *)&width, sizeof(unsigned int)))
        stoped = true;
    else if(!file.write ((char *)&height, sizeof(unsigned int)))
        stoped = true;
    if(stoped)
    {
        cout << "ERREUR SURVENUE LORS DE L'ECRITURE DANS LE FICHIER : " << fileName << endl;
        file.close();
    }
    else
    {
        int nb0 = 0;
        int nbValue = 0;
        unsigned int value = 1;
        // On écrit la première valeur pour avoir un nb value > 0
        value = rand() % (max+1) + min;
        file.write((char *) &nb0, sizeof(unsigned int));            // Je me sers juste de nb 0 comme variable pour pouvoir ajouter un 0
        file.write((char *) &nb0, sizeof(unsigned int));
        file.write((char *) &value, sizeof(int));

        // On boucle pour générer des valeurs
        for(unsigned int i = 0; i < height; i++)
        {
            for(unsigned int j = 0; j < width ; j++)
            {
                if((double)nb0 / (double)nbValue > (double)80 / 100)            // On n'ajoute une valeur que si il y a plus de 80 % de 0.
                {
                    value = rand() % (max+1) + min;
                    file.write((char *) &i, sizeof(unsigned int));
                    file.write((char *) &j, sizeof(unsigned int));
                    file.write((char *) &value, sizeof(int));
                }
                else
                {
                    nb0 ++;
                }
                nbValue ++;
            }
        }
    }
    // Je m'en fiche un peu de mieux coder cette méthode, elle ne servira pas souvent.
}

void SparseMatrix::renameFile(string const&fileName)
{
    if(rename(this->fileName.c_str(), fileName.c_str()))
        this->fileName = fileName;
}

bool SparseMatrix::isSet() const
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
			extension_s.push_back(fileName[i]);
		}
		if(extension)
		{
			extension_s.push_back(fileName[i]);
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
			indicePointExt = i;
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
