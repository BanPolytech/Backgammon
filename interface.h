#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>


#define U1 1
#define U2 2
#define IA 0

#ifndef COULEURS
#define COULEURS

#define clrscr() printf("\033[H\033[2J")
#define couleur(param) printf("\033[%sm",param)


#endif

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
		printf("1%c",abs(c)%10+48);
	else if (abs(c) > 5 )
		printf("%c ",c+48);
	else if (c > 0)
		printf("O ");
	else
		printf("X ");
}


void display(int T[25], int Cimetiere_IA, int Cimetiere_U, int Sortie_IA, int Sortie_U)
{
	int k,i; //k: case du pion|i: hauteur du pion dans sa case
	
	k=13;
	printf("   14  16  18    19  21  23\n");
	printf(" 13  15  17        20  22  24\n");
	printf(" ____________________________\n");
	printf("|%c'%c'%c'%c'%c'%c |%c |%c'%c'%c'%c'%c'%c |\\ Sortie : %d \n", pion(T[13],1),pion(T[14],1), pion(T[15],1), pion(T[16],1), pion(T[17],1), pion(T[18],1), pion(Cimetiere_IA,1), pion(T[19],1),pion(T[20],1), pion(T[21],1), pion(T[22],1), pion(T[23],1), pion(T[24],1), Sortie_U);
	printf("|%c %c %c %c %c %c |%c |%c %c %c %c %c %c |\\  \n", pion(T[13],2),pion(T[14],2), pion(T[15],2), pion(T[16],2), pion(T[17],2), pion(T[18],2), pion(Cimetiere_IA,2), pion(T[19],2),pion(T[20],2), pion(T[21],2), pion(T[22],2), pion(T[23],2), pion(T[24],2));	
	printf("|%c %c %c %c %c %c |%c |%c %c %c %c %c %c |\\  \n", pion(T[13],3),pion(T[14],3), pion(T[15],3), pion(T[16],3), pion(T[17],3), pion(T[18],3), pion(Cimetiere_IA,3), pion(T[19],3),pion(T[20],3), pion(T[21],3), pion(T[22],3), pion(T[23],3), pion(T[24],3));	
	printf("|%c %c %c %c %c %c |%c |%c %c %c %c %c %c |\\  \n", pion(T[13],4),pion(T[14],4), pion(T[15],4), pion(T[16],4), pion(T[17],4), pion(T[18],4), pion(Cimetiere_IA,4), pion(T[19],4),pion(T[20],4), pion(T[21],4), pion(T[22],4), pion(T[23],4), pion(T[24],4));	

	printf("|");
	for (k=13;k<18;k++) pion_mil(T[k]);
	pion_mil(T[k]);
	printf("|");
	pion_mil(Cimetiere_IA);
	printf("|");
	for (k=19;k<24;k++) pion_mil(T[k]);
	pion_mil(T[k]);
	printf("|\\\n");

	printf("|            |  |            |\\\n");

	printf("|");
	for (k=12;k>7;k--) pion_mil(T[k]);
	pion_mil(T[k]);
	printf("|");
	pion_mil(Cimetiere_U);
	printf("|");
	for (k=6;k>1;k--) pion_mil(T[k]);
	pion_mil(T[k]);
	printf("|\\\n");

	printf("|%c %c %c %c %c %c |%c |%c %c %c %c %c %c |\\  \n", pion(T[12],4),pion(T[11],4), pion(T[10],4), pion(T[9],4), pion(T[8],4), pion(T[7],4), pion(Cimetiere_U,4), pion(T[6],4),pion(T[5],4), pion(T[4],4), pion(T[3],4), pion(T[2],4), pion(T[1],4));	
	printf("|%c %c %c %c %c %c |%c |%c %c %c %c %c %c |\\  \n", pion(T[12],3),pion(T[11],3), pion(T[10],3), pion(T[9],3), pion(T[8],3), pion(T[7],3), pion(Cimetiere_U,3), pion(T[6],3),pion(T[5],3), pion(T[4],3), pion(T[3],3), pion(T[2],3), pion(T[1],3));	
	printf("|%c %c %c %c %c %c |%c |%c %c %c %c %c %c |\\  \n", pion(T[12],2),pion(T[11],2), pion(T[10],2), pion(T[9],2), pion(T[8],2), pion(T[7],2), pion(Cimetiere_U,2), pion(T[6],2),pion(T[5],2), pion(T[4],2), pion(T[3],2), pion(T[2],2), pion(T[1],2));	
	printf("|%c,%c,%c,%c,%c,%c |%c |%c,%c,%c,%c,%c,%c |\\ Sortie : %d \n", pion(T[12],1),pion(T[11],1), pion(T[10],1), pion(T[9],1), pion(T[8],1), pion(T[7],1), pion(Cimetiere_U,1), pion(T[6],1),pion(T[5],1), pion(T[4],1), pion(T[3],1), pion(T[2],1), pion(T[1],1), Sortie_IA);
	printf(" TTTTTTTTTTTTTTTTTTTTTTTTTTTT\\\n");
	printf(" 12  10   8         5   3   1\n");
	printf("   11  9    7     6   4   2\n");
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

void possibles_pion(int c,int i) //Renvoie un char représentant un pion IA 0
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
		//printf("1%c",abs(c)%10+48);
		//color(7,0);
		//Version portable
		//printf("A%c",c%10+48);
		//Version Linux
		couleur("31");
		printf("1%c",abs(c)%10+48);
		couleur("0");
	}
	else if (c >= 10)
		printf("1%c",abs(c)%10+48);
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
		printf("O ");
		couleur("0");
	}
	else if (c <= 10)
		printf("1%c",abs(c)%10+48);
	else if (c >= 10)  //pion possible J2 >= 10
	{
		//Version Windows
		//color(5,0);
		//printf("1%c",abs(c)%10+48); 
		//color(7,0);
		//Version portable
		//printf("Q%c",c%10+48); 
		//Version Linux
		couleur("32");
		printf("1%c",abs(c)%10+48);
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
		printf("O ");
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






void display_pions_possibles_gen(int T[25], int joueur, int Cimetiere_IA, int Cimetiere_U, int Sortie_IA, int Sortie_U)
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
		possibles_pion(T[k],1);
		printf("|%c |", pion(Cimetiere_IA,1));
		for (k=19;k<24;k++)
			possibles_pion_haut_J1(T[k],1);
		possibles_pion(T[k],1);
		printf("|\\	Sortie : %d\n", Sortie_U);
		//Fin Affichage première ligne du plateau
	
	
		for (i=2;i<5;i++)
		{
			printf("|");
			for (k=13;k<19;k++)
				possibles_pion(T[k],i);
			printf("|%c |", pion(Cimetiere_IA,i));
			for (k=19;k<24;k++)
				possibles_pion(T[k],i);
			possibles_pion(T[k],i);
			printf("|\\\n");
		}

		//Affichage milieu du plateau----------------------------------------------
		printf("|");
		for (k=13;k<18;k++)
			possibles_pion_mil_J1(T[k]);
		possibles_pion_mil_J1(T[k]);
		printf("|");
		pion_mil(Cimetiere_IA);
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
		printf("|  |");  //obligatoirement vide sinon display cim
		for (k=6;k>1;k--)
			possibles_pion_mil_J1(T[k]);
		possibles_pion_mil_J1(T[k]);
		printf("|\\\n");
		//Affichage fin du milieu de plateau----------------------------------------
	
		for (i=4;i>1;i--)
		{
			printf("|");
			for (k=12;k>6;k--)
				possibles_pion(T[k],i);
			printf("|  |");  //obligatoirement vide sinon display cim
			for (k=6;k>1;k--)
				possibles_pion(T[k],i);
			possibles_pion(T[k],i);
			printf("|\\\n");
		}
		
		//Affichage dernière ligne du plateau
		printf("|");
		for (k=12;k>7;k--)
			possibles_pion_bas_J1(T[k],1);
		possibles_pion(T[k],1);
		printf("|  |");  //obligatoirement vide sinon display cim
		for (k=6;k>1;k--)
			possibles_pion_bas_J1(T[k],1);
		possibles_pion(T[k],1);
		printf("|\\ Sortie: %d\n", Sortie_IA);
	}




	else if (joueur == 2)
	{
		printf("|");
		for (k=13;k<18;k++)
			possibles_pion_haut_J2(T[k],1);
		possibles_pion_J2(T[k],1);
		printf("|  |");  //obligatoirement vide sinon display cim
		for (k=19;k<24;k++)
			possibles_pion_haut_J2(T[k],1);
		possibles_pion_J2(T[k],1);
		printf("|\\	Sortie : %d\n", Sortie_U);
		//Fin Affichage première ligne du plateau
	
	
		for (i=2;i<5;i++)
		{
			printf("|");
			for (k=13;k<19;k++)
				possibles_pion_J2(T[k],i);
			printf("|  |");  //obligatoirement vide sinon display cim
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
		printf("|  |");  //obligatoirement vide sinon display cim
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
		pion_mil(-Cimetiere_U);
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
			printf("%c ",pion(-Cimetiere_U,i));
			printf("|");
			for (k=6;k>1;k--)
				possibles_pion_J2(T[k],i);
			possibles_pion_J2(T[k],i);
			printf("|\\\n");
		}
		
		//Affichage dernière ligne du plateau
		printf("|");
		for (k=12;k>7;k--)
			possibles_pion_bas_J2(T[k],1);
		possibles_pion_J2(T[k],1);
		printf("|");
		printf("%c ",pion(-Cimetiere_U,1));
		printf("|");
		for (k=6;k>1;k--)
			possibles_pion_bas_J2(T[k],1);
		possibles_pion_J2(T[k],1);
		printf("|\\ Sortie: %d\n", Sortie_IA);
	}
	else printf("\nAucun utilisateur n'a ete selectione\n\n");

	printf(" TTTTTTTTTTTTTTTTTTTTTTTTTTTT\\\n");
	//Fin Affichage dernière ligne du plateau
	
	printf(" 12  10  8         5   3   1\n");
	printf("   11  9   7     6   4   2\n");
}



void display_pions_possibles_cim(int T[25],int joueur, int Cimetiere_IA, int Cimetiere_U, int Sortie_IA, int Sortie_U)
{
	int k,i; //k: case du pion|i: hauteur du pion dans sa case
	
	k=13;
	printf("   14  16  18    19  21  23\n");
	printf(" 13  15  17        20  22  24\n");
	printf(" ____________________________\n");
	if (joueur == U1)
	{	
		printf("|%c'%c'%c'%c'%c'%c |%c |%c'%c'%c'%c'%c'%c |\\ Sortie : %d \n", pion(T[13],1),pion(T[14],1), pion(T[15],1), pion(T[16],1), pion(T[17],1), pion(T[18],1), pion(Cimetiere_IA,1), pion(T[19],1),pion(T[20],1), pion(T[21],1), pion(T[22],1), pion(T[23],1), pion(T[24],1), Sortie_U);
		printf("|%c %c %c %c %c %c |%c |%c %c %c %c %c %c |\\  \n", pion(T[13],2),pion(T[14],2), pion(T[15],2), pion(T[16],2), pion(T[17],2), pion(T[18],2), pion(Cimetiere_IA,2), pion(T[19],2),pion(T[20],2), pion(T[21],2), pion(T[22],2), pion(T[23],2), pion(T[24],2));	
		printf("|%c %c %c %c %c %c |%c |%c %c %c %c %c %c |\\  \n", pion(T[13],3),pion(T[14],3), pion(T[15],3), pion(T[16],3), pion(T[17],3), pion(T[18],3), pion(Cimetiere_IA,3), pion(T[19],3),pion(T[20],3), pion(T[21],3), pion(T[22],3), pion(T[23],3), pion(T[24],3));	
		printf("|%c %c %c %c %c %c |%c |%c %c %c %c %c %c |\\  \n", pion(T[13],4),pion(T[14],4), pion(T[15],4), pion(T[16],4), pion(T[17],4), pion(T[18],4), pion(Cimetiere_IA,4), pion(T[19],4),pion(T[20],4), pion(T[21],4), pion(T[22],4), pion(T[23],4), pion(T[24],4));	

		printf("|");
		for (k=13;k<18;k++) pion_mil(T[k]);
		pion_mil(T[18]);
		printf("|");
		pion_mil(Cimetiere_IA);
		printf("|");
		for (k=19;k<24;k++) pion_mil(T[k]);
		pion_mil(T[24]);
		printf("|\\\n");

		printf("|            |  |            |\\\n");

		printf("|");
		for (k=12;k>7;k--) pion_mil(T[k]);
		pion_mil(T[7]);
		printf("|");
		possibles_pion_mil_J1(-Cimetiere_U);
		printf("|");
		for (k=6;k>1;k--) pion_mil(T[k]);
		pion_mil(T[1]);
		printf("|\\\n");

		for (i=4; i>1; i--)
		{
			printf("|%c %c %c %c %c %c |", pion(T[12],i),pion(T[11],i), pion(T[10],i), pion(T[9],i), pion(T[8],i), pion(T[7],i));	
			possibles_pion(-Cimetiere_U,i);
			printf("|%c %c %c %c %c %c |\\ \n", pion(T[6],i),pion(T[5],i), pion(T[4],i), pion(T[3],i), pion(T[2],i), pion(T[1],i));
		}

		printf("|%c,%c,%c,%c,%c,%c |", pion(T[12],1),pion(T[11],1), pion(T[10],1), pion(T[9],1), pion(T[8],1), pion(T[7],1) );
		possibles_pion(-Cimetiere_U,1);
		printf("|%c,%c,%c,%c,%c,%c |\\ Sortie : %d \n", pion(T[6],1),pion(T[5],1), pion(T[4],1), pion(T[3],1), pion(T[2],1), pion(T[1],1), Sortie_IA);
	}
	else if (joueur == U2)
	{	
		printf("|%c'%c'%c'%c'%c'%c |", pion(T[13],1),pion(T[14],1), pion(T[15],1), pion(T[16],1), pion(T[17],1), pion(T[18],1));
		possibles_pion_J2(Cimetiere_IA,1);
		printf("|%c'%c'%c'%c'%c'%c |\\ Sortie : %d \n", pion(T[19],1),pion(T[20],1), pion(T[21],1), pion(T[22],1), pion(T[23],1), pion(T[24],1), Sortie_U);

		for (i=2; i<5; i++)
		{
			printf("|%c %c %c %c %c %c |", pion(T[13],i),pion(T[14],i), pion(T[15],i), pion(T[16],i), pion(T[17],i), pion(T[18],i));	
			possibles_pion_J2(Cimetiere_IA,i);
			printf("|%c %c %c %c %c %c |\\ \n", pion(T[19],i),pion(T[20],i), pion(T[21],i), pion(T[22],i), pion(T[23],i), pion(T[24],i));
		}

		printf("|");
		for (k=13;k<18;k++) pion_mil(T[k]);
		pion_mil(T[k]);
		printf("|");
		possibles_pion_mil_J2(Cimetiere_IA);
		printf("|");
		for (k=19;k<24;k++) pion_mil(T[k]);
		pion_mil(T[k]);
		printf("|\\\n");

		printf("|            |  |            |\\\n");

		printf("|");
		for (k=12;k>7;k--) pion_mil(T[k]);
		pion_mil(T[k]);
		printf("|");
		pion_mil(-Cimetiere_U);
		printf("|");
		for (k=6;k>1;k--) pion_mil(T[k]);
		pion_mil(T[k]);
		printf("|\\\n");


		printf("|%c %c %c %c %c %c |%c |%c %c %c %c %c %c |\\  \n", pion(T[12],4),pion(T[11],4), pion(T[10],4), pion(T[9],4), pion(T[8],4), pion(T[7],4), pion(-Cimetiere_U,4), pion(T[6],4),pion(T[5],4), pion(T[4],4), pion(T[3],4), pion(T[2],4), pion(T[1],4));	
		printf("|%c %c %c %c %c %c |%c |%c %c %c %c %c %c |\\  \n", pion(T[12],3),pion(T[11],3), pion(T[10],3), pion(T[9],3), pion(T[8],3), pion(T[7],3), pion(-Cimetiere_U,3), pion(T[6],3),pion(T[5],3), pion(T[4],3), pion(T[3],3), pion(T[2],3), pion(T[1],3));	
		printf("|%c %c %c %c %c %c |%c |%c %c %c %c %c %c |\\  \n", pion(T[12],2),pion(T[11],2), pion(T[10],2), pion(T[9],2), pion(T[8],2), pion(T[7],2), pion(-Cimetiere_U,2), pion(T[6],2),pion(T[5],2), pion(T[4],2), pion(T[3],2), pion(T[2],2), pion(T[1],2));	
		printf("|%c,%c,%c,%c,%c,%c |%c |%c,%c,%c,%c,%c,%c |\\ Sortie : %d \n", pion(T[12],1),pion(T[11],1), pion(T[10],1), pion(T[9],1), pion(T[8],1), pion(T[7],1), pion(-Cimetiere_U,1), pion(T[6],1),pion(T[5],1), pion(T[4],1), pion(T[3],1), pion(T[2],1), pion(T[1],1), Sortie_IA);
	}
	printf(" TTTTTTTTTTTTTTTTTTTTTTTTTTTT\\\n");
	printf(" 12  10   8         5   3   1\n");
	printf("   11  9    7     6   4   2\n");
}

void display_pions_possibles(int T[25], int joueur, int Cimetiere_IA, int Cimetiere_U, int Sortie_IA, int Sortie_U)
{
	if ((Cimetiere_U != 0 && joueur == U1) || (Cimetiere_IA != 0 && joueur == U2))
		display_pions_possibles_cim(T, joueur, Cimetiere_IA, Cimetiere_U, Sortie_IA, Sortie_U);
	else
		display_pions_possibles_gen(T, joueur, Cimetiere_IA, Cimetiere_U, Sortie_IA, Sortie_U);
}



void possibles_coups_J1(int T[25], int c, int k,int i, int pos, int de1, int de2)
{	
	if (k == pos) //on est sur le pion de départ
	{
		if (abs(c)==i)
		{
			couleur("31");
			printf("X");
			couleur("0");	
		}
		else 
			printf("%c", pion(c, i));	
	}
	else if (c>1  ||   (k != pos+de1    &&    k != pos+de2 &&    ((T[pos+de1]>0 && T[pos+de2]>0)   ||   k != pos+de1+de2) ))	
		printf("%c", pion(c, i)); // on ne peut pas jouer, on affiche normalement
	else
	{
		if (c == 1 && i == 1)
		{
			couleur("41");
			printf("O");
			couleur("0");
		}
		else if (abs(c) == i-1 && i != 2)
		{
			couleur("41");
			printf(" ");
			couleur("0");
		}
		else
			printf("%c", pion(c,i));
	}
}

void possibles_coups_mil_J1(int T[25], int c, int k, int pos, int de1, int de2)
{
	if (k == pos)  //on est sur la case de départ
	{
		if (c > -5)
			pion_mil(c);
		else if (c == -5)
		{	
			couleur("31");
			printf("X ");
			couleur("0");	
		}
		else if (c > -10)
		{
			couleur("31");
			printf("%c ",abs(c)+48);
			couleur("0");
		}
		else
		{
			couleur("31");
			printf("1%c",abs(c)%10+48);
			couleur("0");
		}
	}
	else if (c>1  ||   (k != pos+de1    &&    k != pos+de2 &&    ((T[pos+de1]>0 && T[pos+de2]>0)   ||   k != pos+de1+de2) ))
		pion_mil(c);  // on ne peut pas jouer, on affiche normalement
	else
	{
		if (c > -4)
			printf("  ");
		else if (c == -4)
		{
			couleur("41");
			printf(" ");
			couleur("0");
			printf(" ");
		}
		else if (c > -9)
		{
			couleur("41");
			printf("%c",abs(c-1)+48);
			couleur("0");
			printf(" ");
		}
		else
		{
			couleur("41");
			printf("1%c",abs(c-1)%10+48);
			couleur("0");
		}
	}
}

void possibles_coups_J2(int T[25], int c, int k,int i, int pos, int de1, int de2)
{	
	if (k == pos) //on est sur la case de départ
	{
		if (c==i)
		{
			couleur("32");
			printf("O");
			couleur("0");	
		}
		else 
			printf("%c", pion(c, i));
	}
	else if (c<-1  ||   (k != pos-de1    &&    k != pos-de2 &&    ((T[pos-de1]<0 && T[pos-de2]<0)   ||   k != pos-de1-de2) ))	
		printf("%c", pion(c, i)); // on ne peut pas jouer, on affiche normalement
	else
	{
		if (c == -1 && i == 1)
		{
			couleur("42");
			printf("X");
			couleur("0");
		}
		else if (c == i-1 && i != 2)
		{
			couleur("42");
			printf(" ");
			couleur("0");
		}
		else
			printf("%c", pion(c,i));
	}
}

void possibles_coups_mil_J2(int T[25], int c, int k, int pos, int de1, int de2)
{
	if (k == pos)  //on est sur la case de départ
	{
		if (c < 5)
			pion_mil(c);
		if (c == 5)
		{	
			couleur("32");
			printf("O ");
			couleur("0");	
		}
		else if (c < 10)
		{
			couleur("32");
			printf("%c ",c+48);
			couleur("0");
		}
		else
		{
			couleur("32");
			printf("1%c",c%10+48);
			couleur("0");
		}
	}
	else if (c<-1  ||   (k != pos-de1    &&    k != pos-de2 &&    ((T[pos-de1]<0 && T[pos-de2]<0)   ||   k != pos-de1-de2) ))
		pion_mil(c);  // on ne peut pas jouer, on affiche normalement
	else
	{
		if (c < 4)
			printf("  ");
		else if (c == 4)
		{
			couleur("42;30");
			printf(" ");
			couleur("0");
			printf(" ");
		}
		else if (c < 9)
		{
			couleur("42;30");
			printf("%c",c+1+48);
			couleur("0");
			printf(" ");
		}
		else
		{
			couleur("42;30");
			printf("1%c",(c+1)%10+48);
			couleur("0");
		}
	}
}

void display_coups_possibles_gen(int T[25], int joueur,int position, int de1, int de2, int Cimetiere_IA, int Cimetiere_U, int Sortie_IA, int Sortie_U)
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
		{
			possibles_coups_J1(T, T[k], k, 1, position, de1, de2);
			printf("'");
		}
		possibles_coups_J1(T, T[k], k, 1, position, de1, de2);
		printf(" |%c |", pion(Cimetiere_IA,1));
		for (k=19;k<24;k++)
		{
			possibles_coups_J1(T, T[k], k, 1, position, de1, de2);
			printf("'");
		}
		possibles_coups_J1(T, T[k], k, 1, position, de1, de2);
		printf(" |\\	Sortie : %d\n", Sortie_U);
		//Fin Affichage première ligne du plateau
	
	
		for (i=2;i<5;i++)
		{
			printf("|");
			for (k=13;k<19;k++)
			{	
				possibles_coups_J1(T, T[k], k, i, position, de1, de2);
				printf(" ");
			}
			printf("|%c |", pion(Cimetiere_IA,i));
			for (k=19;k<24;k++)
			{	
				possibles_coups_J1(T, T[k], k, i, position, de1, de2);
				printf(" ");
			}
			possibles_coups_J1(T, T[k], k, i, position, de1, de2);
			printf(" |\\\n");
		}

		//Affichage milieu du plateau----------------------------------------------
		printf("|");
		for (k=13;k<19;k++)
			possibles_coups_mil_J1(T, T[k], k, position, de1, de2);
		printf("|");
		pion_mil(Cimetiere_IA);
		printf("|");
		for (k=19;k<25;k++)
			possibles_coups_mil_J1(T, T[k], k, position, de1, de2);
		printf("|\\\n");
	
		printf("|            |  |            |\\\n");
	
		printf("|");
		for (k=12;k>6;k--)
			possibles_coups_mil_J1(T, T[k], k, position, de1, de2);
		printf("|  |");  //obligatoirement vide sinon display cim
		for (k=6;k>0;k--)
			possibles_coups_mil_J1(T, T[k], k, position, de1, de2);
		printf("|\\\n");
		//Affichage fin du milieu de plateau----------------------------------------
	
		for (i=4;i>1;i--)
		{
			printf("|");
			for (k=12;k>6;k--)
			{	
				possibles_coups_J1(T, T[k], k, i, position, de1, de2);
				printf(" ");
			}
			printf("|  |");  //obligatoirement vide sinon display cim
			for (k=6;k>1;k--)
			{	
				possibles_coups_J1(T, T[k], k, i, position, de1, de2);
				printf(" ");
			}
			possibles_coups_J1(T, T[k], k, i, position, de1, de2);
			printf(" |\\\n");
		}
		
		//Affichage dernière ligne du plateau
		printf("|");
		for (k=12;k>7;k--)
		{
			possibles_coups_J1(T, T[k], k, 1, position, de1, de2);
			printf(",");
		}
		possibles_coups_J1(T, T[k], k, 1, position, de1, de2);
		printf(" |  |");  //obligatoirement vide sinon display cim
		for (k=6;k>1;k--)
		{
			possibles_coups_J1(T, T[k], k, 1, position, de1, de2);
			printf(",");
		}
		possibles_coups_J1(T, T[k], k, 1, position, de1, de2);
		printf(" |\\ Sortie: %d\n", Sortie_IA);
	}




	else if (joueur == 2)
		{
		printf("|");
		for (k=13;k<18;k++)
		{
			possibles_coups_J2(T, T[k], k, 1, position, de1, de2);
			printf("'");
		}
		possibles_coups_J2(T, T[k], k, 1, position, de1, de2);
		printf(" |%c |", pion(Cimetiere_IA,1));
		for (k=19;k<24;k++)
		{
			possibles_coups_J2(T, T[k], k, 1, position, de1, de2);
			printf("'");
		}
		possibles_coups_J2(T, T[k], k, 1, position, de1, de2);
		printf(" |\\	Sortie : %d\n", Sortie_U);
		//Fin Affichage première ligne du plateau
	
	
		for (i=2;i<5;i++)
		{
			printf("|");
			for (k=13;k<19;k++)
			{	
				possibles_coups_J2(T, T[k], k, i, position, de1, de2);
				printf(" ");
			}
			printf("|%c |", pion(Cimetiere_IA,i));
			for (k=19;k<24;k++)
			{	
				possibles_coups_J2(T, T[k], k, i, position, de1, de2);
				printf(" ");
			}
			possibles_coups_J2(T, T[k], k, i, position, de1, de2);
			printf(" |\\\n");
		}

		//Affichage milieu du plateau----------------------------------------------
		printf("|");
		for (k=13;k<19;k++)
			possibles_coups_mil_J2(T, T[k], k, position, de1, de2);
		printf("|");
		pion_mil(Cimetiere_IA);
		printf("|");
		for (k=19;k<25;k++)
			possibles_coups_mil_J2(T, T[k], k, position, de1, de2);
		printf("|\\\n");
	
		printf("|            |  |            |\\\n");
	
		printf("|");
		for (k=12;k>6;k--)
			possibles_coups_mil_J2(T, T[k], k, position, de1, de2);
		printf("|  |");  //obligatoirement vide sinon display cim
		for (k=6;k>0;k--)
			possibles_coups_mil_J2(T, T[k], k, position, de1, de2);
		printf("|\\\n");
		//Affichage fin du milieu de plateau----------------------------------------
	
		for (i=4;i>1;i--)
		{
			printf("|");
			for (k=12;k>6;k--)
			{	
				possibles_coups_J2(T, T[k], k, i, position, de1, de2);
				printf(" ");
			}
			printf("|  |");  //obligatoirement vide sinon display cim
			for (k=6;k>1;k--)
			{	
				possibles_coups_J2(T, T[k], k, i, position, de1, de2);
				printf(" ");
			}
			possibles_coups_J2(T, T[k], k, i, position, de1, de2);
			printf(" |\\\n");
		}
		
		//Affichage dernière ligne du plateau
		printf("|");
		for (k=12;k>7;k--)
		{
			possibles_coups_J2(T, T[k], k, 1, position, de1, de2);
			printf(",");
		}
		possibles_coups_J2(T, T[k], k, 1, position, de1, de2);
		printf(" |  |");  //obligatoirement vide sinon display cim
		for (k=6;k>1;k--)
		{
			possibles_coups_J2(T, T[k], k, 1, position, de1, de2);
			printf(",");
		}
		possibles_coups_J2(T, T[k], k, 1, position, de1, de2);
		printf(" |\\ Sortie: %d\n", Sortie_IA);
	}

	else printf("\nAucun utilisateur n'a ete selectione\n\n");

	printf(" TTTTTTTTTTTTTTTTTTTTTTTTTTTT\\\n");
	//printf(" T¯T¯T¯T¯T¯T¯T¯¯¯T¯T¯T¯T¯T¯T¯T\\\n");
	//Fin Affichage dernière ligne du plateau
	
	printf(" 12  10  8         5   3   1\n");
	printf("   11  9   7     6   4   2\n");
}

void display_coups_possibles_cim(int T[25], int joueur,int position, int de1, int de2, int Cimetiere_IA, int Cimetiere_U, int Sortie_IA, int Sortie_U)
{
	int k,i; //k: case du pion|i: hauteur du pion dans sa case
	
	k=13;
	printf("   14  16  18    19  21  23\n");
	printf(" 13  15  17        20  22  24\n");
	//Affichage première ligne du plateau
	printf(" ____________________________\n");
	
	if (joueur == 1)
	{
		printf("|%c'%c'%c'%c'%c'%c |%c |%c'%c'%c'%c'%c'%c |\\ Sortie : %d \n", pion(T[13],1),pion(T[14],1), pion(T[15],1), pion(T[16],1), pion(T[17],1), pion(T[18],1), pion(Cimetiere_IA,1), pion(T[19],1),pion(T[20],1), pion(T[21],1), pion(T[22],1), pion(T[23],1), pion(T[24],1), Sortie_U);
		printf("|%c %c %c %c %c %c |%c |%c %c %c %c %c %c |\\  \n", pion(T[13],2),pion(T[14],2), pion(T[15],2), pion(T[16],2), pion(T[17],2), pion(T[18],2), pion(Cimetiere_IA,2), pion(T[19],2),pion(T[20],2), pion(T[21],2), pion(T[22],2), pion(T[23],2), pion(T[24],2));	
		printf("|%c %c %c %c %c %c |%c |%c %c %c %c %c %c |\\  \n", pion(T[13],3),pion(T[14],3), pion(T[15],3), pion(T[16],3), pion(T[17],3), pion(T[18],3), pion(Cimetiere_IA,3), pion(T[19],3),pion(T[20],3), pion(T[21],3), pion(T[22],3), pion(T[23],3), pion(T[24],3));	
		printf("|%c %c %c %c %c %c |%c |%c %c %c %c %c %c |\\  \n", pion(T[13],4),pion(T[14],4), pion(T[15],4), pion(T[16],4), pion(T[17],4), pion(T[18],4), pion(Cimetiere_IA,4), pion(T[19],4),pion(T[20],4), pion(T[21],4), pion(T[22],4), pion(T[23],4), pion(T[24],4));	

		printf("|");
		for (k=13;k<18;k++) pion_mil(T[k]);
		pion_mil(T[k]);
		printf("|");
		pion_mil(Cimetiere_IA);
		printf("|");
		for (k=19;k<24;k++) pion_mil(T[k]);
		pion_mil(T[k]);
		printf("|\\\n");

		printf("|            |  |            |\\\n");		
	
		printf("|");
		for (k=12;k>6;k--)
			possibles_coups_mil_J1(T, T[k], k, position, de1, de2);
		printf("|");
		possibles_pion_mil_J1(-Cimetiere_U);
		printf("|");
		for (k=6;k>0;k--)
			possibles_coups_mil_J1(T, T[k], k, position, de1, de2);
		printf("|\\\n");
		//Affichage fin du milieu de plateau----------------------------------------
	
		for (i=4;i>1;i--)
		{
			printf("|");
			for (k=12;k>6;k--)
			{	
				possibles_coups_J1(T, T[k], k, i, position, de1, de2);
				printf(" ");
			}
			printf("|");
			possibles_pion(-Cimetiere_U,i);
			printf("|");
			for (k=6;k>1;k--)
			{	
				possibles_coups_J1(T, T[k], k, i, position, de1, de2);
				printf(" ");
			}
			possibles_coups_J1(T, T[k], k, i, position, de1, de2);
			printf(" |\\\n");
		}
		
		//Affichage dernière ligne du plateau
		printf("|");
		for (k=12;k>7;k--)
		{
			possibles_coups_J1(T, T[k], k, 1, position, de1, de2);
			printf(",");
		}
		possibles_coups_J1(T, T[k], k, 1, position, de1, de2);
		printf(" |");
		possibles_pion(-Cimetiere_U,i);
		printf("|");
		for (k=6;k>1;k--)
		{
			possibles_coups_J1(T, T[k], k, 1, position, de1, de2);
			printf(",");
		}
		possibles_coups_J1(T, T[k], k, 1, position, de1, de2);
		printf(" |\\ Sortie: %d\n", Sortie_IA);
	}




	else if (joueur == 2)
		{
		printf("|");
		for (k=13;k<18;k++)
		{
			possibles_coups_J2(T, T[k], k, 1, position, de1, de2);
			printf("'");
		}
		possibles_coups_J2(T, T[k], k, 1, position, de1, de2);
		printf(" |");
		possibles_pion_J2(Cimetiere_IA,1);
		printf("|");
		for (k=19;k<24;k++)
		{
			possibles_coups_J2(T, T[k], k, 1, position, de1, de2);
			printf("'");
		}
		possibles_coups_J2(T, T[k], k, 1, position, de1, de2);
		printf(" |\\	Sortie : %d\n", Sortie_U);
		//Fin Affichage première ligne du plateau
	
	
		for (i=2;i<5;i++)
		{
			printf("|");
			for (k=13;k<19;k++)
			{	
				possibles_coups_J2(T, T[k], k, i, position, de1, de2);
				printf(" ");
			}
			printf("|");
			possibles_pion_J2(Cimetiere_IA,i);
			printf("|");
			for (k=19;k<24;k++)
			{	
				possibles_coups_J2(T, T[k], k, i, position, de1, de2);
				printf(" ");
			}
			possibles_coups_J2(T, T[k], k, i, position, de1, de2);
			printf(" |\\\n");
		}

		//Affichage milieu du plateau----------------------------------------------
		printf("|");
		for (k=13;k<19;k++)
			possibles_coups_mil_J2(T, T[k], k, position, de1, de2);
		printf("|");
		possibles_pion_mil_J2(Cimetiere_IA);
		printf("|");
		for (k=19;k<25;k++)
			possibles_coups_mil_J2(T, T[k], k, position, de1, de2);
		printf("|\\\n");
	
		printf("|            |  |            |\\\n");
	
		printf("|");
		for (k=12;k>7;k--) pion_mil(T[k]);
		pion_mil(T[k]);
		printf("|");
		pion_mil(Cimetiere_U);
		printf("|");
		for (k=6;k>1;k--) pion_mil(T[k]);
		pion_mil(T[k]);
		printf("|\\\n");
	
		printf("|%c %c %c %c %c %c |%c |%c %c %c %c %c %c |\\  \n", pion(T[12],4),pion(T[11],4), pion(T[10],4), pion(T[9],4), pion(T[8],4), pion(T[7],4), pion(Cimetiere_U,4), pion(T[6],4),pion(T[5],4), pion(T[4],4), pion(T[3],4), pion(T[2],4), pion(T[1],4));	
		printf("|%c %c %c %c %c %c |%c |%c %c %c %c %c %c |\\  \n", pion(T[12],3),pion(T[11],3), pion(T[10],3), pion(T[9],3), pion(T[8],3), pion(T[7],3), pion(Cimetiere_U,3), pion(T[6],3),pion(T[5],3), pion(T[4],3), pion(T[3],3), pion(T[2],3), pion(T[1],3));	
		printf("|%c %c %c %c %c %c |%c |%c %c %c %c %c %c |\\  \n", pion(T[12],2),pion(T[11],2), pion(T[10],2), pion(T[9],2), pion(T[8],2), pion(T[7],2), pion(Cimetiere_U,2), pion(T[6],2),pion(T[5],2), pion(T[4],2), pion(T[3],2), pion(T[2],2), pion(T[1],2));	
		printf("|%c,%c,%c,%c,%c,%c |%c |%c,%c,%c,%c,%c,%c |\\ Sortie : %d \n", pion(T[12],1),pion(T[11],1), pion(T[10],1), pion(T[9],1), pion(T[8],1), pion(T[7],1), pion(Cimetiere_U,1), pion(T[6],1),pion(T[5],1), pion(T[4],1), pion(T[3],1), pion(T[2],1), pion(T[1],1), Sortie_IA);
	}

	else printf("\nAucun utilisateur n'a ete selectione\n\n");

	printf(" TTTTTTTTTTTTTTTTTTTTTTTTTTTT\\\n");
	//Fin Affichage dernière ligne du plateau
	
	printf(" 12  10  8         5   3   1\n");
	printf("   11  9   7     6   4   2\n");
}


void display_coups_possibles(int T[25], int joueur,int position, int de1, int de2, int Cimetiere_IA, int Cimetiere_U, int Sortie_IA, int Sortie_U)
{
	if (((joueur == U1 && T[position]>-1) || (joueur == U2 && T[position]<1)) && position !=0 && position != 25)
	{
		printf("Coup impossible\n");
	}
	else
	{
		if (Cimetiere_U != 0 && joueur == U1)
			display_coups_possibles_cim( T, joueur, 0, de1, de2, Cimetiere_IA, Cimetiere_U, Sortie_IA, Sortie_U);
		else if (Cimetiere_IA != 0 && joueur == U2)
			display_coups_possibles_cim( T, joueur, 25, de1, de2, Cimetiere_IA, Cimetiere_U, Sortie_IA, Sortie_U);
		else
			display_coups_possibles_gen( T, joueur, position, de1, de2, Cimetiere_IA, Cimetiere_U, Sortie_IA, Sortie_U);
	}
}

void afficher(int T[25])
{
	int i;
	
	for (i=0;i<13;i++)
		printf("%d: %d    %d: %d\n",i,T[i],i+13,T[i+13]);
	printf("\n");
}

