#include <stdio.h>
#include <stdlib.h>
#include "affichage.h"
/*
void display(int T[24][2])
{
	int i,j,k;
	
	k=0;
	printf(" __________________________\n");
	for (j=1;j=7;j++)
	{
		if (T[k][0] == 1)
			printf("0 ");
		else	
			printf("  ");
		k++;		
	}
	for (i=2;i<14;i++)
	{
		printf("|");
		for (j=1;j<7;j++)
		{	
			if (T[k][0] == 1)
				printf("0 ");
			else	
				printf("  ");
			k++;
		}
		printf("|");
		for (j=8;j<14;j++)
		{	
			if (T[k][0] == 1)
				printf("0 ");
			else	
				printf("  ");
			k++;
		}
		printf(" | %d\n",k);
	}
	printf(" TTTTTTTTTTTTTTTTTTTTTTTTTT\n");
}
*/
void initialisation() {

	//il faut mettre les pions de bases

	//il faut definir qui joue en premier


}


int main(void)
{
	int T[26][2]={{0},{0}};

	initialisation();
	afficher(T);
	display(T);
	return 0;
}
/*
int main(void)
{
	int i;
	int tableau[10][2];
	for (i = 0; i < 10; i++)
	{
	    tableau[i][1] = i;
	}
	printf("%d",tableau[9][1]);
	return 0;
}
*/
