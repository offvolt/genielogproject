#include <iostream>
#include <string>
#include "converter.h"
#include <fstream> 

using namespace std;

int main()
{
    string fichL,fichE,fichL1,fichE2; // fichier lecture, fichier ecriture
    fichL="mat.txt";
    fichE="mat2.txt";
    fichL1="mat2.txt";
    fichE2="mat3.txt";
    Converter::convertbin(fichL,fichE);
    Converter::convert(fichL1,fichE2);
    return 0;
}
