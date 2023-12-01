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
void ARM64::Format(bool IsFormat) {
	this->format = IsFormat;
}
//___________________________________ Varbût pievienot ______________________________
/* void ARM64::FormatTo(int byteTo) {
	if (bytee <= 8) {
		this->bytee = byteTo;
	}
	else
	{
		this->bytee = 8;
	}
} */
string ARM64::GetValueHEX(ull value) {
	string result = "0x";
	ull a = value;
	int formatSpace = 0;
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
		formatSpace++;
		if (formatSpace == 2 && format) {
			result = result + " ";
			formatSpace = 0;
		}
	}
	return result;
}

//___________________________________________________________________________________________________

string ARM64::GetValueBIN(ull value) {

	string result = "0b";
	ull a = value;
	int formatSpace = 0;
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
		formatSpace++;
		if (formatSpace == 8 && format) {
			result = result + " ";
			formatSpace = 0;
		}
	}
	return result;
}

//___________________________________________________________________________________________________

string ARM64::GetValueDEC(ull value) {
	return std::to_string(value);
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

	else if (format == "DEC") {
		for (int i = 0; i < 33; i++) {
			string result = "R" + to_string(i) + " :" + GetValueDEC(this->Registr[i]) + "\t";
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

	else if (format == "DEC") {
		string result = "R" + to_string(whichOne) + ": " + GetValueDEC(this->Registr[whichOne]);
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

	else if (format == "DEC") {
		for (int i = from; i < to; i++) {
			string result = "R" + to_string(i) + " :" + GetValueDEC(this->Registr[i]) + "\t";
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


void ARM64::MOV_RR(int in, int out) {
	this->Registr[in] = this->Registr[out];
}
//___________________________________________________________________________________________________

void ARM64::MOV_RC(int in, unsigned short con) { //unsigned short
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
	bool PN = this->Registr[y] & 0x8000000000000000;
	this->Registr[x] = this->Registr[y] >> cik;
	if (PN) {
		this->Registr[x] & 0x8000000000000000;
		this->Registr[x] = this->Registr[x] + 0x8000000000000000;
	}
	
}

//____________________________________________ ROR _______________________________________________________

void ARM64::ROR(int x, int y, int cik) {
	this->Registr[x] = (this->Registr[y] >> cik) | (this->Registr[y] << (sizeof(this->Registr[y]) * 8 - cik));
	//rotateRight
}

//___________________________________________________________________________________________________

void ARM64::MOVK(int x, unsigned short value, int cik) {
	if ((cik == 0) || (cik == 16) || (cik == 32) || (cik == 48)) {
		ull a = value;
		a = a << cik;
		this->Registr[x] = this->Registr[x] + a;
	}
	else {
		cout << "EROR: Nepielaujama komandas operanda vertiba" << endl;
	}
}

//___________________________________________________________________________________________________

void ARM64::MOVZ(int x, unsigned short value, int cik) {
	if ((cik == 0) || (cik == 16) || (cik == 32) || (cik == 48)) {
		ull a = value;
		a = a << cik;
		this->Registr[x] = 0;
		this->Registr[x] = this->Registr[x] + a;
	}
	else {
		cout << "EROR: Nepielaujama komandas operanda vertiba" << endl;
	}
}

//___________________________________________________________________________________________________



//___________________________________________________________________________________________________


//___________________________________________________________________________________________________
//___________________________________________________________________________________________________


//___________________________________________________________________________________________________
//___________________________________________________________________________________________________


//___________________________________________________________________________________________________
//___________________________________________________________________________________________________





