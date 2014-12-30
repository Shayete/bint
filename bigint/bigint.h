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
	bint operator +(const long long);
	bint operator +(const bint &);

	bint operator -(const long);
	bint operator -(const long long);
	bint operator -(const bint &);

	bint operator =(const long);
	bint operator =(const long long);
	bint operator =(const char *);

	friend std::ostream & operator <<(std::ostream &, const bint &);

	void convert(char *dst, const char *src);
	void itoa(const int n, char *dst);

private:
	char *n;
	short size_n;
};
