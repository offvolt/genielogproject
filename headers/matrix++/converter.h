#ifndef H_CONVERTISER
#define H_CONVERTISER

using namespace std;

class Converter
{
private:
	// Ici seront écrites les fonctions utilitaires
	// Dont convert a besoin et dont l'utilisateur n'a pas le droit
	// D'accès.
public:
	static void convert(string &fileName1, string &fileName2);
};

#endif
