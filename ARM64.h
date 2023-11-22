#pragma once
#include <iostream>
#include <string>
#include "const.h"


using namespace std;

class ARM64 {

//private:
private:
	ull mask = 0x000000000000000f;
	ull Registr[33];
	string GetValueHEX(ull value);
	string GetValueBIN(ull value);
public:
	ARM64();
	
	
	//string GetValueBin(ull value);
	
	void PrintAllRegistrToStringConsole(string format);
	void PrintOneRegistrToStringComsole(int whichOne, string format);
	

	//_________________ Comands __________________________________

	void MOW_RR(int in, int out);
	void MOW_RC(int in, unsigned short con);
};