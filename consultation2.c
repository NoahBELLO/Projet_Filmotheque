/*************************
    BELLO Noah
    Bachelor 1 Informatique
    Projet C : Partie 2 
    Nom du fichier : consultation2.c
    Date : 22/12/2022
*************************/

// DIRECTIVE //

#include "fonctions.h"

int main(void)
{
    /*
        PROGRAMME PRINCIPAL
        Paramètres utilisées : film et tab_film de type Film; flot de type FILE; taille, choix et compteur de type int
        Instructions utilisées : 1 return
        Fonction utilisée : Ouverture_Fichier_En_Lecture_Avec_Tableau
    */

    // DÉCLARATIONS DES VARIABLES //

    Film film, tab_film[D] ;
    FILE *flot ;
    int taille, choix = -1, compteur ;

    // UTILISATION D'UNE FONCTION //

    Ouverture_Fichier_En_Lecture_Avec_Tableau(flot, &taille, film, tab_film, D, choix, compteur) ;

    return 0 ;
}