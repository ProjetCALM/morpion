//
//  main.c
//  Projet CALM
//  VERSION SANS IA
//
//  Created by Adrien MIGNEROT on 20/12/2017.
//  Copyright © 2017 Projet CALM. All rights reserved.
//

#include "Header.h"

joueur repertoire[REP];
char tableau[nblignes][nbcolonnes];
int i, choix, nombreJoueurs, niveau, quitter = 0;

int main(int argc, const char * argv[]) {
    printf("*** Bienvenue sur le jeu des morpions ! ***\n\n");
    
    while(i != 1){
        printf("*********\n");
        printf("1 - Mode classique (2 joueurs)\n");
        printf("2 - Mode tournoi\n");
        printf("3 - Quitter\n");
        printf("*********\n");
        printf("Que souhaitez-vous faire ?\n");
        scanf("%d", &choix);
        switch(choix){
            case 1 :
                printf("Saisir le nom du premier joueur :\n");
                scanf(" %s", repertoire[0].nom);
                printf("Saisir le nom du second joueur :\n");
                scanf(" %s", repertoire[1].nom);
                
                initTab(tableau); //initialise le jeu avec des cases vides
                afficherTab(tableau); //affiche le jeu (vide)
                do
                {
                    quitter = modifTab(tableau, repertoire, i);//enregistre la saisie du joueur (1 si i est paire, sinon 2).
                    i++;
                }
                while(!testGagnant(tableau, repertoire) && quitter == 0);//test si 3 mêmes cractères sont alignés, si oui, ajoute des points au score du gagnant et le félicite.
                break;
            case 2 :
                printf("Saisir le nombre de joueurs (4 ou 8) :\n");
                scanf("%d", &nombreJoueurs);
                while(nombreJoueurs != 4 && nombreJoueurs != 8){
                    printf("Desole, cette configuration n est pas disponible !\nVous pouvez faire un tournoi de 4 ou 8 joueurs.\n");
                    printf("Saisir le nombre de joueurs :\n");
                    scanf("%d", &nombreJoueurs);
                }
                tournoi(tableau, repertoire, nombreJoueurs);
                break;
            case 3 :
                i = 1;
                break;
            default:
                printf("Votre choix n est pas dans la liste\n");
                break;
        }
    }
    return 0;
}
