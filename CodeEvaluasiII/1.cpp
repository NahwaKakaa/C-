#include <iostream>
using namespace std;

#define BATAS 100

struct Stack {
	int data[BATAS];
	int top;
};

void buatStack(Stack &stack){
	stack.top = -1;
}

bool kosong(Stack &stack){
	return stack.top == -1;
}

bool penuh(Stack &stack){
	return stack.top == BATAS - 1;
}

void push(Stack &stack, int value)
{
    if (!penuh(stack))
    {
        stack.top++;
        stack.data[stack.top] = value;
    }
    else
    {
        cout << "Stack penuh!" << endl;
    }
}

int pop(Stack &stack)
{
    if (!kosong(stack))
    {
        int value = stack.data[stack.top];
        stack.top--;
        return value;
    }
    else
    {
        cout << "Stack kosong!" << endl;
        return -1;
    }
}

void cetakSegitiga(int tinggi)
{
    for (int i = 1; i <= tinggi; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << "* ";
        }
        cout << endl;
    }
}

void cetakKotak(int sisi)
{
    for (int i = 0; i < sisi; i++)
    {
        for (int j = 0; j < sisi; j++)
        {
            cout << "* ";
        }
        cout << endl;
    }
}

void cetakPersegiPanjang(int panjang, int lebar)
{
    for (int i = 0; i < panjang; i++)
    {
        for (int j = 0; j < lebar; j++)
        {
            cout << "* ";
        }
        cout << endl;
    }
}

void cetakLingkaran(int radius)
{
    float ketebalan = 0.4;
    for (int i = 0; i <= 2 * radius; i++)
    {
        for (int j = 0; j <= 2 * radius; j++)
        {
            float dx = radius - i;
            float dy = radius - j;
            float jarak = dx * dx + dy * dy;
            if (jarak >= (radius - ketebalan) * (radius - ketebalan) && jarak <= (radius + ketebalan) * (radius + ketebalan))
            {
                cout << "* ";
            }
            else
            {
                cout << "  ";
            }
        }
        cout << endl;
    }
}

int main(){

	Stack stack;
	buatStack(stack);

	int pil, tinggi, sisi, panjang, lebar, radius;
	char ulang = 'y';

	do {
		system("cls");
		cout << "Nama \t: Nahwa Kaka Saputra Anggareksa" << endl;
		cout << "NIM \t: 13020230187" << endl;
		
		cout << "Menu Bentuk Geometri: " << endl;
		cout << "1. Cetak Segitiga\n";
		cout << "2. Cetak Kotak\n";
		cout << "3. Cetak Persegi Panjang\n";
		cout << "4. Cetak Lingkaran\n";
		cout << "5. Keluar\n";
		
		cout << "Masukkan Pilihan: ";
		cin >> pil;
		switch(pil){
			case 1 :
				cout << "Masukkan tinggi segitiga: ";
				cin >> tinggi;
				push(stack, tinggi);
				cetakSegitiga(tinggi);
				cout << "Ulang program (y/n) : ";
				cin >> ulang;
				break;
			case 2 :
				cout << "Masukkan sisi kotak: ";
				cin >> sisi;
				push(stack, sisi);
				cetakKotak(sisi);
				cout << "Ulang program (y/n) : ";
				cin >> ulang;
				break;
			case 3 :
				cout << "Masukkan panjang persegi panjang: ";
				cin >> panjang;
				push(stack, panjang);
				cout << "Masukkan lebar persegi panjang: ";
				cin >> lebar;
				push(stack, lebar);
				cetakPersegiPanjang(panjang, lebar);
				cout << "Ulang program (y/n) : ";
				cin >> ulang;
				break;
			case 4 :
				cout << "Masukkan radius lingkaran: ";
				cin >> radius;
				push(stack, radius);
				cetakLingkaran(radius);
				cout << "Ulang program (y/n) : ";
				cin >> ulang;
				break;
			case 5 :
				ulang = 'n'; 
				break;
			default :
				system("cls");
				cout << "Pilihan tidak valid!!" << endl;
				cout << "\nUlang program (y/n) : ";
				cin >> ulang;
				break;
		}

	}while(ulang == 'y');

	system("cls");
	cout << "Keluar dari program." << endl;

	return 0;
}
