#include "bigint.h"

using namespace std;

char *cmalloc(const size_t n)
{
	char *p = (char *)malloc(sizeof(char) * n);
	if(!p) {
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

int itoa(const long long n, char *dst)
{
	long long il_n = n;
	int digit, digit_ret;

	for(digit = 1; (il_n /= 10) != 0; digit++);
	digit_ret = digit;

	il_n = n;
	*(dst + digit) = 0x00;

	for(digit -= 1; digit >= 0; digit--) {
		*(dst + digit) = ((il_n % 10) + 0x30);
		il_n /= 10;
	}

	return digit_ret;
}

void memset(char *dst, const int val, const size_t n)
{
	unsigned int i;
	for(i = 0; i < n; i++)
		*(dst + i) = val;

}

void memcpy(char *dst, const char *src, const size_t n)
{
	unsigned int i;
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

bint bint::operator +(const int n)
{
	bint s, b_tmp = n;
	s = bint_add(*this, b_tmp);

	return s;
}

bint bint::operator +(const long n)
{
	bint s, b_tmp = n;
	s = bint_add(*this, b_tmp);

	return s;
}

bint bint::operator +(const long long n)
{
	bint s, b_tmp = n;
	s = bint_add(*this, b_tmp);

	return s;
}

bint bint::operator +(const bint &ref)
{
	bint s;
	s = bint_add(*this, ref);

	return s;
}

void bint::operator +=(const int n)
{
	bint s, b_tmp = n;
	*this = *this + n;
}	

void bint::operator +=(const long n)
{
	bint s, b_tmp = n;
	*this = *this + n;
}

void bint::operator +=(const long long n)
{
	bint s, b_tmp = n;
	*this = *this + n;
}

void bint::operator +=(const bint &ref)
{
	*this = *this + ref;
}


bint bint::operator -(const int n)
{
	bint s, b_tmp = n;

	s = bint_sub(*this, b_tmp);
	s = bint_cleanup(s);

	return s;
}

bint bint::operator -(const long n)
{
	bint s, b_tmp = n;

	s = bint_sub(*this, b_tmp);
	s = bint_cleanup(s);

	return s;

}

bint bint::operator -(const long long n)
{
	bint s, b_tmp = n;

	s = bint_sub(*this, b_tmp);
	s = bint_cleanup(s);

	return s;	
}

bint bint::operator -(const bint &ref)
{
	if(*this < ref) {
		cout << "negative is not supported" << endl;
		exit(1);
	}

	bint s;

	s = bint_sub(*this, ref);
	s = bint_cleanup(s);

	return s;
}

void bint::operator -=(const int n)
{
	bint b_tmp = n;
	*this = *this - b_tmp;
}

void bint::operator -=(const long n)
{
	bint b_tmp = n;
	*this = *this - b_tmp;
}

void bint::operator -=(const long long n)
{
	bint b_tmp = n;
	*this = *this - b_tmp;
}

void bint::operator -=(const bint &ref)
{
	*this = *this - ref;
}

bint bint::operator *(const int n)
{
	bint s, b_tmp = n;

	s = bint_mul(*this, b_tmp);
	s = bint_cleanup(s);

	return s;
}

bint bint::operator *(const bint &ref)
{
	bint s;

	s = bint_mul(*this, ref);
	s = bint_cleanup(s);

	return s;
}

void bint::operator ++(const int n)
{
	*this = *this + 1;
}

void bint::operator --(const int n)
{
	*this = *this - 1;
}

void bint::operator =(const int n)
{
	char *tmp = cmalloc(MAX_SIZE);

	this->size_n = 0;
	memset(this->n, 0, MAX_SIZE);
	
	itoa(n, tmp);
	this->size_n = convert(this->n, tmp);

	free(tmp);
}

void bint::operator =(const long n)
{
	char *tmp = cmalloc(MAX_SIZE);

	this->size_n = 0;
	memset(this->n, 0, MAX_SIZE);

	itoa(n, tmp);
	this->size_n = convert(this->n, tmp);

	free(tmp);
}

void bint::operator =(const long long n)
{
	char *tmp = cmalloc(MAX_SIZE);

	this->size_n = 0;
	memset(this->n, 0, MAX_SIZE);

	itoa(n, tmp);
	this->size_n = convert(this->n, tmp);

	free(tmp);
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

bool bint::operator >(const bint &ref)
{
	return bint_biggger(*this, ref);
}

bool bint::operator <(const bint &ref)
{
	return bint_smaller(*this, ref);
}

bool bint::operator ==(const int n)
{
	int i;

	bint n_tmp = n;

	if(this->size_n != n_tmp.size_n) return false;
	else
		for(i = this->size_n - 1; *(this->n + i) == *(n_tmp.n + i); i--);

	if(!i) return false;
	else return true;	
}

bool bint::operator ==(const bint &ref)
{
	int i;

	if(this->size_n != ref.size_n) return false;
	else
		for(i = this->size_n - 1; *(this->n + i) == *(ref.n + i); i--);

	if(!i) return false;
	else return true;
}

ostream& operator <<(ostream &os, const bint &ref)
{
	int i, j = 0;
	char *lc_n = cmalloc(MAX_SIZE);

	for(i = ref.size_n - 1; i >= 0; i--, j++)
		*(lc_n + j) = *(ref.n + i) + 0x30;

	*(lc_n + j) = 0;

	os << "[size_n : " << ref.size_n << "], [n : " << lc_n << " ]";

	free(lc_n);
	return os;
}

bint bint::factorial(const int n)
{
	bint s = n;
	int i_n = n;

	for(i_n -= 1; i_n > 1; i_n--) {
		s = s * i_n;
	}

	return s;
}

/* Addition Function 
 * when a + b;
 * @param n is a left operand (a)
 * @param nn is a right operand (b)
 */
bint bint::bint_add(const bint n, const bint nn)
{
	bint s;

	int i = 0, j;
	short size_n = 0, size_n_real = n.size_n;
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
		size_n_real = n.size_n;
	else if(j <= 0)
		size_n_real = nn.size_n;

	for(i = 0; i < size_n_real; i++) {
		if((*(n_p + i) + *(nn_p + i)) >= 10) {
			*(n_p + i) = (*(n_p + i) + *(nn_p + i)) - 10;
			*(ad_p + i) = *(n_p + i);

			for(j = i + 1; (*(n_p + j) + 1) >= 10; j++)
				*(n_p + j) = 0;
				
			if(j == n.size_n) {
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
	size_n += size_n_real;

	memcpy(s.n, ad_p, size_n);
	s.size_n = size_n_real;

	free(n_p);
	free(nn_p);
	free(ad_p);
	
	return s;
}

bint bint::bint_sub(const bint n, const bint nn)
{
	bint s;

	int i, j;
	short size_n, size_n_real = n.size_n;
	char *n_p, *nn_p, *sb_p;

	n_p = cmalloc(MAX_SIZE);
	nn_p = cmalloc(MAX_SIZE);
	sb_p = cmalloc(MAX_SIZE);


	memset(n_p, 0, MAX_SIZE);
	memset(nn_p, 0, MAX_SIZE);
	memset(sb_p, 0, MAX_SIZE);

	memcpy(n_p, n.n, n.size_n);
	memcpy(nn_p, nn.n, nn.size_n);

	for(i = 0; i < size_n_real; i++) {
		if((*(n_p + i) - *(nn_p + i)) < 0) {
			*(n_p + i) = (10 + *(n_p + i)) - *(nn_p + i);
			*(sb_p + i) = *(n_p + i);

			for(j = i + 1; ((j < n.size_n) && ((*(n_p + i) - 1) < 0)); j++)
				*(n_p + i) = 9;

			if(j == n.size_n) {
				(*(n_p + j))--;
				size_n--;

				*(sb_p + j) = *(n_p + j);
			} else
				(*(n_p + j))--;
		} else
			*(sb_p + i) = *(n_p + i) - *(nn_p + i);
	}
	size_n += size_n_real;

	s.size_n = size_n;
	memcpy(s.n, sb_p, size_n);

	free(n_p);
	free(nn_p);
	free(sb_p);
		
	return s;
}

bint bint::bint_mul(const bint n, const bint nn)
{
	bint s, ml_bi;
	int h, i, j, k, x = 0, y, z, val_t, size_n = n.size_n;
	char *n_p, *nn_p, *ml_p;

	n_p = cmalloc(MAX_SIZE);
	nn_p = cmalloc(MAX_SIZE);
	ml_p = cmalloc(MAX_SIZE);

	memset(n_p, 0, MAX_SIZE);
	memset(nn_p, 0, MAX_SIZE);
	memset(ml_p, 0, MAX_SIZE);

	memcpy(n_p, n.n, n.size_n);
	memcpy(nn_p, nn.n, nn.size_n);

	j = n.size_n - nn.size_n;
	if(j > 0) 
		size_n = n.size_n;
	else if(j < 0)
		size_n = nn.size_n;

	for(i = 0; i < size_n; i++) {
		for(j = 0; j < size_n; j++) {
			memset(ml_p, 0, MAX_SIZE);
			if((*(n_p + j) * *(nn_p + i)) >= 10) {
				val_t = *(n_p + j) * *(nn_p + i);
				y = itoa(val_t, ml_p) - 1;
				k = (i + j);

				h = *(ml_p + 0) - 0x30;
				*(ml_p + 0) = *(ml_p + 1) - 0x30;
				*(ml_p + 1) = h;
					
				for(x = y, h = k; h > 0; x++, h--) {
					*(ml_p + x + 1) = *(ml_p + x);
					*(ml_p + x) = *(ml_p + x - 1);
				}

				for(x = k - 1; x >= 0; x--)
					*(ml_p + x) = 0;

				ml_bi.size_n = k + 2;
				memcpy(ml_bi.n, ml_p, k + 2);

				s += ml_bi;
			} 
			else {
				val_t = *(n_p + j) * *(nn_p + i);
				y = itoa(val_t, ml_p) - 1;
				k = (i + j);

				*(ml_p + 0) = *(ml_p + 0) - 0x30;
				for(x = y, h = k; h > 0; x++, h--) {
					*(ml_p + x + 1) = *(ml_p + x);
					*(ml_p + x) = *(ml_p + x - 1);
				}

				for(x = k - 1; x >= 0; x--)
					*(ml_p + x) = 0;

				ml_bi.size_n = k + 2;
				memcpy(ml_bi.n, ml_p, k + 2);

				s += ml_bi;
			}
		}
	}

	free(n_p);
	free(nn_p);
	free(ml_p);
	
	return s;
}

bool bint::bint_biggger(const bint n, const bint nn)
{
	int i, j;

	j = n.size_n - nn.size_n;
	if(j > 0) return true;
	else if(j < 0) return false;
	else {
		for(i = n.size_n - 1; ((i >= 0) && (*(n.n + i) == *(nn.n + i))); i--);

		if(!i) return false;
		else if(*(n.n + i) > *(nn.n + i)) return true;
		else return false;
	}
}

bool bint::bint_smaller(const bint n, const bint nn)
{
	int i, j;
	j = nn.size_n - n.size_n;
	if(j > 0) return true;
	else if(j < 0) return false;
	else {
		for(i = n.size_n - 1; ((i >= 0) && (*(n.n + i) == *(nn.n + i))); i--);

		if(!i) return false;
		else if(*(n.n + i) < *(nn.n + i))
			return true;
		else return false;
	}
}

bint bint::bint_cleanup(const bint n)
{
	bint s = n;
	int i;

	for(i = s.size_n; *(s.n + i) == 0 && *(s.n + i - 1) == 0; i--) 
		s.size_n--;

	return s;
}
