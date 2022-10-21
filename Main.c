
#include <stdio.h>
#include <stdlib.h>
#include "Graph.c"



void main(){
    Graph G = creerGraph();
    int nb_noeuds = 6;
    for(int i=1;i<=nb_noeuds;i++)
        creerNoeudAvecInfo(&G,i);
    // for(int i=1;i<=nb_noeuds;i++)
    //     affInfo(noeudGraph(G,i),i*10);

    // for(int i=1;i<nb_noeuds;i++)
    //     libererNoeud(&G,noeudGraph(G,1));
    afficher_graph(G);
    afficher_noeuds_graph(G);
    // for(int i =1;i<=nbreGraph(G);i++){
    //     afficher_noeud(noeudGraph(G,i));
    // }

    //Test avec les arcs
    for (int i =2;i<=nb_noeuds;i++){
        creerArc(noeudGraph(G,1),noeudGraph(G,i),i*10+1);
        afficher_noeud(noeudGraph(G,1));
    }
    afficher_arc_noeud(noeudGraph(G,1));
    libererArc(noeudGraph(G,1),noeudGraph(G,3));
    libererArc(noeudGraph(G,1),noeudGraph(G,5));
    afficher_arc_noeud(noeudGraph(G,1));
    libererArc(noeudGraph(G,1),noeudGraph(G,4));
    afficher_arc_noeud(noeudGraph(G,1));
    libererArc(noeudGraph(G,1),noeudGraph(G,2));
    afficher_arc_noeud(noeudGraph(G,1));

}
//afficher_adjacents_noeud(noeudGraph(G,1));
    // for(int i =1;i<=nbreGraph(G);i++){
    //     afficher_noeud(noeudGraph(G,i));
    // }

    // for (int i=2;i<=nb_noeuds;i++){
    //     afficher_arc(arc(noeudGraph(G,1),noeudGraph(G,i)));
    // }
    // afficher_noeud(adjacent(noeudGraph(G,1),1));