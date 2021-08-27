#include <cmath>
#include <iostream>
#include <string>

using namespace std;

int main(int, const char *[]) {
	// strings are always constructed empty
	string date;

	cout << "Please enter a date in mm/dd/yyyy format.\n";
	cin >> date;

	string userMonth = date.substr(0, 2);
	string userDay = date.substr(3, 2);
	string userYear = date.substr(6, 4);

	// userMonth + userDay + userYear;

	// string userMonth =
	// int total = stoi(userDay + userYear);
	int total = stoi(userMonth);
	string month[12] = {
		"January",
		"February",
		"March",
		"April",
		"May",
		"June",
		"July",
		"August",
		"September",
		"October",
		"November",
		"December"};

	if (total < 1 || total > 12) {
		cout << "That is not a valid month.\n";
		return 1;
	}
	if (userDay < "01" || userDay > "31") {
		cout << "That is not a valid day.\n";
		return 1;
	}
	// "1439" vs. "1450"
	// compare '1' vs '1' => equal
	// compare '4' vs '4' => equal
	// compare '3' vs '5' => less than (stop here! because !=)
	if (userYear < "1000" || userYear > "9999") {
		cout << "Invalid year. Bad egg!\n";
		return 1;
	}

	// December 25, 1999
	cout << month[total - 1] << " " << userDay << ", " << userYear << endl;

	if (userYear > "2021") {
		cout << "You livin' in the future, dawg.\n";
	}
	return 0;

	// int day[31];
	// for (int x = 1; x <= 31; x++) {
	// 	day[x - 1] =
	// 		x;	// do day[x-1] because arrays start at 0, but here x will start at 1
	// }
	// // if want day == 3, index day[2] (since arrays start at 0)

	// int year[121];
	// for (int x = 1900; x <= 2021; x++) {
	// 	year[x - 1900] = x;
	// }

	// return 0;
}
