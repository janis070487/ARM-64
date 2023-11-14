#pragma once
#include <iostream>
#include <string>
#include "Comands.h"
using namespace std;

class ARM64 {
private:
	unsigned long long Registr[30];
	unsigned long long PC = 0;		// Program Counter
	unsigned long long SP = 0;		// Stack Pointer
	unsigned long long XZR = 0;		// Statuss flages
	unsigned long long LR = 0;		// Link Register ir tas pats kas X30
	unsigned long long FP = 0;		// Frame Pointer ir tas pats kas X29
	string GetValueString(unsigned long long value, string format = "HEX");
	string GetValueHEX(unsigned long long value);
	string GetValueBin(unsigned long long value);
public:
	string GetValueBIN(unsigned long long value);
	void PrintAllRegistrToStringConsole();
	void PrintOneRegistrToStringComsole(int whichOne);
	void PrintOneRegistrToStringComsole(string whichOne);
};