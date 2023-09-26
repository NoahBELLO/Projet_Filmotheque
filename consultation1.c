/*************************
    BELLO Noah
    Bachelor 1 Informatique
    Projet C : Partie 1 
    Nom du fichier : consultation1.c
    Date : 22/12/2022
*************************/

// DIRECTIVE //

#include "fonctions.h"

int main(void)
{
    /*
        PROGRAMME PRINCIPAL
        Paramètres utilisées : film de type Film; flot de type FILE; taille et ret de type int
        Instructions utilisées : 1 return
        Fonction utilisée : Ouverture_Fichier_En_Lecture
    */

    // DÉCLARATIONS DES VARIABLES //

    Film film ;
    FILE *flot;
    int taille, ret;

    // UTILISATION D'UNE FONCTION //

    Ouverture_Fichier_En_Lecture(flot, &taille, film, &ret) ;

    return 0 ;
}