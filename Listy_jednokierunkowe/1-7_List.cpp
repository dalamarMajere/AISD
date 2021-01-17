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

    vector<int> stos(0);
    while (tmp != NULL) {
        stos.push_back(tmp->value);
        tmp = tmp->Next;
    }

    int sz = stos.size();
    for (int i = sz - 1; i >= 0; i--)
        cout << stos[i] << " ";
    cout << "\n";
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

List lista;

int main() {

	lista = List();

	for (int i = 1; i <= 5; i++) {
		lista.Insert(i, i);
	}
	lista.Print();
	//output: 1 2 3 4 5

	lista.Insert(10, 3);
	lista.Print();
	//output: 1 2 10 3 4 5

	lista.Insert(20, 1);
	lista.Print();
	//output: 20 1 2 10 3 4 5

	lista.Insert(30, 2);
	lista.Print();
	//output: 20 30 1 2 10 3 4 5

	lista.Remove(3);
	lista.Print();
	//output: 20 30 2 10 3 4 5

	lista.Remove(1);
	lista.Print();
	//output: 30 2 10 3 4 5

	lista.Remove(6);
	lista.Print();
	//output: 30 2 10 3 4

	lista.PrintReverse();
	//output: 4 3 10 2 30
	lista.PrintReverseRecursion(lista.GetHead());
	//output: 4 3 10 2 30
	cout << "\n";

	cout << lista.Read(3) << " ";
	cout << lista.Read(1) << " ";
	cout << lista.Read(5) << " ";
	//output: 10 30 4
	cout << "\n";

    Element* res = lista.Search(30);
    if (res != NULL)
        cout << res->value << "\n";
    else cout << "Nie ma takiego elementu\n";
	//output: 30

	res = lista.Search(50);
	if (res != NULL)
        cout << res->value << "\n";
    else cout << "Nie ma takiego elementu\n";
	//output: Nie ma takiego elementu


	lista.Destroy();
	lista.Print();
	//output: 
	return 0;
}
