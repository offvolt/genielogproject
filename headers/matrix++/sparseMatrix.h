#ifndef SPARSEMATRIX_H_INCLUDED
#define SPARSEMATRIX_H_INCLUDED

/*! \file sparseMatrix.h
 *  \brief Header de la classe SparseMatrix
 *  Cette classe est notre entité de base sur laquelle nous
 *  allons travailler. Elle permet de faire un lien avec un
 *  fichier sparseMatrix.
 *  \author Mathias.Q
 *  \date 11/04/2014
 */

#include <fstream>
#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>       /* time */

#include "converter.h"

using namespace std;
class SparseMatrix
{
private:
    static string binExt;
	string fileName;
	string name;
	unsigned int width;
	unsigned int height;

public:

// ******************** CONSTRUCTORS AND DESTRUCTORS *************************** //
	/*!
	 *	\fn SparseMatrix()
	 *	\brief Constructeur vide
	 *
	 *	Un constructeur qui ne lit pas l'objet à un fichier.
	 *	L'instance ne vaut donc rien, c'est un objet vide,
	 *	non paramétré.
	 *	\sa SparseMatrix(string const& fileName)
	 */
	SparseMatrix();

	/*!
	 *	\fn SparseMatrix(string const& fileName)
	 *	\brief Constructeur
	 *
	 * Constructeur faisant référence à un fichier, elle en récupère ses champs.
	 *
	 *	\sa SparseMatrix()
	 *	\param fileName le nom du fichier.
	 */
	SparseMatrix(string const& name, string const&fileName);

	/*!
	 * \fn ~SparseMatrix()
	 * \brief Destructeur
	 *
	 * Un destructeur qui n'a pas grande utilité ici.
	 */
	~SparseMatrix();

	/*!
	 *	\fn init(string const& fileName)
	 *	\brief Initialisateur
	 *
	 * Permet d'initialiser la matrice en la liant à un fichier s'il existe déjà.
	 */
	void init(string const& name, string const& fileName);

	/*!
	 *	\fn void newMatrix(unsigned int const& width, unsigned int const& height, string const& fileName, string const& name)
	 *	\brief Création d'une nouvelle matrice.
	 *
	 *	Va créer un nouveau fichier et initialiser les valeurs
	 *	width et heigth.
	 *	Attention : Remplace le fichier si déjà existant !
	 *	\param width la largeur de la matrice.
	 *	\param height la hauteur de la matrice.
	 *	\param fileName le nom du fichier que l'on veut créer.
	 */
	void newMatrix(unsigned int const& width, unsigned int const& height, string const& fileName, string const& name);

// ************************* MANY FUNCTIONS ************************** //
	/*!
	 *	\fn void random(unsigned int const& min, unsigned int const& max)
	 *	\brief Remplissage random de la matrice.
	 *
	 *	Va remplir la matrice de manière aléatoire avec des valeurs
	 *	comprises entre min et max.
	 *	Attention : Remplace les valeurs déjà existantes.
	 *  Attention : Le random ne respecte pas toutes les règles d'une matrice creuse.
	 *
	 *	\param min la valeur minimale.
	 *	\param max la valeur maximale.
	 */
	void random(unsigned int const& min, unsigned int const& max);

	/*!
	 *	\fn void renameFile(string const& fileName)
	 *	\brief Renommer le fichier
	 *
	 *	Renomme le nom du fichier sur le disque dur. A ne pas
	 *	confondre avec setName qui correspond au nom de la
	 *	matrice dans le programme.
	 *	\param fileName nouveau nom du fichier.
	 */
	void renameFile(string const&fileName);

	/*!
	 *	\fn bool isSet() const
	 *	\brief Vérifier si la matrice est configurée
	 *
	 * 	Vérifie si la matrice est bien configurée, soit si
	 *	elle est liée à un fichier. Si tel est le cas,
	 *	retourne vrai, sinon retourne faux.
	 *	\return Retourne vrai si la matrice est bien configurée, sinon faux.
	 */
	bool isSet() const;

// ************************** ACCESSORS AND MUTATORS ************************ //
	/*!
	 *	\fn unsigned int getWidth() const
	 *	\brief Retourne la largeur.
	 *
	 *	Retourne la largeur de la matrice.
	 *	\return La largeur de la matrice.
	 */
	unsigned int getWidth()const;

	/*!
	 *	\fn unsigned int getHeight() const
	 *	\brief Retourne la hauteur de la matrice.
	 *	\return La hauteur de la matrice.
	 */
	unsigned int getHeight()const;

	/*!
	 *	\fn string getFileName() const
	 *	\brief Retourne le nom du fichier.
	 *
	 *	Retourne le nom du fichier.
	 *	A ne pas confondre avec le nom de la matrice.
	 *	\return Le nom du fichier.
	 */
	string getFileName()const;

	/*!
	 *	\fn string getName() const
	 *	\brief Retourne la nom de la matrice.
	 *
	 *	Retourne le nom de la matrice.
	 *	A ne pas confondre avec le nom du fichier.
	 *	\return Le nom de la matrice.
	 */
	string getName() const;

	/*!
	 *	\fn string getBinExt() const
	 *	\brief Retourne l'extension binaire des fichiers.
	 *
	 *	Retourne l'extension binaire des fichiers.
	 *  C'est en fait une configuration.
	 *	\return L'extension binaire des fichiers.
	 */
	string getBinExt() const;

	/*
	 *	\fn void setFileName(string const& fileName)
	 *	\brief Modifie le nom du fichier.
	 *
	 *	Modifie le nom du fichier. Il vérifie aussi si
	 *	l'extension est bonne.
	 *	\param fileName le nouveau nom du fichier.
	 */
	void setFileName(string const& fileName);

	/*
	 *	\fn void setName(string const& name)
	 *	\brief Modifie le nom de la matrice
	 *
	 *	Modifie le nom de la matrice.
	 *	\param name le nouveau nom de la matrice.
	 */
	void setName(string const& name);

	/*
	 *	\fn static void setBinExt(string const& binExt)
	 *	\brief Modifie l'extension des fichiers binaire
	 *
	 *	Modifie l'extension la norme de l'extension des fichiers binaire.
	 *
	 *	\param L'extension d'un fichier binaire.
	 */
	static void setBinExt(string const& binExt);

// ************************ STATIC UTILITIES *************************** //
	/*
	 *	\fn static void isBinType(string const& filename)
	 *	\brief Vérifier que c'est un type bin.
	 *
  	 * Permet de vérifier si le fichier est de type bin ou non. S'il ne l'est pas
  	 * il est alors considéré comme un type texte.
  	 *
  	 */
	static bool isBinType(string const& fileName);

	/*
	 *	\fn static void replaceExtension(string &fileName);
	 *	\brief Vérifier que c'est un type bin.
	 *
	 * Permet de remplacer l'extension d'un filename donné. Le remplace
	 * directement dans l'argument.
  	 *
  	 */
	static void replaceExtension(string &fileName);

private:

// ******************** PRIVATE SETTERS ************************* //
	/*
	 *	\fn void setWidth(unsigned int const& width)
	 *	\brief Modifie la largeur
	 *
	 *	Modifie la largeur de la matrice. Celle
	 *	-ci n'est utilisable que par la classe
	 *	car elle ne permet que sa configuration.
	 *	L'utilisateur n'y a pas accès.
	 *	\param width la nouvelle largeur de la matrice.
	 */
	void setWidth(unsigned int const& width);

	/*
	 *	\fn void setHeight(unsigned int const& height)
	 *	\brief Modifie la hauteur
	 *
	 *	Modifie la hauteur de la matrice. Celle
	 *	-ci n'est utilisable que par la classe
	 *	car elle ne permet que sa configuration.
	 *	L'utilisateur n'y a pas accès.
	 *	\param height la nouvelle hauteur de la matrice.
	 */
	void setHeight(unsigned int const& height);


};

#endif // SPARSEMATRIX_H_INCLUDED
