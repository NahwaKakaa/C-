#include <iostream>
using namespace std;

struct Tumpukan {
    string barang[100];
    int puncak;

    Tumpukan() { puncak = -1; }

    bool penuh() { return puncak == 99; }

    bool kosong() { return puncak == -1; }

    void tambah(string item) {
        if (!penuh()) {
            barang[++puncak] = item;
        }
    }

    void hapus() {
        if (!kosong()) {
            puncak--;
        }
    }

    string lihat() {
        if (!kosong()) {
            return barang[puncak];
        } else {
            return "";
        }
    }

    void tampilkanBelanjaan() {
        if (kosong()) {
            cout << "Belum ada belanjaan." << endl;
        } else {
            for (int i = puncak; i >= 0; i--) {
                cout << barang[i] << " ";
            }
            cout << endl;
        }
    }
};

struct Antrian {
    string namaPelanggan[100];
    Tumpukan belanjaan[100];
    int depan, belakang;

    Antrian() { depan = belakang = -1; }

    bool penuh() { return belakang == 99; }

    bool kosong() { return depan == -1; }

    void tambahAntrian(string nama) {
        if (!penuh()) {
            if (kosong()) depan = 0;
            namaPelanggan[++belakang] = nama;
        }
    }

    void hapusAntrian() {
        if (!kosong()) {
            if (depan == belakang) {
                depan = belakang = -1;
            } else {
                depan++;
            }
        }
    }

    string lihatPelanggan() {
        if (!kosong()) {
            return namaPelanggan[depan];
        } else {
            return "";
        }
    }

    void tampilkanAntrian() {
        if (kosong()) {
            cout << "Antrian kosong." << endl;
        } else {
        	cout << "Daftar pelanggan dalam antrian : " << endl;
            for (int i = depan; i <= belakang; i++) {
                cout << namaPelanggan[i] << endl;
            }
        }
    }
};

int main() {
    Antrian antrian;
    int pilihan;
    string nama, barang;

    do {
    	cout << "Nama \t\t:Nahwa Kaka Saputra Anggareksa" << endl;
    	cout << "Stambuk \t: 13020230187" << endl;
    	
        cout << "\n============UMI Mart============\n";
        cout << "1. Tambah Pelanggan ke Antrian\n";
        cout << "2. Tambah barang ke Keranjang Pelanggan\n";
        cout << "3. Tampilkan Antrian Pelanggan\n";
        cout << "4. Tampilkan Barang di Keranjang Pelanggan\n";
        cout << "5. Selesaikan belanja dan hapus Pelanggan dari Antrian\n";
        cout << "6. Keluar\n";
        cout << "Masukkan pilihan: ";
        cin >> pilihan;
        system("cls");

        switch (pilihan) {
            case 1: {
                cout << "Masukkan nama pelanggan: ";
                cin >> nama;
                antrian.tambahAntrian(nama);
                cout << "Pelanggan " << nama << " telah ditambahkan ke dalam antrian.\n" << endl;
                break;
            }
            case 2: {
            	if (antrian.kosong()) {
                    cout << "Tidak ada pelanggan dalam antrian.\n" << endl;
                } else {
                    cout << "Masukkan barang yang dibeli pelanggan " << antrian.lihatPelanggan() << ": ";
                    cin >> barang;
                    antrian.belanjaan[antrian.depan].tambah(barang);
                    cout << "Barang " << barang << " telah ditambahkan ke keranjang pelanggan " << antrian.lihatPelanggan() << endl;
                }
                break;
            }
            case 3: {
        		antrian.tampilkanAntrian();
        		cout << endl;
                break;
            }
            case 4: {
                if (antrian.kosong()) {
                    cout << "Tidak ada pelanggan dalam antrian.\n" << endl;
                } else {
                    cout << "Belanjaan pelanggan " << antrian.lihatPelanggan() << " adalah: \n";
                    antrian.belanjaan[antrian.depan].tampilkanBelanjaan();
                }
                break;
            }
            case 5: {
                if (antrian.kosong()) {
                    cout << "Tidak ada pelanggan dalam antrian.\n" << endl;
                } else {
                    cout << "Pelanggan " << antrian.lihatPelanggan() << " telah selesai belanja." << endl;
                    cout << "Belanjaan pelanggan tersebut: ";
                    antrian.belanjaan[antrian.depan].tampilkanBelanjaan();
                    antrian.hapusAntrian();
                }
                break;
            }
            case 6:
                cout << "Keluar dari program.\n";
                break;
            default:
                cout << "Pilihan tidak valid.\n";
        }

    } while (pilihan != 6);

    return 0;
}
