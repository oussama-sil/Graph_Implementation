#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
#include "LLC.c"



/*-------------------------------------------------------------------*/
/*--------------------IMPLEMENTATION FILE D'ATTENTE-----------------*/
/*-----------------------------------------------------------------*/




typedef struct file_attente* pointeur_file;
typedef struct file_attente file_attente;
struct file_attente
{
	POINTEUR_LI tete;
	POINTEUR_LI queue;
};

void creer_file(file_attente *Fil)
{
	Fil->tete = NULL;
	Fil->queue = NULL;
}

int file_vide(file_attente Fil)
{
	if (Fil.tete == NULL)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
void enfiler(file_attente *Fil, int val)
{

	POINTEUR_LI q = NULL;
	q = malloc(sizeof(MAILLON_LI));
	aff_val_li(q, val);
	aff_adr_li(q, NULL);
	if (!file_vide(*Fil))
	{
		(Fil->queue)->suiv = q;
	}
	else
	{
		(Fil->tete) = q;
	}
	Fil->queue = q;
}

void defiler(file_attente  *Fil, int* val)
{
	POINTEUR_LI sauv = NULL;
	if (!file_vide(*Fil))
	{
		sauv = Fil->tete;
		*val = VALEUR(Fil->tete);
		Fil->tete = SUIVANT(Fil->tete);
		LIBERER_LI(sauv);

	}
	else
	{
		printf("underflow : file d'attente vide !!!\n");
		system("pause");
	}
}
