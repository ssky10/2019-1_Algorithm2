#include <iostream>
#include "Matrix.h"

using namespace std;

int main(void) {
	Matrix m1(2, 3);
	m1.doPrint();
	cout << endl;

	cout << m1.getElement(2, 2) << endl;
	cout << endl;

	m1.setElement(2, 2, -10);
	m1.doPrint();
	cout << endl;

	m1.doTranspose();
	m1.doPrint();
	cout << endl;

	Matrix m2(2, 3);
	m2.doPrint();
	cout << endl;

	(m2*m1).doPrint();
	return 0;
}