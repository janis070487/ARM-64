#include "ARM64.h"
#include <string>
#include <iostream>

#define ull unsigned long long

//___________________________________________________________________________________________________

ARM64::ARM64() {
	for (int i = 0; i < 33; i++) {
		this->Registr[i] = 0;
	}
}

//___________________________________________________________________________________________________

string ARM64::GetValueHEX(ull value) {
	string result = "0x";
	ull a = value;
	for (int i = 15; i > -1; i--) {
		a = value >> (i * 4);
		a = a & this->maskH;
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

//___________________________________________________________________________________________________

string ARM64::GetValueBIN(ull value) {

	string result = "0b";
	ull a = value;
	for (int i = 63; i > -1; i--) {
		a = value >> i;
		a = a & this->maskB;
		switch (a)
		{
		case 0: result = result + '0';
			break;
		case 1: result = result + '1';
			break;
		}
	}
	return result;
}

//___________________________________________________________________________________________________

void ARM64::PrintAllRegistrToStringConsole(string format) {
	if (format == "HEX") {
		for (int i = 0; i < 33; i++) {
			string result = "R" + to_string(i) + " :" + GetValueHEX(this->Registr[i]) + "\t";
			std::cout << result << endl;
		}
	}

	else if (format == "BIN") {
		for (int i = 0; i < 33; i++) {
			string result = "R" + to_string(i) + " :" + GetValueBIN(this->Registr[i]) + "\t";
			std::cout << result << endl;
		}
	}

	else {
		for (int i = 0; i < 33; i++) {
			string result = "R" + to_string(i) + " :" + "**********\t";
			std::cout << result << endl;
		}	
	}
}

//___________________________________________________________________________________________________

void ARM64::PrintOneRegistrToStringComsole(int whichOne, string format) {
	if (format == "HEX") {
		string result = "R" + to_string(whichOne) + " :" + GetValueHEX(this->Registr[whichOne]);
		std::cout << result << endl;	
	}

	else if (format == "BIN") {
		string result = "R" + to_string(whichOne) + ": " + GetValueBIN(this->Registr[whichOne]);
		std::cout << result << endl;
	}

	else {
		std::cout << "**********" << endl;
	}

}

//___________________________________________________________________________________________________

void ARM64::PrintFromToRegistrToStringComsole(int From, int To, string format) {
	int from = From;
	int to = To;
	if (from < 0) from = 0;
	if (to > 33) to = 33;
	if (From < 0) From = 0;
	if (format == "HEX") {
		for (int i = from; i < to; i++) {
			string result = "R" + to_string(i) + " :" + GetValueHEX(this->Registr[i]) + "\t";
			std::cout << result << endl;
		}
	}

	else if (format == "BIN") {
		for (int i = from; i < to; i++) {
			string result = "R" + to_string(i) + " :" + GetValueBIN(this->Registr[i]) + "\t";
			std::cout << result << endl;
		}
	}

	else {
		for (int i = from; i < to; i++) {
			string result = "R" + to_string(i) + " :" + "**********\t";
			std::cout << result << endl;
		}
	}
}

//_________________ Comands __________________________________


void ARM64::MOW_RR(int in, int out) {
	this->Registr[in] = this->Registr[out];
}
//___________________________________________________________________________________________________

void ARM64::MOW_RC(int in, unsigned short con) { //unsigned short
	this->Registr[in] = con;
}

//___________________________________________________________________________________________________

void ARM64::LSL(int x, int y, int cik) {
	this->Registr[x] = this->Registr[y] << cik;
}

//___________________________________________________________________________________________________

void ARM64::LSR(int x, int y, int cik) {
	this->Registr[x] = this->Registr[y] >> cik;
}

//___________________________________________________________________________________________________

void ARM64::ASR(int x, int y, int cik) {

}

//___________________________________________________________________________________________________

void ARM64::ROR(int x, int y, int cik) {

}

//___________________________________________________________________________________________________
//___________________________________________________________________________________________________




