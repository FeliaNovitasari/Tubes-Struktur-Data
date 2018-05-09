#include <iostream>
#include <cstdlib>
#include "relasi_dll.h"

using namespace std;

void createList_Parent(list_P &P){
    first(P) = NULL;
}

address_P alokasi_Parent(infotype_P dp){
    address_P pP;
    pP = new elm_P;
    info(pP)= dp;
    next(pP) = pP;
    return pP;
}

address_P dealokasi_Parent(address_P pP){
    delete(pP);
}

void printInfo_Parent(list_P &P){
    address_P pP;
    if (first(P) == NULL){
        cout<<"data tempat tidak ada"; cout<<endl;
    }
    else{
        int i=1;
        pP = first(P);
        cout<<"Data Tempat:"<<endl;
        while (next(pP) != first(P)){
            cout<<endl;
            cout<<"["<<i<<"]";
            cout<<"   Lantai : "<<info(pP).lantai<<endl;
            cout<<"      Blok   : "<<info(pP).blok<<endl;
            cout<<"      Kuota  : "<<info(pP).kuota<<endl;
            cout<<"      Sisa   : "<<info(pP).sisa<<endl;
            pP = next(pP); i++;
        }
        cout<<endl;
        cout<<"["<<i<<"]";
        cout<<"  Lantai : "<<info(pP).lantai<<endl;
        cout<<"      Blok   : "<<info(pP).blok<<endl;
        cout<<"      Kuota  : "<<info(pP).kuota<<endl;
        cout<<"      Sisa   : "<<info(pP).sisa<<endl<<endl;
        cout<<"Banyak tempat parkir: "<<i<<endl;
    }
}

void insertFirst_Parent(list_P &P, address_P pP){
    address_P Q;
    if (first(P) == NULL){
        first(P) = pP;
        next(pP) = pP;
    }else{
        Q = first(P);
        while (next(Q) != first(P)){
            Q =next(Q);
        }
        next(Q) = pP;
        next(pP) = first(P);
        first(P) = pP;
    }
}

void insertLast_Parent(list_P &P, address_P pP){
    address_P Q;
    if (first(P) == NULL){
        first(P) = pP;
        next(pP) = pP;
    }else{
        Q = first(P);
        while (next(Q) != first(P)){
            Q = next(Q);
        }
        next(Q) = pP;
        next(pP) = first(P);
    }
}

void deleteFirst_Parent(list_P &P, address_P pP){
    address_P Q;
    if(first(P)!=NULL){
        pP=first(P);
        if (next(pP)==first(P)){
            next(pP)=NULL;
            first(P)=NULL;
        }else{
            Q=first(P);
            while(next(Q)!=first(P)){
                Q=next(Q);
            }
            first(P)=next(pP);
            next(Q)=next(pP);
            next(pP)=NULL;
        }
    }
}

void deleteAfter_Parent(list_P &P, address_P pP, address_P prec){
    if((first(P)!=NULL)&&(prec!=NULL)){
        if(next(prec)==first(P)){
            deleteFirst_Parent(P,pP);
        }else{
            pP=next(prec);
            next(prec)=next(pP);
            next(pP)=NULL;
        }
    }
}

/// menu 1 registrasi ////////////////////////
void insertTempatParkir(list_P &P){
    infotype_P dp; address_P pP; string ans;
    system("cls");
    cout<<"BERANDA >>> REGISTRASI >>> INSERT PARKIR"<<endl;
    cout<<"========================================="<<endl<<endl;
    cout<<"Masukkan data parkir:"<<endl;
    cout<<"Lantai: "; cin>>dp.lantai;
    cout<<"Blok  : "; cin>>dp.blok;
    if ((dp.blok == "A")||(dp.blok == "a")){
        dp.kuota = 50;
        dp.blok = "A";
    }else if ((dp.blok == "B" )||(dp.blok == "b")){
        dp.kuota =50;
        dp.blok = "B";
    }else if ((dp.blok == "C")||(dp.blok == "c")){
        dp.kuota = 30;
        dp.blok = "C";
    }else if ((dp.blok == "D")||(dp.blok == "d")){
        dp.kuota = 30;
        dp.blok = "D";
    }

    address_P  cari = cariBlokLantai(P,dp.blok,dp.lantai);
    if(cari == NULL){
        dp.sisa = dp.kuota;
        pP = alokasi_Parent(dp);
        if (first(P) == NULL){
            insertFirst_Parent(P,pP);
        }else{
            insertLast_Parent(P,pP);
        }
        cout<<endl<<"insert parkir berhasil"<<endl<<endl;
    }else{
        cout<<endl<<"maaf data sudah ada"<<endl;
    }
    cout<<"==========================================="<<endl;
    cout<<"Insert parkir lagi [Y/T]: "; cin>>ans;
    if ((ans == "Y")||(ans == "y")){
        insertTempatParkir(P);
    }else{
        cout<<endl<<endl;
        system("PAUSE");
    }
}

void lantaiTerpenuh(list_P &P){
    //menampilkan urutan tempat parkir paling penuh dan tidak
    system("cls");
    cout<<" BERANDA >>> DAFTAR TEMPAT TERPENUH"<<endl;
    cout<<"============================================================="<<endl<<endl;
    address_P pP;
    pP=first(P);
    if(pP!=NULL){
        int sisa1,sisa2,sisa3;
        sisa1=0; sisa2=0; sisa3=0;
        do{
            if (info(pP).lantai=="1"){
                if ((info(pP).blok == "A")||(info(pP).blok == "B")){
                    sisa1 = 50-info(pP).sisa +sisa1;
                }else{
                    sisa1 = 30-info(pP).sisa+sisa1;
                }
            }else if(info(pP).lantai=="2"){
                if ((info(pP).blok == "A")||(info(pP).blok == "B")){
                    sisa2 = 50-info(pP).sisa +sisa2;
                }else{
                    sisa2 = 30-info(pP).sisa+sisa2;
               }
            }else if(info(pP).lantai=="3"){
                if ((info(pP).blok == "A")||(info(pP).blok == "B")){
                    sisa3 = 50-info(pP).sisa +sisa3;
                }else{
                    sisa3 = 30-info(pP).sisa+sisa3;
                }
            }
            pP=next(pP);
        }while(pP!=first(P));

        if ((sisa1>sisa2)&&(sisa1>sisa3)){ ///lantai 1
            cout<<"Lantai terpenuh adalah lantai 1"<<endl<<endl;
            cout<<"Urutan lantai terpenuh:"<<endl;
            cout<<"[1] Lantai 1"<<endl;
            cout<<"    Pengunjung : "<<sisa1<<endl;
            if (sisa2>sisa3){
                cout<<"[2] Lantai 2"<<endl;
                cout<<"    Pengunjung : "<<sisa2<<endl;
                cout<<"[3] Lantai 3"<<endl;
                cout<<"    Pengunjung : "<<sisa3<<endl;
            }else{
                cout<<"[2] Lantai 3"<<endl;
                cout<<"    Pengunjung : "<<sisa3<<endl;
                cout<<"[3] Lantai 2"<<endl;
                cout<<"    Pengunjung : "<<sisa2<<endl;
            }
        }else if((sisa2>sisa1)&&(sisa2>sisa3)){ ///lantai 2
            cout<<"Lantai terpenuh adalah lantai 2"<<endl<<endl;
            cout<<"Urutan lantai terpenuh:"<<endl;
            cout<<"[1] Lantai 2"<<endl;
            cout<<"    Pengunjung : "<<sisa2<<endl;
            if (sisa1>sisa3){
                cout<<"[2] Lantai 1"<<endl;
                cout<<"    Pengunjung : "<<sisa1<<endl;
                cout<<"[3] Lantai 3"<<endl;
                cout<<"    Pengunjung : "<<sisa3<<endl;
            }else{
                cout<<"[2] Lantai 3"<<endl;
                cout<<"    Pengunjung : "<<sisa3<<endl;
                cout<<"[3] Lantai 1"<<endl;
                cout<<"    Pengunjung : "<<sisa1<<endl;
            }
        }else if((sisa3>sisa2)&&(sisa3>sisa1)){ ///lantai 3
            cout<<"Lantai terpenuh adalah lantai 3"<<endl<<endl;
            cout<<"Urutan lantai terpenuh:"<<endl;
            cout<<"[1] Lantai 3"<<endl;
            cout<<"    Pengunjung : "<<sisa3<<endl;
            if (sisa2>sisa1){
                cout<<"[2] Lantai 2"<<endl;
                cout<<"    Pengunjung : "<<sisa2<<endl;
                cout<<"[3] Lantai 1"<<endl;
                cout<<"    Pengunjung : "<<sisa1<<endl;
            }else{
                cout<<"[2] Lantai 1"<<endl;
                cout<<"    Pengunjung : "<<sisa1<<endl;
                cout<<"[3] Lantai 2"<<endl;
                cout<<"    Pengunjung : "<<sisa2<<endl;
            }         //   cout<<"Lantai Terpenuh : Lantai 3"<<endl;
        }else if ((sisa1==sisa2)&&(sisa2==sisa3)){
            cout<<"Banyak pengunjung setiap lantai sama"<<endl<<endl;
            cout<<"Daftar banyak pengunjung:"<<endl;
            cout<<"[1] Lantai 1"<<endl;
            cout<<"    Pengunjung : "<<sisa1<<endl;
            cout<<"[2] Lantai 2"<<endl;
            cout<<"    Pengunjung : "<<sisa2<<endl;
            cout<<"[3] Lantai 3"<<endl;
            cout<<"    Pengunjung : "<<sisa3<<endl;
        }else if ((sisa1>sisa2)&&(sisa2==sisa3)){
            cout<<"Lantai terpenuh adalah lantai 1"<<endl<<endl;
            cout<<"Daftar banyak pengunjung:"<<endl;
            cout<<"[1] Lantai 1"<<endl;
            cout<<"    Pengunjung : "<<sisa1<<endl;
            cout<<"[2] Lantai 2"<<endl;
            cout<<"    Pengunjung : "<<sisa2<<endl;
            cout<<"[3] Lantai 3"<<endl;
            cout<<"    Pengunjung : "<<sisa3<<endl;

        }else if ((sisa2>sisa1)&&(sisa1==sisa3)){
            cout<<"Lantai terpenuh adalah lantai 2"<<endl<<endl;
            cout<<"Daftar banyak pengunjung:"<<endl;
            cout<<"[1] Lantai 2"<<endl;
            cout<<"    Pengunjung : "<<sisa2<<endl;
            cout<<"[2] Lantai 1"<<endl;
            cout<<"    Pengunjung : "<<sisa1<<endl;
            cout<<"[3] Lantai 3"<<endl;
            cout<<"    Pengunjung : "<<sisa3<<endl;
        }else if ((sisa3>sisa1)&&(sisa1==sisa2)){
            cout<<"Lantai terpenuh adalah lantai 3"<<endl<<endl;
            cout<<"Daftar banyak pengunjung:"<<endl;
            cout<<"[1] Lantai 3"<<endl;
            cout<<"    Pengunjung : "<<sisa1<<endl;
            cout<<"[2] Lantai 2"<<endl;
            cout<<"    Pengunjung : "<<sisa2<<endl;
            cout<<"[3] Lantai 1"<<endl;
            cout<<"    Pengunjung : "<<sisa1<<endl;

        }
        cout<<endl;
    }else{
        cout<<endl<<"tidak ada data"<<endl<<endl;
    }
    cout<<"============================================================="<<endl;
    cout<<"Tekan enter untuk kembali "<<endl<<endl;
    system("PAUSE");
}

