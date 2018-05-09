#ifndef RELASI_TDLL_H_INCLUDED
#define RELASI_TDLL_H_INCLUDED

#include "child_sll.h"
#include "parent_csll.h"
#include "relasi_dll.h"

#include <iostream>
using namespace std;

#define first(L) ((L).first)
#define last(L) ((L).last)
#define next(P) (P)->next
#define prev(P) (P)->prev
#define info(P) (P)->info
#define child(P) (P)->child
#define parent(P) (P)->parent


typedef struct elm_R *address_R;


struct infotype_R{
    int jm,mm;
    int jk,mk;
    string date;
    int jam,menit;
    int tarif;
};

struct elm_R{
    infotype_R info;
    address_R next;
    address_R prev;
    address_C child;
    address_P parent;
};

struct list_R{
    address_R first;
    address_R last;
};

address_R alokasi_Relasi(address_C pC, address_P pP,infotype_R dr);
void createList_Relasi(list_R &R);
void dealokasi_Relasi(address_R &pR);
void printInfo_Relasi(list_R &R);
void insertFirst_Relasi(list_R &R, address_R pR);
void insertLast_Relasi(list_R &R, address_R pR);
void deleteFirst_Relasi(list_R &R, address_R pR);
void deleteLast_Relasi(list_R &R, address_R pR);
void deleteAfter_Relasi(list_R &R, address_R pR, address_R prec);

//KODINGNYA////////////////////
void registrasi(list_C &C, list_P &P, list_R &R); //menu 1
void masuk(list_C &C, list_P &P, list_R &R);
void inputData(list_C &C, list_P &P, list_R &R);
void lihatData(list_C &C, list_P &P, list_R &R); //menu 2
void cariData(list_C &C, list_P &P, list_R &R); //menu3
void hapusData(list_C &C, list_P &P, list_R &R); //menu 4
void pendapatan(list_R &R); //menu 5

//helper
address_C cariPlat(list_C C, string plat);
address_P cariBlokLantai(list_P, string blok, string lantai);
address_R cariTanggal(list_R, string date);
string ubahBlok(string blok);
void cariTempat(list_P &P);
void cariKendaraan(list_C &C);
void cariRelasi(list_R &R);
void hapusTempat(list_P &P);
void hapusKendaraan(list_C &C);
void hapusRelasi(list_R &R);

#endif // RELASI(TDLL)_H_INCLUDED
