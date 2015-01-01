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

short convert(char *dst, const char *src)
{
	int i = 0, j = 0, size_n = 0;

	for(i = 0; *(src + i) != 0; i++)
		size_n++;

	for(i = size_n - 1; i >= 0; i--, j++)
		*(dst + i) = *(src + j) - 0x30;

	return size_n;
}

void itoa(const int n, char *dst)
{
	int il_n = n;
	short digit;

	for(digit = 1; (il_n /= 10) != 0; digit++);

	il_n = n;
	*(dst + digit) = 0x00;

	for(digit -= 1; digit >= 0; digit--)
	{
		*(dst + digit) = ((il_n % 10) + 0x30);
		il_n /= 10;
	}
}

void memset(char *dst, const int val, const size_t n)
{
	int i;
	for(i = 0; i < n; i++)
		*(dst + i) = val;

}

void memcpy(char *dst, const char *src, const size_t n)
{
	int i;
	for(i = 0; i < n; i++)
		*(dst + i) = *(src + i);
}

bint::bint()
{
	this->size_n = 0;
	this->n = cmalloc(MAX_SIZE);

	memset(this->n, 0, MAX_SIZE);
}

bint::bint(const int n)
{
	char *tmp = cmalloc(MAX_SIZE);

	this->size_n = 0;
	this->n = cmalloc(MAX_SIZE);

	itoa(n, tmp);
	this->size_n = convert(this->n, tmp);

	free(tmp);
}

bint::bint(const long n)
{
	char *tmp = cmalloc(MAX_SIZE);

	this->size_n = 0;
	this->n = cmalloc(MAX_SIZE);

	memset(this->n, 0, MAX_SIZE);
	
	itoa(n, tmp);
	this->size_n = convert(this->n, tmp);

	free(tmp);
}

bint::bint(const long long n)
{
	char *tmp = cmalloc(MAX_SIZE);

	this->size_n = 0;
	this->n = cmalloc(MAX_SIZE);

	memset(this->n, 0, MAX_SIZE);

	itoa(n, tmp);
	this->size_n = convert(this->n, tmp);

	free(tmp);
}

bint::bint(const char *n)
{
	this->size_n = 0;
	this->n = cmalloc(MAX_SIZE);

	memset(this->n, 0, MAX_SIZE);

	this->size_n = convert(this->n, n);
}

bint::bint(const bint &ref)
{
	int i;

	this->size_n = 0;
	this->n = cmalloc(MAX_SIZE);

	memset(this->n, 0, MAX_SIZE);

	for(i = 0; i < ref.size_n; i++)
		*((this->n) + i) = *(ref.n + i);

	*((this->n) + i + 1) = 0;
	this->size_n = ref.size_n;
}

bint::~bint() { free(this->n); }

bint bint::operator +(const long n)
{
}

bint bint::operator +(const long long n)
{
}

bint bint::operator +(const bint &ref)
{
	bint s;

	s = bint_add(*this, ref);

	return s;
}

bint bint::operator -(const long n)
{
}

bint bint::operator -(const long long n)
{
}

bint bint::operator -(const bint &ref)
{
}

bint bint::operator =(const long n)
{
}

bint bint::operator =(const long long n)
{
}

void bint::operator =(const char *n)
{
	this->size_n = 0;
	memset(this->n, 0, MAX_SIZE);

	this->size_n = convert(this->n, n);
}

void bint::operator =(const bint &ref)
{
	this->size_n = 0;
	memset(this->n, 0, MAX_SIZE);

	this->size_n = ref.size_n;
	memcpy(this->n, ref.n, ref.size_n);
}

ostream& operator <<(ostream &os, const bint &bint)
{
	int i, j = 0;
	char *lc_n = cmalloc(MAX_SIZE);

	for(i = bint.size_n - 1; i >= 0; i--, j++)
		*(lc_n + j) = *(bint.n + i) + 0x30;

	*(lc_n + j) = 0;

	os << "[size_n : " << bint.size_n << "], [n : " << lc_n << " ]";

	free(lc_n);
	return os;
}

bint bint::bint_add(const bint n, const bint nn)
{
	/* when a + b;
	 * argument n is a left operand (a)

	 * argument nn is a right operand (b)
	 */

	bint s;

	int i, j = 0, x, y;
	short size_n = 0;
	char *n_p, *nn_p, *ad_p;

	n_p = cmalloc(MAX_SIZE);
	nn_p = cmalloc(MAX_SIZE);
	ad_p = cmalloc(MAX_SIZE);

	memset(n_p, 0, MAX_SIZE);
	memset(nn_p, 0, MAX_SIZE);
	memset(ad_p, 0, MAX_SIZE);
	
	memcpy(n_p, n.n, n.size_n);
	memcpy(nn_p, nn.n, nn.size_n);

	j = n.size_n - nn.size_n;
	if(j > 0)
	{
		for(i = 0; i < n.size_n; i++)
		{
			if((*(n_p + i) + *(nn_p + i)) >= 10)
			{
				*(n_p + i) = (*(n_p + i) + *(nn_p + i)) - 10;
				*(ad_p + i) = *(n_p + i);
				
				for(j = i + 1; (*(n_p + j) + 1) >= 10; j++)
					*(n_p + j) = 0;

				if(j == n.size_n)
				{
					(*(n_p + j))++;
					size_n++;

					*(ad_p + j) = *(n_p + j);
				}
				else
					(*(n_p + j))++;

			}
			else
				*(ad_p + i) = *(n_p + i) + *(nn_p + i);
		}
		size_n += n.size_n;
	}
	else if(j < 0)
	{
		for(i = 0; i < nn.size_n; i++)
		{
			if((*(nn_p + i) + *(n_p + i)) >= 10)
			{
				*(nn_p + i) = (*(nn_p + i) + *(n_p + i)) - 10;
				*(ad_p + i) = *(nn_p + i);

				for(j = i + 1; (*(nn_p + j) + 1) >= 10; j++)
					*(nn_p + j) = 0;

				if(j == nn.size_n)
				{
					(*(nn_p + j))++;
					size_n++;

					*(ad_p + j) = *(nn_p + j);
				}
				else
					(*(nn_p + j))++;
			}
			else
				*(ad_p + i) = *(nn_p + i) + *(n_p + i);
		}
		size_n += nn.size_n;
	}
	else
	{
		for(i = 0; i < n.size_n; i++)
		{
			if((*(n_p + i) + *(nn_p + i)) >= 10)
			{
				*(n_p + i) = (*(n_p + i) + *(nn_p + i)) - 10;
				*(ad_p + i) = *(n_p + i);

				for(j = i + 1; (*(n_p + j) + 1) >= 10; j++)
					*(n_p + j) = 0;
				
				if(j == n.size_n)
				{
					(*(n_p + j))++;
					size_n++;
						
					*(ad_p + j) = *(n_p + j);
				}
				else
					(*(n_p + j))++;
			}	
			else
				*(ad_p + i) = *(n_p + i) + *(nn_p + i);
		}
		size_n += n.size_n;
	}

	memcpy(s.n, ad_p, size_n);
	s.size_n = size_n;

	free(n_p);
	free(nn_p);
	free(ad_p);
	
	return s;
}
