#include "Test.h"

int Test::nCount = 0;

Test::Test() {
	nCount++;
	cout << "Object Test was made" << endl;
	cout << "nCount: " << nCount << endl;
}

Test::Test(const Test& other) {
	nCount++;
	cout << "Copy an object. Amount of objects: " << nCount << endl;
}

Test::~Test() {
	nCount--;
	cout << "Object Test was destroyed" << endl;
	cout << "nCount: " << nCount << endl;
}

Child::Child() {
	cout << "Child obj was made" << endl;
}

Child::~Child() {
	cout << "Child obj was destroyed" << endl;
}

Aggregate::Aggregate() {
	cout << "Aggregate obj was made" << endl;
}

Aggregate::~Aggregate() {
	cout << "Aggregate obj was destroyed" << endl;
}