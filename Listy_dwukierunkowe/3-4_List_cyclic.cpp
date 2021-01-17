#include <iostream>
#include <vector>

using namespace std;

struct Element {
	int value;
	Element* Next;
};

class List {
	Element* Head;
	Element* Tail;
	int Size = 0;
	bool isCyclic = false;

public:
	List();
	~List();

	void Insert(int x, int i);
	void Remove(int i);
	int Read(int i);

	int GetSize();
	void Print();
	void PrintReverse();
	void PrintReverseRecursion(Element* x);

	void To_Cyclic();
	void Reverse_Cyclic();
	Element* Search(int x);
    void Destroy();
	Element* GetHead();
};

List::List() {
	Head = NULL;
	Tail = NULL;
}

List::~List() {
    Destroy();
}

int List::GetSize() {
	return Size;
}

void List::Insert(int x, int i) {
	Size++;

	Element* newElement = new Element;
	newElement->value = x;
    newElement->Next = NULL;

    //pierwszy element
	if (Head == NULL) {
		Head = Tail = newElement;
		return;
	}

	//dodanie do glowy (lub jesli index jest ujemny)
	if (i <= 1) {
        newElement->Next = Head;
        Head = newElement;
        return;
	}

    //dodanie na koniec listy (lub jesli index jest wiekszy, niz rozmiar listy)
	if (i >= GetSize() - 1) {
        Tail->Next = newElement;
        Tail = newElement;
        return;
	}

	Element* tmp = Head;
	for (int j = 1; j < i - 1; j++) {
		tmp = tmp->Next;
	}

	newElement->Next = tmp->Next;
	tmp->Next = newElement;
}


void List::Remove(int i) {
    Size--;

    Element* tmp = Head;
    Element* current = new Element;
	for (int j = 1; j < i - 1; j++) {
		tmp = tmp->Next;
	}

	if (i <= 1) {
        Element* tmp = Head;
        Head = Head->Next;
        delete tmp;
        return;
	}

    current = tmp->Next;
    tmp->Next = current->Next;

    if (i >= GetSize() + 1) {
        Tail = tmp;
	}

	delete current;
}

Element* List::GetHead() {
    return Head;
}

void List::Print() {
	Element* tmp = Head;
	int i = 1;
	while (i++ <= GetSize()) {
		cout << tmp->value << " ";
		tmp = tmp->Next;
	}

	cout << "\n";
}

void List::Destroy() {
    int i = 1;
    while (i++ <= GetSize()) {
        Element* tmp = Head;
        Head = Head->Next;
        delete tmp;
    }
}


void List::PrintReverseRecursion(Element* tmp) {
    if (tmp == NULL) {
        return;
    }

    PrintReverseRecursion(tmp->Next);

    cout << tmp->value << " ";
}

void List::To_Cyclic() {
	isCyclic = true;
	Tail->Next = Head;
}

void List::Reverse_Cyclic() {
	int i = 1;
	Element* current = Head;
	Element* prev = Tail;
	while (i++ <= GetSize()) {
		Element* bubble = current->Next;
		current->Next = prev;

		prev = current;
		current = bubble;
	}
	Head->Next = Tail;
	Head = Tail;
}

List lista;

int main() {

	lista = List();

	for (int i = 1; i <= 5; i++) {
		lista.Insert(i, i);
	}
	lista.Print();
	//output: 1 2 3 4 5

	lista.To_Cyclic();
	lista.Reverse_Cyclic();
	lista.Print();

	lista.Destroy();
	return 0;
}
