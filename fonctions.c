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

void initTab(char tableau[nblignes][nbcolonnes])
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

int modifTab(char tableau[nblignes][nbcolonnes], joueur repertoire[], int i)
{
    
    int colonne;
    int ligne;
    if(i%2 == 0){
    printf("Au tour de %s :\n\n", repertoire[0].nom);
        printf("Choisir une ligne :\n");
    scanf("%d", &ligne);
        printf("\nChoisir une colonne :\n");
    scanf("%d",&colonne);
    system("cls");
        if(ligne == 0 || colonne == 0){
            return 1;
        }
    while(tableau [ligne -1][colonne -1] != ' '){
        afficherTab(tableau);
        printf("Cette case est deja prise !\n");
        printf("Choisir une ligne :\n");
        scanf("%d", &ligne);
        printf("\nChoisir une colonne :\n");
        scanf("%d",&colonne);
    }
        tableau [ligne -1][colonne -1] ='X';
    afficherTab(tableau);
        return 0;
    } else {
    printf("Au tour de %s :\n\n", repertoire[1].nom);
        printf("Choisir une ligne :\n");
    scanf("%d", &ligne);
        printf("\nChoisir une colonne :\n");
    scanf("%d",&colonne);
    system("cls");
        if(ligne == 0 || colonne == 0){
            return 1;
        }
    while(tableau [ligne -1][colonne -1] != ' '){
        afficherTab(tableau);
        printf("Cette case est deja prise !\n");
        printf("Choisir une ligne :\n");
        scanf("%d", &ligne);
        printf("\nChoisir une colonne :\n");
        scanf("%d",&colonne);
    }
        tableau [ligne -1][colonne -1] ='O';
    afficherTab(tableau);
        return 0;
    }
    
}

void afficherTab(char tableau[nblignes][nbcolonnes])
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

int testGagnant(char tableau[nblignes][nbcolonnes], joueur repertoire[])
{
    int i, j, somme = 0, caseVide = 0;
    for (i=0; i<nblignes; i++, somme=0)
    {
        for (j=0; j<nbcolonnes; j++){
            somme+=tableau[i][j];
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

int testGagnantTournoi(char tableau[nblignes][nbcolonnes], joueur repertoire[], int joueurA, int joueurB)
{
    int i, j, somme = 0, caseVide = 0;
    char car;
    for (i=0; i<nblignes; i++, somme=0)
    {
        for (j=0; j<nbcolonnes; j++){
            somme+=tableau[i][j];
        }
        if(somme==264)
        {
            printf("Felicitations %s, tu remporte la partie !\n", repertoire[joueurA].nom);
            repertoire[joueurA].pointsTournoi+=1;
            printf("\n* Saisir un caractere pour continuer. *\n");
            scanf(" %c", &car);
            system("cls");
            return 1;
        }
        if(somme==237)
        {
            printf("Felicitations %s, tu remporte la partie !\n", repertoire[joueurB].nom);
            repertoire[joueurB].pointsTournoi+=1;
            printf("\n* Saisir un caractere pour continuer. *\n");
            scanf(" %c", &car);
            system("cls");
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
            printf("Felicitations %s, tu remporte la partie !\n", repertoire[joueurA].nom);
            repertoire[joueurA].pointsTournoi+=1;
            printf("\n* Saisir un caractere pour continuer. *\n");
            scanf(" %c", &car);
            system("cls");
            return 1;
        }
        if(somme==237)
        {
            printf("Felicitations %s, tu remporte la partie !\n", repertoire[joueurB].nom);
            repertoire[joueurB].pointsTournoi+=1;
            printf("\n* Saisir un caractere pour continuer. *\n");
            scanf(" %c", &car);
            system("cls");
            return 1;
        }
    }
    if((tableau[0][0] + tableau[1][1] + tableau[2][2] == 264) ||
       (tableau[0][2] + tableau[1][1] + tableau[2][0] == 264))
    {
        printf("Felicitations %s, tu remporte la partie !\n", repertoire[joueurA].nom);
        repertoire[joueurA].pointsTournoi+=1;
        printf("\n* Saisir un caractere pour continuer. *\n");
        scanf(" %c", &car);
        system("cls");
        return 1;
    }
    if((tableau[0][0] + tableau[1][1] + tableau[2][2] == 237) ||
       (tableau[0][2] + tableau[1][1] + tableau[2][0] == 237))
    {
        printf("Felicitations %s, tu remporte la partie !\n", repertoire[joueurB].nom);
        repertoire[joueurB].pointsTournoi+=1;
        printf("\n* Saisir un caractere pour continuer. *\n");
        scanf(" %c", &car);
        system("cls");
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
    int chiffre = 0, tire = 0;
    srand(time(NULL));
    tire = rand()%1;
    printf("Aucun des 2 joueurs n'a gagne \n");
    printf("Procedons a un tirage au sort ! \n");
    printf("%s doit choisir un chiffre entre 0 et 1 : \n", repertoire[joueurA].nom);
    scanf(" %d", &chiffre);
    while(chiffre != 0 && chiffre != 1){
        printf("%s doit choisir un chiffre entre 0 et 1 : \n", repertoire[joueurA].nom);
        scanf(" %d", &chiffre);
    }
    if(chiffre == tire){
        printf("Felicitations %s, tu remporte le tirage !\n", repertoire[joueurA].nom);
        repertoire[joueurA].pointsTournoi+=1;
    } else {
        printf("Felicitations %s, tu remporte le tirage !\n", repertoire[joueurB].nom);
        repertoire[joueurB].pointsTournoi+=1;
    }
    printf("\n* Saisir un caractere pour continuer. *\n");
    scanf(" %c", &car);
    system("cls");
    return 2;
}

int modifTabTournoi(char tableau[nblignes][nbcolonnes], joueur repertoire[], int i, int joueurA, int joueurB)
{

    int colonne;
    int ligne;
    if(i%2 == 0){
        printf("Au tour de %s :\n\n", repertoire[joueurA].nom);
        printf("Choisir une ligne :\n");
        scanf("%d", &ligne);
        system("cls");
        printf("\nChoisir une colonne :\n");
        scanf("%d",&colonne);
        system("cls");
        if(ligne == 0 || colonne == 0){
            return 1;
        }
        while(tableau [ligne -1][colonne -1] != ' '){
        afficherTab(tableau);
        printf("Cette case est deja prise !\n");
        printf("Choisir une ligne :\n");
        scanf("%d", &ligne);
        printf("\nChoisir une colonne :\n");
        scanf("%d",&colonne);
        }
        tableau [ligne -1][colonne -1] ='X';
        afficherTab(tableau);
        return 0;
    } else {
        printf("Au tour de %s :\n\n", repertoire[joueurB].nom);
        printf("Choisir une ligne :\n");
        scanf("%d", &ligne);
        printf("\nChoisir une colonne :\n");
        scanf("%d",&colonne);
        system("cls");
        if(ligne == 0 || colonne == 0){
            return 1;
        }
        while(tableau [ligne -1][colonne -1] != ' '){
            afficherTab(tableau);
            printf("Cette case est deja prise !\n");
            printf("Choisir une ligne :\n");
            scanf("%d", &ligne);
            printf("\nChoisir une colonne :\n");
            scanf("%d",&colonne);
        }
        tableau [ligne -1][colonne -1] ='O';
        afficherTab(tableau);
        return 0;
    }
    
}

void initPointsTournoi(joueur repertoire[]){
    int i = 0;
    for(i=0;i<8;i++){
        repertoire[i].pointsTournoi=0;
    }
}

void tournoi(char tableau[nblignes][nbcolonnes], joueur repertoire[], int nombreJoueurs)
{
    int i, quitter = 0;
    system("cls");
    printf("*** Vous etes en mode tournoi pour %d joueurs ***\n\n", nombreJoueurs);
    switch(nombreJoueurs){
        case 4 :
            initPointsTournoi(repertoire);
            for(i=0;i<4;i++){
                printf("Saisir le nom du joueur %d :\n", i+1);
                scanf(" %s", repertoire[i].nom);
            }
            //Match 1
            initTab(tableau);
            afficherTab(tableau);
            do
            {
                quitter = modifTabTournoi(tableau, repertoire, i, 0, 1);
                i++;
            }
            while(!testGagnantTournoi(tableau, repertoire, 0, 1) && quitter == 0);
            
            //Match 2
            
            initTab(tableau);
            afficherTab(tableau);
            do
            {
                quitter = modifTabTournoi(tableau, repertoire, i, 2, 3);
                i++;
            }
            while(!testGagnantTournoi(tableau, repertoire, 2, 3) && quitter == 0);
            
            //Match Final
            
            /* On trie le tableau en fonction du nombre de points de tournoi */
            int i, j=0;
            int gagnants[10] = {0};
            for(i=0; i<4; i++){
                    if(repertoire[i].pointsTournoi == 1) {
                        gagnants[j] = i;
                        j++;
                    }
                }
            system("cls");
            printf("Finale : %s VS %s\n\n", repertoire[gagnants[0]].nom, repertoire[gagnants[1]].nom);
            initTab(tableau);
            afficherTab(tableau);
            do
            {
                quitter = modifTabTournoi(tableau, repertoire, i, gagnants[0], gagnants[1]);
                i++;
            }
            while(!testGagnantTournoi(tableau, repertoire, gagnants[0], gagnants[1]) && quitter == 0);
            char car;
            for(i=0; i<4; i++){
                if(repertoire[i].pointsTournoi == 2){
                    repertoire[i].score += 10;
                    printf("10 points ont etes ajoutes au score de %s pour avoir remporte le tournoi !\n", repertoire[i].nom);
                    printf("\n* Saisir un caractere pour continuer. *\n");
                    scanf(" %c", &car);
                    system("cls");
                }
            }
            break;
        case 8 :
            initPointsTournoi(repertoire);
            for(i=0;i<8;i++){
                printf("Saisir le nom du joueur %d :\n", i+1);
                scanf(" %s", repertoire[i].nom);
            }
            int k = 0;
            for(j=0,k=1;j<7;j=j+2,k=k+2){
                initTab(tableau);
                afficherTab(tableau);
                do
                {
                    quitter = modifTabTournoi(tableau, repertoire, i, j, k);
                    i++;
                }
                while(!testGagnantTournoi(tableau, repertoire, j, k) && quitter == 0);
            }
            
            /* On trie le tableau en fonction du nombre de points de tournoi */
            for(i=0, j=0; i<8; i++){
                if(repertoire[i].pointsTournoi == 1) {
                    gagnants[j] = i;
                    j++;
                }
            }
            system("cls");
            printf("Demi-Finale 1 : %s VS %s\n\n", repertoire[gagnants[0]].nom, repertoire[gagnants[1]].nom);
            initTab(tableau);
            afficherTab(tableau);
            do
            {
                quitter = modifTabTournoi(tableau, repertoire, i, gagnants[0], gagnants[1]);
                i++;
            }
            while(!testGagnantTournoi(tableau, repertoire, gagnants[0], gagnants[1]) && quitter == 0);
            system("cls");
            printf("Demi-Finale 2 : %s VS %s\n\n", repertoire[gagnants[2]].nom, repertoire[gagnants[3]].nom);
            initTab(tableau);
            afficherTab(tableau);
            do
            {
                quitter = modifTabTournoi(tableau, repertoire, i, gagnants[2], gagnants[3]);
                i++;
            }
            while(!testGagnantTournoi(tableau, repertoire, gagnants[2], gagnants[3]) && quitter == 0);
            
            /* On trie le tableau en fonction du nombre de points de tournoi */
            for(i=0, j=0; i<8; i++){
                if(repertoire[i].pointsTournoi == 2) {
                    gagnants[j] = i;
                    j++;
                }
            }
            
            system("cls");
            printf("Finale : %s VS %s\n\n", repertoire[gagnants[0]].nom, repertoire[gagnants[1]].nom);
            initTab(tableau);
            afficherTab(tableau);
            do
            {
                quitter = modifTabTournoi(tableau, repertoire, i, gagnants[0], gagnants[1]);
                i++;
            }
            while(!testGagnantTournoi(tableau, repertoire, gagnants[0], gagnants[1]) && quitter == 0);
            for(i=0, j=0; i<8; i++){
                if(repertoire[i].pointsTournoi == 3){
                    repertoire[i].score += 20;
                    printf("20 points ont etes ajoutes au score de %s pour avoir remporte le tournoi !\n", repertoire[i].nom);
                    printf("\n* Saisir un caractere pour continuer. *\n");
                    scanf(" %c", &car);
                    system("cls");
                }
            }
            break;
        default:
            printf("Une erreur est survenue !\n");
            break;
    }
}
