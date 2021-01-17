#include <iostream>

using namespace std;

struct Node{
    int value;
    Node* Next;
};

Node* stos;

//polozenie elementu na wierzcholku stosu
void push(Node* &a, int x) {
    Node* currentNode = a;

    while (currentNode->Next != NULL) {
        currentNode = currentNode->Next;
    }

    Node* newElem = new Node;
    newElem->value = x;
    newElem->Next = NULL;

    currentNode->Next = newElem;
}

//pobranie ostatnio odlozonego elementu i zwrocenie go jako wartosci funkcji
int pop(Node* &a) {
    Node* currentNode = a;
    Node* result = a;

    while (currentNode->Next != NULL) {
        result = currentNode->Next;
        if (result->Next == NULL) {
            currentNode->Next = NULL;
        }
        else currentNode = result;
    }

    int ret = result->value;
    delete result;
    return ret;
}

//zwrocenie elementu znajdujacego sie na wierzcholku stosu bez jego usuwania
int topEl(Node* a) {
    Node* currentNode = a;
    while (currentNode->Next != NULL) {
        currentNode = currentNode->Next;
    }

    return currentNode->value;
}

//sprawdzenie, czy stos jest pusty
bool isEmpty(Node* a) {
    return (a->Next == NULL);
}

int main() {
    stos = new Node;
    stos->value = NULL;
    stos->Next = NULL;

    cout << (isEmpty(stos)==true? "Empty":"Not empty") << "\n";
    //output: Empty

    for (int i = 1; i <= 4; i++) {
        push(stos, i);
    }
    cout << topEl(stos) << "\n";
    //output: 4

    cout << (isEmpty(stos)==true? "Empty":"Not empty") << "\n";
    //output: Not empty

    for (int i = 1; i <= 4; i++) {
        cout << pop(stos) << " ";
    }
    cout << "\n";
    //output: 4 3 2 1

    cout << (isEmpty(stos)==true? "Empty":"Not empty") << "\n";
    //output: Empty


    return 0;
}
