#include <stdio.h>
#include <stdlib.h>
#include "interface.h"

#define PROF_MAX 4
#define MIN 0
#define MAX 121 //120=8*15 cela correspond a tous les pions dans le jan de fin



//Déclarations:
int evaluer(int T[25]);
void jouer(coup coup_a_jouer, int T[], int *Cim_IA, int *Cim_U, int *S_IA, int *S_U, int * mange, int * sort);
int backtrack_rec(int profondeur,int T[25], int *Cim_IA, int *Cim_U, int *S_IA, int *S_U );
int min(int a,int b);
int max(int a,int b);
void dejouer(coup coup_a_jouer, int T[], int *Cim_IA, int *Cim_U, int *S_IA, int *S_U, int * mange, int * sort);
tpc possib_deplacement_departIA(int T[], int de1, int de2, tpc c, int *taille);
coup backtrack(int de1, int de2, int T[], int *Cim_IA, int *Cim_U, int *S_IA, int *S_U );
void tour_IA(int T[], int *Cim_IA, int *Cim_U, int *S_IA, int *S_U) ;



/*-------------------------------------------------------------------------------*/
/*                                      MAIN                                     */
/*-------------------------------------------------------------------------------*/

int main()
{
	int T[25]={0};
	int Cimetiere_IA = 0,Cimetiere_U = 0, Sortie_IA = 0, Sortie_U = 0;
	int fin=0;

	initialiser_pions_plateau(T);
	do
	{
		tour_joueur(T, U1, &Cimetiere_IA, &Cimetiere_U, &Sortie_IA, &Sortie_U);
		if (!fin)
			tour_IA(T, &Cimetiere_IA, &Cimetiere_U, &Sortie_IA, &Sortie_U); 
			//tour_joueur(T, U2, &Cimetiere_IA, &Cimetiere_U, &Sortie_IA, &Sortie_U);
	}
	while(!fin);
}

/*-------------------------------------------------------------------------------*/
/*                               Nouvelles fonctions                             */
/*-------------------------------------------------------------------------------*/

int evaluer(int T[25])
{
	int k, somme=0;
	for (k=1; k<24; k++)
	{
		if (k>=19 && k<=24 && T[k]>0)
			somme+=1*T[k];
		else if (k>=13 && k<=18 && T[k]>0)
			somme+=2*T[k];
		else if (k>=7 && k<=12 && T[k]>0)
			somme+=4*T[k];
		else if (k>=1 && k<=6 && T[k]>0)
			somme+=8*T[k];
	}
	return somme;
}

void jouer(coup coup_a_jouer, int T[], int *Cim_IA, int *Cim_U, int *S_IA, int *S_U, int * mange, int * sort)
{
	if(coup_a_jouer.joueur == U1) {
		if (T[coup_a_jouer.depart + coup_a_jouer.deplacement] == 1) {
			T[coup_a_jouer.depart + coup_a_jouer.deplacement] -= 1;
			*Cim_IA += 1;
			*mange = 1;
		}
		if (coup_a_jouer.depart == 0) {
			*Cim_U -= 1;
		} else {
			T[coup_a_jouer.depart] += 1;
		}
		if (coup_a_jouer.depart + coup_a_jouer.deplacement == 25) {
			*S_U += 1;
			*sort = 1;
		} else {
			T[coup_a_jouer.depart + coup_a_jouer.deplacement] -= 1;
		}
	} else if (coup_a_jouer.joueur == IA) {
		if (T[coup_a_jouer.depart + coup_a_jouer.deplacement] == -1) {
			T[coup_a_jouer.depart + coup_a_jouer.deplacement] += 1;
			*Cim_U += 1;
			*mange = 1;
		}
		if (coup_a_jouer.depart == 25) {
			*Cim_IA -= 1;
		} else {
			T[coup_a_jouer.depart] -= 1;
		}
		if (coup_a_jouer.depart + coup_a_jouer.deplacement == 0) {
			*S_IA += 1;
			*sort = 1;			
		} else {
			T[coup_a_jouer.depart - coup_a_jouer.deplacement] += 1;
		}
	}
}

void dejouer(coup coup_a_jouer, int T[], int *Cim_IA, int *Cim_U, int *S_IA, int *S_U, int * mange, int * sort)
{
	if(coup_a_jouer.joueur == U1) {
		if (*mange == 1) {
			T[coup_a_jouer.depart + coup_a_jouer.deplacement] += 1;
			*Cim_IA -= 1;
		}
		if (coup_a_jouer.depart == 0) {
			*Cim_U += 1;
		} else {
			T[coup_a_jouer.depart] -= 1;
		}
		if (*sort == 1) {
			*S_U -= 1;
		} else {
			T[coup_a_jouer.depart + coup_a_jouer.deplacement] += 1;
		}
	} else if (coup_a_jouer.joueur == IA) {
		if (*mange == 1) {
			T[coup_a_jouer.depart + coup_a_jouer.deplacement] -= 1;
			*Cim_U -= 1;
		}
		if (coup_a_jouer.depart == 25) {
			*Cim_IA += 1;
		} else {
			T[coup_a_jouer.depart] += 1;
		}
		if (*sort = 1) {
			*S_IA -= 1;				
		} else {
			T[coup_a_jouer.depart - coup_a_jouer.deplacement] -= 1;
		}
	}
}


int min(int a,int b)
{
	return (a <= b) ? a : b;
} 

int max(int a,int b)
{	
	return (a > b) ? a : b; 
}

int backtrack_rec(int profondeur, int T[], int *Cim_IA, int *Cim_U, int *S_IA, int *S_U )
{
	printf("Récursion de back track profondeur %d\n",profondeur );

	tpc C;
	int tmp, nbcoup,joueur,step,c,eval;
	int mange = 0, sort = 0;

	joueur=profondeur%2;
	step = etape(T, joueur, *Cim_IA, *Cim_U, *S_IA, *S_U);
	C=coups_possibles(T, joueur, &nbcoup, step);
	tmp = (joueur) ? MAX : MIN; //120 est le max car 8*15=120

	if (profondeur < PROF_MAX)
	{ //On est sur un noeud
		for (c=0; c<nbcoup; c++)
		{
			mange = 0; sort = 0;
			jouer(C[c], T, Cim_IA, Cim_U, S_IA, S_U, &mange, &sort);
			eval=backtrack_rec(profondeur + 1, T, Cim_IA, Cim_U, S_IA, S_U );
			tmp = (joueur) ?  min(tmp, eval) : max (tmp, eval); 
			dejouer(C[c], T, Cim_IA, Cim_U, S_IA, S_U, &mange, &sort); 
		}
		return tmp;
	}
	else
	{ //On est sur une feuille
		eval=evaluer(T);
		return eval;
	}
}

int backtrack_rec_alphabeta(int profondeur, int T[], int *Cim_IA, int *Cim_U, int *S_IA, int *S_U )
{
	printf("Récursion de back track profondeur %d\n",profondeur );

	tpc C;
	int tmp, nbcoup,joueur,step,c,eval;
	int mange = 0, sort = 0;

	joueur=profondeur%2;
	step = etape(T, joueur, *Cim_IA, *Cim_U, *S_IA, *S_U);
	C=coups_possibles(T, joueur, &nbcoup, step);
	tmp = (joueur) ? MAX : MIN; //120 est le max car 8*15=120

	if (profondeur < PROF_MAX)
	{ //On est sur un noeud
		for (c=0; c<nbcoup; c++)
		{
			mange = 0; sort = 0;
			jouer(C[c], T, Cim_IA, Cim_U, S_IA, S_U, &mange, &sort);
			eval=backtrack_rec(profondeur + 1, T, Cim_IA, Cim_U, S_IA, S_U );
			tmp = (joueur) ?  min(tmp, eval) : max (tmp, eval); 
			dejouer(C[c], T, Cim_IA, Cim_U, S_IA, S_U, &mange, &sort); 
		}
		return tmp;
	}
	else
	{ //On est sur une feuille
		eval=evaluer(T);
		return eval;
	}
}

tpc possib_deplacement_departIA(int T[], int de1, int de2, tpc c, int *taille) 
{
	tpc depl;
	depl = (tpc)malloc(sizeof(coup));
	//printf("malloc depl\n");
	int i=0, j=0;

	for(i=0; i < *taille; i++) {\
		if (c[i].deplacement == de1 || c[i].deplacement == de2) {
			depl = (tpc)realloc(depl, sizeof(coup) * (j + 1));
			depl[j] = c[i];
			j++;
		}
	}
	*taille = j;	//taille change pour la nouvelle taille de la table de "deplacements"
	return depl;
}


coup backtrack(int de1, int de2, int T[], int *Cim_IA, int *Cim_U, int *S_IA, int *S_U )
{
	tpc CoupsPoss, coups;
	coup choix;
	int c,step, taillecoup = 0, tailleposs = 0, tmp,score, num_choix;
	//int *Scores;
	int mange = 0, sort = 0;

	step = etape(T, IA, *Cim_IA, *Cim_U, *S_IA, *S_U);
	coups = coups_possibles(T, IA, &taillecoup, step); //tous les coups avec toutes combinaisons de dés 
	CoupsPoss = possib_deplacement_departIA(T, de1, de2, coups, &tailleposs);
	tmp = MIN;

	printf("Nb de coup possibles sans dé et pos: %d\n", taillecoup);
	printf("Nb de coup possibles sans pos: %d \n", tailleposs);

	for (c= 0; c < tailleposs; c++)
	{

		printf("Appel de backtrack_rec \n");

		mange = 0; sort = 0;
		jouer(CoupsPoss[c], T, Cim_IA, Cim_U, S_IA, S_U, &mange, &sort);
		//Scores[c]=backtrack_rec(profondeur, T, *Cim_IA, *Cim_U, *S_IA, *S_U);
		score = backtrack_rec(1, T, Cim_IA, Cim_U, S_IA, S_U);
		dejouer(CoupsPoss[c], T, Cim_IA, Cim_U, S_IA, S_U, &mange, &sort);
		if (score > tmp)
		{
			num_choix = c;
			tmp = score;
		}
	}
	return CoupsPoss[num_choix];
}

void tour_IA(int T[], int *Cim_IA, int *Cim_U, int *S_IA, int *S_U) 
{
	coup coup_choisi;
	int de1, de2, mange = 0, sort = 0;

	printf("\n\nTOUR DE L'IA\n");

	srand(time(NULL)); // initialisation de rand
	de1 = lancer_de();
	de2 = lancer_de();

	printf("Dés qu'obtiens l'IA: de1: %d   de2: %d\n\n",de1,de2 );

	coup_choisi=backtrack(de1, de2, T, Cim_IA, Cim_U, S_IA, S_U );
	jouer(coup_choisi, T, Cim_IA, Cim_U, S_IA, S_U, &mange, &sort);
	display(T, *Cim_IA, *Cim_U, *S_IA, *S_U);

	printf("\nFIN DU TOUR DE L'IA\n\n");
}