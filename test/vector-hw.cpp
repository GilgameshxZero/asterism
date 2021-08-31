/*
	Author: Daniel Kopta and ??
	July 2017

	CS 6010 Fall 2019
	Vector util library definitions

	Complete the functions defined in this file.

	Some basic tests for your library are provided in VectorTest.cpp.
	Compile the tests together with your library using the following command:
	clang++ -std=c++11 VectorTest.cpp VectorUtil.cpp

	Most of the provided tests will fail until you have provided correct
	implementations for the VectorUtil library functions.

	You will need to provide more thorough tests.
*/

#include <cassert>
#include <iostream>
#include <string>
#include <vector>

// #include "VectorUtil.h"
using namespace std;

bool Contains(vector<int> input, int lookFor) {
	int a = 0;
	for (; a < input.size(); a++) {
		if (input[a] == lookFor) {
			return true;
		}
	}
	return false;
}

int FindMin(vector<int> input) {
	if (input.size() == 0) {
		cout << "STOP!!!!\n"
		return 1;
	}

	int a = 1;
	int smallest = input[a - 1];
	for (; a < input.size(); a++) {
		// 3, 1, 3, 2
		if (input[a] < smallest) {
			smallest = input[a];
		}
	}
	return smallest;
}

int FindMax(vector<int> input) {
	int a = 1;
	int largest = input[a - 1];
	for (; a < input.size(); a++) {
		// 3, 1, 3, 2
		if (input[a] > largest) {
			largest = input[a];
		}
	}
	return largest;
}

int Average(vector<int> input) {
	int a = 0;
	int totalSum = 0;
	int totalAverage = 0;
	for (; a < input.size(); a++) {
		totalSum = input[a] + totalSum;
	}
	totalAverage = totalSum / input.size();

	return totalAverage;
}

bool IsSorted(vector<int> input) {
	// bool IsSorted(vector<int> input) returns true if the input vector is sorted
	// in ascending order, false otherwise.
	int a = 1;
	for (; a < input.size(); a++) {
		if (input[a] < input[a - 1]) {
			return false;
		}
	}
	return true;
}
// bool IsSorted(vector<int> input) returns true if the input vector is sorted
// in ascending order, false otherwise.
//    vector<int> nondecreasing;
//    int a = 1;
//
//    while (nondecreasing.size() != input.size()){
//
//    for( ; a - 1 < input.size(); a++){
//        if (input[a] > input[a-1]){
//            nondecreasing.push_back(a);
//        }
//
//    }
//    } doesn't work for the nondecreasing thing, because whether or not it's
//    the ascending order of the given vector must still be defined
/*
	Author: Daniel Kopta and ??
	July 2017

	CS 6010 Fall 2019
	Vector util library tests

	Compile this file together with your VectorUtil library with the following
	command: clang++ -std=c++11 VectorTest.cpp VectorUtil.cpp

	Most of the provided tests will fail until you have provided correct
	implementations for the VectorUtil library functions.

	You will need to provide more thorough tests.
*/

using namespace std;
/*
 * Helper function for failing a test.
 * Prints a message and exits the program.
 */
void ErrorExit(std::string message) {
	std::cerr << "Failed test: " << message << std::endl;
	exit(1);	// Causes the entire program to exit.
}

int main() {
	// We can use list initialization syntax:
	vector<int> v1 = {3, 1, 0, -1, 5};

	// Or we can repeatedly push_back items
	vector<int> v2;
	v2.push_back(1);
	v2.push_back(2);
	v2.push_back(3);

	// When testing, be sure to check boundary conditions, such as an empty vector
	vector<int> empty;

	// v1 doesn't contain 4, so this should return false
	if (Contains(v1, 4)) {
		ErrorExit("Contains() - test 1");
	}

	// v1 does contain -1, so this should return true
	if (!Contains(v1, -1)) {
		ErrorExit("Contains() - test 2");
	}

	/*
	 * The vector 'empty' doesn't contain anything, so this should return false
	 * The specific value we're looking for here (99) is not important in this
	 * test. This test is designed to find any general errors caused by the array
	 * being empty. That type of error is unlikely to depend on the value we are
	 * looking for.
	 */
	if (Contains(empty, 99)) {
		ErrorExit("Contains() - empty");
	}

	vector<int> firstTest = {1, 2, 69};
	int Tester1 = 69;
	assert(Contains(firstTest, Tester1) == true);

	vector<int> secondTest = {3, 1, 3, 2};
	int Tester2 = 1;
	assert((FindMin(secondTest) == Tester2));

	vector<int> thirdTest = {3, 1, 3, 2};
	int Tester3 = 3;
	assert((FindMax(thirdTest) == Tester3));

	vector<int> fourthTest = {2, 2, 3, 1};
	int Tester4 = 2;
	assert((Average(fourthTest) == Tester4));

	vector<int> fifthTest = {45, 3, 2, 3, -1, 69};
	assert((IsSorted(fifthTest) == false));

	vector<int> sixthTest = {1, 2, 3, 4, 68};
	assert((IsSorted(sixthTest) == true));

	// Since any failed test exits the program, if we made it this far, we passed
	// all tests.
	std::cout << "All tests passed!\n";
}
