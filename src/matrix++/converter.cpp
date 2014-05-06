#include <iostream>
#include <string>
#include "Converter.h"
#include <fstream>

using namespace std;

#include <vector>



void Converter::convertbin(string &fileName1,string &fileName2)
{
    
    string caractere; // chiffre uniquement de 0 a 9
    int i(0),x(1),n;
    int num=0;
    
    ifstream fichier(fileName1);
    ofstream fichier2 (fileName2, ios::out | ios::binary);
    
    while(fichier.get(caractere[i]))
    {
        vector<int> tab(0);
        num=0;
        x=1;
        if(caractere[i]!=';' && caractere[i]!='\n' && caractere[i]!=' ') // on peut faire a chaque espace
        {
            n=caractere[i] -'0';
            tab.push_back(n);
            i++;
            while(fichier.get(caractere[i]) && caractere[i]!=';' && caractere[i]!='\n' && caractere[i]!=' ')
            {
                n=caractere[i] -'0';
                tab.push_back(n);
                i++;
            }
            for(int z=tab.size()-1 ; z >= 0; z--)
            {

                    num += tab[z]*x;   //On additionne toutes les notes
                    // en gros on fait 1*10 + 2*100 + 3*1000 = 3210
                    x*=10;
            }
            //cout<<num<<","; // afficher le fichier 1
            //fichier2 <<num+2<<" "; // Ecrire dans le fichier
            fichier2.write ((char *)&num, sizeof(int));
        }
        /* ------ A utiliser pour l'affichage de fichier1 ------ */
        /*
        cout<<num<<","; // afficher le fichier 1
        if(caractere[i]=='\n')
        {
            //fichier2<<endl; // Sauter une ligne dans le fichier
            cout<<endl;
        }
        */
        i=0;
    }

     fichier.close();
     fichier2.close();
}


void Converter::convert(string &fileName1,string &fileName2)
{

    ifstream fichier(fileName1);
    ofstream fichier2(fileName2);
    int a;
    int h(0),m(0);
    while(fichier.read ((char *)&a, sizeof(int)))
    {
        if(h==0)
        {
            fichier2 <<a<<";";
        }
        else if(h==1)
        {
            fichier2 <<a;
            fichier2<<endl;
            m=h+3;
        }
        else if(m==h)
        {
            fichier2 <<a;
            fichier2<<endl;
            m=h+3;
        }
        else fichier2 <<a<<";";
        
        h++;
    }

    fichier.close();
    fichier2.close();
    
}


bool Converter::verif(string &fileName)
{
    ifstream fichier(fileName);
    string nom="tmp.txt";
    
    Converter::convertbin(fileName,nom); // Creation d'un fichier temporaire en binaire
    ifstream fichiertmp(nom);
    
    
    int a;
    int val(0),m(2),m2(3),m3(4),x(0);
    
    vector<int> tab(0);
    
    while(fichiertmp.read ((char *)&a, sizeof(int)) )
    {
        tab.push_back(a); // Recupere toutes les données de la matrice
    }

    int sizeTab=tab.size();
    vector<int> tabLigne(0);
    vector<int> tabColonne(0);
    vector<int> tabValeur(0);
    
    for(int i=2 ; i<sizeTab; i++)
    {
        if(m==i)
        {
            tabLigne.push_back(tab[i]); // Stocke tous les indices des lignes
            m=m+3;
        }
        if(m2==i)
        {
            tabColonne.push_back(tab[i]); // Stocke tous les indices des Colonnes
            m2=m2+3;
        }
        if(m3==i)
        {
            tabValeur.push_back(tab[i]); // Stocke tous les valeur
            m3=m3+3;
        }
    }
    
    for(int i=0 ; i<tabColonne.size(); i++) // Verifie si les colonnes en ordre croissant
    {
        if(tabColonne[i]>tabColonne[i+1] && i<tabColonne.size()-1) // pour eviter le depassement
        {
            cout<<"Probleme apres la colonne ["<<tabColonne[i]<<"]"<<endl;
            return false;
        }
    }
    
    for(int i=0 ; i<tabLigne.size(); i++) // Verifie si les ligne en ordre croissant
    {
        if(tabLigne[i]>tabLigne[i+1] && i<tabLigne.size()-1)
        {
            cout<<"Probleme apres la ligne ["<<tabLigne[i]<<"]"<<endl;
            return false;
        }
    }
    
    for(int i=0 ; i<tabValeur.size(); i++) // Verifie si une valeur == 0
    {
        if(tabValeur[i]==0)
        {
            cout<<"ERREUR : Dans le fichier contenant la matrice on ne doit avoir mat[i][j]=0"<<endl;
            return false;
        }
    }
    
    // Verification si chaque colone a une valeur
    
    
    for(int i=0 ; i<tabColonne.size(); i++) // Verifie si les colonnes en ordre croissant
    {
        for(int j=0 ; j<tabColonne.size(); j++) // Verifie si les colonnes en ordre croissant
        {
            if(i==tabColonne[j]) x=1;
        }
        if(x!=1)
        {
            cout<<"ERREUR : La colonne "<<i<<" n'est pas remplie"<<endl;
            return false;
        }
        x=0;
    }
    
    remove("tmp.txt"); // Supprime le fichier temporaire
    fichier.close();
    fichiertmp.close();
    
    return true;
}
