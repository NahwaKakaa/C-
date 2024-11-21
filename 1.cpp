#include <iostream>
using namespace std;

struct Keluarga {
    string namaAyah;      
    string namaIbu;       
    int jumlahAnak;
    string namaAnak[100];
};

int main() {
    Keluarga keluarga;

    cout << "Masukkan nama Ayah \t: ";
    getline(cin, keluarga.namaAyah);
    cout << "Masukkan nama Ibu \t: ";
    getline(cin, keluarga.namaIbu);
    cout << "Masukkan jumlah anak \t: ";
    cin >> keluarga.jumlahAnak;
    cin.ignore(); 

    if (keluarga.jumlahAnak > 100) {
        cout << "Jumlah anak maksimal adalah 100. Menggunakan 100 anak.\n";
        keluarga.jumlahAnak = 100;
    }

    for (int i = 0; i < keluarga.jumlahAnak; i++) {
        cout << "Masukkan nama anak ke-" << i + 1 << "\t: ";
        getline(cin, keluarga.namaAnak[i]);
    }

    cout << "\nData Keluarga:\n";
    cout << "Nama Ayah \t: " << keluarga.namaAyah << endl;
    cout << "Nama Ibu \t: " << keluarga.namaIbu << endl;
    cout << "Jumlah Anak \t: " << keluarga.jumlahAnak << endl;
    for (int i = 0; i < keluarga.jumlahAnak; i++) {
        cout << "Nama Anak ke-" << i + 1 << "\t: " << keluarga.namaAnak[i] << endl;
    }

    return 0;
}
