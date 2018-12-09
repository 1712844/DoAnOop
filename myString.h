#ifndef __MYSTRING_H_
#define __MYSTRING_H_

#define RESERVED_SIZE 15

#include <iostream>

class myString {
private:
	char* mystr;
	size_t mylength;
	size_t mycapacity;
public:
	static const size_t npos = -1;

	myString();
	myString(const char *c);
	myString(const myString &str, size_t pos, size_t len = npos); //copy til the end if len = npos
	myString(const myString &str);
	myString(const char* s, size_t n);
	myString(size_t n, char c);
	~myString();
	myString& operator=(const myString &str);
	myString& operator=(const char* s);
	myString& operator=(char c);

	size_t myLength();
	size_t size() const;
	size_t max_size() const;
	void myResize(size_t n);
	void myResize(size_t n, char c);
	size_t capacity() const;
	void reserve(size_t n = 0);
	void clear();
	bool empty() const;
	void shrink_to_fit();

	char &operator[](size_t pos);
	const char &operator[](size_t pos) const;
	char &at(size_t pos);
	const char& at(size_t pos) const;
	char &back();
	const char& back() const;
	char &front();
	const char& front() const;

	myString& operator+=(const myString &str);
	myString& operator+=(const char* str);
	myString& operator+=(char c);
	myString& append(const myString &str);
	myString& append(const myString &str, size_t subpos, size_t sublen);
	myString& append(const char* s);
	myString& append(const char* s, size_t n);
	myString& append(size_t n, char c);
	void pushback(char c);
	myString& assign(const myString& str);
	myString& assign(const myString& str, size_t subpos, size_t sublen);
	myString& assign(const char* s);
	myString& assign(const char*s, size_t n);
	myString& assign(size_t n, char c);
	myString& insert(size_t pos, const myString& str);
	myString& insert(size_t pos, const myString& str, size_t subpos, size_t sublen);
	myString& insert(size_t pos, const char* s);
	myString& insert(size_t pos, const char* s, size_t n);
	myString& insert(size_t pos, char c, size_t n);
	myString& erase(size_t pos = 0, size_t len = npos);
	myString& replace(size_t pos, size_t len, const myString &str);
	myString& replace(size_t pos, size_t len, const myString &str, size_t subpos, size_t sublen);
	myString& replace(size_t pos, size_t len, const char* s);
	myString& replace(size_t pos, size_t len, const char*s, size_t n);
	myString& replace(size_t pos, size_t len, size_t n, char c);
	void swap(myString &str);
	void pop_back();
	const char* c_str() const;
	const char* data() const;
	size_t copy(char*s, size_t len, size_t pos = 0) const;
	size_t find(const myString& str, size_t pos = 0) const;
	size_t find(const char* s, size_t pos = 0) const;
	size_t find(const char* s, size_t pos, size_t n) const;
	size_t find(char c, size_t pos = 0) const;
	size_t rfind(const myString& str, size_t pos = npos) const;
	size_t rfind(const char* s, size_t pos = npos) const;
	size_t rfind(const char* s, size_t pos, size_t n) const;
	size_t rfind(char c, size_t pos = npos) const;
	size_t find_first_of(const myString& str, size_t pos = 0) const;
	size_t find_first_of(const char* s, size_t pos = 0) const;
	size_t find_first_of(const char* s, size_t pos, size_t n) const;
	size_t find_first_of(char c, size_t pos = 0) const;
	size_t find_last_of(const myString& str, size_t pos = npos) const;
	size_t find_last_of(const char* s, size_t pos = npos) const;
	size_t find_last_of(const char* s, size_t pos, size_t n) const;
	size_t find_last_of(char c, size_t pos = npos) const;
	size_t find_first_not_of(const myString& str, size_t pos = 0) const;
	size_t find_first_not_of(const char* s, size_t pos = 0) const;
	size_t find_first_not_of(const char* s, size_t pos, size_t n) const;
	size_t find_first_not_of(char c, size_t pos = 0) const;
	size_t find_last_not_of(const myString& str, size_t pos = npos) const;
	size_t find_last_not_of(const char* s, size_t pos = npos) const;
	size_t find_last_not_of(const char* s, size_t pos, size_t n) const;
	size_t find_last_not_of(char c, size_t pos = npos) const;
	myString substr(size_t pos = 0, size_t len = npos) const;
	int compare(const myString& str) const;
	int compare(size_t pos, size_t len, const myString& str) const;
	int compare(size_t pos, size_t len, const myString& str,size_t subpos, size_t sublen) const;
	int compare(const char* s) const;
	int compare(size_t pos, size_t len, const char* s) const;
	int compare(size_t pos, size_t len, const char* s, size_t n) const;

	friend myString operator+ (const myString & lhs, const myString & rhs);
	friend myString operator+ (const myString& lhs, const char*   rhs);
	friend myString operator+ (const char*   lhs, const myString& rhs);
	friend myString operator+ (const myString& lhs, char rhs);
	friend myString operator+ (char lhs, const myString& rhs);
	friend bool operator== (const myString& lhs, const myString& rhs);
	friend bool operator== (const char*   lhs, const myString& rhs);
	friend bool operator== (const myString& lhs, const char*   rhs);
	friend bool operator!= (const myString& lhs, const myString& rhs);
	friend bool operator!= (const char*   lhs, const myString& rhs);
	friend bool operator!= (const myString& lhs, const char*   rhs);
	friend bool operator<  (const myString& lhs, const myString& rhs);
	friend bool operator<  (const char*   lhs, const myString& rhs);
	friend bool operator<  (const myString& lhs, const char*   rhs);
	friend bool operator<= (const myString& lhs, const myString& rhs);
	friend bool operator<= (const char*   lhs, const myString& rhs);
	friend bool operator<= (const myString& lhs, const char*   rhs);
	friend bool operator>  (const myString& lhs, const myString& rhs);
	friend bool operator>  (const char*   lhs, const myString& rhs);
	friend bool operator>  (const myString& lhs, const char*   rhs);
	friend bool operator>= (const myString& lhs, const myString& rhs);
	friend bool operator>= (const char*   lhs, const myString& rhs);
	friend bool operator>= (const myString& lhs, const char*   rhs);
	friend void swap(myString& x, myString& y);
	friend std::ostream& operator<< (std::ostream& output, const myString& str);
	friend std::istream& operator>> (std::istream& is, myString& str);
	friend std::istream& getline(std::istream& is, myString& str, char delim);
	friend std::istream& getline(std::istream& is, myString& str);
};



size_t Length(const char* c);
#endif
