#include <iostream>
using namespace std;

// Membuat stack kosong
template <typename T>
void createStack_103032400130(stack<T> &S) {
    S.top = -1;
}

// Mengecek apakah stack kosong
template <typename T>
bool isEmpty_103032400130(stack<T> S) {
    return S.top == -1;
}

// Mengecek apakah stack penuh
template <typename T>
bool isFull_103032400130(stack<T> S) {
    return S.top == MAXSTACK - 1;
}

// Push elemen ke stack
template <typename T>
void push_103032400130(stack<T> &S, T x) {
    if (!isFull_103032400130(S)) {
        S.top++;
        S.info[S.top] = x;
    } else {
        cout << "Stack penuh!\n";
    }
}

// Pop elemen dari stack
template <typename T>
void pop_103032400130(stack<T> &S, T &x) {
    if (!isEmpty_103032400130(S)) {
        x = S.info[S.top];
        S.top--;
    } else {
        cout << "Stack kosong!\n";
    }
}
