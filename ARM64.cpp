#include "ARM64.h"
#include <string>
#include <iostream>

#define ull unsigned long long



ARM64::ARM64() {
	for (int i = 0; i < 33; i++) {
		this->Registr[i] = 0;
	}
}

string ARM64::GetValueHEX(ull value) {
	string result = "0x";
	ull a = 0;
	for (int i = 0; i < 16; i++) {
		a = value >> i * 4;
		a = a & this->mask;
		switch (a)
		{
		case 0: result = result + '0';
			break;
		case 1: result = result + '1';
			break;
		case 2: result = result + '2';
			break;
		case 3: result = result + '3';
			break;
		case 4: result = result + '4';
			break;
		case 5: result = result + '5';
			break;
		case 6: result = result + '6';
			break;
		case 7: result = result + '7';
			break;
		case 8: result = result + '8';
			break;
		case 9: result = result + '9';
			break;
		case 10: result = result + 'a';
			break;
		case 11: result = result + 'b';
			break;
		case 12: result = result + 'c';
			break;
		case 13: result = result + 'd';
			break;
		case 14: result = result + 'e';
			break;
		case 15: result = result + 'f';
			break;
		}
	}
	return result;
}

string ARM64::GetValueBIN(ull value) {
	string result = "0b";
	return result;
}
void ARM64::PrintAllRegistrToStringConsole(string format) {

}

void ARM64::PrintOneRegistrToStringComsole(int whichOne, string format) {
	if (format == "HEX") {
		//std::cout << GetValueHEX(this->Registr[whichOne]) << endl;
		std::cout << format << std::endl;
	}

	else if (format == "BIN") {
		//std::cout << GetValueBIN(this->Registr[whichOne]) << endl;
		std::cout << format << std::endl;
	}

	else {
		//std::cout << "**********" << endl;
	}

}

//_________________ Comands __________________________________
void ARM64::MOW_RR(int in, int out) {
	this->Registr[in] = this->Registr[out];
}

void ARM64::MOW_RC(int in, unsigned short con) {
	this->Registr[in] = con;
}




