/*************************
    BELLO Noah
    Bachelor 1 Informatique
    Projet C : Partie 3 
    Nom du fichier : consultation3.c
    Date : 22/12/2022
*************************/

// DIRECTIVE //

#include "fonctions.h"

int main(void)
{
    /*
        PROGRAMME PRINCIPAL
        Paramètres utilisées : film1 et tab_film de type Film; flot de type FILE; mot_clef de type char; 
    taille, choix, pos et compteur de type int
        Instructions utilisées : 1 return
        Fonction utilisée : Ouverture_Fichier_En_Lecture_Et_Affichage_Resultat
    */

    // DÉCLARATIONS DES VARIABLES //

    Film film, tab_film[D] ;
    FILE *flot ;
    char mot_clef[N] ;
    int taille, choix = -1, compteur = 0, pos;

    // UTILISATION D'UNE FONCTION //

    Ouverture_Fichier_En_Lecture_Et_Affichage_Resultat(flot, &taille, film, tab_film, D, &compteur, pos, mot_clef, &choix) ;
    
    return 0 ;
}