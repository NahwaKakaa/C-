#include <iostream>
using namespace std;

int stack[3], top = -1;

void push(int x) {
    stack[++top] = x;
    cout << x << " ditambahkan ke stack.\n";
}

void pop() {
    cout << stack[top--] << " dikeluarkan dari stack.\n";
}

int main() {
    push(10);
    push(20);
    push(30);
    cout << endl << "Isi stack : " << endl;
    pop();
    pop();
    pop();
    
    return 0;
}