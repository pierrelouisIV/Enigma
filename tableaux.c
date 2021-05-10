#include "tableaux.h"

#define NB 13
// configuration des cables du tableau de connection : 
Cable cable[NB] = { {65, 70}, {66, 71}, {67, 72}, {68, 73}, {69, 74}, {75, 80}, {76, 81}, {77, 82},
		    {79, 83}, {88, 84}, {89, 85}, {87, 90}, {78, 86}};  



// substitution d'un caractère :
char cablage(char c, int nb_cables)
{
	for(int i=0; i<nb_cables; ++i)
	{
		if(c == cable[i].deb) return cable[i].fin;
		else if(c == cable[i].fin) return cable[i].deb;
	}
	return c;	// cas ou tous les cables ne sont pas pris
}



// afficher les connections :
void afficher_cables(int nb_cables)
{
	printf("Tableau de connection : \n");
	for(int i=0; i<nb_cables; ++i)
	{
		printf("cable %d : %c -> %c \n", i, cable[i].deb, cable[i].fin);
	}
}
