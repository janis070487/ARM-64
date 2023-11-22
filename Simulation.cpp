
#include <iostream>
#include "ARM64.h"
//#include "const.h"

using namespace std;



int main()
{
	

	ARM64 arm64;
	
	arm64.MOW_RC(X0, 15);


	//cout << arm64.Registr[0] << endl;
	arm64.PrintOneRegistrToStringComsole(0, "HEX");

	return 0;
}
