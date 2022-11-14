
#Dictionary

   Pentru inceput, am adaugat 2 noi structuri, T_Lungime si TCuvant. In tabela mea hash, am un 
vector de liste generice. Void* info din fiecare lista generica va puncta catre o structura T_Lungime,
unde exista o lungime si o alta lista generica, pe care am denumit-o sublista.
Void* info din aceasta sublista, va puncta catre o structura TCuvant, unde voi stoca
o frecventa de aparitie a cuvintelor si cuvintele in sine.
    In functii-TLungime.c si functii-TCuvant.c exista multe functii auxiliare care primesc void* info
si fac automat cast la structura respectiva.
    In functii-TLG.c am inclus functii care pot fi aplicate atat pe liste cat si pe subliste, intrucat
sunt de tipul TLG amandoua.
    In continuare, programul primeste din linia de comanda fisierul pe care trebuie sa-l deschida. Voi citi
din acesta linie cu linie, si voi folosi strtok pentru a trece prin el. Verific daca primul cuvant din acea
linie este "insert" si apoi merg mai departe cu strtok pana la urmatoarea linie si inserez cuvant cu cuvant in tabela 
mea hash. Pentru fiecare cuvant voi aloca o singura data memorie, adica daca exista deja in sublista, doar voi incrementa frecventa.
Daca cuvantul este "print", voi merge mai departe cu strtok si daca token-ul este NULL, fac afisarea pentru
toata tabela hash. Daca token-ul este o litera, voi folosi sscanf pentru a salva litera si ce urmeaza in variabile
separate pentru a le putea da ca argumente functiei de printare. Daca token-ul este o cifra, folosesc iar sscanf.
Mentionez ca inainte de fiecare printare voi sorta lista corespunzator.
    La sfarsit, eliberez toata memoria si inchid fisierul.
  
