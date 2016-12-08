#include <stdio.h>




char pion(int T[26][2],int k,int i) //Renvoie un char représentant un pion blanc
{									//un pion noir, ou le vide		
	if (i > T[k][0])
		return ' ';
	else if (T[k][1]==0)
		return 'O';
	else
		return 'X';
}

void pion_mil(int T[26][2],int k)
{	
	if (T[k][0] < 5)
		printf("  ");
	else if (T[k][0] > 10)
	{
		printf("1%c",T[k][0]%10+48);
	}
	else if (T[k][0] > 5 && T[k][0] < 10)
		printf("%c ",T[k][0]+48);
	else if (T[k][1]==0)
		printf("O ");
	else
		printf("X ");
}


void display(int T[26][2])
{
	int k,i; //k: case du pion|i: hauteur du pion dans sa case
	
	k=13;
	
	//Affichage première ligne du plateau
	printf(" ___________________________\n");
	
	printf("|");
	for (k=13;k<18;k++)
	{
		printf("%c'",pion(T,k,1));
	}
	printf("%c ",pion(T,k,1));
	printf("|%c|",pion(T,25,1));
	for (k=19;k<24;k++)
	{
		printf("%c'",pion(T,k,1));
	}
	printf("%c ",pion(T,k,1));
	printf("|\\\n");
	//Fin Affichage première ligne du plateau
	
	
	for (i=2;i<5;i++)
	{
		printf("|");
		for (k=13;k<19;k++)
		{
			printf("%c ",pion(T,k,i));
		}
		printf("|%c|",pion(T,25,i));
		for (k=19;k<24;k++)
		{
			printf("%c ",pion(T,k,i));
		}
		printf("%c ",pion(T,k,i));
		printf("|\\\n");
	}

	/*Affichage milieu du plateau----------------------------------------------*/
	printf("|");
	for (k=13;k<18;k++)
	{
		pion_mil(T,k);
	}
	pion_mil(T,k);
	printf("| |");
	for (k=19;k<24;k++)
	{
		pion_mil(T,k);
	}
	pion_mil(T,k);
	printf("|\\\n");

	printf("|            | |            |\\\n");

	printf("|");
	for (k=12;k>7;k--)
	{
		pion_mil(T,k);
	}
	pion_mil(T,k);
	printf("| |");
	for (k=6;k>1;k--)
	{
		pion_mil(T,k);
	}
	pion_mil(T,k);
	printf("|\\\n");
	/*Affichage fin du milieu de plateau----------------------------------------*/
	
	for (i=4;i>1;i--)
	{
		printf("|");
		for (k=12;k>6;k--)
		{
			printf("%c ",pion(T,k,i));
		}
		printf("|%c|",pion(T,0,i));
		for (k=6;k>1;k--)
		{
			printf("%c ",pion(T,k,i));
		}
		printf("%c ",pion(T,k,i));
		printf("|\\\n");
	}
	
	//Affichage dernière ligne du plateau
	printf("|");
	for (k=12;k>7;k--)
	{
		printf("%c,",pion(T,k,i));
	}
	printf("%c ",pion(T,k,i));
	printf("|%c|",pion(T,0,i));
	for (k=6;k>1;k--)
	{
		printf("%c,",pion(T,k,i));
	}
	printf("%c ",pion(T,k,i));
	printf("|\\\n");
	
	printf(" TTTTTTTTTTTTTTTTTTTTTTTTTTT\\\n");
	//Fin Affichage dernière ligne du plateau
}


void afficher(int T[26][2])
{
	int i;
	
	for (i=0;i<13;i++)
		printf("%d: %d %d    %d: %d %d\n",i,T[i][0],T[i][1],i+13,T[i+13][0],T[i+13][1]);
	printf("\n");
}

int main(void)
{
	int T[26][2]={{0},{0}};
	
	T[1][0]=2;
	T[1][1]=1;
	T[6][0]=5;
	T[6][1]=0;
	T[8][0]=3;
	T[8][1]=0;
	T[12][0]=5;
	T[12][1]=1;
	T[13][0]=5;
	T[13][1]=0;
	T[17][0]=3;
	T[17][1]=1;
	T[19][0]=5;
	T[19][1]=1;
	T[24][0]=2;
	T[24][1]=0;
	
	afficher(T);
	display(T);
	return 0;
}

