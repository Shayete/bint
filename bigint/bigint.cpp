#include <iostream>
#include <stdlib.h>

#include "bigint.h"

using namespace std;

char *cmalloc(const size_t n)
{
	char *p = (char *)malloc(sizeof(char) * n);

	if(!p)
	{
		cout << "out of memory" << endl;
		exit(1);
	}

	return p;
}

bint::bint()
{
	this->size_n = 0;
	this->n = cmalloc(33);
}

bint::bint(const int n)
{
	char *tmp = cmalloc(33);

	this->size_n = 0;
	this->n = cmalloc(33);

	itoa(n, tmp);
	convert(this->n, tmp);

	free(tmp);
}

bint::bint(const long n)
{
	char *tmp = cmalloc(33);

	this->size_n = 0;
	this->n = cmalloc(33);
	
	itoa(n, tmp);
	convert(this->n, tmp);

	free(tmp);
}

bint::bint(const long long n)
{
	char *tmp = cmalloc(33);

	this->size_n = 0;
	this->n = cmalloc(33);

	itoa(n, tmp);
	convert(this->n, tmp);

	free(tmp);
}

bint::bint(const char *n)
{
	this->size_n = 0;
	this->n = cmalloc(33);

	convert(this->n, n);
}

bint::bint(const bint &ref)
{
	int i;

	this->size_n = 0;
	this->n = cmalloc(33);

	for(i = 0; i < ref.size_n; i++)
		*((this->n) + i) = *(ref.n + i);

	*((this->n) + i + 1) = 0;
	this->size_n = ref.size_n;
}

bint::~bint() { free(this->n); }

bint bint :: operator +(const long n)
{
}

bint bint :: operator +(const long long n)
{
}

bint bint :: operator +(const bint &ref)
{
}

bint bint :: operator -(const long n)
{
}

bint bint :: operator -(const long long n)
{
}

bint bint :: operator -(const bint &ref)
{
}

bint bint :: operator =(const long n)
{
}

bint bint :: operator =(const long long n)
{
}

bint bint :: operator =(const char *n)
{
	cout << "test2" << endl;
}

ostream& operator <<(ostream &os, const bint &bint)
{
	int i;
	char *lc_n = cmalloc(33);

	for(i = 0; i < bint.size_n; i++)
		*(lc_n + i) = *(bint.n + i) + 0x30;

	*(lc_n + i + 1) = 0;

	os << "[size_n : " << bint.size_n << "], [n : " << lc_n << " ]" << endl;

	free(lc_n);
	return os;
}

void bint::convert(char *dst, const char *src)
{
	int i = 0;

	for(i = 0; *(src + i) != 0; i++)
	{
		*(dst + i) = *(src + i) - 0x30;

		this->size_n++;
	}
}

void bint::itoa(const int n, char *dst)
{
	int ilocal_n = n;
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
