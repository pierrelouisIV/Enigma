#include "rotors.h"
#include "tableaux.h"

int main(int argc, char **argv)
{
	// tableau de connexion :
	int n;
	printf("Combien de cables voulez vous ?\n");
	scanf("%d", &n);
	afficher_cables(n);
	
	// rotors :
	initialisation_rotor();
	afficher_rotors();
	
	//
	char msg[100];
	char dechiffre[100];
	printf("Veuillez entrer le message clair : \n");
	scanf("%s", msg);
	char c;
	printf("\n mot chiffree : ");
	for(int i=0; i<strlen(msg); ++i)
	{
	   c = cablage(msg[i], n);
	   c = crypter_lettre(c);
	   printf("%c", c);
	   dechiffre[i] = c;
	}
	printf("\n");
	
	for(int i=0; i<strlen(msg); ++i)
	{
	   c = decrypter_lettre(dechiffre[i]);
	   printf("%c", cablage(c, n));
	}
	printf("\n");
	return 0;
}
