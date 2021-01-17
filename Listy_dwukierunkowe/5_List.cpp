#include <iostream>
#include <vector>

using namespace std;

struct Element {
	char value;
	Element* Next;
};

class List {
	Element* Head;
	Element* Tail;
	int Size = 0;

public:
	List();
	~List();

	void Insert(char x, int i);
	void Remove(int i);
	char Read(int i);

	int GetSize();

	void Print();

	void Destroy();

	Element* GetHead();
};

List::List() {
	Head = Tail = NULL;
}

List::~List() {
    Destroy();
}

int List::GetSize() {
	return Size;
}

void List::Insert(char x, int i) {
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

char List::Read(int i) {
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
	int i = 1;
	while (i++ <= GetSize()) {
		cout << tmp->value << " ";
		tmp = tmp->Next;
	}
	cout << "\n";
}

void List::Destroy() {
    while (GetSize() > 0) {
        Element* tmp = Head;
        Head = Head->Next;
        delete tmp;
		Size--;
    }
	Head = Tail = NULL;
}

//stack


//polozenie elementu na wierzcholku stosu
void push(Element*& a, char x) {
	Element* currentNode = a;

	while (currentNode->Next != NULL) {
		currentNode = currentNode->Next;
	}

	Element* newElem = new Element;
	newElem->value = x;
	newElem->Next = NULL;

	currentNode->Next = newElem;
}

//pobranie ostatnio odlozonego elementu i zwrocenie go jako wartosci funkcji
char pop(Element*& a) {
	Element* currentNode = a;
	Element* result = a;

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
char topEl(Element* a) {
	Element* currentNode = a;
	while (currentNode->Next != NULL) {
		currentNode = currentNode->Next;
	}

	return currentNode->value;
}

//sprawdzenie, czy stos jest pusty
bool isEmpty(Element* a) {
	return (a->Next == NULL);
}

//sprawdzenie poprawnosci polskiej notacji
bool is_valid_pn(List a) {
	//tworzymy stos, na ktory bedziemy dawali nowe elementy:
	//znaki i cyfry. Dwie cyfry (oznaczone jako !) do rzedu beda pobierac
	//ostatni znak i zamiast niego wstawiac nowy !. 
	//Jesli znaku nie ma, notacja nie jest poprawna
	//Oraz ona nie jest poprawna jesli pod koniec na stosie bedzie cos innego, 
	//niz wykrzyknik
	Element* s = new Element;
	s->value = 0;
	s->Next = NULL;

	Element* current = a.GetHead();

	while (current != NULL) {
		char c = current->value;
		//jesli nowy element cyfra lub litera
		if ((c >= '0' && c <= '9') || (c >= 'a' && c <= 'z')) {
			//jesli gorny element na stosie tez cyfra lub litera
			//to pobieramy go, pobieramy znak,, ktory lezy na stosie nastepny
			while (topEl(s) == '!') {
				pop(s);
				if (!isEmpty(s)) {
					pop(s);
				}
				else return false;
			}
			push(s, '!');
		}
		else push(s, c);
		current = current->Next;
	}
	if (!isEmpty(s) && topEl(s) == '!') pop(s);
	return isEmpty(s);
}

List lista;

int main() {

	lista = List();

	//3 * (a / (4 - b))
	//pn: * 3 / a - 4 b

	lista.Insert('*', 1);
	lista.Insert('3', 2);
	lista.Insert('//', 3);
	lista.Insert('a', 4);
	lista.Insert('-', 5);
	lista.Insert('4', 6);
	lista.Insert('b', 7);
	lista.Print();
	//output: * 3 / a - 4 b

	cout << (is_valid_pn(lista) == true? "Valid":"Invalid") << "\n";
	//output: Valid

	lista.Destroy();

	lista.Insert('*', 1);
	lista.Insert('//', 2);
	lista.Insert('//', 3);
	lista.Insert('a', 4);
	lista.Insert('-', 5);
	lista.Insert('4', 6);
	lista.Insert('b', 7);
	lista.Print();
	//output: * / / a - 4 b

	cout << (is_valid_pn(lista) == true ? "Valid" : "Invalid") << "\n";
	//output: Invalid
	return 0;
}
