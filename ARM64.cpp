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

void ARM64::Apcode(unsigned int code) {
	unsigned int Bits = code >> 31;
	unsigned int Opcode = ((code & 0b01000000000000000000000000000000) >> 25) + ((code & 0b00011111000000000000000000000000) >> 24);
	unsigned int ConditionCode = (code & 0b00100000000000000000000000000000) >> 29;
	unsigned int Shift = (code & 0b00000000110000000000000000000000) >> 22;
	unsigned int None = (code & 0b00000000001000000000000000000000) >> 21;
	unsigned int Rm = (code & 0b00000000000111110000000000000000) >> 16;
	unsigned int Imm6 = (code & 0b00000000000000001111110000000000) >> 10;
	unsigned int Rn = (code & 0b00000000000000000000001111100000) >> 5;
	unsigned int Rd = (code & 0b00000000000000000000000000011111);

	string Bits_S = BIN(Bits, 1);
	string Opcode_S = BIN(Opcode, 6);
	string ConditionCode_S = BIN(ConditionCode, 1);
	string Shift_S = BIN(Shift, 2);
	string None_S = BIN(None, 1);
	string Rm_S = BIN(Rm, 5);
	string Imm6_S = BIN(Imm6, 6);
	string Rn_S = BIN(Rn, 5);
	string Rd_S = BIN(Rd, 5);

	cout << "_____________________________________________________________________________" << endl;
	cout << "Bits: \t\t" << "Decimala vertiba: " << Bits<< "\t" << "Binara vertiba: " << Bits_S << "\t" << endl;
	cout << "ConditionCode: \t" << "Decimala vertiba: " << ConditionCode << "\t" << "Binara vertiba: " << ConditionCode_S << "\t" << endl;
	cout << "Opcode: \t" << "Decimala vertiba: " << Opcode << "\t" << "Binara vertiba: " << Opcode_S << "\t" << endl;
	cout << "Shift: \t\t" << "Decimala vertiba: " << Shift << "\t" << "Binara vertiba: " << Shift_S << "\t" << endl;
	cout << "None: \t\t" << "Decimala vertiba: " << None << "\t" << "Binara vertiba: " << None_S << "\t" << endl;
	cout << "Rm: \t\t" << "Decimala vertiba: " << Rm << "\t" << "Binara vertiba: " << Rm_S << "\t" << endl;
	cout << "Imm6: \t\t" << "Decimala vertiba: " << Imm6 << "\t" << "Binara vertiba: " << Imm6_S << "\t" << endl;
	cout << "Rn: \t\t" << "Decimala vertiba: " << Rn << "\t" << "Binara vertiba: " << Rn_S << "\t" << endl;
	cout << "Rd: \t\t" << "Decimala vertiba: " << Rd << "\t" << "Binara vertiba: " << Rd_S << "\t" << endl;
	cout << "_____________________________________________________________________________" << endl;

}


string ARM64::BIN(unsigned int value, int cik) {
	string result = "";
	ull a = value;
	int position = 32 - (33 - cik);
	for (int i = position; i > -1; i--) {
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

 /*
 D2801005   mov x5, #128
 1 0 110010 10 0 00000 000100 00000 00101
 mov rc



 AA0203E0    mov x0, x2
 1 1 001010 00 0 00010 000000 11111 00000
 mov rr
*/

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
		case 10: result = result + 'A';
			break;
		case 11: result = result + 'B';
			break;
		case 12: result = result + 'C';
			break;
		case 13: result = result + 'D';
			break;
		case 14: result = result + 'E';
			break;
		case 15: result = result + 'F';
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



//_________________ Comands Apcodes ____________________________________________________________________


void ARM64::Comand(unsigned int code) {
	unsigned int Bits = code >> 31;
	unsigned int Opcode =		((code & 0b01000000000000000000000000000000) >> 25) + ((code & 0b00011111000000000000000000000000) >> 24);
	unsigned int ConditionCode = (code & 0b00100000000000000000000000000000) >> 29;
	unsigned int Shift =		 (code & 0b00000000110000000000000000000000) >> 22;
	unsigned int None =			 (code & 0b00000000001000000000000000000000) >> 21;
	unsigned int Rm =			 (code & 0b00000000000111110000000000000000) >> 16;
	unsigned int Imm6 =			 (code & 0b00000000000000001111110000000000) >> 10;
	unsigned int Rn =			 (code & 0b00000000000000000000001111100000) >> 5;
	unsigned int Rd =			 (code & 0b00000000000000000000000000011111);

	switch (Opcode)
	{
	case 51:                                    // LSL x1, x0, #5
		if (Bits) {
			this->Registr[Rd] = (this->Registr[Rn] << (63 - Imm6));
		}
		else {
			this->Registr[Rd] = (this->Registr[Rn] << (31 - Imm6));
			this->Registr[Rd] = (this->Registr[Rd] & 0x00000000FFFFFFFF);
		}
		break;

	case 50:									 // mov x0, #55      Ieladç reìistrâ pozitîvu konstantu
	{
		unsigned short constt = Rn + (Imm6 << 5) + (Rm << 11);
		this->Registr[Rd] = constt;
	}
		break;

	case 18:									// mov X0, #-55     Ieladç reìistrâ negativu konstantu
	{
		unsigned short constt = Rn + (Imm6 << 5) + (Rm << 11);
		if (Bits) {
			this->Registr[Rd] = constt;
			this->Registr[Rd] = ~(this->Registr[Rd]);
		}
		else {
			this->Registr[Rd] = ~constt;
			this->Registr[Rd] = this->Registr[Rd] & 0x00000000FFFFFFFF;
		}
		break;
	}
	case 10:									// mov x0, x1       komç reìistru no reìistra
		if (Bits){
			this->Registr[Rd] = this->Registr[Rm];
		}
		else {
			this->Registr[Rd] = this->Registr[Rm] & 0x00000000FFFFFFFF;
		}
		break;
		
	default:
		
		cout << "Eror Comand: " << endl;
		break;
	}



}

//_________________ Comands ____________________________________________________________________________



//___________________________________________________________________________________________________



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

void ARM64::MOVN(int x, unsigned short value, int cik) {
	if ((cik == 0) || (cik == 16) || (cik == 32) || (cik == 48)) {
		//unsigned short b = 
		ull a = (~value);
		a = a << cik;
		this->Registr[x] = a;
		//this->Registr[x] = this->Registr[x] + a;
	}
	else {
		cout << "EROR: Nepielaujama komandas operanda vertiba" << endl;
	}
}

//___________________________________________________________________________________________________

void ARM64::SBFM(int x, int y, int no, int lidz) {
	ull result = this->Registr[y];
	//    4   9
	// 011001 11000 11101
	// 
	result = result << (15 - lidz);
	result = result >> (15 - lidz + (no + 1));
	ull numberOfSigns = result >> (lidz - no + 1);
	if (numberOfSigns) {
		this->Registr[x] = 0;
		this->Registr[x] = ~this->Registr[x];
		this->Registr[x] = this->Registr[x];
		//  11111111
		//  00001101
		//  11110010
		//  00001101
		//  
	}
	else {
		this->Registr[x] = result;
	}
}

//___________________________________________________________________________________________________

void ARM64::UBFM(int x, int y, int no, int lidz) {
	ull result = this->Registr[y]; 
	result = result << (15 - lidz);
	result = result >> (15 - lidz + (no + 1));
	this->Registr[x] = result;
}


//___________________________________________________________________________________________________


//___________________________________________________________________________________________________
//___________________________________________________________________________________________________


//___________________________________________________________________________________________________
//___________________________________________________________________________________________________





