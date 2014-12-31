#include <iostream>
#include "bigint.h"

using namespace std;

int main(int argc, char *argv[])
{
	bint a = "48573849501734958320", b = "19583364959923749584", c;

	cout << b + a << endl;

	c = a + b;

	cout << c << endl;
}
