//
//  main.c
//  Projet CALM
//  VERSION NON FINALE
//
//  Created by Adrien MIGNEROT on 20/12/2017.
//  Copyright © 2017 Projet CALM. All rights reserved.
//

#include "Header.h"

joueur repertoire[REP];
char tableau[nblignes][nbcolonnes];
int i = 0;

int main(int argc, const char * argv[]) {
    printf("*** Bienvenue sur le jeu des morpions ! ***\n\n");
    printf("Saisir le nom du premier joueur :\n");
    scanf(" %s", repertoire[0].nom);
    printf("Saisir le nom du second joueur :\n");
    scanf(" %s", repertoire[1].nom);
    
    inittab(tableau); //initialise le jeu avec des cases vides
    affichertab(tableau); //affiche le jeu (vide)
    do
    {
        modiftab(tableau, repertoire, i);//enregistre la saisie du joueur (1 si i est paire, sinon 2).
        i++;
    }
    while(!testgagnant(tableau, repertoire));//test si 3 mêmes cractères sont alignés, si oui, ajoute des points au score du gagnant et le félicite.
    return 0;
}
