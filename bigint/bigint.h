#define MAX_SIZE 100

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
	void operator =(const char *);
	void operator =(const bint &bint);

	friend std::ostream & operator <<(std::ostream &, const bint &);
private:
	char *n;
	short size_n;

	bint bint_add(const bint n, const bint nn);
};
