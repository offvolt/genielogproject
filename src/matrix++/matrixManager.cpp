#include "matrixManager.h"

MatrixManager::MatrixManager()
{
}
MatrixManager::~MatrixManager()
{
}
void MatrixManager::clear()
{
    matrix.clear();
}

// ********************** MANAGER ********************************* //

void MatrixManager::add(string const& name, string const& fileName)
{
    SparseMatrix sparseMatrix(name, fileName);
    add(sparseMatrix);
}
void MatrixManager::add(SparseMatrix const& sparseMatrix)
{
    if(sparseMatrix.getName() != "" && !isSet(sparseMatrix.getName()))
    {
        matrix.push_back(sparseMatrix);
    }
}
void MatrixManager::del(SparseMatrix const& sparseMatrix)
{
    for(list<SparseMatrix>::iterator it = matrix.begin(); it != matrix.end(); it++)
    {
        if(sparseMatrix.getName() == it->getName())
        {
            matrix.erase(it);
        }
    }
}

bool MatrixManager::isSet(string const& matrixName)
{
    for(list<SparseMatrix>::iterator it = matrix.begin(); it != matrix.end(); it++)
    {
        if(it->getName() == matrixName)
            return true;
    }
    return false;
}









// ********************** MATRIX FUNCTIONS ********************************* //
bool MatrixManager::addMatrix(string const& matrixA, string const& matrixB, string const& matrixOut)
{

// GET THE WITH AND HEIGHT
	SparseMatrix mA = getMatrix(matrixA),
                 mB = getMatrix(matrixB),
   		 mC;
        if(matrixOut != "");
		mC = getMatrix(matrixOut);

// CASE ERROR : WIDTH AND HEIGHT
    if(mA.getWidth() != mB.getWidth() || mA.getHeight() != mB.getHeight())
    {
        cout << "ERROR : " << endl;
        if(mA.getWidth() != mB.getWidth())
            cout << matrixA << "->width(" << mA.getWidth() << ") != " << matrixB << "->width(" << mB.getWidth() << ")" << endl;
        if(mA.getHeight() != mB.getHeight())
            cout << matrixA << "->height(" << mA.getHeight() << ") != " << matrixB << "->height(" << mB.getHeight() << ")" << endl;
        return false;
    }

// READING FILE AND VARIABLES
    ifstream matrixA_file(mA.getFileName().c_str(), ios::binary);
    ifstream matrixB_file(mB.getFileName().c_str(), ios::binary);
    ofstream matrixC_file;
    if(matrixOut == "")
        matrixC_file.open(".tmp", ios::binary);
    else
        matrixC_file.open(mC.getFileName().c_str(), ios::binary);

    MatrixCase cA,
               cB,
               cC;

    unsigned int width = mA.getWidth(),
                 height = mA.getHeight();

    bool         stopReadA = false,
                 stopReadB = false,
                 readA = false,
                 readB = false;

// NO ERROR
    if(matrixA_file && matrixB_file && matrixC_file)
    {
            cout << "WRITING !" << endl;
        matrixA_file.seekg(8);
        matrixB_file.seekg(8);

        MatrixManager::readCase(matrixA_file, cA);
        MatrixManager::readCase(matrixB_file, cB);

        matrixC_file.write((char*) &width, sizeof(unsigned int));
        matrixC_file.write((char*) &height, sizeof(unsigned int));

        readA = false;
        readB = false;
        while(!stopReadA || !stopReadB)
        {
        // OPERATION
            if(cA.getI() == cB.getI() && cA.getJ() == cB.getJ())                        // On fait l'addition !
            {
                readA = true;
                readB = true;
                cC.setValue(cA.getValue() + cB.getValue());
                cC.setI(cA.getI());
                cC.setJ(cA.getJ());
            }
            else if(cA.getI() < cB.getI() || (cA.getI() == cB.getI() && cA.getJ() < cB.getJ()))       // Cas où A est traité
            {
                readA = true;
                cC.setValue(cA.getValue());
                cC.setI(cA.getI());
                cC.setJ(cA.getJ());
            }

            else if(cB.getI() < cA.getI() || (cB.getI() == cA.getI() && cB.getJ() < cA.getJ()))       // Cas où B est traité
            {
                readB = true;
                cC.setValue(cB.getValue());
                cC.setI(cB.getI());
                cC.setJ(cB.getJ());
            }

        // WRITING VALUE
            MatrixManager::writeCase(matrixC_file, cC);

        // READ MAT A
            if(!(readA && MatrixManager::readCase(matrixA_file, cA)))
                stopReadA = true;

        // READ MAT B
            if(!(readB && MatrixManager::readCase(matrixB_file, cB)))
                stopReadB = true;
        }
        matrixA_file.close();
        matrixB_file.close();
        matrixC_file.close();
    }


// ERROR READING
    else
    {
        if(!matrixA_file)
            cout << "Un probleme est survenu lors de l'ouverture du fichier : " << matrixA << endl;
        if(!matrixB_file)
            cout << "Un probleme est survenu lors de l'ouverture du fichier : " << matrixB << endl;
        if(!matrixC_file)
            cout << "Un probleme est survenu lors de l'ouverture du fichier : " << ".tmp"<< endl;
        return false;
    }
    return true;

}	// On fait A+B et on met ça dans matrixOut.


















/*bool MatrixManager::subMatrix(string const& matrixA, string const& matrixB, string const& matrixOut)
{

return true;

}	// On fait A-B et on met ça dans matrixOut.
*/













bool MatrixManager::multMatrix(string const& matrixA, string const& matrixB, string const& matrixOut)
{

// GET THE WITH AND HEIGHT
	SparseMatrix mA = getMatrix(matrixA),
                 mB = getMatrix(matrixB),
  		mC;
	if(matrixOut == "")
		mC = getMatrix(matrixOut);
// CASE ERROR : WIDTH AND HEIGHT
    if(mA.getWidth() != mB.getHeight())
    {
        cout << "ERROR : " << endl;
        cout << matrixA << "->width(" << mA.getWidth() << ") != " << matrixB << "->height(" << mB.getWidth() << ")" << endl;
        return false;
    }

// READING FILE
    ifstream matrixA_file(mA.getFileName().c_str(), ios::binary);
    ifstream matrixB_file(mB.getFileName().c_str(), ios::binary);
    ofstream matrixC_file;
    if(matrixOut == "")
        matrixC_file.open(".tmp", ios::binary);
    else
        matrixC_file.open(mC.getFileName().c_str(), ios::binary);
    // c pour current
    MatrixCase cA,
               cB,
               cC;

   // unsigned int    cI,
     //               cY;
    int          width = mA.getWidth(),
                 height = mA.getHeight();

    vector<MatrixCase> lineA;
    vector<MatrixCase> colB;



// NO ERROR
    if(matrixA_file && matrixB_file && matrixC_file)
    {
        matrixA_file.seekg(8);
        matrixB_file.seekg(8);

        matrixC_file.write((char*) &width, sizeof(unsigned int));
        matrixC_file.write((char*) &height, sizeof(unsigned int));

        while(MatrixManager::getNextLine(matrixA_file, lineA))
        {
            MatrixCase cC;
            if(lineA.size() > 0)
            {
                for(unsigned int j = 0 ; j < mB.getWidth(); j++)
                {
                    MatrixManager::getCol(j, matrixB_file, colB, lineA);
                    cC.setValue(prodScal(lineA, colB));
                    if(cC.getValue() != 0)
                    {
                        cC.setI(lineA.begin()->getI());
                        cC.setJ(j);
                        MatrixManager::writeCase(matrixC_file, cC);
                    }

                }

            }
        }
        matrixA_file.close();
        matrixB_file.close();
        matrixC_file.close();
    }

// ERROR READING
    else
    {
        if(!matrixA_file)
            cout << "Un probleme est survenu lors de l'ouverture du fichier : " << matrixA << endl;
        if(!matrixB_file)
            cout << "Un probleme est survenu lors de l'ouverture du fichier : " << matrixB << endl;
        if(!matrixC_file)
            cout << "Un probleme est survenu lors de l'ouverture du fichier : " << ".tmp"<< endl;
        return false;
    }
    return true;

}// On fait A*B et on met ça dans matrixOut.
bool inverseMatrix(string const& matrixA, string const& matrixOut)
{
    return true;
}		        // On inverse A et on met ça dans matrixOut.
bool puisMatrix(string const& matrixA, unsigned int const& n, string const& matrixOut)
{
    return true;
}	// On fait A^n et on met ça dans matrixOut.
bool transpMatrix(string const& MatrixA, string const& matrixOut)
{
    return true;
}		        // On fait la transposée de A et on met ça dans matrixOut.



bool MatrixManager::display(string const& name)
{
    cout << "AFFICHAGE " << std::endl;
	SparseMatrix mA = getMatrix(name);

    mA.getFileName();
    ifstream matrixA_file(mA.getFileName().c_str(), ios::binary);

    if(matrixA_file)
    {
        MatrixCase matrixCase;

        cout << "MATRICE [" << mA.getName() << "]" << std::endl;
        cout << "Hauteur : " << mA.getHeight() << std::endl;
        cout << "Largeur : " << mA.getWidth() << std::endl;
        matrixA_file.seekg(8);
        while(readCase(matrixA_file, matrixCase))
        {
            std::cout << matrixCase.getI() << " , " << matrixCase.getJ() << " => " << matrixCase.getValue() << std::endl;
        }
    }
    else
        return false;
    return true;

}
void MatrixManager::setMatrix(SparseMatrix const&matrixOut)
{

}

SparseMatrix MatrixManager::getMatrix(string const& name)
{
    SparseMatrix result;

    for(list<SparseMatrix>::iterator it = matrix.begin(); it != matrix.end(); it++)
    {
        if(it->getName() == name)
            return *it;
    }
    return result;
}




// UTILITIES
bool MatrixManager::readCase(ifstream &file, MatrixCase & matrixCase)
{
    unsigned int i = 0;
    unsigned int j = 0;
    int value = 0;
    if( file.read((char*) &i, sizeof(unsigned int)) &&
        file.read((char*) &j, sizeof(unsigned int)) &&
        file.read((char*) &value, sizeof(int)) )
    {
        matrixCase.setI(i);
        matrixCase.setJ(j);
        matrixCase.setValue(value);
        return true;
    }
    return false;
}

bool MatrixManager::writeCase(ofstream &file, MatrixCase & matrixCase)
{
    unsigned int i = matrixCase.getI();
    unsigned int j = matrixCase.getJ();
    int value = matrixCase.getValue();
    if( file.write((char*) &i, sizeof(unsigned int)) &&
        file.write((char*) &j, sizeof(unsigned int)) &&
        file.write((char*) &value, sizeof(int)) )
    {
        matrixCase.setI(i);
        matrixCase.setJ(j);
        matrixCase.setValue(value);
        return true;
    }
    return false;

}
bool MatrixManager::getNextLine(ifstream &file, vector<MatrixCase> & line)
{
    line.clear();
    MatrixCase cA;
    if(!MatrixManager::readCase(file, cA))
        return false;
    unsigned int cI = cA.getI();
    line.push_back(cA);
    while(MatrixManager::readCase(file, cA) && cI == cA.getI())
    {
        line.push_back(cA);
    }
    if(cI != cA.getI())
    {
	int tellG = file.tellg();
	int constInt = 12;
        file.seekg(tellG - constInt);
    }
    return true;
}


void MatrixManager::getCol(unsigned int const& col, ifstream & file, vector<MatrixCase> & colV, vector<MatrixCase> & lineV)
{
    colV.clear();
    file.seekg(8, ios::beg);
    MatrixCase cA;
    vector<MatrixCase>::iterator itLine = lineV.begin();
    while(MatrixManager::readCase(file, cA))
    {
        if(cA.getJ() == col)
        {
            while(itLine != lineV.end() && cA.getI() > itLine->getJ())
            {
                itLine ++;
            }
            if(itLine != lineV.end() && itLine->getJ() == cA.getI())
            {
                colV.push_back(cA);
            }
        }
    }
    file.clear();
}



int MatrixManager::prodScal(vector<MatrixCase> & line, vector<MatrixCase> & col)
{
    int sum = 0;
    MatrixCase cLine,
               cCol;
    vector<MatrixCase>::iterator itLine = line.begin();
    vector<MatrixCase>::iterator itCol = col.begin();
    while(itLine != line.end() && itCol != col.end())
    {
        cLine = *itLine;
        cCol = *itCol;
        if(cLine.getJ() == cCol.getI())
        {
            sum += cLine.getValue() * cCol.getValue();
            itLine ++;
            itCol ++;
        }
        else if(cLine.getJ() < cCol.getI())
            itLine ++;
        else
            itCol ++;
    }
    return sum;
}
