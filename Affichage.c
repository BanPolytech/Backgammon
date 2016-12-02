#include <stdio.h>


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
void display(int T[26][2])
{
	int i,j,k;
	
	k=0;
	printf(" ____________________________\n");
	
	printf("|");
	for (j=1;j<6;j++)
	{
		printf(" '");
	}
	printf("  ");
	printf("| |");
	for (j=8;j<13;j++)
	{
		printf(" '");
	}
	printf("  ");
	printf(" |\n");
	
	for (i=3;i<14;i++)
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
	
	printf("|");
	for (j=1;j<6;j++)
	{
		printf(" ,");
	}
	printf("  ");
	printf("| |");
	for (j=8;j<13;j++)
	{
		printf(" ,");
	}
	printf("  ");
	printf(" |\n");
	
	printf(" TTTTTTTTTTTTTTTTTTTTTTTTTTTT\n");
}

void afficher(int T[26][2])
{
	int i;
	
	for (i=0;i<26;i++)
		printf("%d: %d %d\n",i,T[i][0],T[i][1]);
	printf("\n");
}
int main(void)
{
	int T[26][2]={{0},{0}};
	//T[0][0]=1; //Il y a 1 pion BLANC à la case 0
	//T[0][1]=0;
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
