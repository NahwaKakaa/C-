#include <iostream>
using namespace std;

struct Mobil {
    string merek;                
    string namaPemilik;          
    int tahunPembelian;          
    string platMobil;            
    float hargaPembelian;        
    int jumlahBan;               
    int jumlahKursi;             
    string warnaMobil;           
    bool pernahDiservice;        
};

int main() {
    int jumlahMobil;

    cout << "Masukkan jumlah data mob: ";
    cin >> jumlahMobil;
    cin.ignore();

    Mobil mob[10]; 

    for (int i = 0; i < jumlahMobil; i++) {
        cout << "\n========INPUT DATA " << i + 1 << "==========\n";
        cout << "Masukkan Merek Mobil: ";
        getline(cin, mob[i].merek);
        cout << "Masukkan Nama Pemilik (nama mahasiswa): ";
        getline(cin, mob[i].namaPemilik);
        cout << "Masukkan Tahun Pembelian: ";
        cin >> mob[i].tahunPembelian;
        cin.ignore(); 
        cout << "Masukkan Plat Mobil: ";
        getline(cin, mob[i].platMobil);
        cout << "Masukkan Harga Pembelian Mobil: ";
        cin >> mob[i].hargaPembelian;
        cout << "Masukkan Jumlah Ban: ";
        cin >> mob[i].jumlahBan;
        cout << "Masukkan Jumlah Kursi: ";
        cin >> mob[i].jumlahKursi;
        cin.ignore(); 
        cout << "Masukkan Warna Mobil: ";
        getline(cin, mob[i].warnaMobil);
        
        char service;
        cout << "Apakah mobil pernah diservice? (y/n): ";
        cin >> service;
        mob[i].pernahDiservice = (service == 'y' || service == 'Y');
        cin.ignore(); 
        cout << endl;
    }

    cout << "\n=========HASIL==========\n";
    for (int i = 0; i < jumlahMobil; i++) {
        cout << "========DATA " << i + 1 << "===========\n";
        cout << "Merek Mobil: " << mob[i].merek << endl;
        cout << "Nama Pemilik: " << mob[i].namaPemilik << endl;
        cout << "Tahun Pembelian: " << mob[i].tahunPembelian << endl;
        cout << "Plat Mobil: " << mob[i].platMobil << endl;
        cout << "Harga Pembelian Mobil: " << mob[i].hargaPembelian << endl;
        cout << "Jumlah Ban: " << mob[i].jumlahBan << endl;
        cout << "Jumlah Kursi: " << mob[i].jumlahKursi << endl;
        cout << "Warna Mobil: " << mob[i].warnaMobil << endl;
        cout << "Pernah Diservice: " << (mob[i].pernahDiservice ? "Ya" : "Tidak") << endl <<endl;
    }

    return 0;
}
