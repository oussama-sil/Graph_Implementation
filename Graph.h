#ifndef CONST_IBIB
#define CONST_IBIB


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
    int deg_in;
    int deg_out;
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
TYPE_INFO_ARC info_arc(Arc a);

Arc suiv_arc(Arc a);

Noeud noeud_arc(Arc a);

void aff_info_arc(Arc a,TYPE_INFO_ARC info);

void aff_suiv_arc(Arc a,Arc suiv);

void aff_noeud_arc(Arc a,Noeud noeud);

Arc allouer_arc();

Arc creer_arc(TYPE_INFO_ARC info_arc,Noeud noeud);

void liberer_arc(Arc a);




/*Sur les Noeud*/
TYPE_INFO_NOEUD info_noeud(Noeud n);

Noeud suiv_noeud(Noeud n);

int deg_noeud(Noeud n);

int deg_in(Noeud n);

int deg_out(Noeud n);

Arc liste_arc_noeud(Noeud n);

void aff_info_noeud(Noeud n,TYPE_INFO_NOEUD info);

void aff_suiv_noeud(Noeud n,Noeud suiv);

void aff_deg_noeud(Noeud n,int deg);

void aff_deg_out_noeud(Noeud n,int deg);

void aff_deg_in_noeud(Noeud n,int deg);

void inc_deg_noeud(Noeud n);

void dec_deg_noeud(Noeud n);

void inc_deg_in_noeud(Noeud n);

void dec_deg_in_noeud(Noeud n);

void inc_deg_out_noeud(Noeud n);

void dec_deg_out_noeud(Noeud n);

void aff_liste_arc_noeud(Noeud n,Arc a);

Noeud allouer_noeud();

Noeud creer_noeud(TYPE_INFO_NOEUD info_noeud);

void liberer_noeud(Noeud n);



/****************************************************/
/************Machine virtuelle Graph*****************/
/****************************************************/


/**Cas orienté*/
Graph creerGraph();

Noeud creerNoeud(Graph *G);

Noeud creerNoeudAvecInfo(Graph *G,TYPE_INFO_NOEUD info);

void libererNoeud(Graph *G, Noeud u);

Arc creerArc(Noeud u,Noeud v,TYPE_INFO_ARC info);

void libererArc(Noeud u, Noeud v);

void affInfo(Noeud u,TYPE_INFO_NOEUD info);


Noeud noeudGraph(Graph G,int i);

int nbreGraph(Graph G);

int degre(Noeud u);

TYPE_INFO_NOEUD info(Noeud u);

Arc arc(Noeud u,Noeud v);

TYPE_INFO_ARC InfoArc(Noeud u,Noeud v);

void affArc(Noeud u,Noeud v,TYPE_INFO_ARC info);

Noeud adjacent(Noeud u,int i);


/****************************************************/
/**************Fonctions d'affichage*****************/
/****************************************************/


//! Ces affichages supposent que les info dans les arcs et noeuds sont de type int
void afficher_arc(Arc a);

void afficher_noeud(Noeud n);

void afficher_graph(Graph G);

void afficher_noeuds_graph(Graph G);

void afficher_arc_noeud(Noeud u);

void afficher_adjacents_noeud(Noeud u);





#endif