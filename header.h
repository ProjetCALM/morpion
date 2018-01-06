//
//  main.c
//  Projet CALM
//  VERSION SANS IA
//
//  Created by Adrien MIGNEROT on 20/12/2017.
//  Copyright © 2017 Projet CALM. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
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
    int pointsTournoi;
}joueur;

joueur initJoueur(void);
void initTab(char tableau[nblignes][nbcolonnes]);
int modifTab(char tableau[nblignes][nbcolonnes], joueur repertoire[], int i);
void afficherTab(char tableau[nblignes][nbcolonnes]);
int testGagnant(char tableau[nblignes][nbcolonnes], joueur repertoire[]);
void tournoi(char tableau[nblignes][nbcolonnes], joueur repertoire[], int nombreJoueurs);
void initPointsTournoi(joueur repertoire[]);
int testGagnantTournoi(char tableau[nblignes][nbcolonnes], joueur repertoire[], int joueurA, int joueurB);
int modifTabTournoi(char tableau[nblignes][nbcolonnes], joueur repertoire[], int i, int joueurA, int joueurB);

#endif /* Source_h */
