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
	ull xzr = 0;

	string GetValueHEX(ull value);
	string GetValueBIN(ull value);
	string GetValueDEC(ull value);
public:

	ARM64();

	
	void Apcode(unsigned int code);
	void Comand(unsigned int code);

	string BIN(unsigned int value, int cik);
	//string GetValueBin(ull value);
	void Format(bool IsFormat);
	//___________________________________ Varbût pievienot ______________________________
	//void FormatTo(int byteTo);

	void PrintAllRegistrToStringConsole(string format);
	void PrintOneRegistrToStringComsole(int whichOne, string format);
	void PrintFromToRegistrToStringComsole(int From, int To, string format);

	//_________________ Comands __________________________________

	//https://metanit.com/assembler/arm64/2.3.php
	void MOV_RR(int in, int out);             // ievieto reìistrâ reìistru
	void MOV_RC(int in, unsigned short con);  // ievieto reìistru konstantu

	// https://metanit.com/assembler/arm64/2.17.php
	void LSL(int x, int y, int cik);		 // Loìiskais shift pa kreisi
	void LSR(int x, int y, int cik);		 // Loìiskais shift pa labi
	void ASR(int x, int y, int cik);         // Aritmçtiskais shift pa labi
	void ROR(int x, int y, int cik);		 // Rotate pa labi



	// https://metanit.com/assembler/arm64/2.16.php
	void MOVK(int x, unsigned short value, int cik);	    // ievieto konkretos bitus reìistrâ pârçjos neaiztiekot
	void MOVZ(int x, unsigned short, int cik);		// ievieto konkretos bitus reìistrâ pârçjos iestatot nulçs
	void MOVN(int x, unsigned short value, int cik); // ielâdç inverso skaitli no konstantes


	// https://metanit.com/assembler/arm64/2.18.php
	void SBFM(int x, int y, int no, int lidz);  // Kopç noteiktus bitus no reìistra uz registru un òem verâ zimi
	void UBFM(int x, int y, int no, int lidz);  // Kopç noteiktus bitus no reìistra uz registru un neòem vçrâ zîmi
	void EXTR(int x, int y, int z, int bit);    // kopç no divu reìistru daïas citâ reìistrâ
	
};




