#include <iostream>

using namespace std;

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

struct Element {
	int value;
	Element* Next;
};

class List {
	Element* Head;
	Element* Tail;
	int Size = 0;

public:
	List();
	~List();

    //Zad. 1
    //wstawienie elementu x do listy pomiedzy elementy ai-1 oraz ai
	void Insert(int x, int i);
    //usuniecie i-tego elementu listy
	void Remove(int i);
    //zwrocenie i-tego elementu listy bez jego usuwania
	int Read(int i);

	//Zad. 2
	//Napisz funkcje zwracajaca liczbe elementow podanej listy
	int GetSize();

	//Zad. 3
	//Napisz procedure wypisujaca wszystkie elementy listy
	void Print();

	//Zad. 4
    //Napisz procedure wypisujaca wszystkie elementy listy w odwrotnej kolejnosci korzystajac ze stosu.
	void PrintReverse();

	//Zad. 5
    //Napisz procedure wypisujaca wszystkie elementy listy w odwrotnej kolejnosci niewykorzystujac zadnej dodatkowej struktury danych.
	void PrintReverseRecursion(Element* x);

    //Zad. 6
	//Napisz procedure usuwajaca wszystkie elementy listy
	void Destroy();

	//Zad. 7
    //Napisz funkcje zwracajaca wskaznik do elementu listy zawierajacego w polu dane wartosc x
	Element* Search(int x);

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

int List::Read(int i) {
    Element* tmp = Head;
	for (int j = 1; j < i; j++) {
		tmp = tmp->Next;
	}

	return tmp->value;
}

Element* List::GetHead() {
    return Head;
}

void List::Print() {
	Element* tmp = Head;
	while (tmp != NULL) {
		cout << tmp->value << " ";
		tmp = tmp->Next;
	}
	cout << "\n";
}

void List::Destroy() {
    while (Head != NULL) {
        Element* tmp = Head;
        Head = Head->Next;
        delete tmp;
    }
}

void List::PrintReverse() {
    Element* tmp = Head;

	Node* stos = new Node;
	stos->Next = NULL;
	stos->value = NULL;

	int i = 1;
    while (tmp != NULL) {
        push(stos, tmp->value);
        tmp = tmp->Next;
		i++;
    }

	for (int j = 1; j <= i; j++) {
		cout << pop(stos) << " ";
	}
}

Element* List::Search(int x) {
    Element* tmp = Head;
	while (tmp != NULL) {
		if (tmp->value == x) return tmp;
		tmp = tmp->Next;
	}
	return NULL;
}

void List::PrintReverseRecursion(Element* tmp) {
    if (tmp == NULL) {
        return;
    }

    PrintReverseRecursion(tmp->Next);

    cout << tmp->value << " ";
}

Element* tail(Element* lis) {
    return lis->Next;
}

Element* Zad3(Element* lis, int n) {
    if (n == 0)
        return lis;
    return Zad3(tail(lis), n - 1);
}

List lista;

int main() {

	lista = List();

	for (int i = 1; i <= 9; i++) {
		lista.Insert(i, i);
	}
	lista.Print();
	//output: 1 2 3 4 5

	lista.Print();
	//output:
	return 0;
}
