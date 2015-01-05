#include <iostream>
#include <stdlib.h>

#define MAX_SIZE 100

class bint 
{
public:
	bint();
	bint(const int);
	bint(const long);
	bint(const long long);
	bint(const unsigned long long);
	bint(const char *);
	bint(const bint&);
	~bint();

	bint operator +(const int);
	bint operator +(const long);
	bint operator +(const long long);
	bint operator +(const bint &);

	bint operator -(const int);
	bint operator -(const long);
	bint operator -(const long long);
	bint operator -(const bint &);

	bint operator *(const bint &);

	void operator ++(const int);
	void operator --(const int);

	void operator =(const int);
	void operator =(const long);
	void operator =(const long long);
	void operator =(const char *);
	void operator =(const bint &);

	bool operator >(const long);
	bool operator >(const long long);
	bool operator >(const char *);
	bool operator >(const bint &);

	bool operator <(const long);
	bool operator <(const long long);
	bool operator <(const char *);
	bool operator <(const bint &);

	bool operator ==(const int);
	bool operator ==(const long);
	bool operator ==(const long long);
	bool operator ==(const char *);
	bool operator ==(const bint &);

	friend std::ostream & operator <<(std::ostream &, const bint &);
private:
	char *n;
	short size_n;

	bint bint_add(const bint, const bint);
	bint bint_sub(const bint, const bint);
	bint bint_mul(const bint, const bint);
	bool bint_biggger(const bint, const bint);
	bool bint_smaller(const bint, const bint);
	bint bint_cleanup(const bint);
};
