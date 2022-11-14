#include <stdlib.h>
#include <stdio.h>

#ifndef _TLG_
#define _TLG_

/*structura pentru o lista generica*/
typedef struct celula_g 
{
    void* info;
    struct celula_g* urm;
} TCelula_G, *TLG;

/*functii pentru liste si sublista*/
TLG alocare_memorie_sublista(void* s);
TLG alocare_memorie_lista(void* s);
void distrugere_sublista(TLG* sublista);
void distrugere_lista(TLG* lista);
void afisare_sublista(TLG sublista);
void afisare_sublista3(TLG sublista, int max);
void afisare_lista(TLG lista);
void afisare_lista2(TLG lista, int max);
void afisare_lista3(TLG lista, int max);
int inserare_in_sublista(TLG* sublista, void* s);
int inserare_in_lista(TLG* lista, void* s);
void sortare_sublista(TLG sublista);
void sortare_lista(TLG lista);
int gasire_frecventa_in_sublista(TLG sublista, int max);
int gasire_frecventa_in_lista(TLG lista, int max);


#endif
