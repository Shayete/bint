class bint
{
public:
	bint();
	bint(const int);
	bint(const long);
	bint(const long long);
	bint(const char *);
	bint(const bint&);
	~bint();

	bint operator +(const long);
	bint operator + (const long long);
	bint operator + (const bint &);

	bint operator - (const long);
	bint operator - (const long long);
	bint operator - (const bint &);

	bint operator = (const long);
	bint operator = (const long long);
	bint operator = (const char *);

	void itoa(int n, char *dst);

private:
	unsigned char *n;

};
