#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "couleurs.h"

#define U1 1
#define U2 2
#define IA 0


char pion(int c,int i) //Renvoie un char représentant un pion IA 0
{									//un pion adversaire X, ou le vide		
	if (i > abs(c))
		return ' ';
	else if (c>0)
		return 'O';
	else
		return 'X';
}

void pion_mil(int c)
{	
	if (abs(c) < 5)
		printf("  ");
	else if (abs(c) >= 10)
		printf("1%c",c%10+48);
	else if (abs(c) > 5 )
		printf("%c ",c+48);
	else if (c > 0)
		printf("O ");
	else
		printf("X ");
}


void display(int T[25], int *Cimetiere_IA, int *Cimetiere_U, int *Sortie_IA, int *Sortie_U)
{
	int k,i; //k: case du pion|i: hauteur du pion dans sa case
	
	k=13;
	printf("   14  16  18    19  21  23\n");
	printf(" 13  15  17        20  22  24\n");
	//Affichage première ligne du plateau
	printf(" ____________________________\n");
	
	printf("|");
	for (k=13;k<18;k++)
	{
		printf("%c'",pion(T[k],1));
	}
	printf("%c ",pion(T[k],1));
	printf("|%c |",pion(*Cimetiere_IA,1));
	for (k=19;k<24;k++)
	{
		printf("%c'",pion(T[k],1));
	}
	printf("%c ",pion(T[k],1));
	printf("|\\	Sortie : %d\n", *Sortie_U);
	//Fin Affichage première ligne du plateau
	
	
	for (i=2;i<5;i++)
	{
		printf("|");
		for (k=13;k<19;k++)
		{
			printf("%c ",pion(T[k],i));
		}
		printf("|%c |",pion(*Cimetiere_IA,i));
		for (k=19;k<24;k++)
		{
			printf("%c ",pion(T[k],i));
		}
		printf("%c ",pion(T[k],i));
		printf("|\\\n");
	}

	/*Affichage milieu du plateau----------------------------------------------*/
	printf("|");
	for (k=13;k<18;k++)
	{
		pion_mil(T[k]);
	}
	pion_mil(T[k]);
	printf("|");
	pion_mil(*Cimetiere_IA);
	printf("|");
	for (k=19;k<24;k++)
	{
		pion_mil(T[k]);
	}
	pion_mil(T[k]);
	printf("|\\\n");

	printf("|            |  |            |\\\n");

	printf("|");
	for (k=12;k>7;k--)
	{
		pion_mil(T[k]);
	}
	pion_mil(T[k]);
	printf("|");
	pion_mil(*Cimetiere_U);
	printf("|");
	for (k=6;k>1;k--)
	{
		pion_mil(T[k]);
	}
	pion_mil(T[k]);
	printf("|\\\n");
	/*Affichage fin du milieu de plateau----------------------------------------*/
	
	for (i=4;i>1;i--)
	{
		printf("|");
		for (k=12;k>6;k--)
		{
			printf("%c ",pion(T[k],i));
		}
		printf("|%c |",pion(*Cimetiere_U,i));
		for (k=6;k>1;k--)
		{
			printf("%c ",pion(T[k],i));
		}
		printf("%c ",pion(T[k],i));
		printf("|\\\n");
	}
	
	//Affichage dernière ligne du plateau
	printf("|");
	for (k=12;k>7;k--)
	{
		printf("%c,",pion(T[k],i));
	}
	printf("%c ",pion(T[k],i));
	printf("|%c |",pion(*Cimetiere_U,i));
	for (k=6;k>1;k--)
	{
		printf("%c,",pion(T[k],i));
	}
	printf("%c ",pion(T[k],i));
	printf("|\\ Sortie: %d\n", *Sortie_IA);
	
	printf(" TTTTTTTTTTTTTTTTTTTTTTTTTTTT\\\n");
	//Fin Affichage dernière ligne du plateau
	
	printf(" 12 10   8         5   3   1\n");
	printf("   11  9   7     6   4   2\n");
}


void possibles_pion_haut_J1(int c,int i) //Renvoie un char représentant un pion IA 0
{									//un pion adversaire X, ou le vide		
	if (i > abs(c))
		printf(" '");
	else if (i == abs(c) && c<0) //pion possible J1
	{
		//Version Windows
		//color(12,0);
		//printf("X'");
		//color(7,0);
		//Version portable
		//printf("A'");
		//Version Linux
		couleur("31");
		printf("X'");
		couleur("0");
	}
	else if (c>0)
		printf("O'");
	else
		printf("X'");
}

void possibles_pion_J1(int c,int i) //Renvoie un char représentant un pion IA 0
{									//un pion adversaire X, ou le vide		
	if (i > abs(c))
		printf("  ");
	else if (i == abs(c) && c<0) //pion possible J1
	{
		//Version Windows
		//color(12,0);
		//printf("X ");
		//color(7,0);
		//Version portable
		//printf("A ");
		//Version Linux
		couleur("31");
		printf("X ");
		couleur("0");
	}
	else if (c>0)
		printf("O ");
	else
		printf("X ");
}

void possibles_pion_mil_J1(int c)
{	
	if (abs(c) < 5)
		printf("  ");
	else if (c == -5)  //pion possible J1
	{
		//Version Windows
		//color(12,0);
		//printf("X ");
		//color(7,0);
		//Version portable
		//printf("A ");
		//Version Linux
		couleur("31");
		printf("X ");
		couleur("0");
	}
	else if (c == 5)
		printf("O ");
	else if (c <= 10) //pion possible J1 >= 10
	{
		//Version Windows
		//color(12,0);
		//printf("1%c",c%10+48);
		//color(7,0);
		//Version portable
		//printf("A%c",c%10+48);
		//Version Linux
		couleur("31");
		printf("X ");
		couleur("0");
	}
	else if (c >= 10)
		printf("1%c",c%10+48);
	else if(c < -5 )   //pion possible J1 entre 5 et 10 
	{
		//Version Windows
		//color(12,0);
		//printf("%c ",c+48);
		//color(7,0);
		//Version portable
		//printf("%cA",c+48);
		//Version Linux
		couleur("31");
		printf("X ");
		couleur("0");
	}
	else
		printf("%c ",c+48);
}

void possibles_pion_bas_J1(int c,int i) //Renvoie un char représentant un pion IA 0
{									//un pion adversaire X, ou le vide		
	if (i > abs(c))
		printf(" ,");
	else if (i == abs(c) && c<0) //pion possible J1
	{
		//Version Windows
		//color(12,0);
		//printf("X,");
		//color(7,0);
		//Version portable
		//printf("A,");
		//Version Linux
		couleur("31");
		printf("X,");
		couleur("0");
	}
	else if (c>0)
		printf("O,");
	else
		printf("X,");
}

void possibles_pion_haut_J2(int c,int i) //Renvoie un char représentant un pion IA 0
{									//un pion adversaire X, ou le vide		
	if (i > abs(c))
		printf(" '");
	else if (i == abs(c) && c>0) //pion possible J2
	{
		//Version Windows
		//color(5,0);  
		//printf("O'");
		//color(7,0);
		//Version portable
		//printf("Q'");
		//Version Linux
		couleur("32");
		printf("O'");
		couleur("0");
	}
	else if (c>0)
		printf("O'");
	else
		printf("X'");
}

void possibles_pion_J2(int c,int i) //Renvoie un char représentant un pion IA 0
{									//un pion adversaire X, ou le vide		
	if (i > abs(c))
		printf("  ");
	else if (i == abs(c) && c>0) //pion possible J2
	{
		//Version Windows
		//color(5,0);
		//printf("O ");
		//color(7,0);
		//Version portable
		//printf("Q ");
		//Version Linux
		couleur("32");
		printf("O ");
		couleur("0");
	}
	else if (c>0)
		printf("O ");
	else
		printf("X ");
}

void possibles_pion_mil_J2(int c)
{	
	if (abs(c) < 5)
		printf("  ");
	else if (c == -5)
		printf("X ");
	else if (c == 5)   //pion possible J2
	{
		//Version Windows
		//color(5,0);
		//printf("O ");
		//color(7,0);
		//Version portable
		//printf("Q ");
		//Version Linux
		couleur("32");
		printf("X ");
		couleur("0");
	}
	else if (c <= 10)
		printf("1%c",c%10+48);
	else if (c >= 10)  //pion possible J2 >= 10
	{
		//Version Windows
		//color(5,0);
		//printf("1%c",c%10+48); 
		//color(7,0);
		//Version portable
		//printf("Q%c",c%10+48); 
		//Version Linux
		couleur("32");
		printf("X ");
		couleur("0");
	} 
	else if(c < -5 )
		printf("%c ",c+48);
	else    //pion possible J2 entre 5 et 10
	{
		//Version Windows
		//color(5,0);
		//printf("%c ",c+48);
		//color(7,0);
		//Version portable
		//printf("%cQ",c+48);	
		//Version Linux
		couleur("32");
		printf("X ");
		couleur("0");
	}		 
}

void possibles_pion_bas_J2(int c,int i) //Renvoie un char représentant un pion IA 0
{									//un pion adversaire X, ou le vide		
	if (i > abs(c))
		printf(" ,");
	else if (i == abs(c) && c>0) //pion possible J2
	{
		//Version Windows
		//color(5,0);
		//printf("O,");
		//color(7,0);
		//Version portable
		//printf("Q,");
		//Version Linux
		couleur("32");
		printf("O,");
		couleur("0");
	}
	else if (c>0)
		printf("O,");
	else
		printf("X,");
}


void display_pions_possibles(int T[25], int joueur, int *Cimetiere_IA, int *Cimetiere_U, int *Sortie_IA, int *Sortie_U)
{
	int k,i; //k: case du pion|i: hauteur du pion dans sa case
	
	k=13;
	printf("   14  16  18    19  21  23\n");
	printf(" 13  15  17        20  22  24\n");
	//Affichage première ligne du plateau
	printf(" ____________________________\n");
	
	if (joueur == 1)
	{
		printf("|");
		for (k=13;k<18;k++)
			possibles_pion_haut_J1(T[k],1);
		possibles_pion_J1(T[k],1);
		printf("|");
		possibles_pion_J1(*Cimetiere_IA,i);
		printf("|");
		for (k=19;k<24;k++)
			possibles_pion_haut_J1(T[k],1);
		possibles_pion_J1(T[k],1);
		printf("|\\	Sortie : %d\n", *Sortie_U);
		//Fin Affichage première ligne du plateau
	
	
		for (i=2;i<5;i++)
		{
			printf("|");
			for (k=13;k<19;k++)
				possibles_pion_J1(T[k],i);
			printf("|");
			possibles_pion_J1(*Cimetiere_IA,i);
			printf("|");
			for (k=19;k<24;k++)
				possibles_pion_J1(T[k],i);
			possibles_pion_J1(T[k],i);
			printf("|\\\n");
		}

		//Affichage milieu du plateau----------------------------------------------
		printf("|");
		for (k=13;k<18;k++)
			possibles_pion_mil_J1(T[k]);
		possibles_pion_mil_J1(T[k]);
		printf("|");
		possibles_pion_mil_J1(*Cimetiere_IA);
		printf("|");
		for (k=19;k<24;k++)
			possibles_pion_mil_J1(T[k]);
		possibles_pion_mil_J1(T[k]);
		printf("|\\\n");
	
		printf("|            |  |            |\\\n");
	
		printf("|");
		for (k=12;k>7;k--)
			possibles_pion_mil_J1(T[k]);
		possibles_pion_mil_J1(T[k]);
		printf("|");
		possibles_pion_mil_J1(*Cimetiere_U);
		printf("|");
		for (k=6;k>1;k--)
			possibles_pion_mil_J1(T[k]);
		possibles_pion_mil_J1(T[k]);
		printf("|\\\n");
		//Affichage fin du milieu de plateau----------------------------------------
	
		for (i=4;i>1;i--)
		{
			printf("|");
			for (k=12;k>6;k--)
				possibles_pion_J1(T[k],i);
			printf("|");
			possibles_pion_J1(*Cimetiere_U,i);
			printf("|");
			for (k=6;k>1;k--)
				possibles_pion_J1(T[k],i);
			possibles_pion_J1(T[k],i);
			printf("|\\\n");
		}
		
		//Affichage dernière ligne du plateau
		printf("|");
		for (k=12;k>7;k--)
			possibles_pion_bas_J1(T[k],i);
		possibles_pion_J1(T[k],i);
		printf("|");
		possibles_pion_J1(*Cimetiere_U,i);
		printf("|");
		for (k=6;k>1;k--)
			possibles_pion_bas_J1(T[k],i);
		possibles_pion_J1(T[k],i);
		printf("|\\ Sortie: %d\n", *Sortie_IA);
	}




	else if (joueur == 2)
	{
		printf("|");
		for (k=13;k<18;k++)
			possibles_pion_haut_J2(T[k],1);
		possibles_pion_J2(T[k],1);
		printf("|");
		possibles_pion_J2(*Cimetiere_IA,i);
		printf("|");
		for (k=19;k<24;k++)
			possibles_pion_haut_J2(T[k],1);
		possibles_pion_J2(T[k],1);
		printf("|\\	Sortie : %d\n", *Sortie_U);
		//Fin Affichage première ligne du plateau
	
	
		for (i=2;i<5;i++)
		{
			printf("|");
			for (k=13;k<19;k++)
				possibles_pion_J2(T[k],i);
			printf("|");
			possibles_pion_J2(*Cimetiere_IA,i);
			printf("|");
			for (k=19;k<24;k++)
				possibles_pion_J2(T[k],i);
			possibles_pion_J2(T[k],i);
			printf("|\\\n");
		}

		//Affichage milieu du plateau----------------------------------------------
		printf("|");
		for (k=13;k<18;k++)
			possibles_pion_mil_J2(T[k]);
		possibles_pion_mil_J2(T[k]);
		printf("|");
		possibles_pion_mil_J2(*Cimetiere_IA);
		printf("|");
		for (k=19;k<24;k++)
			possibles_pion_mil_J2(T[k]);
		possibles_pion_mil_J2(T[k]);
		printf("|\\\n");
	
		printf("|            |  |            |\\\n");
	
		printf("|");
		for (k=12;k>7;k--)
			possibles_pion_mil_J2(T[k]);
		possibles_pion_mil_J2(T[k]);
		printf("|");
		possibles_pion_mil_J2(*Cimetiere_U);
		printf("|");
		for (k=6;k>1;k--)
			possibles_pion_mil_J2(T[k]);
		possibles_pion_mil_J2(T[k]);
		printf("|\\\n");
		//Affichage fin du milieu de plateau----------------------------------------
	
		for (i=4;i>1;i--)
		{
			printf("|");
			for (k=12;k>6;k--)
				possibles_pion_J2(T[k],i);
			printf("|");
			possibles_pion_J2(*Cimetiere_U,i);
			printf("|");
			for (k=6;k>1;k--)
				possibles_pion_J2(T[k],i);
			possibles_pion_J2(T[k],i);
			printf("|\\\n");
		}
		
		//Affichage dernière ligne du plateau
		printf("|");
		for (k=12;k>7;k--)
			possibles_pion_bas_J2(T[k],i);
		possibles_pion_J2(T[k],i);
		printf("|");
		possibles_pion_J2(*Cimetiere_U,i);
		printf("|");
		for (k=6;k>1;k--)
			possibles_pion_bas_J2(T[k],i);
		possibles_pion_J2(T[k],i);
		printf("|\\ Sortie: %d\n", *Sortie_IA);
	}
	else printf("\nAucun utilisateur n'a ete selectione\n\n");

	printf(" TTTTTTTTTTTTTTTTTTTTTTTTTTTT\\\n");
	//Fin Affichage dernière ligne du plateau
	
	printf(" 12 10   8         5   3   1\n");
	printf("   11  9   7     6   4   2\n");
}

void afficher(int T[25])
{
	int i;
	
	for (i=0;i<13;i++)
		printf("%d: %d    %d: %d\n",i,T[i],i+13,T[i+13]);
	printf("\n");
}

void initialiser_pions_plateau(int T[25])
{
	T[1]=-2;
	T[6]=5;
	T[8]=3;
	T[12]=-5;
	T[13]=5;
	T[17]=-3;
	T[19]=-5;
	T[24]=2;
}
