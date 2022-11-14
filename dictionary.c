#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "functii-TCuvant.h"
#include "functii-TLungime.h"
#include "functii-TLG.h"
#include "functii-TBHash.h"
#define MAX 100

int main(int argc, char** argv) {
    //deschid fisier intorc -1 daca nu se deschide
    FILE* fo = fopen(argv[1], "r");
    if (!fo) {
        return -1;
    }
    TH* th = NULL;
    th = initializare_tabela_hash(functia_hash);
    if (!th) {
        fclose(fo);
        return -1;
    }
    /*string unde pastrez litera cu care incepe un cuvant*/
    char* litera = calloc(MAX, 1);
    if (!litera) {
        fclose(fo);
        distrugere_tabela_hash(&th);
        return -1;
    }
    int y; 
    char* line = NULL;
    size_t len = 0;
    //citire din fisier linie cu linie
    //iau cu strtok primul cuvant din linie si il compar cu 
    //"print" sau "insert", iar apoi iau cu strtok ce urmeaza dupa
    //ele si inserez daca e "insert" si daca nu, fac printarea corespunzator
    while (getline(&line, &len, fo) != -1)
    {
        char* token = strtok(line, " .,?!\n");
        if (!strcmp(token, "insert")) {
            char* p = strtok(0, " .,?!\n");
            while (p != NULL) {
                inserare_in_th(th, p);
                p = strtok(0, " .,?!\n");
            }
        } else if (!strcmp(token, "print")) {
            token = strtok(NULL, " .,?!\n");
            if (token == NULL) {
                sortare_tabela_hash(th);
                afisare_tabela_hash(th);
            } else if ((token[0] <= 'z' && token[0] >= 'a') || 
            (token[0] <= 'Z' && token[0] >= 'A')) {
                sscanf(token, "%s", litera);
                token = strtok(NULL, " .,?!\n");
                sscanf(token, "%d", &y);
                sortare_tabela_hash(th);
                afisare_tabela_hash2(th, litera, y);
            } else if (token[0] >= '0' && token[0] <= '9') {
                sscanf(token, "%d", &y);
                sortare_tabela_hash(th);
                afisare_tabela_hash3(th, y);
            }
        }
    }
    //eliberare memorie si inchidere fisier
    free(line);
    free(litera);
    distrugere_tabela_hash(&th);
    fclose(fo);
    return 0;
}
