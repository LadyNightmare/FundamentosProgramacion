// prEx1.cpp
//     Created on: 02/09/2016
//          Alumn:
//          Grade:
//          Group:
// Machine Number:
//

#include <iostream>
#include <array>
using namespace std;

const unsigned SIZE = 4;

typedef array<array<int,SIZE>,SIZE> TSqMatrix;

// returns true when the parameter is an Identity Matrix
//         false in other case
bool identity(TSqMatrix m);

// prints the matrix
void printSqMatrix(TSqMatrix m);

int main() {
	TSqMatrix m = {{
					{{ 1, 0, 0, 0 }},
					{{ 0, 1, 0, 0 }},
					{{ 0, 0, 1, 0 }},
					{{ 0, 0, 0, 1 }}
	}};

	cout << "First example of matrix:\n";
	printSqMatrix(m);
	cout << endl;
	//---------------------------------
	// checking our function
	if (identity(m)) {
		cout << "IS an Indentity Matrix";
	} else {
		cout << "is NOT an Indentity Matrix";
	}
	cout << endl << endl;

	m[0][2] = 5;
	cout << "Second example of matrix:\n";
	printSqMatrix(m);
	cout << endl;
	//---------------------------------
	// checking our function
	if (identity(m)) {
		cout << "IS an Indentity Matrix";
	} else {
		cout << "is NOT an Indentity Matrix";
	}
	cout << endl << endl;

	return 0;
}

void printSqMatrix(TSqMatrix m)
{
	for (unsigned f = 0; f < SIZE; f++) {
		for (unsigned c = 0; c < SIZE; c++) {
			cout << m[f][c] << " ";
		}
		cout << endl;
	}
}

bool identity(TSqMatrix m)
{
	bool isIdentity = true;
	unsigned row,col;

	row = 0;
	while ((row < SIZE) and isIdentity) {
		col = 0;
		while ((col < SIZE) and isIdentity) {
			if ((row == col) and (m[row][col] != 1)) {
				isIdentity = false;
			} else if ((row != col) and (m[row][col] != 0)) {
				isIdentity = false;
			}
			col++;
			// isIdentity =  ((row == col) and (m[row][col] == 1)) or ((row != col) and (m[row][col] == 0));
		}
		row++;
	}
	return isIdentity;
}
