#include <stdio.h>
#include <stdlib.h>

void display(int T[26][2])
{
	int i,j,k;
	
	k=0;
	printf(" ____________________________\n");
	for (i=2;i<14;i++)
	{
		printf("|");
		for (j=1;j<7;j++)
		{	
			printf("  ");
			k++;
		}
		printf("|");
		printf(" ");
		printf("|"); 
		for (j=8;j<14;j++)
		{	
			printf("  ");
			k++;
		}
		printf(" | %d\n",k);
	}
	printf(" TTTTTTTTTTTTTTTTTTTTTTTTTTTT\n");
}

void afficher(int T[26][2])
{
	int i;
	
	for (i=0;i<26;i++)
		printf("%d: %d %d\n",i,T[i][0],T[i][1]);
	printf("\n");
}