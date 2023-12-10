
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
	//a.Apcode(0x929FBCE0); // 1 0 010010 10 0 10000 100000 01111 00000
	//a.Apcode(0xD28ECE40);

	//a.Comand(0x528ECE40); // mov x0, #30322
	//a.Comand(0x128ECE21); // mov x1, #-30322

	a.Comand(0x52802840); // mov x2, #30322
	a.Comand(0x53061400); // a100
	//    1010000100000000 0000000000000000
	
	a.Apcode(0x53061400);
	//a.Apcode(0xD37FF9E8); 
	



	//  11111111110
	//  00000000001



	//a.Apcode(0x128ECE21);

	//  1000100110001110
	//   111011001110010

	//a.Format(true);
	a.PrintFromToRegistrToStringComsole(0, 5, "HEX");
	
	cout << "_____________________________________________________________" << endl;
	
	

	return 0;
}
