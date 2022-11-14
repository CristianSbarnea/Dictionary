#include <stdio.h>
#include <stdlib.h>

#ifndef _T_CUVANT_
#define _T_CUVANT_

/*structura unui cuvant*/
typedef struct cuvant
{
    char* cuvant;
    int frecventa;
} TCuvant;

/*functii pentru TCuvant*/
TCuvant* alocare_memorie_cuvant(void* s);
void distrugere_cuvant(void* s);
void afisare_cuvant(void* s);
void afisare_cuvant1(void* s);
void afisare_cuvant3(void* s, int max);
void afisare_cuvant4(void* s, int max);
int compara_cuvinte(void* s, void* p);
int compara_lungime(void* s, void* p);
int compara_frecventa(void* s, void* p);
int interschimbare_cuvinte(void* s, void* p);
int gasire_frecventa(void* s, int max);

#endif
