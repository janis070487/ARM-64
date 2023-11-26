
#include <iostream>
#include "ARM64.h"

using namespace std;



int main()
{
	

	ARM64 arm64;
	//ull a = 81985529216486895;
	//ull a = 0b1111111111111111;

	ull a = 0x000f;
	arm64.MOW_RC(0, 3);
	
	//arm64.MOW_RC(1, a);
	arm64.LSL(1, 0, 62);
	arm64.ASR(2, 1, 2);
	//arm64.LSR(2, 1, 56);
	arm64.Format(true);
	arm64.PrintFromToRegistrToStringComsole(0, 3, "BIN");
	
	cout << "_____________________________________________________________" << endl;
	unsigned short aa = 0b10101010101010;
	unsigned short cc = 0b01010101010101;
	cout << (aa | cc) << endl;
	//arm64.ASR(1, 1, 1);

	return 0;
}
