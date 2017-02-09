#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TMAX 25
#define IA 0
#define U1 1
#define U2 2

void tour_joueur(int T[], int J, int *Cim_IA, int *Cim_U, int *S_IA, int *S_U);
int lancer_de(void);
int etape(int T[], int J, int Cim_IA, int Cim_U, int S_IA, int S_U);
int choix_coup(int T[], int joueur, int step);
tpc possib_deplacement(int T[], int de1, int de2, tpc c, int pos, int *taille);
void choix_deplacement(int T[], int *de1, int *de2, tpc poss, int taille, int *Cim_IA, int *Cim_U, int *S_IA, int *S_U);
tpc coups_possibles(int T[], int joueur, int *taille, int step);
coup definir_coup(int joueur, int depart, int deplacement);


void tour_joueur(int T[], int J, int *Cim_IA, int *Cim_U, int *S_IA, int *S_U) {


	/* Variables */
	int i, pos, de1, de2, d_double = 0;
	int tailleposs = 0, taillecoup = 0;
	int step;

	tpc poss;
	tpc coups;
	/*---------------*/


/* 	LANCER DES DES */

    srand(time(NULL)); // initialisation de rand
	de1 = lancer_de();
	de2 = lancer_de();

	printf("Lancé des dés\nd1:%d, d2:%d\n",de1,de2);
	if(de1==de2)
		d_double = 1;

/* -------------------*/

/* 	------------------------ 
		BOUCLE DU TOUR
	------------------------ 
*/
	do {

	//	VERIFICATION DE L'ETAPE
	step = etape(T, J, *Cim_IA, *Cim_U, *S_IA, *S_U);

	//	GENERATION DU TABLEAU DE COUPS
	coups = coups_possibles(T, J, &taillecoup, step);
	display_pions_possibles(T, J, *Cim_IA, *Cim_U, *S_IA, *S_U);
/*
	if (J==U1) {
		for (i = 0; i < taillecoup; ++i)
		{
			printf("%d: %d + %d -> %d\n", i, coups[i].depart, coups[i].deplacement, coups[i].depart + coups[i].deplacement);
		}
	} else {
		for (i = 0; i < taillecoup; ++i)
		{
			printf("%d: %d - %d -> %d\n", i, coups[i].depart, coups[i].deplacement, coups[i].depart - coups[i].deplacement);
		}
	}
*/
		//	BOUCLE DU CHOIX D'UN COUP QUI SOIT POSSIBLE
		do {
			tailleposs = taillecoup;
			//	CHOIX DU PION QUE L'ON VEUT JOUER
			pos = choix_coup(T, J, step);
			display_coups_possibles(T, J, pos, de1, de2, *Cim_IA, *Cim_U, *S_IA, *S_U);


			//	GENERATION DU TABLEAU DE POSSIBILITES
			poss = possib_deplacement(T, de1, de2, coups, pos, &tailleposs);
				
			if (tailleposs <= 0) {
				free(poss);
				display_pions_possibles(T, J, *Cim_IA, *Cim_U, *S_IA, *S_U);

			}
		}while(tailleposs <= 0);

/*
		if (J==U1) {
			for (i = 0; i < tailleposs; ++i)
			{
				printf("%d: %d + %d\n", i, poss[i].depart, poss[i].deplacement);
			}
		} else {
			for (i = 0; i < tailleposs; ++i)
			{
				printf("%d: %d - %d\n", i, poss[i].depart, poss[i].deplacement);
			}
		}
*/
		//	CHOIX DU DEPLACEMENT ET MODIFICATION DU TABLEAU
		choix_deplacement(T, &de1, &de2, poss, tailleposs, Cim_IA, Cim_U, S_IA, S_U);

		//	AFFICHAGE DU TABLEAU/RESULTAT
		display(T, *Cim_IA, *Cim_U, *S_IA, *S_U);

		//	DES RESTANT
		printf("\nDés disponible :\nd1: %d, d2: %d\n\n", de1, de2);

		//	DESALLOCATION MEMOIRE
		free(poss);
		free(coups);

	}while(de1 != 0 || de2 != 0);

}


int lancer_de(void) {
	return rand()%6+1;
}

int etape(int T[], int J, int Cim_IA, int Cim_U, int S_IA, int S_U) {
	int i=0, sum=0;

	if (J == U1) {
		for (i = 0; i < 6; ++i)
		{
			sum += T[19+i];
		}
		if (sum - S_U == -15) {
			return 2;
		} else if (Cim_U > 0) {
			return 0;
		} else {
			return 1;
		}

	} else if ( J == U2 || J == IA) {
		for (i = 0; i < 6; ++i)
		{
			sum += T[1+i];
		}
		if (sum + S_IA == 15) {
			return 2;
		} else if (Cim_IA > 0) {
			return 0;
		} else {
			return 1;
		}
	} else {
		printf("----------> Probleme : verifier J\n");
		return -1;
	}
}

int choix_coup(int T[], int joueur, int step) {
	int pos;

	if(joueur == U1) {
		if(step == 0) {
			return pos = 0;
		}
		do {
			printf("Lequel de vos pions voulez-vous jouer?\nVeuillez indiquer le numéro de colonne :");
			scanf("%d",&pos);
			printf("\n");
		}while (T[pos] >= 0);
		printf("\n");
	} else if(joueur == U2) {
		if(step == 0) {
			return pos = 25;
		}
		do {
			printf("Lequel de vos pions voulez-vous jouer?\nVeuillez indiquer le numéro de colonne :");
			scanf("%d",&pos);
			printf("\n");
		}while (T[pos] <= 0);
		printf("\n");
	}

	return pos;
}


tpc possib_deplacement(int T[], int de1, int de2, tpc c, int pos, int *taille) {

	tpc depl;
	depl = (tpc)malloc(sizeof(coup));
	int i=0, j=0;

	for(i=0; i < *taille; i++) {
		if ((c[i].depart == pos && c[i].deplacement == de1) || (c[i].depart == pos && c[i].deplacement == de2)) {
			depl = (tpc)realloc(depl, sizeof(coup) * (j + 1));
			depl[j] = c[i];
			j++;
		}
	}
	*taille = j;	//taille change pour la nouvelle taille de la table de "deplacements"
	return depl;

}

void choix_deplacement(int T[], int *de1, int *de2, tpc poss, int taille, int *Cim_IA, int *Cim_U, int *S_IA, int *S_U) {

	int choix, i=0, j=0, g=0;

	do {
		i=0;
		printf("Veuillez choisir le coup que vous voulez jouer parmi ceux possibles\nVeuillez indiquer le numéro de colonne :");
		scanf("%d",&choix);
		if(poss[0].joueur == U1) {
			for(i=0;i<taille;i++) {
				if (choix == poss[i].depart + poss[i].deplacement) {
					if (T[choix] == 1) {
						T[choix] -= 1;
						*Cim_IA += 1;
					}
					if (poss[i].depart == 0) {
						*Cim_U -= 1;
					} else {
						T[poss[i].depart] += 1;
					}
					if (choix == 25) {
						*S_U += 1;
					} else {
						T[poss[i].depart + poss[i].deplacement] -= 1;
					}
					g=1;
					j = i;
					i = taille;
				}
			}
		} else if (poss[0].joueur == IA || poss[0].joueur == U2) {
			for(i=0;i<taille;i++) {
				if (choix == poss[i].depart - poss[i].deplacement) {
					if (T[choix] == -1) {
						T[choix] += 1;
						*Cim_U += 1;
					}
					if (poss[i].depart == 25) {
						*Cim_IA -= 1;
					} else {
						T[poss[i].depart] -= 1;
					}
					if (choix == 0) {
						*S_IA += 1;				
					} else {
						T[poss[i].depart - poss[i].deplacement] += 1;
					}
					g=1;
					j = i;
					i = taille;
				}
			}
		}

	}while(!g);

	if(poss[j].deplacement == *de1) {
		*de1=0;
	} else if (poss[j].deplacement == *de2) {
		*de2=0;
	}

}



tpc coups_possibles(int T[], int joueur, int *taille, int step) {

	tpc poss;
	poss = (tpc)malloc(sizeof(coup));

	int k = 0, i=0, j =0;

	if (step > 0) {
		for (i = 1; i < TMAX; ++i) {
			if((joueur == IA || joueur == U2) && T[i] > 0) {
				for (j = 1; j <= 6; ++j) {
					if(i - j > 0 && T[i - j] >= -1) {
						poss = (tpc)realloc(poss, sizeof(coup) * (k + 1));
						poss[k] = definir_coup(joueur, i, j);
						k++;
					} else if (i - j == 0  && step == 2) {
						poss = (tpc)realloc(poss, sizeof(coup) * (k + 1));
						poss[k] = definir_coup(joueur, i, j);
						k++;
					}
				}
			} else if (joueur == U1 && T[i] < 0) {
				for (j = 1; j <= 6; ++j) {
					if(i + j < 25 && T[i + j] <= 1) {
						poss = (tpc)realloc(poss, sizeof(coup) * (k + 1));
						poss[k] = definir_coup(joueur, i, j);
						k++;
					} else if (i + j == 25 && step == 2) {
						poss = (tpc)realloc(poss, sizeof(coup) * (k + 1));
						poss[k] = definir_coup(joueur, i, j);
						k++;
					}
				}
			}
		}
	} else if (step == 0) {
		if(joueur == IA || joueur == U2) {
			for (i=1; i<=6; i++) {
				if(T[25 - i] >= -1) {
						poss = (tpc)realloc(poss, sizeof(coup) * (k + 1));
						poss[k] = definir_coup(joueur, 25, i);
						k++;
				}
			}
		} else if (joueur == U1) {
			for (i=1; i<=6; i++) {
				if(T[0 + i] <= 1) {
						poss = (tpc)realloc(poss, sizeof(coup) * (k + 1));
						poss[k] = definir_coup(joueur, 0, i);
						k++;
				}
			}
		}
	}
		
	*taille = k;
	return poss;
}

coup definir_coup(int joueur, int depart, int deplacement) {
	coup c;
	c.joueur = joueur;
	c.depart = depart;
	c.deplacement = deplacement;

	return c;
}