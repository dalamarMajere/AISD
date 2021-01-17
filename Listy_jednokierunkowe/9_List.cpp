#include <iostream>

using namespace std;

struct Dane {
	int num;
	int denum;

	operator == (Dane a) {
		return this->num == a.num && this->denum == a.denum;
	}
};

struct Element {
	Dane value;
	Element* Next;
};

class List {
	Element* Head;
	Element* Tail;
	int Size = 0;

public:
	List();
	~List();

	void Add(Dane x);

	void Print();
	int GetSize();
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

void List::Add(Dane x) {
	Size++;

	Element* newElement = new Element;
	newElement->value = x;
	newElement->Next = NULL;

	if (Head == NULL) {
		Head = Tail = newElement;
		return;
	}

	Tail->Next = newElement;
	Tail = newElement;
}

Element* List::GetHead() {
	return Head;
}

void List::Print() {
	Element* tmp = Head;
	while (tmp != NULL) {

	    int num = tmp->value.num;
        int denum = tmp->value.denum;

		cout << num << "/" << denum << "\n";

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


void FareyFraction(int n, List& farey) {
	int a = 0;
	int b = 1;
	int c = 1;
	int d = n;

	farey.Add({ a, b });
	while (c <= n) {
		int k = (n + b) / d;

		int tmpa = a, tmpb = b;
		a = c;
		b = d;
		c = k * c - tmpa;
		d = k * d - tmpb;

		farey.Add({ a, b });
	}
}


int main() {

	List farey = List();
	FareyFraction(8, farey);

	farey.Print();
	/* output:
		0/1
		1/8
		1/7
		1/6
		1/5
		1/4
		2/7
		1/3
		3/8
		2/5
		3/7
		1/2
		4/7
		3/5
		5/8
		2/3
		5/7
		3/4
		4/5
		5/6
		6/7
		7/8
		1/1
	*/

	return 0;
}
