#include "functii-TLungime.h"
#include "functii-TLG.h"
#include <string.h>

/*functie care aloca memorie pt o structura T_Lungime*/
T_Lungime* alocare_memorie_t_lungime(void* s) {
    T_Lungime* lung = (T_Lungime*)calloc(sizeof(T_Lungime), 1);
    if (!lung) {
        return NULL;
    }
    lung->sublista = alocare_memorie_sublista(s);
    if (!lung->sublista) {
        free(lung);
        return NULL;
    }
    lung->lungime = strlen((char*)s);
    return lung;
}

/*functie de distrugere pentru o structura T_Lungime*/
void distrugere_t_lungime(void* s) {
    T_Lungime* lung = (T_Lungime*)s;
    distrugere_sublista(&lung->sublista);
    free(lung->sublista);
    free(lung);
    lung = NULL;
}

/*functii de afisare T_Lungime*/
void afisare_t_lungime(void* s) {
    T_Lungime* lung = (T_Lungime*) s;
    printf("(%d:", lung->lungime);
    afisare_sublista(lung->sublista);
    printf(")");
}

void afisare_t_lungime2(void* s, int max) {
    T_Lungime* lung = (T_Lungime*) s;
    if (lung->lungime == max) {
        printf("(%d:", lung->lungime);
        afisare_sublista(lung->sublista);
        printf(")");
    }
}

void afisare_t_lungime3(void* s, int max) {
    T_Lungime* lung = (T_Lungime*) s;
    printf("(%d: ", lung->lungime);
    afisare_sublista3(lung->sublista, max);
    printf(")");
}

/*functie care primeste doua structuri T_Lungime si
compara lungimile din ele*/
int compara_t_lungimi(void* s, void* p) {
    T_Lungime* insert = (T_Lungime*) s;
    T_Lungime* existent = (T_Lungime*) p;
    if (insert->lungime == existent->lungime) {
        return 1;
    } else if (insert->lungime > existent->lungime) {
        return 2;
    }
    return 0;
}

/*functie de inserare intr-o structura T_Lungime*/
int inserare_in_t_lungime(T_Lungime* p, void* s) {
    if (p->lungime != strlen((char*)s))
        return 0;
    inserare_in_sublista(&p->sublista, s);
    return 1;
}

/*functie de sortare a unei structuri T_Lungime*/
void sortare_t_lungime(void* s) {
    T_Lungime* lung = (T_Lungime*)s;
    sortare_sublista(lung->sublista);
}

/*functie care primeste 2 structuri T_Lungime si inverseaza
valorile din ele*/
int interschimbare_t_lungimi(void* s, void* p) {
    T_Lungime* ant = (T_Lungime*) s;
    T_Lungime* curr = (T_Lungime*) p;
    T_Lungime* aux = (T_Lungime*)calloc(1, sizeof(T_Lungime));
    if (!aux) {
        return 0;
    }
    aux->lungime = ant->lungime;
    aux->sublista = ant->sublista;
    ant->lungime = curr->lungime;
    ant->sublista = curr->sublista;
    curr->lungime = aux->lungime;
    curr->sublista = aux->sublista;
    free(aux);
    return 1;
}

/*functie care gaseste o frecventa mai mica sau egala decat max
intr-o structura T_Lungime*/
int gasire_frecventa_t_lungime(void* s, int max) {
    T_Lungime* p = (T_Lungime*) s;
    if (gasire_frecventa_in_sublista(p->sublista, max)) {
        return 1;
    }
    return 0;
}

