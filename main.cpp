#include "myString.h"

void main() {
	myString a("abcd1234 523");
	myString e = "accd1234";
	char* c = "aa1234";
	char d = '3';
	char *f="123784";
	myString b;
	getline(std::cin, b, d);
	std::cout << b << std::endl;
	std::cout << b.myLength() << std::endl;
	std::cout << b.capacity() << std::endl;
	
	
	system("pause");
}




