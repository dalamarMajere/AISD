#include <iostream>
#include <vector>

using namespace std;

struct Node {
	int value;
	Node* Next;
	Node* Prev;
};

class List {
	Node* Head;
	Node* Tail;
	int Size = 0;
	bool isCycle = false;

public:
	List();
	~List();

	void Insert(int x, int i);
	void Remove();
	void Remove(int i);
	void Reverse();
	void To_Cycle();
	void Reverse_Cycle();

	int GetSize();
	void Print();

	void Destroy();
};

List::List() {
	Head = Tail = NULL;
}

List::~List() {
    Destroy();
}

void List::Insert(int x, int ind) {
	Size++;

	Node* current = new Node;
	current->value = x;
	current->Next = current->Prev = NULL;

	if (ind < 1 || ind > GetSize() + 1) {
        cout << "Wprowadzono bledne dane\n";
        return;
	}

	if (ind == 1) {
        current->Next = Head;
        if (Head != NULL) {
            Head->Prev = current;
        }
        else {
            Head = Tail = current;
        }
		if (isCycle) {
			Head->Prev = Tail;
			Tail->Next = Head;
		}
        return;
	}

	if (ind == GetSize()) {

        Tail->Next = current;
        current->Prev = Tail;

        Tail = current;

		if (isCycle) {
			Head->Prev = Tail;
			Tail->Next = Head;
		}
        return;
	}

	Node* found = Head;
	for (int i = 1; i < ind; i++) {
		found = found->Next;
	}

	Node* prevFound = found->Prev;

	if (prevFound != NULL) {
		prevFound->Next = current;
	}
	current->Prev = prevFound;

	found->Prev = current;
	current->Next = found;
}

void List::Remove() {
	Size--;
	Remove(1);
}

void List::Remove(int ind) {
	Size--;

	Node* found = Head;
	for (int i = 1; i < ind; i++) {
		found = found->Next;
	}

	Node* prevFound = found->Prev;
	Node* nextFound = found->Next;

	if (ind > GetSize() && prevFound != NULL) {
		prevFound->Next = nextFound;
	}

	if (ind != 1 && nextFound != NULL) {
		nextFound->Prev = prevFound;
	}

	if (ind == 1) {
		Head = nextFound;

		if (isCycle) {
			Head->Prev = Tail;
			Tail->Next = Head;
		}
	}
	if (ind == GetSize() + 1) {
		Tail = prevFound;

		if (isCycle) {
			Head->Prev = Tail;
			Tail->Next = Head;
		}
	}

	delete found;
}

void List::Reverse() {
	Node* current = Head;

    int i = 1;
	Node* bubble;
	while (i++ <= GetSize()) {
        bubble = current->Next;
		current->Next = current->Prev;
		current->Prev = bubble;
		current = bubble;
	}

	bubble = Head;
	Head = Tail;
	Tail = bubble;
}

int List::GetSize() {
	return Size;
}

void List::Print() {
	Node* tmp = Head;
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
        Node* tmp = Head;
        Head = Head->Next;
        delete tmp;
    }
}

List lista;

int main() {

	lista = List();

	for (int i = 1; i <= 5; i++)
		lista.Insert(i, i);
	lista.Print();
	//output: 1 2 3 4 5

	lista.Reverse();
	lista.Print();
	//output: 5 4 3 2 1
	lista.Reverse();

	lista.Remove();
	lista.Print();
	//output: 2 3 4 5
	lista.Remove(3);
	lista.Print();
	//output: 2 3 5
	lista.Remove(3);
	lista.Print();
	//output: 2 3

	lista.Destroy();
	lista.Print();
	//output:
	return 0;
}
