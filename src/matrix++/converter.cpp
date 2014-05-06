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
        if(caractere[i]!=';' && caractere[i]!='\n') // on peut faire a chaque espace
        {
            n=caractere[i] -'0';
            tab.push_back(n);
            i++;
            while(fichier.get(caractere[i]) && caractere[i]!=';' && caractere[i]!='\n')
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


