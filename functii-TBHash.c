/* SBARNEA CRISTIAN-STEFAN - 314CB */
#include "functii-TBHash.h"
#include "functii-TLG.h"

/*functie care imi aloca memorie si initializeaza o tabela hash*/
TH* initializare_tabela_hash(TFHash fh) {
    TH* th = (TH*)calloc(1, sizeof(TH));
    if (!th) {
        return NULL;
    }
    size_t M = 'Z' - 'A' + 1;
    th->v = calloc(M, sizeof(TLG));
    if (!th->v) {
        free(th);
        return NULL;
    }
    th->M = M;
    th->fh = fh;
    return th;
}

/*functia de distrugere a unei tabele hash*/
void distrugere_tabela_hash(TH** th) {
    int i;
    for(i = 0; i < (*th)->M; i++) {
        distrugere_lista(&((*th)->v[i]));
    }
    free((*th)->v);
    free(*th);
    *th = NULL;
}

/*functia care imi reda codul de intrare intr-o tabela hash*/
/*daca cuvantul pe care il primeste nu incepe cu o litera intoarce - 1*/
int functia_hash(void* s) {
    char* p = (char*) s;
    if (p[0] >= 'A' && p[0] <= 'Z') {
        return p[0] - 'A';
    }
    else if (p[0] >= 'a' && p[0] <= 'z') {
        return p[0] - 'a';
    }
    return -1; 
}

/*functie de inserare a unui cuvant intr-o tabela hash data ca parametru*/
/*intoarce 1 daca reuseste si 0 daca nu*/
int inserare_in_th(TH* th, void* s) {
    if (strlen((char*)s) < 3) {
        return 0;
    }
    int cod = th->fh(s);
    if (cod < 0) {
        return 0;
    }
    if (inserare_in_lista(&(th->v[cod]), s)) /*inserare intr-o lista*/
    {
        return 1;
    }
    return 0;
}

/*functie de sortare a unei tabele hash*/
void sortare_tabela_hash(TH* th) {
    int i;
    for (i = 0; i < th->M; i++) {
        sortare_lista(th->v[i]); /*functie de sortare a unei liste*/
    }
}

/*3 functii de afisare a unei tabele hash*/
void afisare_tabela_hash(TH* th) {
    int i;
    for (i = 0; i < th->M; i++) {
        if (th->v[i] == NULL) {
            continue;
        }
        printf("pos %d: ", i);
        afisare_lista(th->v[i]); /*afisare lista*/
    }
}

void afisare_tabela_hash2(TH* th, void* a, int max) {
    int cod = th->fh(a);
    if (cod >= 0 && max > 2) {
        afisare_lista2(th->v[cod], max); /*afisare lista*/
    }
}

void afisare_tabela_hash3(TH* th, int max) {
    int i;
    for (i = 0; i < th->M; i++) {
        if (max == 0) {
            break;
        }
        if (!th->v[i]) {
            continue;
        }
        if (gasire_frecventa_in_lista(th->v[i], max)) {
            printf("pos%d: ", i);
            afisare_lista3(th->v[i], max); /*afisare lista*/
            printf("\n");
        }
    }
}
