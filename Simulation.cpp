
#include <iostream>
#include "ARM64.h"

using namespace std;

// ________________________ !!!!!!!!!!!!!!!! ____________________________
// Parbaudam vai isteniba ka darbojas MOVN komanda realitāte
// Izdomāt kā organizēt 32 un 64 bitu operācījas


// * Pārbaudīt raspberry kas notiek ar max skaitļiem ar komandu mov ja pārsnied 16 bitus kā arī ar negatīviem
//   vai sakrīt ar saites komandām un pameiģināt atšifret komandas
// * Parbaudit ko apkodā nozīmē shift bitu un vai tas saistīts ar komandu piemēram MOVK 0X, #15, LSL #16
//   pārbaudīt ari termux

int main()
{
	

	ARM64 a;
	//a.Apcode(0x928001E0); // 1 0 010010 10 0 10000 100000 01111 00000
	a.Apcode(0xD29FBD00);
	//a.Apcode(0x52800200);

	a.Format(true);
	a.PrintFromToRegistrToStringComsole(0, 4, "BIN");
	
	cout << "_____________________________________________________________" << endl;
	
	

	return 0;
}
