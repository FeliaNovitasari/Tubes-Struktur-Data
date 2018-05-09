#include <iostream>
#include <cstdlib>
#include "relasi_dll.h"

using namespace std;

void createList_Child(list_C &C){
    first(C) = NULL;
}

address_C alokasi_Child(infotype_C dc){
    address_C pC;
    pC = new elm_C;
    info(pC) = dc;
    next(pC) = NULL;
    return pC;
}

void dealokasi_Child(address_C pC){
    delete(pC);
}

void printInfo_Child(list_C &C){
    address_C pC;
    if (first(C) == NULL){
        cout<<endl<<"data kendaraan (pengunjung) tidak ada"<<endl<<endl;
    }
    else{
        int i=1;
        pC = first(C);
        cout<<"Data Kendaraan:"<<endl;
        do{
            cout<<endl;
            cout<<"["<<i<<"]";
            cout<<" Jenis Kendaraan : "<<info(pC).jenis<<endl;
            cout<<"    No.Plat         : "<<info(pC).plat<<endl;
            cout<<"    Merk            : "<<info(pC).merk<<endl;
            cout<<"    Saldo           : Rp."<<info(pC).saldoakhir<<endl;
            cout<<"    Durasi parkir   : "<<info(pC).durasi<<" menit"<<endl;
            pC = next(pC);
            i++;
        }while (pC != NULL);
            cout<<endl<<"Banyak Kendaraan: "<<i-1<<endl;
        }
    }


void insertFirst_Child(list_C &C, address_C pC){
    if (first(C) == NULL){
        first(C) = pC;
    }else{
        next(pC) = first(C);
        first(C) = pC;
    }
}

void insertLast_Child(list_C &C, address_C pC){
    address_C qC;
    if (first(C) == NULL){
        insertFirst_Child(C,pC);
    }else{
        qC = first(C);
        while (next(qC) != NULL){
            qC = next(qC);
        }
        next(qC) = pC;
    }
}

void insertAfter_Child(list_C &C, address_C pC, address_C prec){
    if((first(C)!=NULL)&&(prec!=NULL)){
        next(pC)=next(prec);
        next(prec)=pC;
    }
}


void deleteFirst_Child(list_C &C, address_C pC){
    if (first(C)!=NULL){
        pC=first(C);
        first(C)=next(pC);
        next(pC)=NULL;
    }
}

void deleteAfter_Child(list_C &C, address_C pC, address_C prec){
    if((first(C)!=NULL)&&(prec!=NULL)){
        pC=next(prec);
        next(prec)=next(pC);
        next(pC)=NULL;
    }
}

// menu 5///
void daftarKendaraan(list_C &C){
    system("cls");
    cout<<" BERANDA >>> DAFTAR KENDARAAN TERLAMA PARKIR"<<endl;
    cout<<"============================================================="<<endl;
    address_C prec;
    list_C C1;
    createList_Child(C1);
    address_C pC,qC;
    pC=first(C);
//    printInfo_Child(C);
//    system("pause");
    do{
        deleteFirst_Child(C,pC);
        if((first(C1)==NULL)||(info(pC).durasi>info(first(C1)).durasi)){
            insertFirst_Child(C1,pC);
        }else{
            qC=first(C1);
            while((next(qC)!=NULL)&&((info(next(qC)).durasi)>(info(pC).durasi))){
                qC=next(qC);
            }
            if(next(qC)==NULL){
                insertLast_Child(C1,pC);

            }else if (info(next(qC)).durasi<(info(pC)).durasi){
                insertAfter_Child(C1,pC,qC);
            }
        }
        pC=first(C);
    }while(first(C) != NULL);
    C=C1;
    printInfo_Child(C);
    cout<<"============================================================="<<endl;
    cout<<endl<<endl;
    system("PAUSE");
}
