#ifndef H_ROTORS
#define H_ROTORS

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

// Initialisation :
void initialisation_rotor();

//
int recherche_dichotomique(int * tab, int val, int borne_inf, int borne_sup);

// crypter :
char crypter_lettre(char c);
void mise_a_jour_rotors();

//
void afficher_rotors();



#endif

