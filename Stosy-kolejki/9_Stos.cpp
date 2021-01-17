#include <iostream>

using namespace std;

struct Node {
    int value;
    Node* Next;
};

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

//Przenies elementy ze stosu S1 na stos S2 tak, aby zostal zachowany porzadek elementow:

//korzystajac z jednego dodatkowego stosu
void CopyStos(Node* &a, Node* &b) {
    Node* tmp = new Node;
    tmp->value = NULL;
    tmp->Next = NULL;

    while (!isEmpty(a)) {
        push(tmp, pop(a));
    }
    //dwa razy odwrocony ciag jest oryginalnym ciagiem
    while (!isEmpty(tmp)) {
        push(b, pop(tmp));
    }
}

//nie korzystajac z dodatkowego stosu, lecz wylacznie z pewnej liczby zmiennych lokalnych.
void Copy(Node*& a, Node*& b) {
    int current = 0;

    while (!isEmpty(a)) {
        //pobieramy gorny element ze stosu a
        current = pop(a);

        //przekladamy wszystkie elementy ze stosu b
        //na stos a
        int cnt = 0;
        while (!isEmpty(b)) {
            push(a, pop(b));
            cnt++;
        }
        //na sam dol dajemy current
        push(b, current);
        //dajemy spowrotem elementy ze stosu a na stos b
        while (cnt--) {
            push(b, pop(a));
        }
    }
}

int main() {
    Node* one = new Node;
    Node* two = new Node;
    one->value = two->value = NULL;
    one->Next = two->Next = NULL;

    for (int i = 1; i <= 5; i++) {
        push(one, i);
    }

    CopyStos(one, two);

    for (int i = 1; i <= 5; i++) {
        cout << pop(two) << " ";
        push(one, i);
    }
    cout << "\n";
    //output: 5 4 3 2 1

    Copy(one, two);

    for (int i = 1; i <= 5; i++) {
        cout << pop(two) << " ";
    }
    //output: 5 4 3 2 1

    return 0;
}
