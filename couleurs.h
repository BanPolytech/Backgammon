<<<<<<< HEAD
//#include <windows.h>
#include <stdio.h>
#include <stdlib.h>


#ifndef COULEURS
#define COULEURS

=======
#ifndef COULEURS
#define COULEURS

#include <stdio.h>

>>>>>>> master
#define clrscr() printf("\033[H\033[2J")
#define couleur(param) printf("\033[%sm",param)


#endif
<<<<<<< HEAD
/*
void color(int t,int f)
{
        HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
            SetConsoleTextAttribute(H,f*16+t);
}
*/
=======

>>>>>>> master
