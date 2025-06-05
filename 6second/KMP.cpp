// KMP.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include "KMP_StateMachine.h"


//вирусный код
char vCode[] = { 0x88, 0x42, 0xE0, 0x46, 0xEB, 0x27, 0x00, 0xED, 0x3F, 0x8B, 0xCE, 0xE3, 0x12, 0x8D, 0x7E, 0xE0 };

void Test_KMP() {
	KMP_StateMachine sm(vCode, sizeof(vCode));

	const char* testStr = "abcabxabcaby";
	for (int i = 0; testStr[i] != '\0'; i++) {
		sm.Accept(testStr[i]);
		if (sm.IsFinal()) {
			cout << "Sovpadenie found at index " << i - sizeof(vCode) + 1 << endl;
		}
	}
}

void ScanFile(const string& filename) {
	KMP_StateMachine sm(vCode, sizeof(vCode));
	ifstream ifs(filename, ios::binary);
	if (!ifs.is_open()) {
		cerr << filename << " not found!" << endl;
		return;
	}

	char ch;
	bool infected = false;

	while (ifs.get(ch)) {
		sm.Accept(ch);
		if (sm.IsFinal()) {
			infected = true;
			break;
		}
	}

	ifs.close();

	if (infected) {
		cout << filename << " infected" << endl;
	}
	else {
		cout << filename << " is healthy" << endl;
	} 
}

int main()
{
	Test_KMP();
	//нельзя работать с помощью функций работы со строками вроде strlen, так как они останавливаются на нулевом байте
	string files[] = {
		"TestData/i1.tst",
		"TestData/i2.tst",
		"TestData/h1.tst",
		"TestData/h2.tst",
		"TestData/i3.tst"
	};

	for (const auto& file : files) {
		ScanFile(file);
	}

	return 0;
}

