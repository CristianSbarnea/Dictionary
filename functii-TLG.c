#include "functii-TLG.h"
#include "functii-TCuvant.h"
#include "functii-TLungime.h"

/*functie de alocare memorie pentru o sublista*/
TLG alocare_memorie_sublista(void* s) {
    TLG sublista = (TLG)calloc(1, sizeof(TCelula_G));
    if (!sublista) {
        return NULL;
    }
    sublista->info = alocare_memorie_cuvant(s);
    if (!sublista->info) {
        free(sublista);
        return NULL;
    }
    sublista->urm = NULL;
    return sublista;
}

/*functie care imi distruge o sublista*/
void distrugere_sublista(TLG* sublista) {
    while(*sublista) {
        TLG aux = *sublista;
        *sublista = aux->urm;
        distrugere_cuvant(aux->info);
        free(aux);
    }
    free(*sublista);
    *sublista = NULL;
}

/*functie de alocare memorie pentru o lista*/
TLG alocare_memorie_lista(void* s) {
    TLG lista = (TLG)calloc(1, sizeof(TCelula_G));
    if (!lista) {
        return NULL;
    }
    lista->info = alocare_memorie_t_lungime(s);
    if (!lista->info) {
        free(lista);
        return NULL;
    }
    lista->urm = NULL;
    return lista;
}

/*functie de distrugere lista*/
void distrugere_lista(TLG* lista) {
    while(*lista) {
        TLG aux = *lista;
        *lista = aux->urm;
        distrugere_t_lungime(aux->info);
        free(aux);
    }
    free(*lista);
    *lista = NULL;
}

/*functii de afisare sublista*/
void afisare_sublista(TLG sublista) {
    while(sublista) {
        if (!sublista->urm) {
            afisare_cuvant1(sublista->info);
            break;
        }
        afisare_cuvant(sublista->info);
        sublista = sublista->urm;
    }
}

void afisare_sublista3(TLG sublista, int max) {
    for (; sublista; sublista = sublista->urm) {
        if (!sublista->urm) {
            afisare_cuvant3(sublista->info, max);
            continue;
        }
        afisare_cuvant4(sublista->info, max);
    }
}

/*functii de afisare a unei liste*/
void afisare_lista(TLG lista) {
    while(lista) {
        afisare_t_lungime(lista->info);
        lista = lista->urm;
    }
    printf("\n");
}

void afisare_lista2(TLG lista, int max) {
    while(lista) {
        afisare_t_lungime2(lista->info, max);
        lista = lista->urm;
    }
    printf("\n");
}

void afisare_lista3(TLG lista, int max) {
    for (; lista; lista = lista->urm) {
        if (gasire_frecventa_t_lungime(lista->info, max)) {
            afisare_t_lungime3(lista->info, max);
        }
    }
}

/*functie de inserare a unui cuvant intr-o sublista*/
int inserare_in_sublista(TLG* sublista, void* s) {
    TLG p = *sublista, ant = NULL;
    TLG aux = alocare_memorie_sublista(s);/*aloc memorie pt cuvant*/
    if (!aux) {
        return 0;
    }
    if (!*sublista) {
        *sublista = aux;/*daca sublista e nula, inserez la inceput*/
        return 1;
    }
    if (compara_lungime(aux->info, p->info)) {
        return 0;
    }
    for (; p; ant = p, p = p->urm) {
        if (compara_cuvinte(aux->info, p->info) == 1) {
            TCuvant* x = (TCuvant*)p->info;
            x->frecventa++;
            /*eliberez memoria daca cuvantul exista deja in sublista mea*/
            distrugere_sublista(&aux);
            return 1;
        }
    }
    ant->urm = aux;/*daca nu e nula, inserez la sfarsit*/
    return 1;
}

/*functie de inserare in lista*/
int inserare_in_lista(TLG* lista, void* s) {
    TLG curr = *lista, ant = NULL;
    TLG aux = alocare_memorie_lista(s);/*aloc memorie pentru cuvant*/
    if (!aux) {
        return 0;
    }
    if (!(*lista)) {
        *lista = aux;
        return 1;
    }
    for (; curr; ant = curr, curr = curr->urm) {
        if (compara_t_lungimi(aux->info, curr->info) == 1) {
            inserare_in_t_lungime(curr->info, s);
            /*daca lungimea mea exista in lista, nu inserez si eliberez*/
            distrugere_lista(&aux);
            return 1;
        }
    }
    if (ant == NULL) {
        *lista = aux;
        aux->urm = curr;
        ant = aux;
        return 1;
    }
    aux->urm = curr;
    ant->urm = aux;
    return 1;
}

/*functie care imi intoarce lungimea unei subliste*/
int lungime_sublista(TLG sublista) {
    int count = 0;
    for (; sublista; sublista = sublista->urm) {
        count++;
    }
    return count;
}

/*functie de sortare a unei subliste in functie de frecventa, iar
daca frecventa e egala, sorteaza lexicografic cuvintele*/
void sortare_sublista(TLG sublista) {
    int len = lungime_sublista(sublista);
    int i;
    if (len > 1) {
        for (i = 0; i < len; i++) {
            TLG p = sublista->urm;
            for (; p; sublista = p, p = p->urm) {
                if(compara_frecventa(sublista->info, p->info) == 1) {
                    interschimbare_cuvinte(p->info, sublista->info);
                } else if (compara_frecventa(sublista->info, p->info) == 2) {
                    if (compara_cuvinte(p->info, sublista->info) == 2) {
                        interschimbare_cuvinte(p->info, sublista->info);
                    }
                }
            }
        }
    }
}

/*functie care intoarce lungimea unei liste*/
int lungime_lista(TLG lista) {
    int count = 0;
    for (; lista; lista = lista->urm) {
        count++;
    }
    return count;
}

/*functie interschimbare a doi void* info din listele mele*/
int interschimbare_celule_lista(TLG ant, TLG p) {
    if (interschimbare_t_lungimi(ant->info, p->info)) {
        return 1;
    }
    return 0;
}

/*functie de sortare a unei liste*/
void sortare_lista(TLG lista) {
    int len = lungime_lista(lista);
    int i;
    if (len == 1) {
        sortare_t_lungime(lista->info);
    }
    if (len > 1) {
        for (i = 0 ; i < len; i++) {
            TLG p = lista->urm, ant = lista;
            for (; ant; ant = p, p = p->urm) {
                sortare_t_lungime(ant->info);
                if (p == NULL) {
                    break;
                }
                if (compara_t_lungimi(ant->info, p->info) == 2) {
                    /*sortez crescator in functie de lungimi*/
                    interschimbare_t_lungimi(ant->info, p->info);
                }
            }
        }
    }
}

/*functie care gaseste o frecventa mai mica decat max intr-o sublista*/
int gasire_frecventa_in_sublista(TLG sublista, int max) {
    for (; sublista; sublista = sublista->urm) {
        if (gasire_frecventa(sublista->info, max)) {
            return 1;
        }
    }
    return 0;
}

/*functie care gaseste frecventa mai mica decat max intr-o lista*/
int gasire_frecventa_in_lista(TLG lista, int max) {
    for (; lista; lista = lista->urm) {
        if (gasire_frecventa_t_lungime(lista->info, max)) {
            return 1;
        }
    }
    return 0;
}

