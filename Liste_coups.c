typedef struct coup
{
	int joueur;
	int depart;
	int deplacement;
	struct coup *suivant;
}coup, *t_coup;