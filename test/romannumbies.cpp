//  main.cpp
//  RomanNumerals
//
//  Created by Anna Thomas on 8/26/21.
// The Roman Numeral token rules, in order:

#include <cmath>
#include <iostream>
#include <string>

using namespace std;

int main(int argc, const char *argv[]) {
	int x;

	cout << "Please enter a positive number to convert to Roman Numerals.\n";
	cin >> x;
	bool goodness = cin.good();
	if (!goodness) {
		cout << "I said to put in a positive number.\n";
		return 1;
	}

	// https://en.cppreference.com/w/cpp/io/basic_ios/good

	if (x <= 0) {
		cout << "Roman numeral conversion impossible.\n";
		return 1;
	}

	// string roman[13] {};
	int remainder;
	// loop while remainder is more than 0
	while (x > 0) {
		// x = 2900
		if (x >= 1000) {
			remainder = x % 1000;
			x = x / 1000;
			for (; x > 0; x--) {
				cout << "M";
			}
			x = remainder;
		}
		if (x >= 900) {
			remainder = x % 900;
			x = x / 900;
			for (; x > 0; x--) {
				cout << "CM";
			}
			x = remainder;
		}

		if (x >= 500) {
			remainder = x % 500;
			x = x / 500;
			for (; x > 0; x--) {
				cout << "D";
			}
            x = remainder;
		}
		if (x >= 400) {
			remainder = x % 400;
			x = x / 400;
			for (; x > 0; x--) {
				cout << "CD";
			}
            x = remainder;
		}
		if (x >= 100) {
			remainder = x % 100;
			x = x / 100;
			for (; x > 0; x--) {
				cout << "C";
			}
            x = remainder;
		}
		if (x >= 90) {
			remainder = x % 90;
			x = x / 90;
			for (; x > 0; x--) {
				cout << "XC";
			}
            x = remainder;
		}
		if (x >= 50) {
			remainder = x % 50;
			x = x / 50;
			for (; x > 0; x--) {
				cout << "L";
			}
            x = remainder;
		}
		if (x >= 40) {
			remainder = x % 40;
			x = x / 40;
			for (; x > 0; x--) {
				cout << "XL";
			}
            x = remainder;
		}
		if (x >= 10) {
			remainder = x % 10;
			x = x / 10;
			for (; x > 0; x--) {
				cout << "X";
			}
            x = remainder;
		}
		if (x >= 9) {
			remainder = x % 9;
			x = x / 9;
			for (; x > 0; x--) {
				cout << "IX";
			}
            x = remainder;
		}

		if (x >= 5) {
			remainder = x % 5;
			x = x / 5;
			for (; x > 0; x--) {
				cout << "V";
			}
            x = remainder;
		}
		if (x >= 4) {
			remainder = x % 4;
			x = x / 4;
			for (; x > 0; x--) {
				cout << "IV";
			}
            x = remainder;
		}
		if (x >= 1) {
			remainder = x % 1;
			x = x / 1;
			for (; x > 0; x--) {
				cout << "I";
			}
		}
	}
	// x = roman[x] + roman[x-1]
	// 5 % 3 = 2
	// x = 1005
	// x % 1000 = 5
	// is x % 1000 ever going to be greater than 1000?
	// 1005 = MV

	// all of this wrapped in a loop

	// string s = "";
	// s = s + "K";
	// now, s = "K"
	// s = s + "Q";
	// now, s = "KQ"

	// for (int x; x >= 0; x++) {
	// string totalWord = x;
	// cout<< totalWord;
	//}
    cout<< endl;
	return 0;
}
