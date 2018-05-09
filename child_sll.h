#ifndef CHILD_TSLL_H_INCLUDED
#define CHILD_TSLL_H_INCLUDED
#include <iostream>
#define first(L) ((L).first)
#define info(P) (P)->info
#define next(P) (P)->next
#include "relasi_dll.h"

using namespace std;

typedef struct elm_C *address_C;
struct infotype_C{
    string jenis;
    string plat;
    string merk;
    int saldoawal,saldoakhir;
    int durasi;
};
struct elm_C{
    infotype_C info;
    address_C next;
};
struct list_C{
    address_C first;
};

void createList_Child(list_C &C);
void dealokasi_Child(address_C &pC);
address_C alokasi_Child(infotype_C dc);
void printInfo_Child(list_C &C);
void insertFirst_Child(list_C &C, address_C pC);
void insertLast_Child(list_C &C, address_C pC);
void insertAfter_Child(list_C &C, address_C pC, address_C prec);
void deleteFirst_Child (list_C &C, address_C pC);
void deleteAfter_Child(list_C &C, address_C pC, address_C prec);
//menu tambahan
void daftarKendaraan(list_C &C);//menu6
#endif // CHILD(TSLL)_H_INCLUDED
