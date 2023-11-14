#include "ARM64.h"

string ARM64::GetValueString(unsigned long long value, string format = "HEX") {
	if (format == "HEX") return GetValueHEX(value);
	else if (format == "BIN") return GetValueBin(value);
	else return "**********";
}

string ARM64::GetValueHEX(unsigned long long value) {

}

string ARM64::GetValueBIN(unsigned long long value) {

}
void ARM64::PrintAllRegistrToStringConsole() {

}

void ARM64::PrintOneRegistrToStringComsole(int whichOne) {

}

void ARM64::PrintOneRegistrToStringComsole(string whichOne) {

}
