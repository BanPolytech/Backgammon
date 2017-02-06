#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TMAX 25
#define IA 0
#define U1 1
#define U2 2

void tour_joueur(int T[], int J);
int lancer_de(void);
int choix_coup(int T[], int joueur);
void choix_deplacement(int T[], int pos, tpc poss, int taille);
tpc possib_deplacement(int T[], int de1, int de2, tpc c, int pos, int *taille);
coup definir_coup(int joueur, int depart, int deplacement);
tpc coups_possibles(int T[], int joueur, int *taille);


void tour_joueur(int T[], int J) {

	int i, pos, de1, de2, tailleposs;
	tpc poss;

    srand(time(NULL)); // initialisation de rand
	de1 = lancer_de();
	de2 = lancer_de();

	printf("Lancé des dés\nd1:%d, d2:%d\n",de1,de2);
	tpc coups = coups_possibles(T, J, &tailleposs);
	//display_pions_possibles(T);

	for (i = 0; i < tailleposs; ++i)
	{
		printf("%d: %d + %d -> %d\n", i, coups[i].depart, coups[i].deplacement, coups[i].depart + coups[i].deplacement);
	}
	do {
		pos = choix_coup(T, J);
		poss = possib_deplacement(T, de1, de2, coups, pos, &tailleposs);
	}while(tailleposs <= 0);

	//display_coups_possibles(T, pos, poss);
	for (i = 0; i < tailleposs; ++i)
	{
		printf("%d: %d + %d\n", i, poss[i].depart, poss[i].deplacement);
	}

	choix_deplacement(T, pos, poss, tailleposs);

	free(poss);
	free(coups);


}


int lancer_de(void) {

    int nombre_aleatoire = 0;
    
	return nombre_aleatoire = rand()%6+1;
}

int choix_coup(int T[], int joueur) {
	int pos;

	if(joueur == U1) {
		do {
		printf("Lequel de vos pions voulez-vous jouer?\nVeuillez indiquer le numéro de colonne :");
		scanf("%d",&pos);
		printf("\n");
		}while (T[pos] >= 0);
		printf("\n");
	} else if(joueur == U2) {
		do {
			printf("Lequel de vos pions voulez-vous jouer?\nVeuillez indiquer le numéro de colonne :");
			scanf("%d",&pos);
			printf("\n");
		}while (T[pos] <= 0);
		printf("\n");
	}

	return pos;
}


void choix_deplacement(int T[], int pos, tpc poss, int taille) {

	int choix, i=0, g=0;

	do {
		i=0;
		printf("Veuillez choisir le coup que vous voulez jouer parmi ceux possibles\nVeuillez indiquer le numéro de colonne :");
		scanf("%d",&choix);

		for(i=0;i<taille;i++) {
			if (choix == poss[i].depart + poss[i].deplacement) {
				g=1;
			}
		}

	}while(!g);

	if(poss[i].joueur == IA || poss[i].joueur == U2) {
		T[poss[i].depart] -= 1;
		T[poss[i].depart + poss[i].deplacement] += 1;
	} else if(poss[i].joueur == U1) {
		T[poss[i].depart] += 1;
		T[poss[i].depart + poss[i].deplacement] -= 1;
	}	
}

tpc possib_deplacement(int T[], int de1, int de2, tpc c, int pos, int *taille) {

	int i=0, j=0;
	tpc poss;
	poss = (tpc)malloc(sizeof(coup));

	for(i=0; i < *taille; i++) {
		if ((c[i].depart == pos && c[i].deplacement == de1) || (c[i].depart == pos && c[i].deplacement == de2) || (c[i].depart == pos && c[i].deplacement == de1 + de2)) {
			poss[j] = c[i];
			j++;
		}
	}
	*taille = j;
	return poss;

}

//￣
tpc coups_possibles(int T[], int joueur, int *taille) {

	tpc poss;
	poss = (tpc)malloc(sizeof(coup));
	int k = 0;
	int combinaisons[21][2] = {{1,1},{1,2},{1,3},{1,4},{1,5},{1,6},{2,2},{2,3},{2,4},{2,5},{2,6},{3,3},{3,4},{3,5},{3,6},{4,4},{4,5},{4,6},{5,5},{5,6},{6,6}};

	for (int i = 1; i < TMAX; ++i) {
		if((joueur == IA || joueur == U2) && T[i] > 0) {
			for (int j = 21; j > 0; --j) {
				if(T[i - combinaisons[j][0]] >= 0) {
					poss[k] = definir_coup(joueur, i, combinaisons[j][0]);
					k++;
				} else if(T[i - combinaisons[j][1]] >= 0) {
					poss[k] = definir_coup(joueur, i, combinaisons[j][1]);
					k++;
				}
			}
		} else if (joueur == U1 && T[i] < 0) {
			for (int j = 0; j < 21; ++j) {
				if(T[i + combinaisons[j][0]] <= 0) {
					poss[k] = definir_coup(joueur, i, combinaisons[j][0]);
					k++;
				} else if(T[i + combinaisons[j][1]] <= 0) {
					poss[k] = definir_coup(joueur, i, combinaisons[j][1]);
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