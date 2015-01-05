#include <iostream>
#include "bigint.h"

using namespace std;

int main(int argc, char *argv[])
{
	bint a = "1234";
	bint b = "9876";

	cout << a * b << endl;
	cout << a.factorial(20) << endl;
}
