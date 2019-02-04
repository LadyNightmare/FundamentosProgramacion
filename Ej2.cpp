// prEx2.cpp
//     Created on: 02/09/2016
//          Alumn:
//          Grade:
//          Group:
// Machine Number:
//

#include <iostream>
#include <array>
using namespace std;

const int MAX = 10;

typedef array<int,MAX> TItems;

struct TSet {
	TItems item;
	int numItems;
};

void read(TSet& c);
void write(TSet c);
bool isIn(int elem, TSet c);
TSet intersectionOf(TSet c1, TSet c2);
TSet unionOf(TSet c1, TSet c2, bool& ok);


int main() {

	TSet c1, c2, c3, c4;

	cout << "First TSet:\n";
	read(c1);

	cout << "\nSecond TSet:\n";
	read(c2);

	c3 = intersectionOf(c1, c2);
	cout << "\nIntersection:\n";
	write(c3);

	bool ok;
	c4 = unionOf(c1, c2, ok);
	if (ok) {
		cout << "\nUnion:\n";
		write(c4);
	} else {
		cout << "\nOverflow while building union\n";
	}

	return 0;
}



void read(TSet& c) {

	do {
		cout << "Number of items to read? (<= " << MAX << "): ";
		cin >> c.numItems;
	} while (c.numItems > MAX);

	cout << "Input " << c.numItems << " different natural numbers: ";
	for (int i = 0; i < c.numItems; i++) {
		cin >> c.item[i];
	}
}

void write(TSet c) {

	for (int i = 0; i < c.numItems; i++) {
		cout << c.item[i] << " ";
	}
	cout << endl;
}

bool isIn(int elem, TSet c) {
	int cont = 0;

	while ((cont < c.numItems) and (elem != c.item[cont])) {
		cont++;
	}

	return (cont < c.numItems);
}

TSet intersectionOf(TSet c1, TSet c2)
{
	TSet res;
	res.numItems = 0;
	for (int i = 0; i < c1.numItems; i++) {
		if (isIn(c1.item[i], c2)) {
			res.item[res.numItems] = c1.item[i];
			res.numItems++;
		}
	}
	return res;
}

TSet unionOf(TSet c1, TSet c2, bool& ok)
{
	TSet res;
	int cont;

	res.numItems = 0;
	for (int i = 0; i < c1.numItems; i++) {
		res.item[res.numItems] = c1.item[i];
		res.numItems++;
	}

	cont = 0;
	while ((cont < c2.numItems) and (res.numItems < MAX)) {
		if (not isIn(c2.item[cont], c1)) {
			res.item[res.numItems] = c2.item[cont];
			res.numItems++;
		}
		cont++;
	}

	ok = cont >= c2.numItems;
	return res;
}
