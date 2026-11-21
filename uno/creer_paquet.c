#include <string.h>
typedef struct {
    int numero;
    char couleur;
    char symbole[3];
} carte;

void creer_paquet(carte paquet[108]) {
    int i = 0;
    for(i=0; i<9; i++) {
        paquet[i].numero = i + 1;
        paquet[i].couleur = 'R';
    }


}

    

    
