#pragma once
#include <iostream>
#include <string>
#include "Comands.h"

#define ull unsigned long long
#define FP 28
#define LR 29
#define SP 30
#define PC 31
#define XZR 32

using namespace std;

class ARM64 {

public:
	ull Registr[33];
	
	string GetValueString(ull value, string format);
	string GetValueHEX(ull value);
	string GetValueBIN(ull value);
	//string GetValueBin(ull value);
	
	void PrintAllRegistrToStringConsole();
	void PrintOneRegistrToStringComsole(int whichOne);
	
};