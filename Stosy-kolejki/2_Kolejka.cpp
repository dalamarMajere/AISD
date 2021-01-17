#include <iostream>

using namespace std;

struct Node{
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

    //dodanie elementu do kolejki
    void Add(int x);

    // pobranie pierwszego elementu kolejki(czyli najwczesniej dodanego) i zwrocenie go jako wartosci funkcji
    int Next();

    //zwrocenie elementu znajdujacego sie na poczatku kolejki bez jego usuwania
    int FirstEl();

    //sprawdzenie, czy kolejka jest pusta
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

int main() {

    Queue q = Queue();

    for (int i = 1; i <= 5; i++) {
        q.Add(i);
    }

    for (int i = 1; i <= 5; i++) {
        cout << q.Next() << " ";
    }
    cout << "\n";
    //output: 1 2 3 4 5

    cout << (q.isEmpty() == true ? "Empty" : "Not empty") << "\n";
    //output: Empty

    q.Add(2);
    cout << q.FirstEl() << "\n";
    //output: 2
    cout << (q.isEmpty() == true ? "Empty" : "Not empty") << "\n";
    //output: Not empty
    cout << q.Next() << "\n";
    //output: 2
   
    return 0;
}
