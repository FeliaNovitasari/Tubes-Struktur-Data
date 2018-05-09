#include <iostream>
#include <cstdlib>
#include "relasi_dll.h"

int main()
{
    list_C C; list_P P; list_R R;
    createList_Child(C); createList_Parent(P); createList_Relasi(R);
    char pilih;

    while (pilih != '8'){
        system("cls");
        cout<<endl;
        cout<<"========WELCOME TO MF PARKING======="<<endl;
        cout<<"===================================="<<endl;
        cout<<"| 1.REGISTRASI                      |"<<endl;
        cout<<"| 2.LIHAT DATA                      |"<<endl;
        cout<<"| 3.CARI DATA                       |"<<endl;
        cout<<"| 4.HAPUS DATA                      |"<<endl;
        cout<<"| 5.PENDAPATAN LANTAI               |"<<endl;
        cout<<"| 6.DAFTAR KENDARAAN TERLAMA PARKIR |"<<endl;
        cout<<"| 7.DAFTAR LANTAI TERPENUH          |"<<endl;
        cout<<"| 8.KELUAR                          |"<<endl;
        cout<<"===================================="<<endl;
        cout<<"Pilih: "; cin>>pilih;
            switch(pilih){
            case '1':
                registrasi(C,P,R);
                break;
            case '2':
                lihatData(C,P,R);
                break;
            case '3':
                cariData(C,P,R);
                break;
            case '4':
                hapusData(C,P,R);
            case '5':
                pendapatan(R);
                break;
            case '6':
               daftarKendaraan(C);
                break;
            case '7':
                lantaiTerpenuh(P);
                break;
            //case 7:
            }
    }

    return 0;
}
