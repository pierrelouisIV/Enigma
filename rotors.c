
#include "rotors.h"

#define Z 0	// borne inférieure
#define L 26	// borne supérieure
#define P1 70	// position d'entrainement 1 : 'F'
#define P2 80	// position d'entrainement 2 : 'P'

// Alphabet :
int AZ[26] = {65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78,
		  79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90};

// Premier rotor :  
int R1[26] = {0};
		  
// Second Rotor :		  
int R2[26] = {0};
		  
// Troisième Rotor : 		  
int R3[26] = {0};
		  
// Reflecteur :		  
int Reflect[26] = {0};



// Algo de recherche dans l'alphabet :
int recherche_dichotomique(int * tab, int val, int borne_inf, int borne_sup)
{
	int val_milieu;
	if(borne_inf > borne_sup)
	{
		printf("Erreur recherche \n");
		return -1;
	}
	else
	{
		val_milieu = (borne_inf+borne_sup)/2;
		if(val == tab[val_milieu]) return val_milieu;
		else
		{
			if(val < tab[val_milieu]) return recherche_dichotomique(tab, val, borne_inf, val_milieu--);
			else return recherche_dichotomique(tab, val, val_milieu++, borne_sup);
		}
	}
}



// On initialise les décalages :
void initialisation_rotor()
{
	time_t t;
	srand((unsigned) time(&t));
	int a;
	int j = 0;
	
	while(j != 26)
	{
		a = rand() % 26;
		if(R1[a] == 0)
		{
			R1[a] = AZ[j];
			j++;
		}
	}
	j = 0;
	while(j != 26)
	{
		a = rand() % 26;
		if(R2[a] == 0)
		{
			R2[a] = AZ[j];
			j++;
		}
	}
	j = 0;
	while(j != 26)
	{
		a = rand() % 26;
		if(R3[a] == 0)
		{
			R3[a] = AZ[j];
			j++;
		}
	}
	j = 0;
	while(j != 26)
	{
		a = rand() % 26;
		if(Reflect[a] == 0)
		{
			Reflect[a] = AZ[j];
			j++;
		}
	}
	j = 0;
}

// crypter :
char crypter_lettre(char c)
{
	int indice = -1;
	// Aller :
	indice = recherche_dichotomique(AZ, c, Z, L);
	c = R1[indice];
	indice = recherche_dichotomique(AZ, c, Z, L);
	c = R2[indice];
	indice = recherche_dichotomique(AZ, c, Z, L);
	c = R3[indice];
	
	// Reflecteur :
	indice = recherche_dichotomique(AZ, c, Z, L);
	c = Reflect[indice];
	
	// Retour :
	for(int i = 0; i<L; ++i)
	{
		if(R3[i] == c)
		{
			c = AZ[i];
			break;
		}
	}
	for(int i = 0; i<L; ++i)
	{
		if(R2[i] == c)
		{
			c = AZ[i];
			break;
		}
	}
	for(int i = 0; i<L; ++i)
	{
		if(R1[i] == c)
		{
			c = AZ[i];
			break;
		}
	}
	mise_a_jour_rotors();
	return c;
}

// pour avancer les rotors d'un cran :
void mise_a_jour_rotors()
{
	// rotor le plus à droite :
	for(int i=0; i<L; ++i)
	{
		if(R1[i] == 90) R1[i] = 65;
		else R1[i] += 1;
	}
	if(R1[0] == P1)
	{
		for(int j =0; j<L; ++j)
		{
			if(R2[j] == 90) R2[j] = 65;
			else R2[j] += 1;
		}
	}
	if(R2[0] == P2)
	{
		for(int k =0; k<L; ++k)
		{
			if(R3[k] == 90) R3[k] = 65;
			else R3[k] += 1;
		}
	}
}


//
void afficher_rotors()
{
	printf(" ROTORS : \n  R1    ||  R2    ||  R3 \n");
	for(int i=Z; i<L; ++i)
	{
		printf(" %c -> %c || %c -> %c || %c -> %c   || %c -> %c \n", 
		AZ[i], R1[i], AZ[i], R2[i], AZ[i], R3[i], AZ[i], Reflect[i]);
	}
}
