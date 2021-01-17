#include <iostream>

using namespace std;

//Zaimplementuj kolejke z uzyciem tablicy zamiast dynamicznej struktury danych.

struct Node{
    int value;
    Node* Next;
};

const int SIZE = 1e6;

int q[SIZE+1];
int sz = 0;

void Add(int x) {
    if (sz >= SIZE) {
        cout << "Za duzo elementow";
        return;
    }
    q[sz++] = x;
}

int Next() {
    int ret = q[0];

    for (int i = 1; i < sz; i++) {
        q[i - 1] = q[i];
    }

    sz--;
    return ret;
}

int FirstEl() {
    return q[0];
}

bool isEmpty() {
    return (sz == 0);
}


int main() {
    for (int i = 0; i <= 5; i++)
        Add(i);

    for (int i = 0; i < 5; i++) {
        cout << Next() << " ";
    }
    cout << "\n";
    //output: 0 1 2 3 4

    cout << (isEmpty() == true ? "Empty" : "Not empty") << "\n";
    //output: Not empty
    cout << FirstEl() << "\n";
    //output: 5
    cout << Next() << "\n";
    //output: 5
    cout << (isEmpty() == true ? "Empty" : "Not empty") << "\n";
    //output: Empty


    return 0;
}
