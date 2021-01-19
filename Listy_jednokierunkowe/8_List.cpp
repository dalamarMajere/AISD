#include <iostream>

using namespace std;

/*
* Napisz funkcje zwracajaca li-ste reprezentujaca sume dwoch wielomianow. 
* Mozna zalozyc,ze elementy listy sa uporzadkowane wedlug malejacych wartosci expo
*/

struct Dane {
	int expo;
	int coef;

	operator == (Dane a) {
		return this->expo == a.expo && this->coef == a.coef;
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
	Head = Tail = NULL;
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

	    int coef = tmp->value.coef;
        int expo = tmp->value.expo;

        if (coef != 0) {
            if (tmp != Head) {
                cout << ((coef > 0)? " + ":" - ");
            }
            cout << abs(coef);
            switch (expo) {
                case 0: break;
                case 1: cout << "x"; break;
                default: cout << "x^" << expo;
            }
        }

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


void AddValue(Element* &a, List &lista) {
	lista.Add(a->value);
	a = a->Next;
}


List PolyAdds(List one, List two) {
	List result = List();


	Element* first = one.GetHead();
	Element* second = two.GetHead();

	while (first != NULL && second != NULL) {
		if (first->value.expo > second->value.expo) {
			AddValue(first, result);
		}
		else if (first->value.expo < second->value.expo) {
			AddValue(second, result);
		}
		else  {
			Dane sum = {first->value.expo, first->value.coef + second->value.coef};

			result.Add(sum);

			first = first->Next;
			second = second->Next;
		}
	}

	while (first != NULL) {
		AddValue(first, result);
	}

	while (second != NULL) {
		AddValue(second, result);
	}

	return result;
}


List one, two;

int main() {

	one = List();
	two = List();

	one.Add({ 5, 2 });
	one.Add({ 4, 3 });
	one.Add({ 3, 2 });
	one.Add({ 1, -6 });
	one.Add({ 0, 8 });

	cout << " ";
	one.Print();
	cout << "+\n";

	two.Add({ 7, 6 });
	two.Add({ 3, 9 });
	two.Add({ 2, 2 });
	two.Add({ 1, -6 });
	two.Add({ 0, 1 });

	cout << " ";
    two.Print();
    cout << "=\n";


	List result = PolyAdds(one, two);
	cout << " ";
	result.Print();

	/*
	* output:
	*         2x^5 + 3x^4 + 2x^3		  - 6x + 8
	* +
	*  6x^7 +				9x^3  + 2x^2  - 6x + 1
	* =
	*  6x^7 + 2x^5 + 3x^4 + 11x^3 + 2x^2 - 12x + 9
	*/

	return 0;
}
