#include <iostream>

using namespace std;

//Uporzadkuj elementy na stosie wedlug malejacych wartosci, korzystajac z jednego
//dodatkowego stosu i kilku innych zmiennych lokalnych.

struct Node {
    int value;
    Node* Next;
};

Node* stos;

//polozenie elementu na wierzcholku stosu
void push(Node*& a, int x) {
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
int pop(Node*& a) {
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
    ;
}

//sprawdzenie, czy stos jest pusty
bool isEmpty(Node* a) {
    return (a->Next == NULL);
}

void Sort(Node* &a) {
    //dodatkowy stos
    Node* b = new Node;
    b->value = NULL;
    b->Next = NULL;

    int current = 0;

    //dla kazdego elementu ze stosu
    while (!isEmpty(a)) {
        //pobieramy gorny element
        current = pop(a);

        //przekladamy na gore stosu elementy stosu dodatkowego
        //az do momentu, poki stos dodatkowy nie bedzie pusty
        //lub current element nie bedzie mniejszy, niz
        //biezacy (porzadek malejacy)
        while (current < topEl(b) && !isEmpty(b)) {
            push(a, pop(b));
        }
        //dajemy na gore stosu dodatkowego nasz element
        push(b, current);
        //teraz wszytskie elementy ze stosu a, ktore 
        //byly pobrane ze stosu b
        //beda za O(1) kazdy przelozone na stos dodatkowy spowrotem
    }
    a = b;
}

int main() {
    stos = new Node;
    stos->value = NULL;
    stos->Next = NULL;

    push(stos, 1);
    push(stos, 3);
    push(stos, 2);
    push(stos, 5);
    push(stos, 4);
    push(stos, 6);

    Sort(stos);

    for (int i = 1; i <= 6; i++) {
        cout << pop(stos) << " ";
    }
    //output: 6 5 4 3 2 1

    return 0;
}
