/**
 *
 *	@file: RGBconv.cpp
 *	@desc: Converts a hexadecimal RGB value into decimal form.
 *	@author: Hermione M.
 *	@date: 15 May 2020
 *
 *	This file is licensed under the BSD License: enter requisite licensing bullshit here.
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <iterator>

using namespace std;

int main() {
	//cout << "Testing to make sure I haven't gone senile.\n";
	
	string colourVal[6];
	string a;
	
	cout << "Please enter a valid hexadecimal colour value: ";
	cin >> a;
	printf("\n");
	if (a.size() <= 5 || a.size() >= 7) {
		cout << "FATAL ERROR: Invalid hexidecimal colour code." << endl;
		return 0;
	}

	for (int i = 0; i < a.size(); i++) {
		// cout << a[i] << endl;
		char testing_char = a[i];
		int ascii = (int) testing_char;
		cout << "i: " << i << " - " << testing_char << ": " << ascii << endl;
		if ((ascii >= 97) && (ascii <= 102)) {
			cout << "Lower-case hexadecimal character." << endl;
			testing_char = toupper(testing_char);
			colourVal[i] = testing_char;
		}
		else if ((ascii >= 48) && (ascii <= 57)) {
			cout << "You've passed me a number." << endl;
			colourVal[i] = testing_char;
		}
		else if ((ascii >= 65) && (ascii <= 70)) {
			cout << "Uppercase hexadecimal value." << endl;
			colourVal[i] = testing_char;
		}
		else {
			printf("Invalid character!\n");
			exit(0);
		}
	}

	string r_val = colourVal[0]+colourVal[1];
	string g_val = colourVal[2]+colourVal[3];
	string b_val = colourVal[4]+colourVal[5];
//	cout << r_val << endl << g_val << endl << b_val << endl;
	int red, green, blue;
	red = stoi(r_val, 0, 16);
	green = stoi(g_val, 0, 16);
	blue = stoi(b_val, 0, 16);

	cout << "Hex -> RGB value conversion:\n";
	cout << "Red: " << red << endl;
	cout << "Green: " << green << endl;
	cout << "Blue: " << blue << endl;

	return 0;
}
