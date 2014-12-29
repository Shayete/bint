#include <iostream>
#include <stdlib.h>

#include "bigint.h"

using namespace std;

bint::bint()
{
	this->n = (unsigned char *)malloc(sizeof(unsigned char) * 33);

	cout << "allocated 1" << endl;
}

bint::bint(const int n)
{
	char test[256] = {0};
	
	this->n = (unsigned char *)malloc(sizeof(unsigned char) * 33);

	itoa(n, test);

	cout << test << endl;
}

bint::bint(const long n)
{
	char test[256] = {0};

	this->n = (unsigned char *)malloc(sizeof(unsigned char) * 33);
	
	itoa(n, test);
	
	cout << test << endl;
}

bint::bint(const long long n)
{
	char test[256] = {0};

	this->n = (unsigned char *)malloc(sizeof(unsigned char) * 33);

	itoa(n, test);

	cout << test << endl;
}

bint::bint(const char *n)
{
	this->n = (unsigned char *)malloc(sizeof(unsigned char) * 33);

	cout << n << endl;

	cout << "allocated 4" << endl;
}

bint::bint(const bint &ref)
{
	this->n = (unsigned char *)malloc(sizeof(unsigned char) * 33);

	cout << "allocated 5" << endl;
}

bint::~bint()
{
	free(this->n);

	cout << "free!" << endl;
}

bint bint :: operator +(const long n)
{
}

bint bint :: operator + (const long long n)
{
}

bint bint :: operator + (const bint &ref)
{
}

bint bint :: operator - (const long n)
{
}

bint bint :: operator - (const long long n)
{
}

bint bint :: operator - (const bint &ref)
{
}

bint bint :: operator = (const long n)
{
}

bint bint :: operator = (const long long n)
{
}

bint bint :: operator = (const char *n)
{
	cout << "test2" << endl;
}

void bint::itoa(int n, char *dst)
{
	int i = 0, ilocal_n = n;
	short digit;

	for(digit = 1; (ilocal_n /= 10) != 0; digit++);

	ilocal_n = n;
	*(dst + digit) = 0x00;

	for(digit -= 1; digit >= 0; digit--)
	{
		*(dst + digit) = ((ilocal_n % 10) + 0x30);

		ilocal_n /= 10;
	}
}
