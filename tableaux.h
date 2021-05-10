#ifndef H_TABLEAUX
#define H_TABLEAUX

#include <stdlib.h>
#include <stdio.h>

// un cable :
typedef struct Cable
{
	int deb;
	int fin;
}
Cable;

//substitution :
char cablage(char c, int n);


// afficher tableau de co :
void afficher_cables(int n);

#endif
