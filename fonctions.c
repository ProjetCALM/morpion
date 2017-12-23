//
//  main.c
//  Projet CALM
//  VERSION NON FINALE
//
//  Created by Adrien MIGNEROT on 20/12/2017.
//  Copyright © 2017 Projet CALM. All rights reserved.
//

#include <stdio.h>
#include <time.h>
#include <string.h>
#include <MacTypes.h>
#include "Header.h"

joueur initJoueur(){
    joueur variable;
    memset(variable.nom,0,NOM);
    variable.score = 0;
    return variable;
}

void inittab(char tableau[nblignes][nbcolonnes])
{
    int i = 0;
    int j = 0;
    for(i=0;i<nblignes;i++)
    {
        for(j=0;j<nbcolonnes;j++)
        {
            tableau[i][j] = ' ' ;
        }
        
    }
    
}

void modiftab(char tableau[nblignes][nbcolonnes], joueur repertoire[], int i)
{
    
    int colonne;
    int ligne;
    if(i%2 == 0){
    printf("Au tour de %s :\n\n", repertoire[0].nom);
        printf("Choisir une ligne :\n");
    scanf("%d", &ligne);
        printf("\nChoisir une colonne :\n");
    scanf("%d",&colonne);
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
    tableau [ligne -1][colonne -1] ='X';
    affichertab(tableau);
    } else {
    printf("Au tour de %s :\n\n", repertoire[1].nom);
        printf("Choisir une ligne :\n");
    scanf("%d", &ligne);
        printf("\nChoisir une colonne :\n");
    scanf("%d",&colonne);
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
    tableau [ligne -1][colonne -1] ='O';
    affichertab(tableau);
    }
    
}

void affichertab(char tableau[nblignes][nbcolonnes])
{
    printf("\n\n\n");
    printf("\t+-----------+\n");
    printf("\t| %c | %c | %c |\n", tableau[0][0], tableau[0][1], tableau[0][2]);
    printf("\t+-----------+\n");
    printf("\t| %c | %c | %c |\n", tableau[1][0], tableau[1][1], tableau[1][2]);
    printf("\t+-----------+\n");
    printf("\t| %c | %c | %c |\n", tableau[2][0], tableau[2][1], tableau[2][2]);
    printf("\t+-----------+\n");
    printf("\n\n\n");
    
    
}

int testgagnant(char tableau[nblignes][nbcolonnes], joueur repertoire[])
{
    int i, j, somme, caseVide = 0;
    for (i=0; i<nblignes; i++, somme=0)
    {
        for (j=0; j<nbcolonnes; j++){
            somme=somme+tableau[i][j];
        }
        if(somme==264)
        {
            printf("Felicitations %s, tu remporte la partie !\n", repertoire[0].nom);
            repertoire[0].score+=1;
            return 1;
        }
        if(somme==237)
        {
            printf("Felicitations %s, tu remporte la partie !\n", repertoire[1].nom);
            repertoire[1].score+=1;
            return 1;
        }
    }
    for(j=0 ; j<nbcolonnes ; j++, somme=0)
    {
        for(i=0 ; i<nblignes ; i++){
            somme+=tableau[i][j] ;
        }
        if(somme==264)
        {
            printf("Felicitations %s, tu remporte la partie !\n", repertoire[0].nom);
            repertoire[0].score+=1;
            return 1;
        }
        if(somme==237)
        {
            printf("Felicitations %s, tu remporte la partie !\n", repertoire[1].nom);
            repertoire[1].score+=1;
            return 1;
        }
    }
    if((tableau[0][0] + tableau[1][1] + tableau[2][2] == 264) ||
       (tableau[0][2] + tableau[1][1] + tableau[2][0] == 264))
    {
        printf("Felicitations %s, tu remporte la partie !\n", repertoire[0].nom);
        repertoire[0].score+=1;
        return 1;
    }
    if((tableau[0][0] + tableau[1][1] + tableau[2][2] == 237) ||
       (tableau[0][2] + tableau[1][1] + tableau[2][0] == 237))
    {
        printf("Felicitations %s, tu remporte la partie !\n", repertoire[1].nom);
        repertoire[1].score+=1;
        return 1;
    }
    /* Test si le tableau est plein :*/
    for(i=0; i<nblignes; i++, caseVide = 0){
        for(j=0; j<nbcolonnes; j++) {
            if(tableau[i][j] == ' '){
                return 0;
            }
        }
    }
                printf("Aucun des 2 joueurs n'a gagne \n");
                return 2;
}
