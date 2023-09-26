/*************************
    BELLO Noah
    Bachelor 1 Informatique
    Projet C : Directives, Définition de la structure, Prototypes
    Nom du fichier : fonctions.h
    Date : 22/12/2022
*************************/

//DIRECTIVES//

#include <stdio.h>
#include <string.h> //permet l'utilisation de strcpy, strcmp et strstr
#define N 101  //pour définir la dimension des tableaux de chaînes de caractères dans la déclaration du type Film
#define D 10 //pour définir la dimension du tableau de type Film

// DÉCLARATION STRUCTURE //

typedef struct
{
    /*
        Déclaration du type Film
        Nombre de champ : 5
        Type des champs : 2 chaînes de caractères (char), 2 entiers (int) et 1 réel (float)
        Instructions utilisées : 1 typedef et 1 struct
    */

    char titre[N] ;
    char metteur_en_scene[N] ;
    int annee_de_sortie ; 
    int public;
    float prix_location ;
} Film ;

// PROTOTYPES //

// GÉNÉRAL //
Film Creation_Film(void) ;

// PARTIE 1 //
void Ouverture_Fichier_En_Ecriture(FILE *flot, int *taille, Film film1, int *nbr) ;
void Ouverture_Fichier_En_Lecture(FILE *flot, int *taille, Film film1, int *ret) ;

// PARTIE 2 //
void Ouverture_Fichier_En_Ajout(FILE *flot, int *taille, Film film, int *nbr) ;
void Ouverture_Fichier_En_Lecture_Avec_Tableau(FILE *flot, int *taille, Film film, Film tab[], int nb, int choix, int compteur) ;

// PARTIE 3 //
void Ouverture_Fichier_En_Lecture_Et_Ajout(FILE *flot, Film film, int *taille, int *nbr, int *test, char titre[], Film tab[], int nb) ;
void Ouverture_Fichier_En_Lecture_Et_Affichage_Resultat(FILE *flot, int *taille, Film film, Film tab[], int nb, int *c, int p, char m[], int *choix) ;