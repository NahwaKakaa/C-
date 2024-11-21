#include <iostream>
using namespace std;

int queue[3], front = 0, rear = -1;

void enqueue(int x) {
    queue[++rear] = x;
    cout << x << " ditambahkan ke queue.\n";
}

void dequeue() {
    cout << queue[front++] << " dikeluarkan dari queue.\n";
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    cout << endl << "Isi queue : " << endl;
    dequeue();
    dequeue();
    dequeue();

    return 0;
}