#include <stdio.h>
#include <stdlib.h>
#include "initialisation.h"
#include "interface.h"
#include "gameplay.h"

#define IA 0
#define U1 1
#define U2 2


int main(void)
{
	int T[25]={0};
	int Cimetiere_IA = 0;
	int Cimetiere_U = 0;
	int Sortie_IA = 0;
	int Sortie_U = 0;
	int win = 0;
	int c;

	printf("Jouez vous contre un autre joueur(0) ou contre l'IA(1) ?\n");
	scanf("%d",&c);

	initialiser_pions_plateau(T);


	if(c == 0) {
		while(!win){

			display(T, &Cimetiere_IA, &Cimetiere_U, &Sortie_IA, &Sortie_U);
			tour_joueur(T, U1);
			display(T, &Cimetiere_IA, &Cimetiere_U, &Sortie_IA, &Sortie_U);
			tour_joueur(T, U2);
		}
	} else if(c == 1) {
		while(!win){

			display(T, &Cimetiere_IA, &Cimetiere_U, &Sortie_IA, &Sortie_U);
			tour_joueur(T, U1);
			display(T, &Cimetiere_IA, &Cimetiere_U, &Sortie_IA, &Sortie_U);
			tour_joueur(T, IA);
		}
	}
	return 0;
}

