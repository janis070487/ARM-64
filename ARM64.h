#pragma once
#include <iostream>
#include <string>
#include "const.h"


using namespace std;

class ARM64 {

//private
	bool format = false;
	int bytee = 8;
	ull maskH = 0x000000000000000f;
	ull maskB = 1;
	ull Registr[33];
	
	string GetValueHEX(ull value);
	string GetValueBIN(ull value);
	string GetValueDEC(ull value);
public:
	ARM64();
	
	
	//string GetValueBin(ull value);
	void Format(bool IsFormat);
	//___________________________________ Varb�t pievienot ______________________________
	//void FormatTo(int byteTo);

	void PrintAllRegistrToStringConsole(string format);
	void PrintOneRegistrToStringComsole(int whichOne, string format);
	void PrintFromToRegistrToStringComsole(int From, int To, string format);

	//_________________ Comands __________________________________
	void MOW_RR(int in, int out);             // ievieto re�istr� re�istru
	void MOW_RC(int in, unsigned short con);  // ievieto re�istru konstantu

	void LSL(int x, int y, int cik);		 // Lo�iskais shift pa kreisi
	void LSR(int x, int y, int cik);		 // Lo�iskais shift pa labi
	void ASR(int x, int y, int cik);         // Aritm�tiskais shift pa labi
	void ROR(int x, int y, int cik);		 // Rotate pa labi

};