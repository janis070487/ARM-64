
#include <iostream>
#include "ARM64.h"

using namespace std;



int main()
{
	

	ARM64 arm64;
	//ull a = 81985529216486895;
	//ull a = 0b1111111111111111;

	ull a = 0x000f;
	arm64.MOW_RC(0, a);
	//arm64.MOW_RC(1, a);
	arm64.LSL(1, 0, 60);
	arm64.LSR(2, 1, 56);
	arm64.PrintFromToRegistrToStringComsole(0, 3, "HEX");
	
	long long dd = 1;
	dd = dd << 62;

	unsigned long long z = 0x80ffffffffffffff;
	z = z << 64;

	cout << dd << endl;
	cout << z << endl;


	return 0;
}
