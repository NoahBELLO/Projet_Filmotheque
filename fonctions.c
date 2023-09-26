/*************************
    BELLO Noah
    Bachelor 1 Informatique
    Projet C : Déclaration des fonctions
    Nom du fichier : fonctions.c
    Date : 22/12/2022
*************************/

// DÉCLARATIONS FONCTIONS //

#include "fonctions.h"

// FONCTIONS GÉNÉRAUX //

void Verification(int *a, int *pu, float *pr)
{
    /*
        Le nom de la fonction est Verification, elle permet de vérifier la saisie de l'année, du public et du prix.
        Dans le cas, où l'utilisateur saisi des valeurs incohérentes elle redemandera de saisir une valeur cohérente.
        Elle reçoit trois paramètres, deux de type int en pointeur et un de type float en pointeur.
        Elle ne renvoie pas de valeurs.
        Instructions utilisées : 3 while, 6 printf, 3 scanf, 3 if
        Fonction non demandée dans les consignes mais facilite la lecture du programme principal.
    */

    while((*a < 1891) || (*a > 2023))
    {
        printf("Annee : ") ;
        scanf("%d", a) ;
        if((*a < 1891) || (*a > 2023)) printf("Erreur sur la saisie de l'annee de sortie\n\n") ;
    }

    while((*pu < 0) || (*pu > 1))
    {
        printf("Tout public = 1 sinon 0 : ") ;
        scanf("%d", pu) ;
        if((*pu < 0) || (*pu > 1)) printf("Erreur sur la saisie si c'est public ou pas\n\n") ;
    }

    while(*pr <= 0)
    {
        printf("Prix : ") ;
        scanf("%f", pr) ;
        if(*pr <= 0) printf("Erreur sur la saisie du prix de location\n\n") ;
    }
}

void Saisir(char t[], char m[], int *a, int *pu, float *pr)
{
    /*
        Le nom de la fonction est Saisir, elle permet de saisir des valeurs.
        Elle reçoit cinq paramètres, deux de type char en tableau, deux de type int en pointeur et un de type float en pointeur.
        Elle ne renvoie pas de valeurs.
        Instructions utilisées : 2 printf, 2 scanf
        Fonction utilisé : Verification
        Fonction non demandée dans les consignes mais facilite la lecture du programme principal.
    */

    printf("Titre : ") ;
    scanf("%s", t) ;

    printf("Metteur en scene : ") ;
    scanf("%s", m) ;

    Verification(a, pu, pr) ;
}

Film Creation_Film(void)
{
    /*
        Le nom de la fonction est Creation_Film, elle permet de créer une variable de type Film.
        Elle ne reçoit pas de paramètres, et renvoie une valeur de type Film.
        Instructions utilisées : 2 strcpy, 1 return
        Fonction utilisé : Saisir
        Fonction non demandée dans les consignes mais facilite la lecture du programme principal.
    */

    Film f ;
    int a = 0, pu = -1 ;
    float pr = -1.0 ;
    char t[N], m[N] ;

    Saisir(t, m, &a, &pu, &pr) ;

    strcpy(f.titre, t) ; 
    strcpy(f.metteur_en_scene, m); 
    f.annee_de_sortie = a ; 
    f.public = pu ; 
    f.prix_location = pr ;

    return f ;
}

void Affiche_Resultat(Film f)
{
    /*
        Le nom de la fonction est Affiche_Resultat, elle permet d'afficher la fiche du film.
        Elle reçoit un paramètre type Film, et ne renvoie pas de valeurs.
        Instructions utilisées : 2 printf, 1 if et 1 else if
        Fonction non demandée dans les consignes mais facilite la lecture du programme principal.
    */

    if (f.public == 1) printf("Titre : %s\nMetteur en scene : %s\nAnnee : %d\nTout public\nPrix : %0.2f\n\n", f.titre, f.metteur_en_scene, f.annee_de_sortie, f.prix_location) ;
    else if (f.public == 0) printf("Titre : %s\nMetteur en scene : %s\nAnnee : %d\nReserve aux adultes\nPrix : %0.2f\n\n", f.titre, f.metteur_en_scene, f.annee_de_sortie, f.prix_location) ;
}

int Test_Ouverture(FILE *flot)
{
    /*
        Le nom de la fonction est Test_Ouverture, elle permet de vérifier si le fichier s'ouvre.
        Elle reçoit un paramètre type FILE, et renvoie une valeur de type int.
        Instructions utilisées : 1 if, 1 return et 1 perror
        Fonction non demandée dans les consignes mais facilite la lecture du programme principal.
    */

    if(flot == NULL)
    {
        perror("Faute ouverture ") ;
        return 0 ;
    }
}

int Test_Ecriture(int *nbr)
{
    /*
        Le nom de la fonction est Test_Ecriture, elle permet de vérifier si on écrit bien dans le fichier.
        Elle reçoit un paramètre type int en pointeur, et renvoie une valeur de type int.
        Instructions utilisées : 1 if, 1 return et 1 perror
        Fonction non demandée dans les consignes mais facilite la lecture du programme principal.
    */

    if(*nbr != 1)
    {
        perror("Faute ecriture ") ;
        return 0 ;
    }
}

// FONCTIONS PARTIE 1 //

void Ouverture_Fichier_En_Ecriture(FILE *flot, int *taille, Film film1, int *nbr)
{
    /*
        Le nom de la fonction est Ouverture_Fichier_En_Ecriture, elle permet de d'ouvrir un fichier et d'écrire dedans.
        Elle reçoit quatre paramètres, deux de type int en pointeur, un de type Film et un de type FILE.
        Elle ne renvoie pas de valeur.
        Instructions utilisées : 1 fopen, 1 fclose, 1 fwrite
        Fonctions utilisées : Test_Ouverture, Test_Ecriture
        Fonction non demandée dans les consignes mais facilite la lecture du programme principal.
    */

    // Ouverture du fichier "filmotheque"
    flot = fopen("filmotheque", "w") ;
    Test_Ouverture(flot) ;

    *taille = sizeof(film1) ;

    // Enregistrement de la donnée
    *nbr = fwrite(&film1, *taille, 1, flot) ;
    Test_Ecriture(nbr) ;

    // Fermeture du fichier 
    fclose(flot) ;
}

int Test_Lecture(int *ret, Film film)
{
    /*
        Le nom de la fonction est Test_Lecture, elle permet de vérifier si on lit bien dans le fichier.
        Elle reçoit deux paramètres, un de type int en pointeur et un de type Film et renvoie une valeur de type int.
        Instructions utilisées : 1 if, 1 else if, 1 return et 1 perror
        Fonction utilisée : Affiche_Resultat
        Fonction non demandée dans les consignes mais facilite la lecture du programme principal.
    */

    if (*ret == -1) {
        perror("Faute lecture : ");
        return 0 ;
    }

    else if (*ret == 0); 
    Affiche_Resultat(film) ;
}

void Ouverture_Fichier_En_Lecture(FILE *flot, int *taille, Film film1, int *ret)
{
    /*
        Le nom de la fonction est Ouverture_Fichier_En_Lecture, elle permet d'ouvrir un fichier et de lire dedans.
        Elle reçoit quatre paramètres, deux de type int en pointeur, un de type Film et un de type FILE.
        Elle ne renvoie pas de valeur.
        Instructions utilisées : 1 fopen, 1 fclose, 1 fread
        Fonctions utilisées : Test_Ouverture, Test_Lecture
        Fonction non demandée dans les consignes mais facilite la lecture du programme principal.
    */

    // Ouverture du fichier "filmotheque" 
    flot = fopen ("filmotheque", "r"); 
    Test_Ouverture(flot) ;

    *taille = sizeof(film1);
    
    // Lire la donnee 
    *ret = fread(&film1, *taille, 1, flot); 
    Test_Lecture(ret, film1) ;

    // Fermeture du fichier 
    fclose(flot); 
}

// FONCTIONS PARTIE 2 //

void Ouverture_Fichier_En_Ajout(FILE *flot, int *taille, Film film, int *nbr)
{
    /*
        Le nom de la fonction est Ouverture_Fichier_En_Ajout, elle permet d'ouvrir un fichier et de rajouter une donnée sans 
    écraser la donnée précédente.
        Elle reçoit quatre paramètres, deux de type int en pointeur, un de type Film et un de type FILE.
        Elle ne renvoie pas de valeur.
        Instructions utilisées : 1 fopen, 1 fclose, 1 fwrite
        Fonctions utilisées : Test_Ouverture, Test_Ecriture
        Fonction non demandée dans les consignes mais facilite la lecture du programme principal.
    */

    // Ouverture du fichier "filmotheque"
    flot = fopen("filmotheque", "a") ;
    Test_Ouverture(flot) ;

    *taille = sizeof(film) ;

    // Enregistrement de la donnée
    *nbr = fwrite(&film, *taille, 1, flot) ;
    Test_Ecriture(nbr) ;
    
    // Fermeture du fichier 
    fclose(flot) ; 
}

void Initialisation_Tableau_Film(Film tab[], int nb)
{
    /*
        Le nom de la fonction est Initialisation_Tableau_Film, elle permet d'initialiser un tableau de type Film.
        Elle reçoit deux paramètres, un de type int, un tableau de type Film.
        Elle ne renvoie pas de valeur.
        Instructions utilisées : 1 for, 1 strcpy.
        Fonction non demandée dans les consignes mais facilite la lecture du programme principal.
    */

    for(int i = 0; i < nb; i++)
    {
        strcpy(tab[i].titre, "NULL") ;
        strcpy(tab[i].metteur_en_scene, "NULL") ;
        tab[i].annee_de_sortie = 0 ;
        tab[i].public = -1 ;
        tab[i].prix_location = 0.0 ;
    }
}

void Affichage_Tableau_Film(Film tab[], int nb)
{
    /*
        Le nom de la fonction est Affichage_Tableau_Film, elle permet d'afficher un tableau de type Film.
        Elle reçoit deux paramètres, un de type int, un tableau de type Film.
        Elle ne renvoie pas de valeur.
        Instructions utilisées : 1 for, 1 if, 1 strcmp, 1 printf.
        Fonction non demandée dans les consignes mais facilite la lecture du programme principal.
    */
    
    for(int i = 0; i < nb; i++) if(strcmp(tab[i].titre, "NULL")) printf("%d : Titre : %s\n", i, tab[i].titre) ;
}

void Verification_Choix(int *chx, int compteur)
{
    /*
        Le nom de la fonction est Verification_Choix, elle permet de vérifier le choix du rang.
        Elle reçoit deux paramètres de type int (un en pointeur et l'autre en non pointeur).
        Elle ne renvoie pas de valeur.
        Instructions utilisées : 2 while, 2 scanf, 4 printf, 3 if, 1 else.
        Fonction non demandée dans les consignes mais facilite la lecture du programme principal.
    */

    if(compteur == 10)
    {
        while((*chx < 0) || (*chx >= compteur))
        {
            printf("Veuillez saisir le rang de votre film : ") ;
            scanf("%d", chx) ;
            if((*chx < 0) || (*chx >= compteur)) printf("Erreur sur la saisie du rang de votre film\n\n") ;
        }
    }

    else
    {
        while((*chx < 0) || (*chx > compteur))
        {
            printf("Veuillez saisir le rang de votre film : ") ;
            scanf("%d", chx) ;
            if((*chx < 0) || (*chx > compteur)) printf("Erreur sur la saisie du rang de votre film\n\n") ;
        }
    }
}

void Affichage_Detail_Film(int chx, Film tab[], int compteur)
{
    /*
        Le nom de la fonction est Affichage_Detail_Film, elle permet d'afficher les détail d'un film.
        Elle reçoit trois paramètres, deux de type int et un tableau de type Film.
        Elle ne renvoie pas de valeur.
        Instructions utilisées : 2 printf, 1 if et 1 else if.
        Fonction utilisée : Verification_Choix
        Fonction non demandée dans les consignes mais facilite la lecture du programme principal.
    */

    Verification_Choix(&chx, compteur) ;
    if (tab[chx].public == 1) printf("Titre : %s\nMetteur en scene : %s\nAnnee : %d\nTout public\nPrix : %0.2f\n\n", tab[chx].titre, tab[chx].metteur_en_scene, tab[chx].annee_de_sortie, tab[chx].prix_location) ;
    else if (tab[chx].public == 0) printf("Titre : %s\nMetteur en scene : %s\nAnnee : %d\nReserve aux adultes\nPrix : %0.2f\n\n", tab[chx].titre, tab[chx].metteur_en_scene, tab[chx].annee_de_sortie, tab[chx].prix_location) ;
}

int Test_Lecture_Et_Creation_Tableau(int *taille, Film film, FILE *flot, Film tab[], int *compteur)
{
    /*
        Le nom de la fonction est Test_Lecture_Et_Creation_Tableau, elle permet de tester si la lecture du fichier fonctionne 
    et créer un tableau.
        Elle reçoit cinq paramètres, deux de type int en pointeur, un de type FILE, un de type Film et un tableau de type Film.
        Elle renvoie une valeur de type int.
        Instructions utilisées : 1 while, 1 perror, 1 return, 2 if et 1 else if, 2 else, 1 break.
        Fonction non demandée dans les consignes mais facilite la lecture du programme principal.
    */

    int ret, j = 0 ; 

    while(1)
    {
        ret = fread(&film, *taille, 1, flot); 
        if (ret == -1) {
            perror("Faute lecture");
            return 0 ;
        }

        // Lire la donnee 
        else if (ret != 0) tab[j] = film ;
        
        else break ;

        j++ ;
    }  

    if(j > 10) *compteur = 10 ;
    else *compteur = j - 1 ;
}

void Ouverture_Fichier_En_Lecture_Avec_Tableau(FILE *flot, int *taille, Film film, Film tab[], int nb, int choix, int compteur)
{
    /*
        Le nom de la fonction est Ouverture_Fichier_En_Lecture_Avec_Tableau, elle permet d'ouvrir un fichier en lecture et 
    de manipuler un tableau.
        Elle reçoit sept paramètres, quatre de type int (un pointeur et trois en non pointeur), un de type FILE, un de type Film et 
    un tableau de type Film.
        Elle ne renvoie pas de valeur.
        Instructions utilisées : 1 fopen, 1 fclose, 1 sizeof.
        Fonctions utilisées : Test_Ouverture, Initialisation_Tableau_Film, Test_Lecture_Et_Creation_Tableau, Affichage_Tableau_Film,
    Affichage_Detail_Film
        Fonction non demandée dans les consignes mais facilite la lecture du programme principal.
    */

    // Ouverture du fichier "filmotheque"
    flot = fopen("filmotheque", "r") ;
    Test_Ouverture(flot) ;

    *taille = sizeof(film) ;

    Initialisation_Tableau_Film(tab, nb) ;

    Test_Lecture_Et_Creation_Tableau(taille, film, flot, tab, &compteur) ;

    Affichage_Tableau_Film(tab, nb) ;

    Affichage_Detail_Film(choix, tab, compteur) ;

    // Fermeture du fichier 
    fclose(flot) ;
}

// FONCTIONS PARTIE 3 //

int Test_Lecture_Et_Creation_Tableau2(int *taille, Film film, FILE *flot, Film tab[])
{
    /*
        Le nom de la fonction est Test_Lecture_Et_Creation_Tableau2, elle permet de tester si la lecture du fichier fonctionne 
    et créer un tableau.
        Elle reçoit quatre paramètres, un de type int en pointeur, un de type FILE, un de type Film et un tableau de type Film.
        Elle renvoie une valeur de type int.
        Instructions utilisées : 1 while, 1 perror, 1 return, 1 if et 1 else if, 1 else, 1 break.
        Fonction non demandée dans les consignes mais facilite la lecture du programme principal.
    */

    int ret, j = 0 ; 

    while(1)
    {
        ret = fread(&film, *taille, 1, flot); 
        if (ret == -1) {
            perror("Faute lecture");
            return 0 ;
        }

        // Lire la donnee 
        else if (ret != 0) tab[j] = film ;
        
        else break ;

        j++ ;
    }  
}

void Saisir2(char t[])
{
    /*
        Le nom de la fonction est Saisir2, elle permet de saisir une chaine de caractère.
        Elle reçoit un paramètre de type char en tableau et ne renvoie pas de valeur.
        Instructions utilisées : 1 printf, 1 scanf.
        Fonction non demandée dans les consignes mais facilite la lecture du programme principal.
    */

    printf("Titre : ");
    scanf("%s", t);
}

int Verification_Entre_Tableau_Et_Chaine_Caractere(char t[], Film tab[], int nb)
{
    /*
        Le nom de la fonction est Verification_Entre_Tableau_Et_Chaine_Caractere, elle permet de vérifier ce que contient le tableau 
    et une chaine de caractère.
        Elle reçoit trois paramètres, un de type int, un de type char en tableau et un tableau de type Film.
        Elle renvoie une valeur de type int.
        Instructions utilisées : 1 for, 1 if, 1 else if, 2 strcmp, 1 printf, 2 return.
        Fonctions utilisées : Saisir2
        Fonction non demandée dans les consignes mais facilite la lecture du programme principal.
    */

    int verif ;

    Saisir2(t) ;

    for(int i = 0; i < nb; i++)
    {
        if(strcmp(tab[i].titre, t) != 0) verif = 1 ;

        else if(strcmp(tab[i].titre, t) == 0)
        {
            printf("Ce film existe deja\n");
            return 0 ;
        }
    }

    return verif ;
}

void Saisir3(char m[], int *a, int *pu, float *pr)
{
    /*
        Le nom de la fonction est Saisir3, elle permet de saisir des données.
        Elle reçoit quatre paramètres, un de type char en tableau, deux de type int en pointeur et un de type float en pointeur. 
        Elle ne renvoie pas de valeur.
        Instructions utilisées : 1 printf, 1 scanf.
        Fonction utilisée : Verification
        Fonction non demandée dans les consignes mais facilite la lecture du programme principal.
    */

    printf("Metteur en scene : ") ;
    scanf("%s", m) ;

    Verification(a, pu, pr) ;
}

Film Creation_Film2(char t[])
{
    /*
        Le nom de la fonction est Creation_Film2, elle permet de créer une variable de type Film.
        Elle reçoit un paramètre de type char en tableau et renvoie une valeur de type Film.
        Instructions utilisées : 2 strcpy, 1 printf, 1 return.
        Fonctions utilisées : Saisir3
        Fonction non demandée dans les consignes mais facilite la lecture du programme principal.
    */

    Film f ;
    int a = 0, pu = -1 ;
    float pr = -1.0 ;
    char m[N] ;

    Saisir3(m, &a, &pu, &pr) ;

    strcpy(f.titre, t) ; 
    strcpy(f.metteur_en_scene, m); 
    f.annee_de_sortie = a ; 
    f.public = pu ; 
    f.prix_location = pr ;

    return f ;
}

int Test(int t, Film film, int *nbr, int *taille, FILE *flot, char titre[])
{
    /*
        Le nom de la fonction est Test, elle permet de tester si une variable est dans le bonne état.
        Elle reçoit six paramètres, trois de type int (deux en pointeur et un en non pointeur), un de type FILE, un de type Film et 
    un de type char en tableau.
        Elle renvoie une valeur de type int.
        Instructions utilisées : 1 if, 1 fwrite, 1 return.
        Fonctions utilisées : Creation_Film2, Test_Ecriture
        Fonction non demandée dans les consignes mais facilite la lecture du programme principal.
    */

    if(t == 1)
    {
        film = Creation_Film2(titre);

        // Enregistrement de la donnée
        *nbr = fwrite(&film, *taille, 1, flot);
        Test_Ecriture(nbr) ;

        return 0;
    }
}

void Ouverture_Fichier_En_Lecture_Et_Ajout(FILE *flot, Film film, int *taille, int *nbr, int *test, char titre[], Film tab[], int nb)
{
    /*
        Le nom de la fonction est Ouverture_Fichier_En_Lecture_Et_Ajout, elle permet de lire un fichier et d'ajouter des données 
    si besoin.
        Elle reçoit huit paramètres, un de type FILE, un de type Film, un tableau de type Film, un de type char en tableau, 
    quatre de type int (trois en pointeur et un en non pointeur). 
        Elle ne renvoie pas de valeur.
        Instructions utilisées : 1 fopen, 1 sizeof, 1 fclose.
        Fonctions utilisées : Test_Ouverture, Initialisation_Tableau_Film, Test_Lecture_Et_Creation_Tableau2,
    Verification_Entre_Tableau_Et_Chaine_Caractere, Test
        Fonction non demandée dans les consignes mais facilite la lecture du programme principal.
    */

    // Ouverture du fichier "filmotheque"
    flot = fopen("filmotheque", "a+") ;
    Test_Ouverture(flot) ;

    *taille = sizeof(film) ;

    Initialisation_Tableau_Film(tab, nb) ;

    Test_Lecture_Et_Creation_Tableau2(taille, film, flot, tab) ;

    *test = Verification_Entre_Tableau_Et_Chaine_Caractere(titre, tab, nb) ;

    Test(*test, film, nbr, taille, flot, titre) ;

    // Fermeture du fichier 
    fclose(flot) ;
}

void Saisir4(char m[])
{
    /*
        Le nom de la fonction est Saisir4, elle permet de saisir une chaine de caractère.
        Elle reçoit un paramètre de type char en tableau et ne renvoie pas de valeur.
        Instructions utilisées : 1 printf, 1 scanf.
        Fonction non demandée dans les consignes mais facilite la lecture du programme principal.
    */

    printf("Veuillez saisir un mot ou une partie du titre : ") ;
    scanf("%s", m) ;
}

void Creation_Compteur_Et_Position(int nb, Film tab[], char m[], int *c, int *p)
{
    /*
        Le nom de la fonction est Creation_Compteur_Et_Position, elle permet de créer un compteur et d'avoir une position.
        Elle reçoit cinq paramètres, trois de type int (deux en pointeur et un en non pointeur), un tableau de type Film et 
    un de type char en tableau.
        Elle ne renvoie pas de valeur.
        Instructions utilisées : 1 for, 1 if, 1 strstr.
        Fonction non demandée dans les consignes mais facilite la lecture du programme principal.
    */

    for(int i = 0; i < nb; i++)
    {
        if(strstr(tab[i].titre, m) != NULL) 
        {
            *c += 1 ; 
            *p = i ;
        }
    }
}

void Verification_Choix2(int *chx, int p, int *c)
{
    /*
        Le nom de la fonction est Creation_Compteur_Et_Position, elle permet de vérifier le choix du rang saisie par l'utilisateur.
        Elle reçoit trois paramètres de type int (deux en pointeur et un en non pointeur) et ne renvoie pas de valeur.
        Instructions utilisées : 1 while, 2 printf, 1 scanf, 1 if.
        Fonction non demandée dans les consignes mais facilite la lecture du programme principal.
    */

    while((*chx < p - *c + 1) || (*chx > p))
    {
        printf("Veuillez saisir le rang de votre film : ") ;
        scanf("%d", chx) ;
        if((*chx < p - *c + 1) || (*chx > p)) printf("Erreur sur la saisie du rang de votre film\n\n") ;
    }  
}

void Affichage_Detail_Film2(int *chx, Film tab[], int p, int *c)
{
    /*
        Le nom de la fonction est Affichage_Detail_Film2, elle permet d'afficher les détail d'un film.
        Elle reçoit quatre paramètres, trois de type int (deux en pointeur et un en non pointeur) et un tableau de type Film.
        Elle ne renvoie pas de valeur.
        Instructions utilisées : 1 if, 1 else if et 2 printf.
        Fonction utilisée : Verification_Choix2
        Fonction non demandée dans les consignes mais facilite la lecture du programme principal.
    */

    Verification_Choix2(chx, p, c) ;
    if (tab[*chx].public == 1) printf("Titre : %s\nMetteur en scene : %s\nAnnee : %d\nTout public\nPrix : %0.2f\n\n", tab[*chx].titre, tab[*chx].metteur_en_scene, tab[*chx].annee_de_sortie, tab[*chx].prix_location) ;
    else if (tab[*chx].public == 0) printf("Titre : %s\nMetteur en scene : %s\nAnnee : %d\nReserve aux adultes\nPrix : %0.2f\n\n", tab[*chx].titre, tab[*chx].metteur_en_scene, tab[*chx].annee_de_sortie, tab[*chx].prix_location) ;
}

void Affiche_Tableau_Avec_Position(Film tab[], int p)
{
    /*
        Le nom de la fonction est Affiche_Tableau_Avec_Position, elle permet d'afficher les détail d'un film.
        Elle reçoit deux paramètres, un de type int et un tableau de type Film et ne renvoie pas de valeur.
        Instructions utilisées : 1 if, 1 else if et 2 printf.
        Fonction non demandée dans les consignes mais facilite la lecture du programme principal.
    */

    if (tab[p].public == 1) printf("Titre : %s\nMetteur en scene : %s\nAnnee : %d\nTout public\nPrix : %0.2f\n\n", tab[p].titre, tab[p].metteur_en_scene, tab[p].annee_de_sortie, tab[p].prix_location) ;
    else if (tab[p].public == 0) printf("Titre : %s\nMetteur en scene : %s\nAnnee : %d\nReserve aux adultes\nPrix : %0.2f\n\n", tab[p].titre, tab[p].metteur_en_scene, tab[p].annee_de_sortie, tab[p].prix_location) ;  
}

void Affiche_Rang(int nb, Film tab[], char m[])
{
    /*
        Le nom de la fonction est Affiche_Rang, elle permet d'afficher le rang des films.
        Elle reçoit trois paramètres, un de type int, un tableau de type Film et un de type char en tableau.
        Elle ne renvoie pas de valeur.
        Instructions utilisées : 1 for, 1 if, 1 strcmp, 1 strstr et 1 printf.
        Fonction non demandée dans les consignes mais facilite la lecture du programme principal.
    */

    for(int i = 0; i < nb; i++) if(strcmp(tab[i].titre, "NULL") && strstr(tab[i].titre, m) != NULL) printf("%d : Titre : %s\n", i, tab[i].titre) ;
}

void Affichage_Film(int *c, Film tab[], int p, char m[], int *chx, int nb)
{
    /*
        Le nom de la fonction est Affichage_Film, elle permet d'afficher des films selon la situation.
        Elle reçoit six paramètres, quatre de type int (deux en pointeur et deux en non pointeur), un tableau de type Film et 
    un de type char en tableau.
        Elle ne renvoie pas de valeur.
        Instructions utilisées : 1 switch, 2 case, 1 printf, 1 default et 3 break.
        Fonctions utilisées : Affiche_Tableau_Avec_Position, Affiche_Rang, Affichage_Detail_Film2
        Fonction non demandée dans les consignes mais facilite la lecture du programme principal.
    */

    switch(*c)
    {
        case 0 :
            printf("Aucun film ne correspond\n") ;
            break ;

        case 1 : 
            Affiche_Tableau_Avec_Position(tab, p) ;
            break ;
        
        default :
            Affiche_Rang(D, tab, m) ;

            Affichage_Detail_Film2(chx, tab, p, c) ;

            break ;
    }
}

void Ouverture_Fichier_En_Lecture_Et_Affichage_Resultat(FILE *flot, int *taille, Film film, Film tab[], int nb, int *c, int p, char m[], int *choix)
{
    /*
        Le nom de la fonction est Ouverture_Fichier_En_Lecture_Et_Affichage_Resultat, elle permet d'ouvrir un fichier en lecture 
    et afficher des films selon la situation.
        Elle reçoit neuf paramètres, cinq de type int (trois en pointeur et deux en non pointeur), un tableau de type Film, 
    un de type char en tableau, un de type Film et un de type FILE.
        Elle ne renvoie pas de valeur.
        Instructions utilisées : 1 fopen, 1 fclose, 1 sizeof.
        Fonctions utilisées : Test_Ouverture, Initialisation_Tableau_Film, Test_Lecture_Et_Creation_Tableau2, Saisir4, 
    Creation_Compteur_Et_Position, Affichage_Film
        Fonction non demandée dans les consignes mais facilite la lecture du programme principal.
    */
   
    // Ouverture du fichier "filmotheque"
    flot = fopen("filmotheque", "r") ;
    Test_Ouverture(flot) ;

    *taille = sizeof(film) ;

    Initialisation_Tableau_Film(tab, nb) ;

    Test_Lecture_Et_Creation_Tableau2(taille, film, flot, tab) ;

    Saisir4(m) ;

    Creation_Compteur_Et_Position(nb, tab, m, c, &p) ; 

    Affichage_Film(c, tab, p, m, choix, nb) ;
    
    // Fermeture du fichier 
    fclose(flot) ;
}
