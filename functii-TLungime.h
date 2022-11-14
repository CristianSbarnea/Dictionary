#include <stdio.h>
#include <stdlib.h>
#include "functii-TLG.h"

#ifndef _T_LUNGIME_
#define _T_LUNGIME_

/*structura T_Lungime, unde voi stoca lungimea cuvintelor din sublista*/
typedef struct celula_lungime
{
    int lungime;
    TLG sublista;
} T_Lungime;

/*functii T_Lungime*/
T_Lungime* alocare_memorie_t_lungime(void* s);
void distrugere_t_lungime(void* s);
void afisare_t_lungime(void* s);
void afisare_t_lungime2(void* s, int max);
void afisare_t_lungime3(void* s, int max);
void sortare_t_lungime(void* s);
int inserare_in_t_lungime(T_Lungime* p, void* s);
int compara_t_lungimi(void* s, void* p);
int interschimbare_t_lungimi(void* s, void* p);
int gasire_frecventa_t_lungime(void* s, int max);

#endif
