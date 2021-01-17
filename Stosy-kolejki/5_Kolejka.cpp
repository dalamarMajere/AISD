#include <iostream>

using namespace std;

//Zaimplementuj kolejke za pomoca dwoch stosow.

struct Node{
    int value;
    Node* Next;
};

//stack

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

//Queue

//przekladamy elementy z pierwszego stosu na drugi
//dzieki temu na drugim stosie kolejnosc elementow
//bedzie odwrotna od pierwszego, czyli
//bedzie spelnona zasada FIFO
void changeStack(Node*& s1, Node*& s2) {
    while (!isEmpty(s1)) {
        push(s2, pop(s1));
    }
}

//dodajemy do s1 kolejny element
void add(int x, Node* &s1, Node* &s2) {
    push(s1, x);
}

//pobieramy kolejny element z drugiego stosu, jezeli on nie jest pusty
//inaczej przekladamy elementy z pierwszego stosu na drugi
//i pobieramy z niego element na szczycie
int next(Node* &s1, Node* &s2) {
    if (isEmpty(s2)) {
        changeStack(s1, s2);
    }
    return pop(s2);
}

//robimy to samo co wyzej, tylko bez usuwania elementu
int firstEl(Node* &s1, Node* &s2) {
    if (isEmpty(s2)) {
        changeStack(s1, s2);
    }
    return topEl(s2);
}

//jezeli na zadnym stosie nie ma elementow
//to kolejka jest pusta
bool isQueueEmpty(Node* s1, Node* s2) {
    return (isEmpty(s1) && isEmpty(s2));
}

int main() {
    Node* s1 = new Node;
    Node* s2 = new Node;

    s1->Next = s2->Next = NULL;

    for (int i = 0; i <= 5; i++) {
        add(i, s1, s2);
    }

    cout << (isQueueEmpty(s1, s2) == true ? "Empty" : "Not empty") << "\n";
    //output: Not empty

    for (int i = 0; i < 5; i++) {
        cout << next(s1, s2) << " ";
    }
    cout << "\n";
    //output: 0 1 2 3 4

    cout << firstEl(s1, s2) << "\n";
    //output: 5
    cout << next(s1, s2) << "\n";
    //output: 5

    cout << (isQueueEmpty(s1, s2) == true ? "Empty" : "Not empty") << "\n";
    //output: Empty
    return 0;
}
