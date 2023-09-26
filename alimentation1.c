/*************************
    BELLO Noah
    Bachelor 1 Informatique
    Projet C : Partie 1 
    Nom du fichier : alimentation1.c
    Date : 22/12/2022
*************************/

// DIRECTIVE //

#include "fonctions.h"

int main(void)
{
    /*
        PROGRAMME PRINCIPAL
        Paramètres utilisées : film1 de type Film; flot de type FILE; taille et nbr de type int
        Instructions utilisées : 1 return
        Fonction utilisée : Ouverture_Fichier_En_Ecriture
    */

    // DÉCLARATIONS DES VARIABLES //

    Film film1 = Creation_Film() ;
    FILE *flot ;
    int taille, nbr ;

    // UTILISATION D'UNE FONCTION //

    Ouverture_Fichier_En_Ecriture(flot, &taille, film1, &nbr) ;

    return 0 ;
}