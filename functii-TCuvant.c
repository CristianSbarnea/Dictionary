/* SBARNEA CRISTIAN-STEFAN - 314CB */

#include "functii-TCuvant.h"
#include <string.h>

/*functie care imi aloca memorie pentru o structura TCuvant*/
TCuvant* alocare_memorie_cuvant(void* s) {
    TCuvant* cuv = (TCuvant*)calloc(sizeof(TCuvant), 1);
    if (!cuv) {
        return NULL;
    }
    char* p = (char*) s;
    cuv->cuvant = strdup(p);
    cuv->frecventa = 1;
    return cuv;
}

/* functie care imi elibereaza memoria unui cuvant */
void distrugere_cuvant(void* s) {
    TCuvant* cuv = (TCuvant*) s;
    free(cuv->cuvant);
    free(cuv);
    cuv = NULL;
}

/*4 functii afisare cuvant*/
void afisare_cuvant(void* s) {
    TCuvant* cuv = (TCuvant*) s;
    printf("%s/%d, ", cuv->cuvant, cuv->frecventa);
}

void afisare_cuvant1(void* s) {
    TCuvant* cuv = (TCuvant*) s;
    printf("%s/%d", cuv->cuvant, cuv->frecventa);
}

void afisare_cuvant3(void* s, int max) {
    TCuvant* cuv = (TCuvant*) s;
    if (cuv->frecventa <= max) {
        printf("%s/%d", cuv->cuvant, cuv->frecventa);
    }
}

void afisare_cuvant4(void* s, int max) {
    TCuvant* cuv = (TCuvant*) s;
    if (cuv->frecventa <= max) {
        printf("%s/%d, ", cuv->cuvant, cuv->frecventa);
    }
}

/*functie care imi compara 2 cuvinte, intoarce 0 daca sunt aceleasi,
si intoarce 2 daca primul e in fata celui de-al doilea dpdv alfabetic*/
int compara_cuvinte(void* s, void* p) {
    TCuvant* x = (TCuvant*) s;
    TCuvant* y = (TCuvant*) p;
    if (strcmp(x->cuvant, y->cuvant) == 0) {
        return 1;
    } else if (strcmp(x->cuvant, y->cuvant) < 0) {
        return 2;
    }
    return 0;
}

/*functie care imi compara lungimea a doua cuvinte*/
int compara_lungime(void* s, void* p) {
    TCuvant* insert = (TCuvant*) s;
    TCuvant* existent = (TCuvant*) p;
    if (strlen(insert->cuvant) != strlen(existent->cuvant)) {
        return 1;
    }
    return 0;
}

/*functie care compara frecventa a doua cuvinte*/
int compara_frecventa(void* s, void* p) {
    TCuvant* ant = (TCuvant*) s;
    TCuvant* curr = (TCuvant*) p;
    if (curr->frecventa > ant->frecventa) {
        return 1;
    } else if (curr->frecventa == ant->frecventa) {
        return 2;
    }
    return 0;
}

/*functie care imi ia valorile din 2 structuri TCuvant si le inverseaza*/
int interschimbare_cuvinte(void* s, void* p) {
    TCuvant* ant = (TCuvant*) s;
    TCuvant* curr = (TCuvant*) p;
    TCuvant* temp = alocare_memorie_cuvant(ant->cuvant);
    if (!temp) {
        return 0;
    }
    temp->frecventa = ant->frecventa;
    free(ant->cuvant);
    ant->cuvant = strdup(curr->cuvant);
    ant->frecventa = curr->frecventa;
    free(curr->cuvant);
    curr->cuvant = strdup(temp->cuvant);
    curr->frecventa = temp->frecventa;
    distrugere_cuvant(temp);
    return 1;
}

/*functie care imi gaseste o frecventa mai mica sau egala cu max 
intr-o structura TCuvant*/
int gasire_frecventa(void* s, int max) {
    TCuvant* cuv = (TCuvant*) s;
    if (cuv->frecventa <= max) {
        return 1;
    }
    return 0;
}

