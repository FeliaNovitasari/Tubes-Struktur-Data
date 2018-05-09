#include <iostream>
#include <cstdlib>
#include "relasi_dll.h"

using namespace std;

///void function helper /////////////////////////////////////////

string ubahBlok(string blok){
    if ((blok == "A")||(blok == "a")){
        blok = "A";
    }else if ((blok == "B" )||(blok == "b")){
        blok = "B";
    }else if ((blok == "C")||(blok == "c")){
        blok = "C";
    }else if ((blok == "D")||(blok == "d")){
        blok = "D";
    }
    return blok;
}

address_P cariBlokLantai(list_P L, string blok, string lantai){
    address_P P = first(L);
    if (first(L) != NULL){
        while (next(P) != first(L)){
            if (info(P).blok == blok && info(P).lantai == lantai){
                return P;
            }
            P = next(P);
        }
        if (info(P).blok == blok && info(P).lantai == lantai){
            return P;
        } else {
            return NULL;
        }
    }
}


address_C cariPlat(list_C L, string plat){
    address_C P = first(L);
    if(first(L)!=NULL){
        while ((next(P)!= first(L))&&(info(P).plat != plat)){
            P = next(P);
        }
        if (info(P).plat == plat){
            return P;
        }else{
            return NULL;
        }

    }
}

address_R cariTanggal(list_R L, string date){
    address_R P = first(L);
    if (first(L) != NULL){
        while ((next(P) != NULL) && (info(P).date != date)){
            P = next(P);
        }
        if (info(P).date == date){
            return P;
        }else{
            return NULL;
        }
    }
}

void cariTempat(list_P &P){
    string blok,ans; string lantai;
    system("cls");
    cout<<"BERANDA >>> CARI DATA >>> CARI TEMPAT"<<endl;
    cout<<"======================================"<<endl<<endl;
    cout<<"Masukkan data tempat:"<<endl;
    cout<<"Blok   : "; cin>>blok;
    cout<<"Lantai : "; cin>>lantai; cout<<endl;
    blok=ubahBlok(blok);
    address_P cari=cariBlokLantai(P,blok,lantai);
    if (cari!=NULL){
        cout<<"Data berhasil ditemukan"<<endl<<endl;
        cout<<"Data Tempat:"<<endl;
        cout<<"Lantai  : "<<info(cari).lantai<<endl;
        cout<<"Blok    : "<<info(cari).blok<<endl;
        cout<<"Kuota   : "<<info(cari).kuota<<endl;
        cout<<"Sisa    : "<<info(cari).sisa<<endl<<endl;
    }else{
        cout<<"Data tidak ditemukan"<<endl;
    }
    cout<<"======================================"<<endl;
    cout<<"Cari data tempat lagi [Y/T]: "; cin>>ans;
    if ((ans=="Y")||(ans=="y")){
        cariTempat(P);
    }else{
        cout<<endl<<endl;
        system("PAUSE");
    }

}

void cariKendaraan(list_C &C){
    string plat,ans;
    system("cls");
    cout<<"BERANDA >>> CARI DATA >>> CARI KENDARAAN"<<endl;
    cout<<"=========================================="<<endl<<endl;
    cout<<"Masukkan no.plat kendaraan: "; cin>>plat; cout<<endl;
    address_C cari=cariPlat(C,plat);
    if (cari!=NULL){
        cout<<"Data berhasil ditemukan"<<endl<<endl;
        cout<<"Data Kendaraan:"<<endl;
        cout<<"Jenis    : "<<info(cari).jenis<<endl;
        cout<<"No.Plat  : "<<info(cari).plat<<endl;
        cout<<"Merk     : "<<info(cari).merk<<endl;
        cout<<"Saldo    : "<<info(cari).saldoakhir<<endl<<endl;
    }else{
        cout<<"Data tidak ditemukan"<<endl;
    }
    cout<<"=========================================="<<endl;
    cout<<"Cari data kendaraan lagi [Y/T]: "; cin>>ans;
    if ((ans=="Y")||(ans=="y")){
        cariKendaraan(C);
    }else{
        cout<<endl<<endl;
        system("PAUSE");
    }

}

void cariRelasi(list_R &R){
    string date,ans;
    system("cls");
    cout<<"BERANDA >>> CARI DATA >>> CARI RELASI"<<endl;
    cout<<"======================================="<<endl<<endl;
    cin.ignore();
    cout<<"Masukkan tanggal: "; getline(cin,date); cout<<endl;
    address_R cari=cariTanggal(R,date);
    if (cari!=NULL){
        cout<<"Data berhasil ditemukan"<<endl<<endl;
        cout<<"Data Tempat:"<<endl;
        cout<<"Jenis Kendaraan  : "<<info(child(cari)).jenis<<endl;
        cout<<"No.Plat          : "<<info(child(cari)).plat<<endl;
        cout<<"Merk             : "<<info(child(cari)).merk<<endl;
        cout<<"Saldo Awal       : "<<info(child(cari)).saldoawal<<endl;
        cout<<"Saldo Akhir      : "<<info(child(cari)).saldoakhir<<endl;
        cout<<"Lantai           : "<<info(parent(cari)).lantai<<endl;
        cout<<"Blok             : "<<info(parent(cari)).blok<<endl;
        cout<<"Masuk            : "<<info(cari).jm<<"."<<info(cari).mm<<endl;
        cout<<"Keluar           : "<<info(cari).jk<<"."<<info(cari).mk<<endl;
        cout<<"Durasi           : "<<info(cari).jam<<" jam "<<info(cari).menit<<" menit "<<endl;
        cout<<"Tarif            : Rp."<<info(cari).tarif<<endl;
    }else{
        cout<<endl<<"Data tidak ditemukan"<<endl;
    }
    cout<<"======================================="<<endl;
    cout<<"Cari data relasi lagi [Y/T]: "; cin>>ans;
    if ((ans=="Y")||(ans=="y")){
        cariRelasi(R);
    }else{
        cout<<endl<<endl;
        system("PAUSE");
    }
}

void hapusTempat(list_P &P){
    string blok,ans; string lantai;
    system("cls");
    cout<<"BERANDA >>> HAPUS DATA >>> HAPUS TEMPAT"<<endl;
    cout<<"======================================"<<endl<<endl;
    cout<<"Masukkan data tempat:"<<endl;
    cout<<"Lantai : "; cin>>lantai;
    cout<<"Blok   : "; cin>>blok; cout<<endl;
    blok=ubahBlok(blok);
    address_P cari=cariBlokLantai(P,blok,lantai);
    if (cari!=NULL){
        cout<<"Data Tempat:"<<endl;
        cout<<"Lantai  : "<<info(cari).lantai<<endl;
        cout<<"Blok    : "<<info(cari).blok<<endl;
        cout<<"Kuota   : "<<info(cari).kuota<<endl;
        cout<<"Sisa    : "<<info(cari).sisa<<endl<<endl;
        cout<<"Hapus data ini [Y/T]: "; cin>>ans;
        if ((ans=="Y")||(ans=="y")){
            if (cari == first(P)){
                deleteFirst_Parent(P,cari);
            }else{
                address_P prec=first(P);
                while (next(prec)!=cari){
                    prec = next(prec);
                }
            deleteAfter_Parent(P,cari,prec);
            }
            cout<<endl<<"data berhasil dihapus"<<endl;
        }else{
            hapusTempat(P);
        }
    }else{
        cout<<"Data tidak ditemukan"<<endl;
    }
    cout<<"======================================"<<endl;
    cout<<"Hapus data tempat lagi [Y/T]: "; cin>>ans;
    if ((ans=="Y")||(ans=="y")){
        hapusTempat(P);
    }else{
        cout<<endl<<endl;
        system("PAUSE");
    }

}

void hapusKendaraan(list_C &C){
    string plat,ans;
    system("cls");
    cout<<"BERANDA >>> HAPUS DATA >>> HAPUS KENDARAAN"<<endl;
    cout<<"=========================================="<<endl<<endl;
    cin.ignore();
    cout<<"Masukkan no.plat kendaraan: "; getline(cin,plat); cout<<endl;
    address_C cari=cariPlat(C,plat);
    if (cari!=NULL){
        cout<<"Data Kendaraan:"<<endl;
        cout<<"Jenis    : "<<info(cari).jenis<<endl;
        cout<<"No.Plat  : "<<info(cari).plat<<endl;
        cout<<"Merk     : "<<info(cari).merk<<endl;
        cout<<"Saldo    : "<<info(cari).saldoakhir<<endl<<endl;
        cout<<"Hapus data ini [Y/T]: "; cin>>ans;
        if ((ans=="Y")||(ans=="y")){
            if (cari == first(C)){
                deleteFirst_Child(C,cari);
            }else{
                address_C prec=first(C);
                while (next(prec)!=cari){
                    prec = next(prec);
                }
                deleteAfter_Child(C,cari,prec);
            }
            cout<<endl<<"data berhasil dihapus"<<endl;
        }else{
            hapusKendaraan(C);
        }
    }else{
        cout<<endl<<"Data tidak ditemukan"<<endl;
    }
    cout<<"=========================================="<<endl;
    cout<<"Haspus data kendaraan lagi [Y/T]: "; cin>>ans;
    if ((ans=="Y")||(ans=="y")){
        hapusKendaraan(C);
    }else{
        cout<<endl<<endl;
        system("PAUSE");
    }

}

void hapusRelasi(list_R &R){
    string date,ans;
    system("cls");
    cout<<"BERANDA >>> HAPUS DATA >>> HAPUS RELASI"<<endl;
    cout<<"======================================="<<endl<<endl;
    cin.ignore();
    cout<<"Masukkan tanggal: "; getline(cin,date); cout<<endl;
    address_R cari=cariTanggal(R,date);
    if (cari!=NULL){
        cout<<"Data Relasi:"<<endl;
        cout<<"Jenis Kendaraan  : "<<info(child(cari)).jenis<<endl;
        cout<<"No.Plat          : "<<info(child(cari)).plat<<endl;
        cout<<"Merk             : "<<info(child(cari)).merk<<endl;
        cout<<"Saldo Awal       : "<<info(child(cari)).saldoawal<<endl;
        cout<<"Saldo Akhir      : "<<info(child(cari)).saldoakhir<<endl;
        cout<<"Lantai           : "<<info(parent(cari)).lantai<<endl;
        cout<<"Blok             : "<<info(parent(cari)).blok<<endl;
        cout<<"Masuk            : "<<info(cari).jm<<"."<<info(cari).mm<<endl;
        cout<<"Keluar           : "<<info(cari).jk<<"."<<info(cari).mk<<endl;
        cout<<"Durasi           : "<<info(cari).jam<<" jam "<<info(cari).menit<<" menit "<<endl;
        cout<<"Tarif            : Rp."<<info(cari).tarif<<endl<<endl;
        cout<<"Hapus data ini [Y/T]: "; cin>>ans; cout<<endl;
        if ((ans=="Y")||(ans=="y")){
            if (cari == first(R)){
                deleteFirst_Relasi(R,cari);
            }else{
                address_R prec=first(R);
                while (next(prec)!=cari){
                    prec = next(prec);
                }
                deleteAfter_Relasi(R,cari,prec);
            }
            cout<<endl<<"data berhasil dihapus"<<endl;
        }else{
            hapusRelasi(R);
        }
    }else{
        cout<<"Data tidak ditemukan"<<endl;
    }
    cout<<"======================================="<<endl;
    cout<<"Hapus data relasi lagi [Y/T]: "; cin>>ans;
    if ((ans=="Y")||(ans=="y")){
        hapusRelasi(R);
    }else{
        cout<<endl<<endl;
        system("PAUSE");
    }
}

