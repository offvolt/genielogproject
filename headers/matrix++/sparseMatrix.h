/// \file sparseMatrix.h
/// \brief Header de la classe SparseMatrix
/// Cette classe est notre entité de base sur laquelle nous
/// allons travailler. Elle permet de faire un lien avec un 
/// fichier sparseMatrix.
/// \author Mathias.Q
/// \date 11/04/2014


#ifndef H_SPARSEMATRIX
#define H_SPARSEMATRIX

#include <fstream>
#include <iostream>
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

	/// \fn SparseMatrix()
	/// \brief Constructeur vide
	///
	/// Un constructeur qui ne lit pas l'objet à un fichier. 
	/// L'instance ne vaut donc rien, c'est un objet vide,
	/// non paramétré.
	/// \sa SparseMatrix(string const& fileName)

	SparseMatrix();	
	
	/// \fn SparseMatrix(string const& fileName)
	/// \brief Constructeur 
	///
	/// \sa SparseMatrix()
	/// \param fileName le nom du fichier.
	///
	SparseMatrix(string const& fileName);				///< Constructure faisant référence à un fichier, elle en récupère ses champs.
	
	/// \fn ~SparseMatrix()
	/// \brief Destructeur
	///
	/// Un destructeur qui n'a pas grande utilité ici.
	///
	~SparseMatrix();

	/// \fn bool newMatrix(unsigned int const& width, unsigned int const& height, string const& fileName)
	/// \brief Création d'une nouvelle matrice.
	///
	/// Va créer un nouveau fichier et initialiser les valeurs 
	/// width et heigth. 
	/// Attention : On ne crée rien si le fichier existe déjà.
	/// \param width la largeur de la matrice.
	/// \param height la hauteur de la matrice.
	/// \param fileName le nom du fichier que l'on veut créer.
	
	bool newMatrix(unsigned int const& width, unsigned int const& height, string const& fileName);	///< Crée une nouvelle matrice ayant pour nom du fichier: fileName.
	
	/// \fn void random(unsigned int const& min, unsigned int const& max)
	/// \brief Remplissage random de la matrice.
	///
	/// Va remplir la matrice de manière aléatoire avec des valeurs
	/// comprises entre min et max.
	/// Attention : Remplace les valeurs déjà existantes.
	/// \param min la valeur minimale.
	/// \param max la valeur maximale.
	
	void random(unsigned const& int min, unsigned int const& max);						///< On remplie la matrice aléatoirement. 
	
	/// \fn void renameFile(string const& fileName)
	/// \brief Renommer le fichier
	///
	/// Renomme le nom du fichier sur le disque dur. A ne pas
	/// confondre avec setName qui correspond au nom de la 
	/// matrice dans le programme.
	/// \param fileName nouveau nom du fichier.
	
	void renameFile(string const&fileName);			///< Renomme le fichier.
	
	/// \fn bool isSet() const
	/// \brief Vérifier si la matrice est configurée
	///
	/// Vérifie si la matrice est bien configurée, soit si
	/// elle est liée à un fichier. Si tel est le cas, 
	/// retourne vrai, sinon retourne faux. 

	bool isSet() const;	

/************************** ACCESSORS AND MUTATORS *************************/
	
	/// \fn unsigned int getWidth() const
	/// \brief Retourne la largeur.
	///
	/// Retourne la largeur de la matrice.
	///
	unsigned int getWidth()const;				///< Récupère la largeur.
	
	/// \fn unsigned int getHeight() const
	/// \brief Retourne la hauteur
	///
	/// Retourne la hauteur de la matrice.

	unsigned int getHeight()const;				///< Modifie la largeur.
	
	/// \fn string getFileName() const
	/// \brief Retourne le nom du fichier.
	///
	/// Retourne le nom du fichier. 
	/// A ne pas confondre avec le nom de la matrice.

	string getFileName()const;				///< On récupère le nom du fichier.
	
	/// \fn string getName() const
	/// \brief Retourne la nom de la matrice.
	///
	/// Retourne le nom de la matrice. 
	/// A ne pas confondre avec le nom du fichier.

	string getName() const;					///< Récupère le nom.	

	/// \fn void setFileName(string const& fileName)
	/// \brief Modifie le nom du fichier.
	///
	/// Modifie le nom du fichier. Il vérifie aussi si
	/// l'extension est bonne.
	/// \param fileName le nouveau nom du fichier.
	
	void setFileName(string const& fileName);			///< On modifie le nom du fichier et on récupère ses valeurs.
	
	/// \fn void setName(string const& name)
	/// \brief Modifie le nom de la matrice
	///
	/// Modifie le nom de la matrice. 
	/// \param name le nouveau nom de la matrice.
	
	void setName(string const& name);				///< On modifie le nom de la matrice.
private:

	/// \fn void setWidth(unsigned int const& width)
	/// Modifie la largeur
	///
	/// Modifie la largeur de la matrice. Celle
	/// -ci n'est utilisable que par la classe 
	/// car elle ne permet que sa configuration.
	/// L'utilisateur n'y a pas accès.
	/// \param width la nouvelle largeur de la matrice.
	
	void setWidth(unsigned int const& width);
	
	/// \fn void setHeight(unsigned int const& height)
	/// \brief Modifie la hauteur
	///
	/// Modifie la hauteur de la matrice. Celle
	/// -ci n'est utilisable que par la classe
	/// car elle ne permet que sa configuration.
	/// L'utilisateur n'y a pas accès.
	/// \param height la nouvelle hauteur de la matrice.
	
	void setHeight(unsigned int const& height);
};
