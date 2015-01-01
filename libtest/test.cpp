#include <iostream>
#include "bigint.h"

using namespace std;

int main(int argc, char *argv[])
{
	bint a = "1293470198237502137651256912356123065123065912873650135";
        bint b = "237023712350721837502183750218375018237501283750", c;
	bint e = 1, f = 1, g = 1;

	cout << b + a << endl;
	cout << e + f + g << endl;

	c = a + b;

	cout << c << endl;
}
