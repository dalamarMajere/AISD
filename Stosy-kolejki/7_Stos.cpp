#include <iostream>

using namespace std;


struct Node {
    int value;
    Node* Next;
};


class Queue {
    Node* Head;
    Node* Tail;
    int Size = 0;

public:
    Queue();
    ~Queue();

    void Add(int x);
    int Next();
    int FirstEl();
    bool isEmpty();
};

Queue::Queue() {
    Head = Tail = NULL;
}

Queue::~Queue() {
    while (Head != NULL) {
        Next();
    }
}

void Queue::Add(int x) {

    Size++;

    Node* newEl = new Node;
    newEl->value = x;
    newEl->Next = NULL;

    if (Head == NULL) {
        Head = Tail = newEl;
        return;
    }

    Tail->Next = newEl;
    Tail = newEl;
}

int Queue::Next() {

    Size--;

    Node* tmp = Head;
    int ret = Head->value;

    Head = Head->Next;
    if (Size == 0) {
        Head = Tail = NULL;
    }

    delete tmp;
    return ret;
}


int Queue::FirstEl() {
    return Head->value;
}

bool Queue::isEmpty() {
    return (Size == 0);
}

//stack

void push(Node* &a, int x) {
    Node* tmp = a;
    while (tmp->Next != NULL) {
        tmp = tmp->Next;
    }

    Node* newElem = new Node;
    newElem->value = x;
    newElem->Next = NULL;
    tmp->Next = newElem;
}

int pop(Node* &a) {
    Node* tmp = a;
    Node* result = a;
    while (tmp->Next != NULL) {
        result = tmp->Next;
        if (result->Next == NULL) {
            tmp->Next = NULL;
        }
        else tmp = result;
    }

    int ret = result->value;
    delete result;
    return ret;
}

int topEl(Node* a) {
    Node* tmp = a;
    while (tmp->Next != NULL) {
        tmp = tmp->Next;
    }

    return tmp->value;
;
}

bool isEmpty(Node* a) {
    return (a->Next == NULL);
}

//Odwroc porzadek elementow na stosie korzystajac z:

//jednej dodatkowej kolejki
void ReverseWithQueue(Node*& a) {

    Queue bubble = Queue();

    while (!isEmpty(a)) {
        bubble.Add(pop(a));
    }
    while (!bubble.isEmpty()) {
        push(a, bubble.Next());
    }
}

//jednego dodatkowego stosu
void ReverseWithStack(Node*& a) {

    Node* bubble = new Node;
    bubble->Next = NULL;
    bubble->value = NULL;

    while (!isEmpty(a)) {
        push(bubble, pop(a));
    }

    a = bubble;
}


int main() {
    Node* stos = new Node;
    stos->value = NULL;
    stos->Next = NULL;

    for (int i = 0; i <= 4; i++)
        push(stos, i);

    ReverseWithQueue(stos);

    Node* tmp = new Node;
    tmp->value = NULL;
    tmp->Next = NULL;

    for (int i = 4; i >= 0; i--) {
        cout << pop(stos) << " ";
        push(tmp, i);
    }
    cout << "\n";
    //output: 0 1 2 3 4
    //stack: gora <- dol
    //       4 3 2 1 0

    stos = tmp;
    ReverseWithStack(stos);

    for (int i = 0; i <= 4; i++) {
        cout << pop(stos) << " ";
    }
    //output: 4 3 2 1 0
    //stack: gora <- dol
    //       0 1 2 3 4

    return 0;
}
