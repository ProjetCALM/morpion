//
//  main.c
//  Projet CALM
//  VERSION NON FINALE
//
//  Created by Adrien MIGNEROT on 20/12/2017.
//  Copyright © 2017 Projet CALM. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <MacTypes.h>

#ifndef Source_h
#define Source_h
#define NOM ((int)100)
#define REP ((int)50)
#define nblignes 3
#define nbcolonnes 3

typedef struct //Joueur
{
    char nom[NOM];
    int score;
}joueur;

joueur initJoueur(void);
void inittab(char tableau[nblignes][nbcolonnes]);
void modiftab(char tableau[nblignes][nbcolonnes], joueur repertoire[], int i);
void affichertab(char tableau[nblignes][nbcolonnes]);
int testgagnant(char tableau[nblignes][nbcolonnes], joueur repertoire[]);

#endif /* Source_h */
