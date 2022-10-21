#include <stdio.h>
#include <stdlib.h>
#include "file_attente.c"

#define TYPE_INFO_ARC int
#define TYPE_INFO_NOEUD int

#define true 1
#define false 0
#define Boolean int
/****************************************************/
/**********Les structure de donneés *****************/
/****************************************************/

/*Structure liste des noeud*/
typedef struct MAILLON_Noeud MAILLON_Noeud;
typedef struct MAILLON_Noeud* Noeud;
typedef struct MAILLON_Arc MAILLON_Arc;
typedef struct MAILLON_Arc* Arc;


struct MAILLON_Noeud
{
    TYPE_INFO_NOEUD infoNoeud;
    int deg;
    Noeud suiv;
    Arc ptrListeArc;
};


/*Structure liste des arcs*/

struct MAILLON_Arc
{
    TYPE_INFO_ARC infoArc;
    Arc suiv;
    // Noeud origine_arc;
    // Noeud dest_arc;
    Noeud noeud;
};



/*Structure graph*/
typedef struct Graph Graph;
struct Graph
{
    Noeud Prem;
    Noeud Dern;
    int nbNoeud;
};

/****************************************************/
/***************Opérations de bases *****************/
/****************************************************/

/*Sur les Arcs*/
TYPE_INFO_ARC info_arc(Arc a){
    return a->infoArc;
}

Arc suiv_arc(Arc a){
    return a->suiv;
}

Noeud noeud_arc(Arc a){
    return a->noeud;
}

void aff_info_arc(Arc a,TYPE_INFO_ARC info){
    a->infoArc = info;
}

void aff_suiv_arc(Arc a,Arc suiv){
    a->suiv = suiv;
}

void aff_noeud_arc(Arc a,Noeud noeud){
    a->noeud= noeud;
}

Arc allouer_arc(){
    Arc a= malloc(sizeof(MAILLON_Arc));
    a->infoArc = 0;
    a->suiv = NULL;
    a->noeud  = NULL;
    return a;
}

Arc creer_arc(TYPE_INFO_ARC info_arc,Noeud noeud){
    Arc a= malloc(sizeof(MAILLON_Arc));
    a->infoArc = info_arc;
    a->suiv = NULL;
    a->noeud  = noeud;
    return a;
}

void liberer_arc(Arc a){
    free(a);
    return NULL;
}




/*Sur les Noeud*/
TYPE_INFO_NOEUD info_noeud(Noeud n){
    return n->infoNoeud;
}

Noeud suiv_noeud(Noeud n){
    return n->suiv;
}

int deg_noeud(Noeud n){
    return n->deg;
}



Arc liste_arc_noeud(Noeud n){
    return n->ptrListeArc;
}

void aff_info_noeud(Noeud n,TYPE_INFO_NOEUD info){
    n->infoNoeud = info;
}

void aff_suiv_noeud(Noeud n,Noeud suiv){
    n->suiv = suiv;
}

void aff_deg_noeud(Noeud n,int deg){
    n->deg = deg;
}



void inc_deg_noeud(Noeud n){
    n->deg = n->deg+1;
}
void dec_deg_noeud(Noeud n){
    n->deg = n->deg-1;
}



void aff_liste_arc_noeud(Noeud n,Arc a){
    n->ptrListeArc = a;
}

Noeud allouer_noeud(){
    Noeud a= malloc(sizeof(MAILLON_Noeud));
    a->deg = 0;
    a->infoNoeud = 0;
    a->ptrListeArc = NULL;
    a->suiv = NULL;
    return a;
}

Noeud creer_noeud(TYPE_INFO_NOEUD info_noeud){
    Noeud a= malloc(sizeof(MAILLON_Noeud));
    a->deg = 0;
    a->infoNoeud = info_noeud;
    a->ptrListeArc = NULL;
    a->suiv = NULL;
    return a;
}

void liberer_noeud(Noeud n){
    free(n);
    return NULL;
}



/****************************************************/
/************Machine virtuelle Graph*****************/
/****************************************************/


/**Cas orienté*/
Graph creerGraph(){
    Graph a;
    a.Dern = NULL;
    a.Prem = NULL;
    a.nbNoeud = 0;
    return a;
}

Noeud creerNoeud(Graph *G){
    Noeud n = allouer_noeud();
    if(G->Prem == NULL){ //Cas premier noeud
        G->Prem = n;
        G->Dern = n;
    }else{
        Noeud tmp = G->Dern;
        aff_suiv_noeud(tmp,n);
        G->Dern = n;
    }
    G->nbNoeud = G->nbNoeud +1;
    return n;
}
Noeud creerNoeudAvecInfo(Graph *G,TYPE_INFO_NOEUD info){
    Noeud n = allouer_noeud();
    aff_info_noeud(n,info);
    if(G->Prem == NULL){ //Cas premier noeud
        G->Prem = n;
        G->Dern = n;
    }else{
        Noeud tmp = G->Dern;
        aff_suiv_noeud(tmp,n);
        G->Dern = n;
    }
    G->nbNoeud = G->nbNoeud +1;
    return n;
}


void libererNoeud(Graph *G, Noeud u){
    if(u==NULL){
        return false;
    }
    Noeud q = NULL;
    Noeud p = G->Prem;
    while(p != u && p!=NULL){
        q=p;
        p = p->suiv;
    }
    if(p==u){
        if(q != NULL){ //cas pas premier
            aff_suiv_noeud(q,p->suiv);
            if(G->Dern == u){
                G->Dern=q;
            }
        }else{ //cas premier
            G->Prem = u->suiv;
            if(G->Dern == u){
                G->Dern=q;
            }
        }
        G->nbNoeud -=1;
        //Supression des arc adjacents des noeuds
        Arc a = u->ptrListeArc;
        Arc tmp = NULL;
        while(a != NULL){
            tmp = a;
            a= a->suiv;
            dec_deg_noeud(noeud_arc(tmp));
            liberer_arc(tmp);
        }
        liberer_noeud(u);
        return false;
    }else{
        return false;
    }
}


Arc creerArc(Noeud u,Noeud v,TYPE_INFO_ARC info){
    if(u==v){
        return NULL;
    }
    Arc a = allouer_arc();
    aff_info_arc(a,info);
    aff_noeud_arc(a,v);
    aff_suiv_arc(a,liste_arc_noeud(u));
    aff_liste_arc_noeud(u,a);
    inc_deg_noeud(u);

    Arc b = allouer_arc();
    aff_info_arc(b,info);
    aff_noeud_arc(b,u);
    aff_suiv_arc(b,liste_arc_noeud(v));
    aff_liste_arc_noeud(v,b);
    inc_deg_noeud(v);
    return a;
}

void libererArc(Noeud u, Noeud v){
    Arc q = NULL;
    Arc p = liste_arc_noeud(u);
    int stop = 0;
    while(p!=NULL && stop==0){
        if(noeud_arc(p)==v){
            stop=1;
        }else{
            q=p;
            p=suiv_arc(p);
        }
    }
    if(stop==1){ //arc trouve dans p et son prec est q
        if(q != NULL){ //cas pas premier
            aff_suiv_arc(q,suiv_arc(p));
        }else{ //cas premier
            aff_liste_arc_noeud(u,suiv_arc(p));
        }
        dec_deg_noeud(u);
        liberer_arc(p);
    }

    /*****/
    q = NULL;
    p = liste_arc_noeud(v);
    stop = 0;
    while(p!=NULL && stop==0){
        if(noeud_arc(p)==u){
            stop=1;
        }else{
            q=p;
            p=suiv_arc(p);
        }
    }
    if(stop==1){ //arc trouve dans p et son prec est q
        if(q != NULL){ //cas pas premier
            aff_suiv_arc(q,suiv_arc(p));
        }else{ //cas premier
            aff_liste_arc_noeud(v,suiv_arc(p));
        }
        dec_deg_noeud(v);
        liberer_arc(p);
    }
}

void affInfo(Noeud u,TYPE_INFO_NOEUD info){
    aff_info_noeud(u,info);
}



Noeud noeudGraph(Graph G,int i){ //i est numero du noeud et va de [1..G.nbrNoeud]
    Noeud n = G.Prem;
    int indx = 1;
    while(indx<i && indx <= G.nbNoeud){
        indx ++;
        n=n->suiv;
    }
    if(indx==i && indx<= G.nbNoeud){
        return n;
    }else{
        return NULL;
    }
}

int nbreGraph(Graph G){
    return G.nbNoeud;
}

int degre(Noeud u){
    return u->deg;
}

TYPE_INFO_NOEUD info(Noeud u){
    return info_noeud(u);
}

Arc arc(Noeud u,Noeud v){
    Arc p = liste_arc_noeud(u);
    int stop = 0;
    while(p!=NULL && stop==0){
        if(noeud_arc(p)==v){
            stop=1;
        }else{
            p=suiv_arc(p);
        }
    }
    if(stop==1){ //arc trouve dans p et son prec est q
        return p;
    }else {
        return NULL;
    }
}

TYPE_INFO_ARC InfoArc(Noeud u,Noeud v){
    return info_arc(arc(u,v));
}

void affArc(Noeud u,Noeud v,TYPE_INFO_ARC info){
    aff_info_arc(arc(u,v),info);
    aff_info_arc(arc(v,u),info);
}

Noeud adjacent(Noeud u,int i){  // les adjacent dans [1..deg(u)]
    int indx =1;
    Arc p = liste_arc_noeud(u);
    int stop = 0;
    while(p!=NULL && stop == 0){
        if(indx==i){
            stop = 1;
        }else{
            p=suiv_arc(p);
            indx++;
        }
    }
    if(stop==1){
        return noeud_arc(p);
    }else{
        return NULL;
    }
}


/****************************************************/
/**************Fonctions d'affichage*****************/
/****************************************************/


//! Ces affichages supposent que les info dans les arcs et noeuds sont de type int
void afficher_arc(Arc a){
    if(a!=NULL){
        printf("Arc : { info : %d , ",a->infoArc);
        if (noeud_arc(a) == NULL){
            printf(" info_noeud : NULL ,");
        }else{
            printf(" info_noeud : %d ,",info_noeud(noeud_arc(a)));
        }
        if (suiv_arc(a) == NULL){
            printf("  suiv: NULL ,");
        }else{
            printf(" suiv : %d ,",info_arc(suiv_arc(a)));
        }
        printf("}\n");
    }else{
        printf("{NULL}");
    }

}
void afficher_noeud(Noeud n){
    if(n!=NULL){
        printf("Noeud : { info : %d , deg : %d ,",info_noeud(n),deg_noeud(n));
        if (liste_arc_noeud(n) == NULL){
            printf(" info_premier_arc : NULL ,");
        }else{
            printf(" info_premier_arc : %d ,",info_arc(liste_arc_noeud(n)));
        }
        if (suiv_noeud(n) == NULL){
            printf("  suiv: NULL ");
        }else{
            printf(" suiv : %d ",info_noeud(suiv_noeud(n)));
        }
        printf("}\n");
    }else{
        printf("{NULL}");
    }

}

void afficher_graph(Graph G){
    if(G.Prem != NULL){
        printf("G :{ premier_noeud : %d , ",info_noeud(G.Prem));
    }else{
        printf("{ premier_noeud : NULL , ");
    }
    if(G.Dern != NULL){
        printf("dernier_noeud : %d , ",info_noeud(G.Dern));
    }else{
        printf(" dernier_noeud : NULL , ");
    }
    printf(": nombre_noeud : %d }\n",G.nbNoeud);
}
void afficher_noeuds_graph(Graph G){
    printf("Noeuds G : { nb_noeuds : %d , noeuds : ",G.nbNoeud);
    Noeud p = G.Prem;
    while(p != NULL){
        printf(" -> %d ",info_noeud(p));
        p=suiv_noeud(p);
    }
    printf("}\n");
}

void afficher_arc_noeud(Noeud u){
    printf("Arc noeuds : { nb_arcs : %d , (info_arc,noeuds) : ",degre(u));
    Noeud p = liste_arc_noeud(u);
    while(p != NULL){
        printf(" -> (%d,%d) ",info_arc(p),info_noeud(noeud_arc(p)));
        p=suiv_arc(p);
    }
    printf("}\n");
}

void afficher_adjacents_noeud(Noeud u){
    printf("Adjacents : { nb_arcs : %d , noeuds : ",degre(u));
    Noeud p = liste_arc_noeud(u);
    while(p != NULL){
        printf(" -> %d ",info_noeud(noeud_arc(p)));
        p=suiv_arc(p);
    }
    printf("}\n");
}





/*********************************/
/**********Algo DFS**************/

int getNoeudPos(Graph G,Noeud n){
    Noeud p = G.Prem;
    int indx = 1;
    while(p != n && p != NULL){
        indx++;
        p = suiv_noeud(p);
    }
    if(p != NULL){
        return indx;
    }else{
        return -1;
    }
}

void DFS(Graph G,int noeud_indx,Boolean Visite[]){
    Visite[noeud_indx-1] = true;
    printf("\t->Visite du noeud : %d\n",info(noeudGraph(G,noeud_indx)));
    for(int i=1;i<=degre(noeudGraph(G,noeud_indx));i++){
        if( Visite[getNoeudPos(G,adjacent(noeudGraph(G,noeud_indx),i))-1]==false){
            DFS(G,getNoeudPos(G,adjacent(noeudGraph(G,noeud_indx),i)),Visite);
        }
    }
}

int parcour_DFS(Graph G){
    printf("\n\t------------------->Parcour DFS<-------------------\n");
    Boolean *Visite =  malloc(nbreGraph(G)*sizeof(Boolean));
    int composante = 0;
    for(int i = 0;i<nbreGraph(G);i++){
        Visite[i]=false;
    }

    for(int i = 1;i<=nbreGraph(G);i++){
        if(Visite[i-1]==false){
            composante++;
            printf("-->Visite composante %d : \n",composante);
            DFS(G,i,Visite);
        }
    }
    return composante;
}




/*********************************/
/**********Algo BFS**************/

void BFS(Graph G,int noeud_indx,Boolean Visite[]){
    file_attente F;
    creer_file(&F);
    Visite[noeud_indx-1] = true;
    printf("\t->Visite du noeud : %d\n",info(noeudGraph(G,noeud_indx)));
    enfiler(&F,noeud_indx);
    int a;
    int tmp;
    while(!file_vide(F)){
        defiler(&F,&a);
        for(int i  = 1;i<=degre(noeudGraph(G,a));i++){
            tmp = getNoeudPos(G,adjacent(noeudGraph(G,a),i));  // pos de l'adjacent
            if(Visite[tmp-1]==false){
                printf("\t->Visite du noeud : %d\n",info(noeudGraph(G,tmp)));
                Visite[tmp-1]=true;
                enfiler(&F,tmp);
            }
        }
    }
}
void parcour_BFS(Graph G){
    printf("\n\t------------------->Parcour BFS<-------------------\n");
    Boolean *Visite =  malloc(nbreGraph(G)*sizeof(Boolean));
    int composante = 0;
    for(int i = 0;i<nbreGraph(G);i++){
        Visite[i]=false;
    }

    for(int i = 1;i<=nbreGraph(G);i++){
        if(Visite[i-1]==false){
            composante++;
            printf("-->Visite composante %d : \n",composante);
            BFS(G,i,Visite);
        }
    }
}


/*****TD03*/

void DFS_Exp(Graph G,int noeud_indx,Boolean Visite[],int exp){
    Visite[noeud_indx-1] = true;
    for(int i=1;i<=degre(noeudGraph(G,noeud_indx));i++){
        if( Visite[getNoeudPos(G,adjacent(noeudGraph(G,noeud_indx),i))-1]==false && getNoeudPos(G,adjacent(noeudGraph(G,noeud_indx),i)) != exp ){
            DFS_Exp(G,getNoeudPos(G,adjacent(noeudGraph(G,noeud_indx),i)),Visite,exp);
        }
    }
}



void pts_articulation_connexe(Graph G){ //cas connexe 
    printf("\n\t------------------->Point d'articulation<-------------------\n");
    int *arti = malloc(nbreGraph(G)*sizeof(int));
    Boolean *Visite = malloc(nbreGraph(G)*sizeof(Boolean));
    int next;
    int test = false;
    for(int i=1;i<=nbreGraph(G);i++){
        for(int j = 0;j<nbreGraph(G);j++){
            Visite[j]=false;
        }
        next = (i % nbreGraph(G)) +1;
        // printf("%d %d\n",i,next);
        DFS_Exp(G,next,Visite,i);
        test=true;
        for(int j = 0;j<nbreGraph(G);j++){
            // printf("-%d %d\n",j+1,Visite[j]);
           if(j==i-1 && Visite[j]==true){
                test=false;
           }else if(j != i-1 && Visite[j]==false){
            test=false;
           }
        }
        if(test==false){
            printf("-->Le %d eme (info = %d) est un pts d'articulation \n",i,info(noeudGraph(G,i)));
        }
    }
}


void pts_articulation(Graph G){ //cas connexe 
    printf("\n\t------------------->Point d'articulation<-------------------\n");
    int *arti = malloc(nbreGraph(G)*sizeof(int));
    Boolean *Visite = malloc(nbreGraph(G)*sizeof(Boolean));
    int next;
    int test = false;
    int nb_composante = parcour_DFS(G);
    int tmp_comp = 0;
    for(int i=1;i<=nbreGraph(G);i++){  //tester chaque noeud 
        for(int j = 0;j<nbreGraph(G);j++){
            Visite[j]=false;
        }
        tmp_comp = 0;
        for(int k = 1;k<=nbreGraph(G);k++){
            if(Visite[k-1]==false && k!=i){
                tmp_comp++;
                DFS_Exp(G,k,Visite,i);
            }
        }
        if(tmp_comp > nb_composante){
            printf("-->Le %d eme (info = %d) est un pts d'articulation \n",i,info(noeudGraph(G,i)));
        }
    }
}