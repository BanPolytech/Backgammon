#include <stdio.h>
#include <stdlib.h>

#include "gameplay.h"

#define PROF_MAX 4
#define MIN 0
#define MAX 120


int evaluer(int T[25]);
void jouer(tpc coup, int T[25], int Cim_IA, int Cim_U, int S_IA, int S_U);
int backtrack_rec(int profondeur,int T[25], int *Cim_IA, int *Cim_U, int *S_IA, int *S_U );
int min(int a,int b);
int max(int a,int b);

/*-------------------------------------------------------------------------------*/
/*                                      MAIN                                     */
/*-------------------------------------------------------------------------------*/



/*-------------------------------------------------------------------------------*/
/*                               Nouvelles fonctions                             */
/*-------------------------------------------------------------------------------*/

int evaluer(int T[25])
{
	int somme=0;
	for (k=1; k<24; k++)
	{
		if (k>=19 && k=<24 && T[k]>0)
			somme+=1*T[k];
		else if (k>=13 && k=<18 && T[k]>0)
			somme+=2*T[k];
		else if (k>=7 && k=<12 && T[k]>0)
			somme+=4*T[k];
		else if (k>=1 && k=<6 && T[k]>0)
			somme+=8*T[k];
	}
	return somme;
}

void jouer(coup coup, int T[], int *Cim_IA, int *Cim_U, int *S_IA, int *S_U, int * mange, int * sort)
{
	if(coup.joueur == U1) {
		if (T[coup.depart + coup.deplacement] == 1) {
			T[coup.depart + coup.deplacement] -= 1;
			*Cim_IA += 1;
			*mange = 1;
		}
		if (coup.depart == 0) {
			*Cim_U -= 1;
		} else {
			T[coup.depart] += 1;
		}
		if (coup.depart + coup.deplacement == 25) {
			*S_U += 1;
			*sort = 1;
		} else {
			T[coup.depart + coup.deplacement] -= 1;
		}
	} else if (coup.joueur == IA) {
		if (T[coup.depart + coup.deplacement] == -1) {
			T[coup.depart + coup.deplacement] += 1;
			*Cim_U += 1;
			*mange = 1;
		}
		if (coup.depart == 25) {
			*Cim_IA -= 1;
		} else {
			T[coup.depart] -= 1;
		}
		if (coup.depart + coup.deplacement == 0) {
			*S_IA += 1;
			*sort = 1;			
		} else {
			T[coup.depart - coup.deplacement] += 1;
		}
	}
}

void dejouer(coup coup, int T[], int *Cim_IA, int *Cim_U, int *S_IA, int *S_U, int * mange, int * sort)
{
	if(coup.joueur == U1) {
		if (*mange == 1) {
			T[coup.depart + coup.deplacement] += 1;
			*Cim_IA -= 1;
		}
		if (coup.depart == 0) {
			*Cim_U += 1;
		} else {
			T[coup.depart] -= 1;
		}
		if (*sort == 1) {
			*S_U -= 1;
		} else {
			T[coup.depart + coup.deplacement] += 1;
		}
	} else if (coup.joueur == IA) {
		if (*mange == 1) {
			T[coup.depart + coup.deplacement] -= 1;
			*Cim_U -= 1;
		}
		if (coup.depart == 25) {
			*Cim_IA += 1;
		} else {
			T[coup.depart] += 1;
		}
		if (*sort = 1) {
			*S_IA -= 1;				
		} else {
			T[coup.depart - coup.deplacement] -= 1;
		}
	}
}

int min(int a,int b)
	return (a <= b) ? a : b; 

int max(int a,int b)
	return (a > b) ? a : b; 

int backtrack_rec(int profondeur, int T[], int *Cim_IA, int *Cim_U, int *S_IA, int *S_U )
{
	tpc C;
	int tmp, nbcoup,joueur,etape,c,eval;
	int mange = 0, sort = 0;

	joueur=profondeur%2;
	etape=etape(T, joueur, *Cim_IA, *Cim_U, *S_IA, *S_U);
	C=coups_possibles(T, joueur, *nbcoup, etape);
	tmp = (joueur) ? MAX : MIN //120 est le max car 8*15=120

	if (profondeur < PROF_MAX)
	{ //On est sur un noeud
		for (c=0; c<nbcoup; c++)
		{
			mange = 0; sort = 0;
			jouer(C[c], T, *Cim_IA, *Cim_U, *S_IA, *S_U, &mange, &sort);
			eval=backtrack_rec(profondeur + 1, T, Cim_IA, Cim_U, S_IA, S_U );
			tmp = (joueur) ?  min(tmp, eval) : max (tmp, eval); 
			dejouer(C[c], T, *Cim_IA, *Cim_U, *S_IA, *S_U, &mange, &sort); 
		}
		return tmp;
	}
	else
	{ //On est sur une feuille
		eval=evaluer(T);
		return eval;
	}
}

//a régler
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

//a chaque étape du for il faut retenir le max et renvoyer le coups associé
coup backtrack(int position, int de1, int de2, int T[], int *Cim_IA, int *Cim_U, int *S_IA, int *S_U )
{
	tpc CoupsPoss, coups;
	coup choix;
	int c,etape, taillecoup = 0, tailleposs = 0, num_choix;
	int *Scores;
	int mange = 0, sort = 0;

	etape = etape(T, joueur, *Cim_IA, *Cim_U, *S_IA, *S_U);
	coups = coups_possibles(T, IA, &taillecoup, etape); //tous les coups avec toutes combinaisons de dés 
	CoupsPoss = possib_deplacement_departIA(T, de1, de2, coups, &tailleposs);
	

	for (c= 0; c < tailleposs; i++)
	{
		mange = 0; sort = 0;
		jouer(CoupsPoss[c], T, *Cim_IA, *Cim_U, *S_IA, *S_U, &mange, &sort);
		Scores[c]=backtrack_rec(profondeur, T, *Cim_IA, *Cim_U, *S_IA, *S_U)
		dejouer(CoupsPoss[c], T, *Cim_IA, *Cim_U, *S_IA, *S_U, &mange, &sort);
	}
}

