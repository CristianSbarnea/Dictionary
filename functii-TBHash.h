#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "functii-TLG.h"

#ifndef _TB_HASH_
#define _TB_HASH_

typedef int (*TFHash)(void*);

typedef struct
{
    size_t M;
    TFHash fh;
    TLG* v; /*vector de liste generice*/
} TH;

/*functii tabela hash*/
TH* initializare_tabela_hash(TFHash fh);
void distrugere_tabela_hash(TH** th);
int functia_hash(void* s);
int inserare_in_th(TH* th, void* s);
void afisare_tabela_hash(TH* th);
void afisare_tabela_hash2(TH* th, void* s, int max);
void afisare_tabela_hash3(TH* th, int max);
void sortare_tabela_hash(TH* th);

#endif
