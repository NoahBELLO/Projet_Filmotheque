/*************************
    BELLO Noah
    Bachelor 1 Informatique
    Projet C : Partie 3 
    Nom du fichier : alimentation3.c
    Date : 22/12/2022
*************************/

// DIRECTIVE //

#include "fonctions.h"

int main(void)
{
    /*
        PROGRAMME PRINCIPAL
        Paramètres utilisées : film1 et tab_film de type Film; flot de type FILE; titre de type char; taille, nbr et test de type int
        Instructions utilisées : 1 return
        Fonction utilisée : Ouverture_Fichier_En_Lecture_Et_Ajout
    */

    // DÉCLARATIONS DES VARIABLES //

    Film film1, tab_film[D] ;
    FILE *flot ;
    char titre[N] ;
    int taille, nbr, test ;

    // UTILISATION D'UNE FONCTION //
    
    Ouverture_Fichier_En_Lecture_Et_Ajout(flot, film1, &taille, &nbr, &test, titre, tab_film, D) ;
    
    return 0;
}