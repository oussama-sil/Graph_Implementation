#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
#define MAILLON_TYPE int
/*--------------------------------------------------------------------*/
/*-------------------------------------------------------------------*/
/*------------------------------------------------------------------*/
typedef struct MAILLON_LI MAILLON_LI;
typedef struct MAILLON_LI* POINTEUR_LI;
struct MAILLON_LI
{
    int val;
    struct MAILLON_LI * suiv;
};
/*--------------------------------------------*/
/*------LA MACHINE ABSTRAITE-----------------*/
/*------------------------------------------*/
int VALEUR(POINTEUR_LI p)
{
    return p->val;
}

POINTEUR_LI SUIVANT(POINTEUR_LI p)
{
    return p->suiv;
}

void aff_val_li(POINTEUR_LI p,int valeur)
{
    p->val=valeur;
}

void aff_adr_li(POINTEUR_LI p, POINTEUR_LI q)
{
    p->suiv=q;
}

void ALLOUER_LI(POINTEUR_LI *p)
{
    *p=malloc(sizeof(MAILLON_LI));
    (*p)->suiv=NULL;
    (*p)->val=0;
}

void LIBERER_LI(POINTEUR_LI p)
{
    free(p);
}

/*----------------------------------------*/
/*----------------------------------------*/
/*----------------------------------------*/

int length_li(POINTEUR_LI p) ///donne le nombre d'elements d'une liste
{
    int cpt = 0;
    while(p!=NULL)
    {
        p = SUIVANT(p);
        cpt+=1;
    }
    return cpt;
}

/*----------------------------------------*/
/*----------------------------------------*/

int freq_val_li(POINTEUR_LI p,int val) /// donne le nombre d'apparitin d'une valeur val dans une liste
{
    int cpt=0;
    while(p!=NULL)
    {
        if(VALEUR(p)==val)
        {
            cpt++;
        }
        p=SUIVANT(p);
    }
    return cpt;
}

/*----------------------------------------*/
/*----------------------------------------*/

int elem_li_max_freq(POINTEUR_LI p) ///donne l'element avec le plus grand nombre d'apparitions
{
    int val,freq=0;
    POINTEUR_LI q=p;
    if(p==NULL)
    {
        printf("ERROR : PAS DE LISTE");
        return  106;

    }
    else
    {
        val=VALEUR(q);
        freq=freq_val_li(p,VALEUR(q));
        q=SUIVANT(q);
        while(q!=NULL)
        {
            if(freq_val_li(p,VALEUR(q))>freq)
            {
                freq=freq_val_li(p,VALEUR(q));
                val=VALEUR(q);
            }
            q=SUIVANT(q);
        }
        return val;
    }
}
/*---------------------------------------*/
/*---------------------------------------*/
void LECT_LI(POINTEUR_LI *p)
{
    *p=NULL;
    POINTEUR_LI q=  NULL;
    POINTEUR_LI r=NULL;
    int nombre=0;
    int encore=1;
    int i=1;
    printf("\n");
    printf("entrez la %d er valeur de la liste: ",i);
    i++;
    scanf("%d",&nombre);
    ALLOUER_LI(&q);
    aff_val_li(q,nombre);
    *p=q;
    printf("encore [1-oui/0-non]:  ");
    scanf("%d",&encore);
    while(encore)
    {
        printf("entrez la %d er valeur de la liste: ",i);
        i++;
        scanf("%d",&nombre);
        ALLOUER_LI(&r);
        aff_val_li(r,nombre);
        aff_adr_li(q,r);
        q=r;
        printf("encore [1-oui/0-non]: ");
        scanf("%d",&encore);
    }
    system("cls");
    printf("\n");
}
/*----------------------------------------*/
/*----------------------------------------*/

/*----------------------------------------*/
/*----------------------------------------*/

void supp_val_liste(POINTEUR_LI *tete, int val)///supprimer dans une liste les elements dont la valeur est egale a val
{
    POINTEUR_LI p=*tete;
    POINTEUR_LI q=*tete;

    while(q!=NULL)
    {
    if(p!=q)
    {
        if(VALEUR(q)==val)
        {
            aff_adr_li(p,SUIVANT(q));
            q=SUIVANT(q);
        }
        else
        {
            p=q;
            q=SUIVANT(q);
        }
    }
    else
    {
        if(VALEUR(q)==val)
        {
            p=SUIVANT(p);
            q=SUIVANT(q);
            *tete=p;
        }
        else
        {
            q=SUIVANT(q);
        }
    }
    }


}
/*--------------*/
/*--*---------------*/
void permut_val_maillon(POINTEUR_LI p,POINTEUR_LI q)///faire la permutaion des valeurs de deux maillon
{
    int val=0;
    val=VALEUR(p);
    aff_val_li(p,VALEUR(q));
    aff_val_li(q,val);
}
/*--------------------*/
/*--------------------*/

void tri_bulle_li(POINTEUR_LI p)///faire le tri des elements d'une liste par le tri bulle
{
    int test=0;
    POINTEUR_LI q=NULL;
    while(test==0)
    {
        q=p;
        test=1;
        while(SUIVANT(q)!=NULL)
        {
            if(VALEUR(q)>VALEUR(SUIVANT(q)))
            {
                permut_val_maillon(q,SUIVANT(q));
                test=0;
            }
            q=SUIVANT(q);
        }
    }
}

/*--------------------*/
/*--------------------*/

void interclassement_li(POINTEUR_LI p1,POINTEUR_LI p2,POINTEUR_LI *p3)///faire l'interclassement de deux listes triees
{
    POINTEUR_LI p=NULL;
    POINTEUR_LI q=NULL;
    while((p1!=NULL)&&(p2!=NULL))
    {
        if(VALEUR(p1)<VALEUR(p2))
        {
            ALLOUER_LI(&q);
            aff_val_li(q,VALEUR(p1));
            if(p!=NULL)
            {
                aff_adr_li(p,q);
            }
            else
            {
                *p3=q;
            }
            p=q;
            p1=SUIVANT(p1);
        }
        else
        {
            ALLOUER_LI(&q);
            aff_val_li(q,VALEUR(p2));
            if(p!=NULL)
            {
                aff_adr_li(p,q);
            }
            else
            {
                *p3=q;
            }
            p=q;
            p2=SUIVANT(p2);
        }
    }

    while(p1!=NULL)
    {
        ALLOUER_LI(&q);
        aff_val_li(q,VALEUR(p1));
        if(p!=NULL)
        {
            aff_adr_li(p,q);
        }
        else
        {
            *p3=q;
        }
        p=q;
        p1=SUIVANT(p1);
    }
    while(p2!=NULL)
    {
        ALLOUER_LI(&q);
        aff_val_li(q,VALEUR(p2));
        if(p!=NULL)
        {
            aff_adr_li(p,q);
        }
        else
        {
            *p3=q;
        }
        p=q;
        p2=SUIVANT(p2);
    }
}



/*----------------------------------*/
/*---------------------------------*/
void insert_val_pos_llc(POINTEUR_LI* tete, int pos, int val) //insertion d'une valeur a une position (1_..)  dans une liste 
{
    int i = 1;
    POINTEUR_LI p = *tete;
    POINTEUR_LI q = NULL;
    POINTEUR_LI r = NULL;
    while (i < pos)
    {
        q = p;
        p = SUIVANT(p);
        i += 1;
    }

    ALLOUER_LI(&r);
    aff_val_li(r, val);
    if (q == NULL)
    {
        aff_adr_li(r, *tete);
        *tete = r;
    }
    else
    {
        aff_adr_li(r, p);
        aff_adr_li(q, r);
    }
}
/*----------------------------------*/
/*---------------------------------*/
/*------------------------------*/
/*-----------------------------*/


int recherche_valeur_llc(POINTEUR_LI tete, int valeur, int* position, POINTEUR_LI* point_pos)//0 si non existe --- 1 sinon 
{
    POINTEUR_LI p = tete;
    int trouv = 0;
    int cpt = 1;
    *position = 0;
    *point_pos = NULL;
    while ((p != NULL) && (trouv == 0))
    {
        if (VALEUR(p) == valeur)
        {
            trouv = 1;
            *position = cpt;
            *point_pos = p;
        }
        p = SUIVANT(p);
        cpt++;
    }
    return trouv;
}

/*------------------------*/
/*-------------------------*/
/*-------------------------*/

void supp_pos_li(POINTEUR_LI* tete, int position)/*----supprimer l'element a la position -1<=position- -------------*/
{
    POINTEUR_LI p = *tete;
    POINTEUR_LI q = NULL;
    POINTEUR_LI sauv = NULL;
    int i = 1;
    while ((i < position) && (p != NULL))
    {
        q = p;
        p = SUIVANT(p);
        i++;
    }
    if (p != NULL)
    {
        if (i == 1)
        {
            sauv = *tete;
            *tete = SUIVANT(*tete);
            LIBERER_LI(sauv);
        }
        else
        {
            sauv = p;
            p = SUIVANT(p);
            LIBERER_LI(sauv);
            aff_adr_li(q, p);
        }
    }

}

/*------------------------*/
/*-------------------------*/
/*-------------------------*/

void supp_val_li(POINTEUR_LI* tete, int valeur)/*----supprimer les elements dont la valeur est egale a val -------------*/
{
    int i = 1;
    POINTEUR_LI p = *tete;
    while (p != NULL)
    {
        if (VALEUR(p) == valeur)
        {
            p = SUIVANT(p);
            supp_pos_li(tete, i);
        }
        else
        {
            i++;
            p = SUIVANT(p);
        }
    }
}

/*------------------------*/
/*-------------------------*/
/*-------------------------*/

void interclassement_li_vol2(POINTEUR_LI* tete_1, POINTEUR_LI* tete_2, POINTEUR_LI* tete_3)/*---cette procedure fait l'interclassementde en fesant le chainage entre les maillons des deux listes ------------- */
{
    POINTEUR_LI p = NULL;
    POINTEUR_LI p1 = *tete_1;
    POINTEUR_LI p2 = *tete_2;

    if (VALEUR(p1) < VALEUR(p2))
    {
        *tete_3 = p1;
        p = *tete_1;
        p1 = SUIVANT(p1);
    }
    else
    {
        *tete_3 = p2;
        p = *tete_2;
        p2 = SUIVANT(p2);

    }
    while ((p1 != NULL) && (p2 != NULL))
    {
        if (VALEUR(p1) < VALEUR(p2))
        {
            aff_adr_li(p, p1);
            p = p1;
            p1 = SUIVANT(p1);
        }
        else
        {
            aff_adr_li(p, p2);
            p = p2;
            p2 = SUIVANT(p2);
        }
    }

    while (p1 != NULL)
    {
        aff_adr_li(p, p1);
        p = p1;
        p1 = SUIVANT(p1);
    }

    while (p2 != NULL)
    {
        aff_adr_li(p, p2);
        p = p2;
        p2 = SUIVANT(p2);
    }
}

/*----------------*/
/*---------------------------*/
/*--------------------------*/
int valeur_pos_li(POINTEUR_LI tete, int position) /*-----donne la valeur a la position -position- ou 1<=position-------- */
{
    int i = 1;
    POINTEUR_LI p = tete;
    POINTEUR_LI q = NULL;
    int valeur = 0;
    while ((i < position) && (p != NULL))
    {
        i++;
        q = p;
        p = SUIVANT(p);
    }
    if (p != NULL)
    {
        valeur = VALEUR(p);
    }
    else
    {
        printf("position existe pas !!!");
        system("pause");
        valeur = 00;
    }
    return valeur;
}

/*----------------------------*/
/*---------------------------*/
/*--------------------------*/


/*---------------------------------------------------*/
/*--------------------------------------------------*/


void permut_maillon_vol_2(POINTEUR_LI p1, POINTEUR_LI p2, POINTEUR_LI p3, POINTEUR_LI* tete) ///SUIOVANT(p3)=p1
{
    //POINTEUR_LI sauv = SUIVANT(p1);
    aff_adr_li(p1, SUIVANT(p2));
    aff_adr_li(p2, p1);
    if (p3 != NULL) {
        aff_adr_li(p3, p2);
    }
    else
    {
        *tete = p2;
    }
}

//--------------------------------------------------------


//--------------------------------------------------------------------


void recherche_elem_llc(POINTEUR_LI tete, int* trouv, POINTEUR_LI* point_elem, int elem)
{
    if (tete == NULL)
    {
        *trouv = 0;
    }
    else
    {
        if (VALEUR(tete) == elem)
        {
            *trouv = 1;
            *point_elem = tete;
        }
        else
        {
            recherche_elem_llc(SUIVANT(tete), trouv, point_elem, elem);
        }
    }
}
//------------------------------------------------------------------------

void inv_llc(POINTEUR_LI* tete, POINTEUR_LI q)
{
    if (SUIVANT(q) == NULL)
    {
        *tete = q;
    }
    else
    {
        inv_llc(tete, SUIVANT(q));
        aff_adr_li(SUIVANT(q), q);
        aff_adr_li(q, NULL);
    }
}
