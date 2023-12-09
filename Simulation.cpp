
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
	a.Apcode(0x929FBCE0); // 1 0 010010 10 0 10000 100000 01111 00000
	a.Apcode(0xE0BC9F92);
	//a.Apcode(0x52800200);

	//a.Comand(0x929FBCE0);
	//a.Comand(0x128001C1);  // mov w1, #-15
	
	//          0000000000000000000000000000000000000000000000001111110111101000    +65000    000000000000fde8       w
	//          0000000000000000000000000000000011111111111111110000001000011000    -65000    00000000ffff0218       W
	//          0000000000000000000000000000000000000000000000001111110111101000    +65000    000000000000fde8       x
	//          1111111111111111111111111111111111111111111111111111111000011000    -65000    1111111111110218       x
	//

	a.Format(true);
	a.PrintFromToRegistrToStringComsole(0, 4, "BIN");
	
	cout << "_____________________________________________________________" << endl;
	
	

	return 0;
}
