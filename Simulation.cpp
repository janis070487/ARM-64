
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
	
	a.MOV_RC(x0, 53);
	a.MOVK(x0, 44, 16);
	a.MOVK(x0, 4, 32);
	a.MOVK(x0, 33, 48);
	a.UBFM(x1, x0, 17, 22);

	a.Format(true);
	a.PrintFromToRegistrToStringComsole(0, 4, "BIN");
	
	cout << "_____________________________________________________________" << endl;
	
	

	return 0;
}
