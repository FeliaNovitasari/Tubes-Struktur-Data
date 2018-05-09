#ifndef PARENT_TSLL_H_INCLUDED
#define PARENT_TSLL_H_INCLUDED
#include <iostream>
#define first(L) ((L).first)
#define next(P) (P)->next
#define info(P) (P)->info

#include "relasi_dll.h"

using namespace std;

typedef struct elm_P *address_P;
struct infotype_P{
    string blok,lantai;
    int kuota;
    int sisa;
};
struct elm_P{
    infotype_P info;
    address_P next;
};
struct list_P{
    address_P first;
};


void createList_Parent(list_P &P);
void dealokasi_Parent(address_P &P);
address_P alokasi_Parent(infotype_P dp);
void printInfo_Parent(list_P &P);
void insertFirst_Parent(list_P &P, address_P pP);
void insertLast_Parent(list_P &P, address_P pP);
void deleteFirst_Parent(list_P &P, address_P pP);
void deleteAfter_Parent(list_P &P, address_P pP, address_P prec);

// menu ///
void insertTempatParkir(list_P &P);
void lantaiTerpenuh(list_P &P); //menu 7
#endif // PARENT(TSLL)_H_INCLUDED
