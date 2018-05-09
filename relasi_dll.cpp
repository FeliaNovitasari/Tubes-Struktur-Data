#include <iostream>
#include <stdlib.h>
#include <string>
#include "relasi_dll.h"
using namespace std;


void createList_Relasi(list_R &R){
    first(R) = NULL;
}

address_R alokasi_Relasi(address_C pC, address_P pP, infotype_R dr){
    address_R pR;
    pR = new elm_R;
    parent(pR) = pP;
    child(pR) = pC;
    info(pR) = dr;
    next(pR) = NULL;
    prev(pR) = NULL;
    return pR;
}

void dealokasi_Relasi(address_R pR){
    delete(pR);
}

void printInfo_Relasi(list_R &R){
    address_R pR;
    if (first(R) == NULL){
        cout<<"data realasi tidak ada"; cout<<endl;
    }
    else{
        int i=1;
        pR = first(R);
        cout<<"Data Relasi:"<<endl;
        while (pR != NULL){
            cout<<endl;
            cout<<"["<<i<<"]";
            cout<<"  Jenis Kendaraan  : "<<info(child(pR)).jenis<<endl;
            cout<<"     No.Plat          : "<<info(child(pR)).plat<<endl;
            cout<<"     Merk             : "<<info(child(pR)).merk<<endl;
            cout<<"     Saldo Awal       : Rp."<<info(child(pR)).saldoawal<<endl;
            cout<<"     Saldo Akhir      : Rp."<<info(child(pR)).saldoakhir<<endl;
            cout<<"     Lantai           : "<<info(parent(pR)).lantai<<endl;
            cout<<"     Blok             : "<<info(parent(pR)).blok<<endl;
            cout<<"     Masuk            : "<<info(pR).jm<<"."<<info(pR).mm<<endl;
            cout<<"     Keluar           : "<<info(pR).jk<<"."<<info(pR).mk<<endl;
            cout<<"     Tanggal          : "<<info(pR).date<<endl;
            cout<<"     Durasi           : "<<info(pR).jam<<" jam "<<info(pR).menit<<" menit "<<endl;
            cout<<"     Tarif            : Rp."<<info(pR).tarif<<endl;
            pR = next(pR); i++;
        }
            cout<<endl<<"Banyak relasi: "<<i-1<<endl;
        }
    }



void insertFirst_Relasi(list_R &R, address_R pR){
    if (first(R) == NULL){
        first(R) = pR;
        last(R) = pR;
    }else{
        next(pR) = first(R);
        prev(first(R)) = pR;
        first(R) = pR;
    }
}

void insertLast_Relasi(list_R &R, address_R pR){
    if (first(R) == NULL){
        first(R) = pR;
        last(R) = pR;
    }else{
        prev(pR) = last(R);
        next(last(R)) = pR;
        last(R) = pR;
    }
}

void deleteFirst_Relasi(list_R &R, address_R pR){
    if(first(R)!=NULL){
        pR=first(R);
        if(pR=last(R)){
            first(R)=NULL;
            last(R)=NULL;
        }else{
            first(R)=next(pR);
            next(pR)=NULL;
            prev(first(R))=NULL;
        }
    }
}

void deleteLast_Relasi(list_R &R, address_R pR){
    if(first(R)!=NULL){
        pR=last(R);
        if(pR==last(R)){
            first(R)=NULL;
            last(R)=NULL;
        }else{
            last(R)=prev(pR);
            prev(pR)=NULL;
            next(last(R))=NULL;
        }
    }
}

void deleteAfter_Relasi(list_R &R, address_R pR, address_R prec){
    if((first(R)!=NULL)&& (prec!=NULL)){
        if(prec!=last(R)){
            if(next(prec)==last(R)){
                deleteLast_Relasi(R,pR);
            }else{
                pR=next(prec);
                next(prec)=next(pR);
                prev(next(pR))=prec;
                next(pR)=NULL;
                prev(pR)=NULL;
            }
        }
    }
}


//kodingnyaaaaaaaaaaaaaaaaaaaaaaaaaa/////////////////////////////////////
//menu1//////////////////////////////////////////////
void registrasi(list_C &C, list_P &P, list_R &R){
    char pilih;
    while (pilih != '4'){
        system("cls");
        cout<<endl;
        cout<<" BERANDA >>> REGISTRASI"<<endl;
        cout<<"============================================================="<<endl;
        cout<<" 1. MASUK"<<endl;
        cout<<" 2. INPUT DATA"<<endl;
        cout<<" 3. INSERT TEMPAT PARKIR"<<endl;
        cout<<" 4. KEMBALI"<<endl; cout<<endl;
        cout<<" *silahkan pilih 1 jika pernah parkir di MF Parking :) "<<endl; cout<<endl;
        cout<<"=============================================================="<<endl;
        cout<<"Pilih: "; cin>>pilih;
        switch(pilih){
        case '1':
            masuk(C,P,R);
            break;
        case '2':
            inputData(C,P,R);
            break;
        case '3':
            insertTempatParkir(P);
            break;
        }
    }
}

void masuk(list_C &C, list_P &P, list_R &R){
    system("cls");
    string plat,blok,lantai,ans; int saldo;
    infotype_C dc; infotype_P dp; infotype_R dr;
    address_C pC; address_P pP; address_R pR;
    cout<<"BERANDA >>> REGISTRASI >>> MASUK"<<endl;
    cout<<"==================================================================="<<endl<<endl;
    cin.ignore();
    cout<<"Masukkan no.plat kendaraan anda: "; getline(cin,plat); cout<<endl;
    pC = cariPlat(C,plat);
    if (pC!=NULL){
        cout<<"Data anda:"<<endl;
        cout<<"Jenis    : "<<info(pC).jenis<<endl;
        cout<<"No.Plat  : "<<info(pC).plat<<endl;
        cout<<"Merk     : "<<info(pC).merk<<endl;
        cout<<"Saldo    : "<<info(pC).saldoawal<<endl<<endl;
        cout<<"Silahkan pilih tempat parkir:"<<endl; //UPDATE DATA
        cout<<"Tambah saldo: Rp. "; cin>>saldo;
        cout<<"Blok        : "; cin>>blok;
        cout<<"Lantai      : "; cin>>lantai;
        do{
        cout<<"Jam Masuk     : "; cin>>dr.jm;
        }while(dr.jm >= 24);
        do{
            cout<<"Menit Masuk   : "; cin>>dr.mm;
        }while (dr.mm >= 60);
        do{
            cout<<"Jam Keluar    : "; cin>>dr.jk;
        }while (dr.jk >= 24);

        do{
            cout<<"Menit Keluar  : "; cin>>dr.mk;
        }while (dr.mk >= 60);

        cin.ignore();
        cout<<"Tanggal     : "; getline(cin,dr.date); cout<<endl;
        int wm,wk,lama,tarif,y,lama2;
        float x;
        ///ngitung parkir//
        wm = (dr.jm*60)+dr.mm; //waktu masuk(detik)
        wk = (dr.jk*60)+dr.mk; //waktu keluar(detik)
        lama = wk-wm;
        info(pC).durasi = info(pC).durasi+lama;
        dr.jam = lama/60;
        dr.menit = lama%60;
        lama2 = lama-60; ///sejam pertama udah diambil
        if ((dc.jenis=="motor")||(dc.jenis=="Motor")||(dc.jenis=="MOTOR")){
            if (lama<0){
                tarif = 2000;
            }else{
                x=lama2/60;
                y=lama2%60;
                if (y==0){
                    tarif=2000+(x*1000);
                }else{
                    tarif=3000+(x*1000); //karena hasil bagi lebih dari 1
                }
            }
        }else{
            if (lama<0){
                tarif = 3000;
            }else{
                x=lama2/60;
                y=lama2%60;
                if (y==0){
                    tarif=3000+(x*2000);
                }else{
                    tarif=5000+(x*2000); //karena hasil bagi lebih dari 1
                }
            }
        }

        blok = ubahBlok(blok);
        pP = cariBlokLantai(P,blok,lantai); //searching
        if (pP == NULL){
            char pil;
            cout<<"maaf data tempat parkir salah"<<endl;
            cout<<"#tekan 1 untuk melihat daftar tempat parkir yang tersedia"<<endl;
            cout<<"#tekan 2 untuk kembali ke menu sebelumnya"<<endl;
            cin>>pil; cout<<endl;
            if (pil == '1'){
                printInfo_Parent(P); cout<<endl<<endl;
                cout<<"Input ulang data"<<endl;
                cout<<"Blok     : "; cin>>blok;
                cout<<"Lantai   : "; cin>>lantai; cout<<endl;
                blok = ubahBlok(blok);
                pP = cariBlokLantai(P,blok,lantai);
                if (pP != NULL){
                    cout<<"maaf data tempat parkir salah lagi"<<endl;
                    cout<<"silahkan tekan 2 untuk kembali ke menu sebelumnya"<<endl;
                    cin>>pil;
                    if (pil == '2'){
                        registrasi(C,P,R);
                    }
                }
            }else if (pil == '2'){
                registrasi(C,P,R);
            }
        }
        if ((lantai=="1")){
            dr.tarif=tarif+3000;
        }else if (lantai=="2"){
            dr.tarif=tarif+2000;
        }else{
            dr.tarif=tarif+1000;
        }
        info(pC).saldoawal = info(pC).saldoawal+saldo;
        info(pC).saldoakhir = info(pC).saldoawal-dr.tarif;
        cout<<"Parkir: "<<endl;
        cout<<"Lama Parkir : "<<dr.jam<<" jam "<<dr.menit<<" menit "<<endl;
        cout<<"Tarif Parkir: "<<dr.tarif<<endl;
        cout<<"Durasi      : "<<info(pC).durasi<<" menit"<<endl;
        cout<<"Saldo Akhir : "<<info(pC).saldoakhir<<endl;

        pR = alokasi_Relasi(pC,pP,dr);
        if (first(R) != NULL){
            insertLast_Relasi(R,pR);
            info(pP).sisa = info(pP).sisa-1;
            cout<<"Terimaksih telah parkir di MF Parking :)"<<endl;
        }
    }else{
        cout<<"Kendaraan tidak ditemukan"<<endl;
        cout<<"Silahkan input data anda terlebih dahulu (*pilih menu REGISTRASI >>> INPUT DATA)"<<endl;
    }
    cout<<"===================================================================================="<<endl;
    cout<<"Input data lagi [Y/T]: "; cin>>ans;
    if ((ans == "Y")||(ans == "y")){
        masuk(C,P,R);
    }else{
        cout<<endl<<endl;
        system("PAUSE");
    }
}

void inputData(list_C &C, list_P &P, list_R &R){
    address_P pP; address_C pC; address_R pR;
    infotype_R dr; infotype_C dc; infotype_P dp;
    string blok,lantai,ans;

    system("cls");
    cout<<"BERANDA >>> REGISTRASI >>> INPUT DATA"<<endl;
    cout<<"=========================================================="<<endl<<endl;
    cout<<"Tarif lantai:"<<endl;
    cout<<" - Lantai 1 Rp.3000"<<endl;
    cout<<" - Lantai 2 Rp.2000"<<endl;
    cout<<" - Lantai 3 Rp.1000"<<endl<<endl;
    cout<<"Tarif:"<<endl;
    cout<<" - Mobil                    - Motor"<<endl;
    cout<<"   1 jam pertama Rp.3000      1 jam pertama Rp.2000"<<endl;
    cout<<"   1 jam berikutnya Rp.2000   1 jam berikutnya Rp.1000"<<endl;
    cout<<"   + tarif lantai             + tarif lantai"<<endl;
    cout<<endl;
    cout<<"*untuk motor silahkan pilih blok A dan B"<<endl;
    cout<<"*untuk mobil silahkan pilih blok C dan D"<<endl;
    cout<<endl; cout<<endl;
    cout<<"Silahkan masukkkan data parkir:"<<endl<<endl;
    cout<<"Data Parkir:"<<endl;
    cout<<"Jenis Kendaraan     : "; cin>>dc.jenis;
    cin.ignore();
    cout<<"No. Plat Kendaraan  : "; getline(cin,dc.plat);
    cout<<"Merk Kendaraan      : "; cin>>dc.merk;
    cout<<"Tambah Saldo        : "; cin>>dc.saldoawal;
    cout<<endl;
    cout<<"Data Tempat Parkir:"<<endl;
    cout<<"Blok          : "; cin>>blok;
    cout<<"Lantai        : "; cin>>lantai;
    cin.ignore();
    cout<<"Tanggal       : "; getline(cin,dr.date);

    do{
        cout<<"Jam Masuk     : "; cin>>dr.jm;
    }while(dr.jm >= 24);
    do{
        cout<<"Menit Masuk   : "; cin>>dr.mm;
    }while (dr.mm >= 60);
    do{
        cout<<"Jam Keluar    : "; cin>>dr.jk;
    }while (dr.jk >= 24);

    do{
        cout<<"Menit Keluar  : "; cin>>dr.mk;
    }while (dr.mk >= 60);
    cout<<endl;

    int wm,wk,lama,tarif,y,lama2;
    float x;
    ///ngitung parkir//
    wm = (dr.jm*60)+dr.mm; ///waktu masuk(detik)
    wk = (dr.jk*60)+dr.mk; ///waktu keluar(detik)
    lama = wk-wm;
    dc.durasi = lama;
    dr.jam = lama/60;
    dr.menit = lama%60;
    lama2 = lama-60; ///sejam pertama udah diambil
    if ((dc.jenis=="motor")||(dc.jenis=="Motor")||(dc.jenis=="MOTOR")){
        if (lama<0){
            tarif = 2000;
        }else{
            x=lama2/60;
            y=lama2%60;
            if (y==0){
                tarif=2000+(x*1000);
            }else{
                tarif=3000+(x*1000); //karena hasil bagi lebih dari 1
            }
        }
    }else{
        if (lama<0){
            tarif = 3000;
        }else{
            x=lama2/60;
            y=lama2%60;
            if (y==0){
                tarif=3000+(x*2000);
            }else{
                tarif=5000+(x*2000); //karena hasil bagi lebih dari 1
            }
        }
    }
    blok = ubahBlok(blok);
    pP = cariBlokLantai(P,blok,lantai);
    if (pP == NULL){
        char pil;
        cout<<"maaf data tempat parkir salah"<<endl;
        cout<<"#tekan 1 untuk melihat daftar tempat parkir yang tersedia"<<endl;
        cout<<"#tekan 2 untuk kembali ke menu sebelumnya"<<endl;
        cin>>pil; cout<<endl;
        if (pil == '1'){
            printInfo_Parent(P); cout<<endl<<endl;
            cout<<"Input ulang data"<<endl;
            cout<<"Blok     : "; cin>>blok;
            cout<<"Lantai   : "; cin>>lantai; cout<<endl;
            blok = ubahBlok(blok);
            pP = cariBlokLantai(P,blok,lantai);
            if (pP == NULL){
                cout<<"maaf data tempat parkir salah lagi"<<endl;
                cout<<"silahkan tekan 2 untuk kembali ke menu sebelumnya"<<endl;
                cin>>pil;
                if (pil == '2'){
                    registrasi(C,P,R);
                }
            }
        }else if (pil == '2'){
            registrasi(C,P,R);
        }
    }
    if ((lantai=="1")){
        dr.tarif=tarif+3000;
    }else if (lantai=="2"){
        dr.tarif=tarif+2000;
    }else{
        dr.tarif=tarif+1000;
    }
    cout<<"Parkir: "<<endl;
    cout<<"Lama Parkir : "<<dr.jam<<" jam "<<dr.menit<<" menit "<<endl;
    cout<<"Tarif Parkir: "<<dr.tarif<<endl; ///gak bisa ngitung ///lebih seribu kalo jam =0
    cout<<"Durasi      : "<<dc.durasi; ///buat ngecek doang jangan lupa hapus
    cout<<endl<<endl;

    dc.saldoakhir = dc.saldoawal-dr.tarif;
    if (pP != NULL){
        pC = alokasi_Child(dc);;
        if (first(C) == NULL){
            insertFirst_Child(C,pC);
        }else{
            insertLast_Child(C,pC);
        }
        pR = alokasi_Relasi(pC, pP, dr);
        if (first(R) == NULL){
            insertFirst_Relasi(R,pR);
        }else{
            insertLast_Relasi(R,pR);
        }
        info(pP).sisa = info(pP).sisa-1;
    }
    cout<<"*untuk parkir selanjutnya silahkan pilih menu REGISTRASI>>>MASUK"<<endl; cout<<endl;
    cout<<"Terimaksih telah parkir di MF Parking :)"<<endl;
    cout<<"================================================================="<<endl;
    cout<<"Input data lagi [Y/T]: "; cin>>ans;
    if ((ans == "Y")||(ans == "y")){
        inputData(C,P,R);
    }else{
        cout<<endl<<endl;
        system("PAUSE");
    }
}

//menu 2///////////////////////////////////////////////////////////////////////////
void lihatData(list_C &C, list_P &P, list_R &R){
    char pilih;
    while (pilih != '4'){
        system("cls");
        cout<<" BERANDA >>> LIHAT DATA"<<endl;
        cout<<"============================================================="<<endl;
        cout<<" 1.DAFTAR TEMPAT"<<endl;
        cout<<" 2.DAFTAR KENDARAAN (pengunjung)"<<endl;
        cout<<" 3.DAFTAR RELASI"<<endl;
        cout<<" 4.KEMBALI"<<endl;
        cout<<"=============================================================="<<endl;
        cout<<"Pilih: "; cin>>pilih;
        switch(pilih){
        case '1':
            system("cls");
            cout<<"BERANDA >>> DATA TEMPAT DAN KENDARAAN >>> DAFTAR TEMPAT"<<endl;
            cout<<"========================================================"<<endl<<endl;
            printInfo_Parent(P); cout<<endl;
            cout<<"========================================================"<<endl;
            cout<<"Tekan enter untuk kembali"<<endl<<endl;
            system("PAUSE");
            break;
        case '2':
            system("cls");
            cout<<"BERANDA >>> DATA TEMPAT DAN KENDARAAN >>> DAFTAR KENDARAAN (pengunjung)"<<endl;
            cout<<"======================================================================="<<endl<<endl;
            printInfo_Child(C); cout<<endl;
            cout<<"======================================================================="<<endl;
            cout<<"Tekan enter untuk kembali"<<endl<<endl;
            system("PAUSE");
            break;
        case '3':
            system("cls");
            cout<<"BERANDA >>> DATA TEMPAT DAN KENDARAAN >>> DAFTAR RELASI"<<endl;
            cout<<"========================================================"<<endl<<endl;
            printInfo_Relasi(R); cout<<endl;
            cout<<"========================================================"<<endl;
            cout<<"Tekan enter untuk kembali"<<endl<<endl;
            system("PAUSE");
            break;
       }
   }
}

//menu 3////////////////////////////////////////////////////////////////////////////
void cariData(list_C &C, list_P &P, list_R &R){
    char pilih;
    while (pilih != '4'){
        system("cls");
        cout<<" BERANDA >>> CARI DATA"<<endl;
        cout<<"============================================================="<<endl;
        cout<<" 1.CARI TEMPAT PARKIR"<<endl;
        cout<<" 2.CARI KENDARAAN"<<endl;
        cout<<" 3.CARI RELASI"<<endl;
        cout<<" 4.KEMBALI"<<endl;
        cout<<"=============================================================="<<endl;
        cout<<"Pilih: "; cin>>pilih;
        switch(pilih){
        case '1':
            cariTempat(P);
            break;
        case '2':
            cariKendaraan(C);
            break;
        case '3':
            cariRelasi(R);
            break;
        }
    }
}

// menu 4 //////////////////////////////////////////////
void hapusData(list_C &C, list_P &P, list_R &R){
    char pilih;
    while (pilih != '4'){
        system("cls");
        cout<<" BERANDA >>> HAPUS DATA"<<endl;
        cout<<"============================================================="<<endl;
        cout<<" 1.HAPUS TEMPAT PARKIR"<<endl;
        cout<<" 2.HAPUS KENDARAAN"<<endl;
        cout<<" 3.HAPUS RELASI"<<endl;
        cout<<" 4.KEMBALI"<<endl;
        cout<<"=============================================================="<<endl;
        cout<<"Pilih: "; cin>>pilih;
        switch(pilih){
        case '1':
            hapusTempat(P);
            break;
        case '2':
            hapusKendaraan(C);
            break;
        case '3':
            hapusRelasi(R);
            break;
        case '4':
            system("PAUSE");
        }
    }
}

// menu 5 ///////////////////////////////////////////////
void pendapatan(list_R &R){
    system("cls");
    cout<<" BERANDA >>> PENDAPATAN"<<endl;
    cout<<"============================================================="<<endl<<endl;
    address_R pR = first(R);
    int pdpt1,pdpt2,pdpt3;
    pdpt1=0; pdpt2=0; pdpt3=0;
    if(pR!=NULL){
        cout<<"Daftar Pendapatan lantai:"<<endl;
        while(pR!=NULL){
            if(info(parent(pR)).lantai=="1"){
                pdpt1=pdpt1+(info(pR).tarif);
            }else if(info(parent(pR)).lantai=="2"){
                pdpt2=pdpt2+(info(pR).tarif);
            }else if(info(parent(pR)).lantai=="3"){
                pdpt3=pdpt3+(info(pR).tarif);
            }
            pR=next(pR);
        }
        cout<<"Lantai 1 : Rp."<<pdpt1<<endl;
        cout<<"Lantai 2 : Rp."<<pdpt2<<endl;
        cout<<"Lantai 3 : Rp."<<pdpt3<<endl<<endl;

        if (((pdpt1>pdpt2)&&(pdpt1>pdpt3))||((pdpt1==pdpt2)||(pdpt1==pdpt3))){
            cout<<"Pendapatan Terbesar : Lantai 1"<<endl;
            cout<<"Total Pendapatan    : "<<pdpt1<<endl<<endl;
        }else if(((pdpt2>pdpt1)&&(pdpt2>pdpt3))||((pdpt2==pdpt1)||(pdpt2==pdpt3))){
            cout<<"Pendapatan Terbesar : Lantai 2"<<endl;
            cout<<"Total Pendapatan    : "<<pdpt2<<endl<<endl;
        }else if(((pdpt3>pdpt1)&&(pdpt3>pdpt2))||((pdpt3==pdpt1)||(pdpt3==pdpt2))){
            cout<<"Pendapatan Terbesar : Lantai 3"<<endl;
            cout<<"Total Pendapatan    : "<<pdpt3<<endl<<endl;
        }
        if ((pdpt1<pdpt2)&&(pdpt1<pdpt3)||((pdpt1==pdpt2)||(pdpt1==pdpt3))){
            cout<<"Pendapatan Terkecil : Lantai 1"<<endl;
            cout<<"Total Pendapatan     : "<<pdpt1<<endl<<endl;
        }else if(((pdpt2<pdpt1)&&(pdpt2<pdpt3))||((pdpt2==pdpt1)||(pdpt2==pdpt3))){
            cout<<"Pendapatan Terkecil : Lantai 2"<<endl;
            cout<<"Total Pendapatan    : "<<pdpt2<<endl<<endl;
        }else if(((pdpt3<pdpt1)&&(pdpt3<pdpt2))||((pdpt3==pdpt1)||(pdpt3==pdpt2))){
            cout<<"Pendapatan Terkecil : Lantai 3"<<endl;
            cout<<"Total Pendapatan    : "<<pdpt3<<endl<<endl;
        }
    }else {
        cout<<"Tidak ada data"<<endl<<endl;
    }
    cout<<"============================================================="<<endl;
    cout<<"Tekan enter untuk kembali"<<endl<<endl;
    system("PAUSE");
}


