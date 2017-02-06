
typedef struct coup {
	int joueur;
	int depart;
	int deplacement;
}coup, *tpc;

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

	//il faut definir qui joue en premier
