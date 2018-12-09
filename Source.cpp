#include "myString.h"

myString::myString()
{
	this->mystr = new char[RESERVED_SIZE +1];
	this->mystr[0] = '\0';
	this->mylength = 0;
	this->mycapacity = RESERVED_SIZE +1;
}

myString::myString(const char *c)
{
	this->mylength = Length(c);
	if (this->mylength <= RESERVED_SIZE) {
		this->mycapacity = RESERVED_SIZE + 1;
	}
	else {
		this->mycapacity = (this->mylength / RESERVED_SIZE)*RESERVED_SIZE + RESERVED_SIZE + 1;
	}
	this->mystr = new char[this->mycapacity];
	for (size_t i = 0; i < this->mylength; i++) {
		this->mystr[i] = c[i];
	}
	this->mystr[this->mylength] = '\0';
}

myString::myString(const myString &str, size_t pos, size_t len)
{
	if (pos >= 0 && pos <= str.mylength) {
		if (len != (pow(2, 32) - 1)) {
			if (len <= (str.mylength - pos) && pos !=str.mylength) {
				this->mylength = len;
			}
			else if (len > str.mylength - pos) {
				this->mylength = str.mylength - pos;
			}
			else if (pos == str.mylength) {
				this->mylength = 0;
			}
			if (this->mylength <= RESERVED_SIZE) {
				this->mycapacity = RESERVED_SIZE + 1;
			}
			else {
				this->mycapacity = (this->mylength / RESERVED_SIZE)*RESERVED_SIZE + RESERVED_SIZE + 1;
			}
			this->mystr = new char[this->mycapacity];
			for (size_t i = 0; i < this->mylength; i++) {
				this->mystr[i] = str.mystr[pos+i];
			}
			this->mystr[this->mylength] = '\0';
		}
		else {
			if ((str.mylength - pos) <= RESERVED_SIZE) {
				this->mycapacity = RESERVED_SIZE + 1;
			}
			else {
				this->mycapacity = ((str.mylength - pos) / RESERVED_SIZE)*RESERVED_SIZE + RESERVED_SIZE + 1;
			}
			this->mylength = str.mylength - pos;
			this->mystr = new char[this->mycapacity];
			for (size_t i = 0; i < this->mylength; i++) {
				this->mystr[i] = str.mystr[pos+ i];
			}
			this->mystr[this->mylength] = '\0';
		}
	}
	else {
		throw;
	}
}

myString::myString(const myString & str)
{
	this->mylength = str.mylength;
	if (this->mylength <= RESERVED_SIZE) {
		this->mycapacity = RESERVED_SIZE + 1;
	}
	else {
		this->mycapacity = (this->mylength / RESERVED_SIZE)*RESERVED_SIZE + RESERVED_SIZE + 1;
	}
	this->mystr = new char[this->mycapacity];
	for (size_t i = 0; i < this->mylength; i++) {
		this->mystr[i] = str.mystr[i];
	}
	this->mystr[this->mylength] = '\0';
}

myString::myString(const char * s, size_t n)
{
	if (n <= Length(s)) {
		this->mylength = n;
	}
	else {
		this->mylength = Length(s);
	}
	if (this->mylength <= RESERVED_SIZE) {
		this->mycapacity = RESERVED_SIZE + 1;
	}
	else {
		this->mycapacity = (this->mylength / RESERVED_SIZE)*RESERVED_SIZE + RESERVED_SIZE + 1;
	}
	this->mystr = new char[this->mycapacity + 1];
	for (size_t i = 0; i < this->mylength; i++) {
		this->mystr[i] = s[i];
	}
	this->mystr[this->mylength] = '\0';
}

myString::myString(size_t n, char c)
{
	this->mylength = n;
	if (this->mylength <= RESERVED_SIZE) {
		this->mycapacity = RESERVED_SIZE + 1;
	}
	else {
		this->mycapacity = (this->mylength / RESERVED_SIZE)*RESERVED_SIZE + RESERVED_SIZE + 1;
	}
	this->mystr = new char[this->mycapacity + 1];
	for (size_t i = 0; i < this->mylength; i++) {
		this->mystr[i] = c;
	}
	this->mystr[this->mylength] = '\0';
}

myString::~myString()
{
	delete[] this->mystr;
	this->mystr = NULL;
	this->mylength = 0;
	this->mycapacity = 0;
}

myString& myString::operator=(const myString & str)
{
	this->mylength = str.mylength;
	this->mystr = new char[this->mylength + 1];
	size_t i = 0;
	for (i; i < this->mylength; i++) {
		this->mystr[i] = str.mystr[i];
	}
	this->mystr[this->mylength] = '\0';
	return *this;
}

myString & myString::operator=(const char * s)
{
	this->mylength = Length(s);
	this->mystr = new char[this->mylength + 1];
	size_t i = 0;
	for (i; i < this->mylength; i++) {
		this->mystr[i] = s[i];
	}
	this->mystr[i] = '\0';
	return *this;
}

myString & myString::operator=(char c)
{
	this->mylength = 1;
	this->mystr = new char[2];
	this->mystr[0] = c;
	this->mystr[1] = '\0';
	return *this;
}

size_t myString::myLength()
{
	return this->mylength;
}

size_t myString::size() const
{
	return this->mylength;
}

size_t myString::max_size() const
{
	return sizeof(size_t) - this->mylength;
}


void myString::myResize(size_t n)
{
	if (n > this->mylength) {
		if (n < this->mycapacity) {
			for (size_t i = this->mylength; i < n; i++) {
				this->mystr[i] = 0;
			}
			this->mystr[n] = '\0';
		}
		else {
			this->mycapacity = (n / (RESERVED_SIZE))*(RESERVED_SIZE)* RESERVED_SIZE + 1;
			char* temp = new char[this->mycapacity];
			for (size_t i = 0; i < n; i++) {
				temp[i] = this->mystr[i];
			}
			for (size_t i = this->mylength; i < n; i++) {
				temp[i] = 0;
			}
			temp[n] = '\0';
			delete[] this->mystr;
			this->mystr = temp;
		}
	}
	else if (n < this->mylength&&n >= 0) {
		this->mystr[this->mylength] = 0;
		this->mystr[n] = '\0';
		this->mylength = n;
	}
	else {
		throw;
	}
}

void myString::myResize(size_t n, char c)
{
	if (n > this->mylength) {
		if (n < this->mycapacity) {
			for (size_t i = this->mylength;i<n; i++) {
				this->mystr[i] = c;
			}
			this->mystr[n] = '\0';
		}
		else {
			this->mycapacity = (n / (RESERVED_SIZE))*(RESERVED_SIZE)* RESERVED_SIZE + 1;
			char* temp = new char[this->mycapacity];
			for (size_t i = 0; i < n; i++) {
				temp[i] = this->mystr[i];
			}
			for (size_t i = this->mylength; i < n; i++) {
				temp[i] = c;
			}
			temp[n] = '\0';
			delete[] this->mystr;
			this->mystr = temp;
		}
	}
	else if (n < this->mylength&&n >= 0) {
		this->mystr[this->mylength] = 0;
		this->mystr[n] = '\0';
		this->mylength = n;
	}
	else {
		throw;
	}
}

size_t myString::capacity() const
{
	return this->mycapacity-1;
}

void myString::reserve(size_t n)
{
	if (n >= this->mylength) {
		this->mycapacity = n;
		char* temp = new char[n + 1];
		for (size_t i = 0; i < this->mylength; i++) {
			temp[i] = this->mystr[i];
		}
		temp[this->mylength] = '\0';
		delete[] this->mystr;
		this->mystr = temp;
	}
	else {
		throw;
	}
}

void myString::clear()
{
	if (this->mystr != NULL) {
		this->~myString();
	}
}

bool myString::empty() const
{
	if (this->mylength == 0) {
		return true;
	}
	else {
		return false;
	}
}

void myString::shrink_to_fit()
{
	this->mycapacity = this->mylength;
	char* temp = new char[this->mylength + 1];
	for (size_t i = 0; i < this->mylength; i++) {
		temp[i] = this->mystr[i];
	}
	temp[this->mylength] = '\0';
	delete[] this->mystr;
	this->mystr = temp;
}

char & myString::operator[](size_t pos)
{
	char* a = new char;
	a = '\0';
	if (pos >= this->myLength() || pos < 0) {
		return *a;
	}
	else {
		return this->mystr[pos];
	}
}

const char & myString::operator[](size_t pos) const
{
	if (pos >= 0 || pos < Length(this->mystr)) {
		return this->mystr[pos];
	}
	else {
		throw;
	}
}

char & myString::at(size_t pos)
{
	char* a = new char;
	a = '\0';
	if (pos >= this->myLength() || pos < 0) {
		return *a;
	}
	else {
		return this->mystr[pos];
	}
}

const char & myString::at(size_t pos) const
{
	if (pos >= 0 || pos < Length(this->mystr)) {
		return this->mystr[pos];
	}
	else {
		throw;
	}
}

char & myString::back()
{
	char* a = new char;
	a = '\0';
	if (this->mystr == NULL) {
		return *a;
	}
	return this->mystr[this->myLength()-1];
}

const char & myString::back() const
{
	if (this->mystr != NULL) {
		return this->mystr[Length(this->mystr) - 1];
	}
	else {
		throw;
	}
}

char & myString::front()
{
	char* a = new char;
	a = '\0';
	if (this->mystr == NULL) {
		return *a;
	}
	return this->mystr[0];
}

const char & myString::front() const
{
	if (this->mystr != NULL) {
		return this->mystr[0];
	}
	else {
		throw;
	}
}

myString& myString::operator+=(const myString & str){
	if (str.mylength < this->mycapacity - this->mylength) {
		size_t j = 0;
		for (size_t i = this->mylength; i < this->mylength + str.mylength; i++) {
			this->mystr[i] = str.mystr[j];
			j++;
		}
		this->mystr[this->mylength + str.mylength] = '\0';
		this->mylength += str.mylength;
	}
	else {
		size_t n = this->mylength + str.mylength;
		size_t newcap=((int)(n / RESERVED_SIZE)) *RESERVED_SIZE + RESERVED_SIZE + 1;
		char *temp = new char[newcap];
		for (size_t i = 0; i < this->mylength; i++) {
			temp[i] = this->mystr[i];
		}
		size_t j = 0;
		for (size_t i = this->mylength; i < n; i++) {
			temp[i] = str.mystr[j];
			j++;
		}
		temp[n] = '\0';
		this->mylength = n;
		this->mycapacity = newcap;
		delete[] this->mystr;
		this->mystr = temp;
	}
	return *this;
}

myString& myString::operator+=(const char * s)
{
	if (Length(s) < this->mycapacity - this->mylength) {
		size_t j = 0;
		for (size_t i = this->mylength; i < this->mylength + Length(s); i++) {
			this->mystr[i] = s[j];
			j++;
		}
		this->mystr[this->mylength + Length(s)] = '\0';
		this->mylength += Length(s);
	}
	else {
		size_t n = this->mylength + Length(s);
		size_t newcap = ((int)(n / RESERVED_SIZE)) *RESERVED_SIZE + RESERVED_SIZE + 1;
		char *temp = new char[newcap];
		size_t j = 0;
		for (size_t i = 0; i < this->mylength; i++) {
			temp[i] = this->mystr[i];
		}
		for (size_t i = this->mylength; i < n; i++) {
			temp[i] = s[j];
			j++;
		}
		temp[n] = '\0';
		this->mylength = n;
		this->mycapacity = newcap;
		delete[] this->mystr;
		this->mystr = temp;
	}
	return *this;
}

myString& myString::operator+=(char c)
{
	if (this->mylength + 1 >= this->mycapacity) {
		this->mycapacity += (RESERVED_SIZE + 1);	
	}
	this->mystr[this->mylength] = c;
	this->mylength += 1;
	this->mystr[this->mylength] = '\0';
	return *this;
}

myString& myString::append(const myString &str)
{
	return this->operator += (str);
}

myString& myString::append(const myString & str, size_t subpos, size_t sublen)
{
	if (subpos < Length(str.mystr)) {
		char* temp;
		if (sublen >= 0 && (sublen < str.mylength - subpos)) {
			temp = new char[sublen + 1];
			for (size_t i = 0; i < sublen; i++) {
				temp[i] = str[subpos+i];
			}
			temp[sublen] = '\0';
		}
		else {
			temp = new char[str.mylength - subpos + 1];
			for (size_t i=0; i <= str.mylength-subpos+1; i++) {
				temp[i] = str[subpos +i];
			}
			temp[str.mylength - subpos] = '\0';
		}
		this->operator+=(temp);
		if (temp != NULL) {
			delete[] temp;
		}
		return *this;
	}
	else {
		throw;
	}
}

myString & myString::append(const char * s)
{
	return this->operator+=(s);
}

myString & myString::append(const char * s, size_t n)
{
	if (n < Length(s) && n>0) {
		char* temp;
		temp = new char[n + 1];
		for (size_t i = 0; i < n; i++) {
			temp[i] = s[i];
		}
		temp[n] = '\0';
		this->operator +=(temp);
		if (temp != NULL) {
			delete[] temp;
		}
		return *this;
	}
	else {
		throw;
	}
}

myString & myString::append(size_t n, char c)
{
	if (n > 0) {
		char *temp = new char[n+1];
		for (size_t i = 0; i < n; i++) {
			temp[i] = c;
		}
		temp[n] = '\0';
		this->operator+=(temp);
		if (temp != NULL) {
			delete[] temp;
		}
		return *this;
	}
	else {
		throw;
	}
}

void myString::pushback(char c)
{
	this->operator+=(c);
}

myString & myString::assign(const myString & str)
{
	if (this->mylength == 0) {
		return this->append(str);
	}
	else {
		this->mystr[this->mylength] = 0;
		this->mylength = 0;
		for (size_t i = 0; i < Length(str.mystr); i++) {
			this->mystr[i] = str.mystr[i];
		}
		this->mystr[Length(str.mystr)] = '\0';
		return *this;
	}
}

myString & myString::assign(const myString & str, size_t subpos, size_t sublen)
{
	if (this->mylength == 0) {
		return this->append(str, subpos, sublen);
	}
	else {
		this->mystr = '\0';
		this->mylength = 0;
		this->append(str, subpos, sublen);
		this->mystr[sublen]='\0';
		return *this;
	}
}

myString & myString::assign(const char * s)
{
	if (this->mylength == 0) {
		return this->append(s);
	}
	else {
		this->mystr = '\0';
		this->mylength = 0;
		this->append(s);
		this->mystr[Length(s)] = '\0';
		return *this;
	}
}

myString & myString::assign(const char * s, size_t n)
{
	if (this->mylength == 0) {
		return this->append(s,n);
	}
	else {
		this->mystr = '\0';
		this->mylength = 0;
		this->append(s,n);
		this->mystr[n] = '\0';
		return *this;
	}
}

myString & myString::assign(size_t n, char c)
{
	if (this->mylength == 0) {
		return this->append(n,c);
	}
	else {
		this->mystr = '\0';
		this->mylength = 0;
		this->append(n, c);
		this->mystr[n] = '\0';
		return *this;
	}
}

myString & myString::insert(size_t pos, const myString & str)
{
	if (pos >= 0 && pos < this->mylength) {
		myString temp(*this, pos);
		this->mystr[pos] = '\0';
		this->mylength = pos;
		this->append(str);
		this->append(temp);
		return *this;
	}
	else {
		throw;
	}
}

myString & myString::insert(size_t pos, const myString & str, size_t subpos, size_t sublen)
{
	if (pos >= 0 && pos < this->mylength && subpos >= 0 && subpos < str.mylength) {
		if (sublen <= str.mylength - subpos) {
			myString hold(*this, pos);
			myString temp(str, subpos, sublen);
			this->mystr[pos] = '\0';
			this->mylength = pos;
			this->append(temp);
			this->append(hold);
			return *this;
		}
		else {
			this->insert(pos, str);
		}
		return *this;
	}
	else {
		throw;
	}
}

myString & myString::insert(size_t pos, const char * s)
{
	if (pos >= 0 && pos < this->mylength) {
		myString temp(*this, pos);
		this->mystr[pos] = '\0';
		this->mylength = pos;
		this->append(s);
		this->append(temp);
		return *this;
	}
	else {
		throw;
	}
}

myString & myString::insert(size_t pos, const char * s, size_t n)
{
	if (pos >= 0 && pos < this->mylength && n>=0) {
		if (n <= Length(s) ) {
			myString temp(*this, pos);
			myString hold(s, n);
			this->mystr[pos] = '\0';
			this->mylength = pos;
			this->append(hold);
			this->append(temp);
			return *this;
		}
		else {
			this->insert(pos, s);
		}
	}
	else {
		throw;
	}
}

myString & myString::insert(size_t pos, char c, size_t n)
{
	if (pos >= 0 && pos < this->mylength && n>=0) {
		myString temp(*this, pos);
		this->mystr[pos] = '\0';
		this->mylength = pos;
		this->append(n,c);
		this->append(temp);
		return *this;
	}
	else {
		throw;
	}
}

myString & myString::erase(size_t pos, size_t len)
{
	if (pos == 0) {
		this->~myString();
	}
	else {
		if (pos < this->mylength) {
			if (len <= (this->mylength - pos) && len >= 0) {
				myString temp(*this, pos + len);
				this->mystr[pos] = 0;
				this->mylength = pos;
				this->append(temp);
				return *this;
			}
			else {
				this->mystr[pos] = 0;
				this->mylength = pos;
				return *this;
			}
		}
		else {
			throw;
		}
	}
}

myString & myString::replace(size_t pos, size_t len, const myString & str)
{
	if (pos >= 0 && pos <= this->mylength && len >= 0) {
		if (len <= this->mylength - pos) {
			this->erase(pos, len);
		}
		else {
			this->erase(pos);
		}
		this->insert(pos, str);
		return *this;
	}
	else {
		throw;
	}
}

myString & myString::replace(size_t pos, size_t len, const myString & str, size_t subpos, size_t sublen)
{
	if (pos >= 0 && pos <= this->mylength && len >= 0) {
		if (len <= this->mylength - pos) {
			this->erase(pos, len);
		}
		else {
			this->erase(pos);
		}
	}
	else {
		throw;
	}
	if (subpos >= 0 && sublen <= str.mylength && sublen >= 0) {
		if (sublen <= str.mylength - subpos) {
			myString temp(str, subpos, sublen);	
		}
		else {
			myString temp(str, subpos);
		}
		this->insert(pos, str);
		return *this;
	}
	else {
		throw;
	}
}

myString & myString::replace(size_t pos, size_t len, const char * s)
{
	if (pos >= 0 && pos <= this->mylength && len >= 0) {
		if (len <= this->mylength - pos) {
			this->erase(pos, len);
		}
		else {
			this->erase(pos);
		}
		this->insert(pos, s);
		return *this;
	}
	else {
		throw;
	}
}

myString & myString::replace(size_t pos, size_t len, const char * s, size_t n)
{
	if (pos >= 0 && pos <= this->mylength && len >= 0) {
		if (len <= this->mylength - pos) {
			this->erase(pos, len);
		}
		else {
			this->erase(pos);
		}
	}
	else {
		throw;
	}
	this->insert(pos, s, n);
}

myString & myString::replace(size_t pos, size_t len, size_t n, char c)
{
	if (pos >= 0 && pos <= this->mylength && len >= 0) {
		if (len <= this->mylength - pos) {
			this->erase(pos, len);
		}
		else {
			this->erase(pos);
		}
	}
	else {
		throw;
	}
	this->insert(pos, c, n);
}

void myString::swap(myString & str)
{
	size_t tempSize = this->mylength;
	size_t tempCap = this->mycapacity;
	myString temp = *this;
	*this = str;
	this->mylength = str.mylength;
	this->mycapacity = str.mycapacity;
	str = temp;
	str.mylength = tempSize;
	str.mycapacity = tempCap;
}

void myString::pop_back()
{
	if (this->mylength > 0) {
		this->mystr[this->mylength - 1] = '\0';
		this->mylength--;
	}
	else {
		throw;
	}
}

const char * myString::c_str() const
{
	return this->mystr;
}

const char * myString::data() const
{
	return this->mystr;
}

size_t myString::copy(char * s, size_t len, size_t pos) const
{
	if (pos < this->mylength) {
		size_t templen;
		if (len <= this->mylength - pos) {
			templen = len;
		}
		else {
			templen = this->mylength - pos;
		 }
		for (size_t i = 0; i < templen; i++) {
			s[i] = this->mystr[pos+i];
		}
		s[templen] = '\0';
		return templen;
	}
	else {
		throw;
	}
}

size_t myString::find(const myString & str, size_t pos) const
{
	if (pos <= this->mylength && str.mylength <= this->mylength-pos) {
		size_t temp = 0;
		size_t step = 0;
		size_t count = 0;
		for (size_t i = pos; i <= this->mylength - str.mylength; i++) {
			if (str.mystr[count] == this->mystr[pos+step]) {
				count++;
			}
			else {
				count=0;
			}
			if (count == str.mylength) {
				temp = i - count;
				return temp;
			}
			step++;
		}
		if (temp == 0) {
			return npos;
		}
	}
	else {
		throw;
	}
}

size_t myString::find(const char * s, size_t pos) const
{
	myString temp(s);
	return this->find(temp, pos);
}

size_t myString::find(const char * s, size_t pos, size_t n) const
{
	if (n >= 0 && pos<=this->mylength && pos>=0) {
		myString temp(s, n);
		return this->find(temp, pos)+1;
	}
	else if (n >= Length(s)) {
		myString temp(s);
		return this->find(temp, pos) + 1;
	}
	else {
		throw;
	}
}

size_t myString::find(char c, size_t pos) const
{
	myString temp(1, c);
	if (pos <= this->mylength && pos >= 0) {
		return this->find(temp, pos)+1;
	}
	else if (this->find(temp, pos) == npos) {
		return npos;
	}
	else {
		throw;
	}
}

size_t myString::rfind(const myString & str, size_t pos) const
{
	if (pos <= this->mylength && str.mylength <= this->mylength - pos) {
		size_t temp = 0;
		size_t step = 0;
		size_t count = str.mylength-1;
		for (size_t i = pos; i >=0; i--) {
			if (str.mystr[count] == this->mystr[i]) {
				count--;
			}
			else {
				count = str.mylength - 1;
			}
			if (count == -1) {
				temp = i;
				return temp;
			}
			step++;
		}
		if (temp == 0) {
			return npos;
		}
	}
	else {
		throw;
	}
}

size_t myString::rfind(const char * s, size_t pos) const
{
	myString temp(s);
	return this->rfind(temp, pos);
}

size_t myString::rfind(const char * s, size_t pos, size_t n) const
{
	if (n >= 0 && pos <= this->mylength && pos >= 0) {
		myString temp(s, n);
		return this->rfind(temp, pos);
	}
	else if (n >= Length(s)) {
		myString temp(s);
		return this->rfind(temp, pos);
	}
	else {
		throw;
	}
}

size_t myString::rfind(char c, size_t pos) const
{
	if (pos <= this->mylength && pos >= 0) {
		myString temp(1, c);
		return this->rfind(temp, pos);
	}
	else {
		throw;
	}
}

size_t myString::find_first_of(const myString & str, size_t pos) const
{
	if (pos >= 0 && pos <= this->mylength) {
		size_t temp = 0;
		for (size_t i = pos; i < this->mylength; i++) {
			for (size_t j = 0; j < str.mylength; j++) {
				if (this->mystr[i] == str.mystr[j]) {
					temp++;
					return i;
				}
			}
		}
		if (temp == 0) {
			return npos;
		}
	}
	else {
		throw;
	}
}

size_t myString::find_first_of(const char * s, size_t pos) const
{
	myString temp(s);
	return this->find_first_of(temp, pos);
}

size_t myString::find_first_of(const char * s, size_t pos, size_t n) const
{
	if (n >= 0 && pos <= this->mylength && pos >= 0) {
		myString temp(s, n);
		return this->find_first_of(temp, pos);
	}
	else if (n >= Length(s)) {
		myString temp(s);
		return this->find_first_of(temp, pos);
	}
	else {
		throw;
	}
}

size_t myString::find_first_of(char c, size_t pos) const
{
	if (pos <= this->mylength && pos >= 0) {
		myString temp(1, c);
		return this->find_first_of(temp, pos) + 1;
	}
	else {
		throw;
	}
}

size_t myString::find_last_of(const myString & str, size_t pos) const
{
	if (pos >= 0 && pos <= this->mylength) {
		size_t temp = 0;
		for (size_t i = pos; i >=0; i--) {
			for (size_t j = 0; j < str.mylength; j++) {
				if (this->mystr[i] == str.mystr[j]) {
					temp++;
					return i;
				}
			}
		}
		if (temp == 0) {
			return npos;
		}
	}
	else {
		throw;
	}
}

size_t myString::find_last_of(const char * s, size_t pos) const
{
	myString temp(s);
	return this->find_last_of(temp, pos);
}

size_t myString::find_last_of(const char * s, size_t pos, size_t n) const
{
	if (n >= 0 && pos <= this->mylength && pos >= 0) {
		myString temp(s, n);
		return this->find_last_of(temp, pos)+1;
	}
	else if (n >= Length(s)) {
		myString temp(s);
		return this->find_last_of(temp, pos)+1;
	}
	else {
		throw;
	}
}

size_t myString::find_last_of(char c, size_t pos) const
{
	if (pos <= this->mylength && pos >= 0) {
		myString temp(1, c);
		return this->find_last_of(temp, pos) + 1;
	}
	else {
		throw;
	}
}

size_t myString::find_first_not_of(const myString & str, size_t pos) const
{
	if (pos >= 0 && pos <= this->mylength) {
		size_t temp = 0;
		for (size_t i = pos; i < this->mylength; i++) {
			for (size_t j = 0; j < str.mylength; j++) {
				if (this->mystr[i] != str.mystr[j]) {
					temp++;
				}
			}
			if (temp == str.mylength) {
				return i;
			}
			else {
				temp = 0;
			}
		}
		if (temp == 0) {
			return npos;
		}
	}
	else {
		throw;
	}
}

size_t myString::find_first_not_of(const char * s, size_t pos) const
{
	myString temp(s);
	return this->find_first_not_of(temp, pos);
}

size_t myString::find_first_not_of(const char * s, size_t pos, size_t n) const
{
	if (n >= 0 && pos <= this->mylength && pos >= 0) {
		myString temp(s, n);
		return this->find_first_not_of(temp, pos);
	}
	else if (n >= Length(s)) {
		myString temp(s);
		return this->find_first_not_of(temp, pos);
	}
	else {
		throw;
	}
}

size_t myString::find_first_not_of(char c, size_t pos) const
{
	if (pos <= this->mylength && pos >= 0) {
		myString temp(1, c);
		return this->find_first_not_of(temp, pos);
	}
	else {
		throw;
	}
}

size_t myString::find_last_not_of(const myString & str, size_t pos) const
{
	if (pos >= 0 && pos <= this->mylength) {
		size_t temp = 0;
		for (size_t i = pos; i >=0; i--) {
			for (size_t j = 0; j < str.mylength; j++) {
				if (this->mystr[i] != str.mystr[j]) {
					temp++;
				}
			}
			if (temp == str.mylength) {
				return i;
			}
			else {
				temp = 0;
			}
		}
		if (temp == 0) {
			return npos;
		}
	}
	else {
		throw;
	}
}

size_t myString::find_last_not_of(const char * s, size_t pos) const
{
	myString temp(s);
	return this->find_last_not_of(temp, pos);
}

size_t myString::find_last_not_of(const char * s, size_t pos, size_t n) const
{
	if (n >= 0 && pos <= this->mylength && pos >= 0) {
		myString temp(s, n);
		return this->find_last_not_of(temp, pos);
	}
	else if (n >= Length(s)) {
		myString temp(s);
		return this->find_last_not_of(temp, pos);
	}
	else {
		throw;
	}
}

size_t myString::find_last_not_of(char c, size_t pos) const
{
	if (pos <= this->mylength && pos >= 0) {
		myString temp(1, c);
		return this->find_last_not_of(temp, pos);
	}
	else {
		throw;
	}
}

myString myString::substr(size_t pos, size_t len) const
{
	return myString(*this, pos, len);
}

int myString::compare(const myString & str) const
{
	size_t temp = this->mylength < str.mylength ? this->mylength : str.mylength;
	for (size_t i = 0; i < temp; i++) {
		if (this->mystr[i] < str.mystr[i])
			return -1;
		else if (this->mystr[i] > str.mystr[i]) {
			return 1;
		}
	}
	if (this->mylength > str.mylength) {
		return 1;
	}
	else if(this->mylength<str.mylength){
		return -1;
	}
	else {
		return 0;
	}
}

int myString::compare(size_t pos, size_t len, const myString & str) const
{
	myString temp(*this, pos, len);
	return temp.compare(str);
}

int myString::compare(size_t pos, size_t len, const myString & str, size_t subpos, size_t sublen) const
{
	myString temp(*this, pos, len);
	myString hold(str, subpos, sublen);
	return temp.compare(hold);
}

int myString::compare(const char * s) const
{
	myString temp(s);
	return this->compare(temp);
}

int myString::compare(size_t pos, size_t len, const char * s) const
{
	myString temp(*this, pos, len);
	return temp.compare(s);
}

int myString::compare(size_t pos, size_t len, const char * s, size_t n) const
{
	myString temp(*this, pos, len);
	if (n <= Length(s) && n >= 0) {
		myString hold(s, n);
		return temp.compare(hold);
	}
	else if (n > Length(s)) {
		myString hold(s);
		return temp.compare(hold);
	}
	else {
		throw;
	}
}

myString operator+(const myString & lhs, const myString & rhs)
{
	myString temp(lhs);
	return temp.append(rhs);
}

myString operator+(const myString & lhs, const char * rhs)
{
	myString temp(lhs);
	return temp.append(rhs);
}

myString operator+(const char * lhs, const myString & rhs)
{
	myString temp(lhs);
	return temp.append(rhs);
}

myString operator+(const myString & lhs, char rhs)
{
	myString temp(lhs);
	return temp.append(1,rhs);
}

myString operator+(char lhs, const myString & rhs)
{
	myString temp(1, lhs);
	return temp.append(rhs);
}

bool operator==(const myString & lhs, const myString & rhs)
{
	if (lhs.compare(rhs) != 0) {
		return false;
	}
	else {
		return true;
	}
}

bool operator==(const char * lhs, const myString & rhs)
{
	myString temp(lhs);
	if (temp.compare(rhs) != 0) {
		return false;
	}
	else {
		return true;
	}
}

bool operator==(const myString & lhs, const char * rhs)
{
	myString temp(rhs);
	if (lhs.compare(temp) != 0) {
		return false;
	}
	else {
		return true;
	}
}

bool operator!=(const myString & lhs, const myString & rhs)
{
	myString temp(lhs);
	if (temp.compare(rhs) != 0) {
		return true;
	}
	else {
		return false;
	}
}

bool operator!=(const char * lhs, const myString & rhs)
{
	myString temp(lhs);
	if (temp.compare(rhs) != 0) {
		return true;
	}
	else {
		return false;
	}
}

bool operator!=(const myString & lhs, const char * rhs)
{
	myString temp(rhs);
	if (lhs.compare(temp) != 0) {
		return true;
	}
	else {
		return false;
	}
}

bool operator<(const myString & lhs, const myString & rhs)
{
	myString temp(lhs);
	if (temp.compare(rhs) == -1) {
		return true;
	}
	else {
		return false;
	}
}

bool operator<(const char * lhs, const myString & rhs)
{
	myString temp(lhs);
	if (temp.compare(rhs) == -1) {
		return true;
	}
	else {
		return false;
	}
}

bool operator<(const myString & lhs, const char * rhs)
{
	myString temp(rhs);
	if (lhs.compare(rhs) != 0) {
		return true;
	}
	else {
		return false;
	}
}

bool operator<=(const myString & lhs, const myString & rhs)
{
	if (lhs.compare(rhs) == -1 || lhs.compare(rhs) == 0) {
		return true;
	}
	else {
		return false;
	}
}

bool operator<=(const char * lhs, const myString & rhs)
{
	myString temp(lhs);
	if (temp.compare(rhs) == -1 || temp.compare(rhs) == 0) {
		return true;
	}
	else {
		return false;
	}
}

bool operator<=(const myString & lhs, const char * rhs)
{
	myString temp(rhs);
	if (lhs.compare(temp) == -1 || lhs.compare(temp) == 0) {
		return true;
	}
	else {
		return false;
	}
}

bool operator>(const myString & lhs, const myString & rhs)
{
	myString temp(lhs);
	if (temp.compare(rhs) == 1) {
		return true;
	}
	else {
		return false;
	}
}

bool operator>(const char * lhs, const myString & rhs)
{
	myString temp(lhs);
	if (temp.compare(rhs) == 1) {
		return true;
	}
	else {
		return false;
	}
}

bool operator>(const myString & lhs, const char * rhs)
{
	myString temp(rhs);
	if (lhs.compare(rhs) == 1) {
		return true;
	}
	else {
		return false;
	}
}

bool operator>=(const myString & lhs, const myString & rhs)
{
	if (lhs.compare(rhs) == 1 || lhs.compare(rhs) == 0) {
		return true;
	}
	else {
		return false;
	}
}

bool operator>=(const char * lhs, const myString & rhs)
{
	myString temp(lhs);
	if (temp.compare(rhs) == 1 || temp.compare(rhs) == 0) {
		return true;
	}
	else {
		return false;
	}
}

bool operator>=(const myString & lhs, const char * rhs)
{
	myString temp(rhs);
	if (lhs.compare(temp) == 1 || lhs.compare(temp) == 0) {
		return true;
	}
	else {
		return false;
	}
}

void swap(myString & x, myString & y)
{
	myString temp(x);
	x = y;
	y = temp;
}

std::ostream & operator<<(std::ostream & output, const myString & str)
{
	output << str.mystr;
	return output;
}

std::istream & operator>>(std::istream & is, myString & str)
{
	char* temp = new char[255];
	is >> temp;
	str.assign(temp);
	return is;
}

std::istream & getline(std::istream & is, myString & str, char delim)
{
	
	char* temp = new char[256];
	is.get(temp, 256, delim);
	str.append(temp);
	return is;
}

std::istream & getline(std::istream & is, myString & str)
{
	char* temp = new char[256];
	is.get(temp, 256);
	str.append(temp);
	return is;
}

size_t Length(const char* c) {
	size_t i = 0;
	if (c == NULL)
		return i;
	else {
		while (c[i] != NULL) {
			i++;
		}
	}
	return i;
}
