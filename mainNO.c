
#include <stdlib.h>
#include <stdio.h>
#include "GraphNO.c";


void main(){
    printf("\n\t------------------->MainNO<-------------------\n\n");
    Graph G = creerGraph();
    int nb_noeuds = 5;
    for(int i=1;i<=nb_noeuds;i++)
        creerNoeudAvecInfo(&G,i);

    for(int i =1;i<=nbreGraph(G);i++){
        afficher_noeud(noeudGraph(G,i));
    }
    printf("----------------------\n");

    creerArc(noeudGraph(G,1),noeudGraph(G,2),1);
    creerArc(noeudGraph(G,1),noeudGraph(G,3),2);
    creerArc(noeudGraph(G,2),noeudGraph(G,4),2);
    creerArc(noeudGraph(G,2),noeudGraph(G,5),3);
    // parcour_DFS(G);
     printf("----------------------\n");
    parcour_BFS(G);
    // for(int i=1;i<=nb_noeuds;i++)
    //     affInfo(noeudGraph(G,i),i*10);

//     // for(int i=1;i<nb_noeuds;i++)
//     //     libererNoeud(&G,noeudGraph(G,1));
//     afficher_graph(G);
//     afficher_noeuds_graph(G);
//     // for(int i =1;i<=nbreGraph(G);i++){
//     //     afficher_noeud(noeudGraph(G,i));
//     // }
//     afficher_noeud(noeudGraph(G,1));

//     //Test avec les arcs

//     afficher_arc_noeud(noeudGraph(G,1));
//     afficher_arc_noeud(noeudGraph(G,2));
//     libererArc(noeudGraph(G,1),noeudGraph(G,2));
//     libererArc(noeudGraph(G,1),noeudGraph(G,3));
//     afficher_arc_noeud(noeudGraph(G,1));
//     afficher_arc_noeud(noeudGraph(G,2));
// afficher_arc_noeud(noeudGraph(G,3));

    // libererArc(noeudGraph(G,1),noeudGraph(G,3));
    // libererArc(noeudGraph(G,1),noeudGraph(G,5));
    // afficher_arc_noeud(noeudGraph(G,1));
    // libererArc(noeudGraph(G,1),noeudGraph(G,4));
    // afficher_arc_noeud(noeudGraph(G,1));
    // libererArc(noeudGraph(G,1),noeudGraph(G,2));
    // afficher_arc_noeud(noeudGraph(G,1));
    // afficher_arc_noeud(noeudGraph(G,2));
}
//afficher_adjacents_noeud(noeudGraph(G,1));
    // for(int i =1;i<=nbreGraph(G);i++){
    //     afficher_noeud(noeudGraph(G,i));
    // }

    // for (int i=2;i<=nb_noeuds;i++){
    //     afficher_arc(arc(noeudGraph(G,1),noeudGraph(G,i)));
    // }
    // afficher_noeud(adjacent(noeudGraph(G,1),1));