#include <stdio.h>
#include <stdlib.h>
#include "interface.h"
#include "gameplay.h"

#define IA 0
#define U1 1
#define U2 2

void initialisation(int T[]) {

	//il faut mettre les pions de bases

	//il faut definir qui joue en premier
	T[1]=-2;
	T[6]=5;
	T[8]=3;
	T[12]=-5;
	T[13]=5;
	T[17]=-3;
	T[19]=-5;
	T[24]=2;

}


int main(void)
{
	int T[25]={0};
	int *Cimetiere_IA;
	int *Cimetiere_U;
	int *Sortie_IA;
	int *Sortie_U;
	int win = 0;
	int c;

	printf("Jouez vous contre un autre joueur(0) ou contre l'IA(1) ?\n");
	scanf("%d",&c);

	if(c == 0) {
		while(!win){

			initialisation(T);
			display(T, Cimetiere_IA, Cimetiere_U, Sortie_IA, Sortie_U);
			tour_joueur(T, U1);
			display(T, Cimetiere_IA, Cimetiere_U, Sortie_IA, Sortie_U);
			tour_joueur(T, U2);

			
		}
	} else if(c == 1) {
		while(!win){

			initialisation(T);
			//display(T);
			tour_joueur(T, U1);
			display(T, Cimetiere_IA, Cimetiere_U, Sortie_IA, Sortie_U);
			tour_joueur(T, IA);

			
		}
	}
	return 0;
}

