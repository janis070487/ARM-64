
#include <iostream>
#include "ARM64.h"

using namespace std;

// * Pārbaudīt raspberry kas notiek ar max skaitļiem ar komandu mov ja pārsnied 16 bitus kā arī ar negatīviem
//   vai sakrīt ar saites komandām un pameiģināt atšifret komandas
// * Parbaudit ko apkodā nozīmē shift bitu un vai tas saistīts ar komandu piemēram MOVK 0X, #15, LSL #16
//   pārbaudīt ari termux

int main()
{
	

	ARM64 arm64;
	//ull a = 81985529216486895;
	//ull a = 0b1111111111111111;

	ull a = 0x000f;
	//arm64.MOV_RC(0, 15);
	arm64.MOVK(0, 15, 16);
	arm64.MOVK(0, 15, 32);
	arm64.MOVK(0, 15, 48);
	arm64.MOV_RR(1, 0);
	arm64.MOVZ(0, 15, 16);
	//arm64.MOVK(0, 15, 32);
	
	
	
	arm64.Format(true);
	arm64.PrintFromToRegistrToStringComsole(0, 4, "BIN");
	
	cout << "_____________________________________________________________" << endl;
	
	//arm64.ASR(1, 1, 1);

	return 0;
}
