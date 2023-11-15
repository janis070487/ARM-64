#include "ARM64.h"
#include <string>

#define ull unsigned long long

string ARM64::GetValueString(ull value, string format = "HEX") {
	if(format == "HEX") { 
		return GetValueHEX(value); 
	}
	
	if(format == "BIN") {
		return GetValueBIN(value); 
	}
	
	else {
		return "**********";
	}
	
	return format;
}

string ARM64::GetValueHEX(ull value) {
	return "HEX";
}

string ARM64::GetValueBIN(ull value) {
	return "BIN";
}
void ARM64::PrintAllRegistrToStringConsole() {

}

void ARM64::PrintOneRegistrToStringComsole(int whichOne) {

}




