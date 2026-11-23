#include <stdio.h>
#include <string.h>
#include <strings.h>
#include <stdlib.h>

typedef struct {
    char symbole[3]; // +2, JJ...
    char couleur; // R, V, J, B
} carte; //  

// Fonction creer_carte
carte creer_carte(char symbole[], char couleur) // carte est le nom de nontre type 
{
    carte c; //jia creer une varible de type carte

    c.symbole[0] = symbole[0]; // copier le premier caractère du symbole dans la structure c
    c.symbole[1] = symbole[1];
    c.symbole[2] = '\0';
    c.couleur = couleur;

    return c;
}
int symbole_valide(char symbole[])
{
    if (symbole[0] >= '0' && symbole[0] <= '9')
    {
        return 1;
    }

    if (strcasecmp(symbole, "PS") == 0 || strcasecmp(symbole, "RV") == 0 || strcasecmp(symbole, "JJ") == 0 || strcmp(symbole, "+2") == 0 || strcmp(symbole, "+4") == 0)
    {
        return 1;
    }

    return 0;
}
int couleur_valide(char couleur)
{
    if (couleur == 'R' || couleur == 'r' || couleur == 'V' || couleur == 'v' || couleur == 'J' || couleur == 'j' || couleur == 'B' || couleur == 'b' || couleur == 'N' || couleur == 'n')
    {
        return 1;
    }

    return 0;
}
void initialiser_paquet(carte paquet[])
{
    char couleurs[] = {'R', 'V', 'J', 'B'};
    char symbole[3];
    int i, j, n, k = 0; // i pour les couleurs j pour les nb et n pour exmplaire 

    // Créer un zéro pour chaque couleur
    for (i = 0; i < 4; i++)
    {
        sprintf(symbole, "%d", 0); // convertir un nb en caractere 
        paquet[k] = creer_carte(symbole, couleurs[i]);
        k++;    
    }

    // Créer les cartes de 1 à 9 pour chaque couleur
    for (i = 0; i < 4; i++)
    {
        for (j = 1; j <= 9; j++)
        {
            // Chaque numéro existe en deux exemplaires
            for (n = 0; n < 2; n++)
            {
                sprintf(symbole, "%d", j); //mpasser de int a chaine de caractere
                paquet[k] = creer_carte(symbole, couleurs[i]);
                k++;
            }
        }
    }
    
    // Créer les cartes +2
    for (i = 0; i < 4; i++)
    {
        for (n = 0; n < 2; n++)
        {
            paquet[k] = creer_carte("+2", couleurs[i]);
            k++;
        }
    }

    // Créer les cartes PS
    for (i = 0; i < 4; i++)
    {
        for (n = 0; n < 2; n++)
        {
            paquet[k] = creer_carte("PS", couleurs[i]);
            k++;
        }
    }

    // Créer les cartes RV
    for (i = 0; i < 4; i++)
    {
        for (n = 0; n < 2; n++)
        {
            paquet[k] = creer_carte("RV", couleurs[i]);
            k++;
        }
    }
// Créer les 4 cartes JJ noires
for (n = 0; n < 4; n++)
{
    paquet[k] = creer_carte("JJ", 'N'); // un exemplaire de carte JJ en noir
    k++;
}

// Créer les 4 cartes +4 noires
for (n = 0; n < 4; n++)
{
    paquet[k] = creer_carte("+4", 'N');
    k++;
}
printf("Nombre de cartes : %d\n", k);
}
void melanger_le_paquet(carte paquet[])
{
    int i, j;
    carte a;

    for (i = 0; i < 108; i++)
    {
        j = rand() % 108; // Générer un index aléatoire entre 0 et 107
        a = paquet[i];
        paquet[i] = paquet[j];
        paquet[j] = a;
    }
}

void distribuer_cartes(carte paquet[])
{
    int i, j, k = 0;

    carte mains[7][2]; // un tableau à deux dimensions 7 lignes pour les 7 cartes et 2 colonnes pour les 2 joueurs.

    for (i = 0; i < 2; i++) // 2 joueurs
    {

        printf("Joueur %d : ", i + 1); 

        for (j = 0; j < 7; j++) 
        {
            mains[j][i] = paquet[k]; // copie une carte du paquet dans la main du joueur.

            printf("%s%c ", mains[j][i].symbole, mains[j][i].couleur);//  affiche le symbole et la couleur de la carte.

            k++;
        }
        printf("\n");
    }
}
void afficher_premiere_carte(carte paquet[])
{
    printf("Premiere carte sur la table : %s %c\n", paquet[14].symbole, paquet[14].couleur);
}



int main()
{
    carte paquet[108];
    carte c1;

    char symbole[] = "+2";
    char couleur = 'V';

    // On vérifie si le symbole et la couleur sont valides
    if (symbole_valide(symbole) && couleur_valide(couleur))
    {
        c1 = creer_carte(symbole, couleur);

        paquet[0] = c1;

        printf("%s %c\n", c1.symbole, c1.couleur);
    }
    else
    {
        printf("Carte invalide !");
    }
 initialiser_paquet(paquet);
 melanger_le_paquet(paquet);
 distribuer_cartes(paquet);
 afficher_premiere_carte(paquet);
    return 0;
}
