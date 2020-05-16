#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <iterator>

using namespace std;

int main() {
	char test = '0';
	int ascii = (int) test;
	cout << ascii << endl;
	test = toupper(test);
	ascii = (int) test;
	cout << ascii << endl;
	return 0;

}
