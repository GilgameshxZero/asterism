//
//  main.cpp
//  VectorPractice
//
//  Created by Anna Thomas on 8/30/21.
//

#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// int sum( vector<int> someVector){

//     int sumsomeVector = 0;

//     for ( int x : someVector ) {
//         sumsomeVector = sumsomeVector + x;
//     }

//     return sumsomeVector;
// }

// vector<char> stringtoVec( string someString) {

//     int x = someString.size() - someString.size();
//     vector<char> sumcharVector;

//     for ( ; x < someString.size(); x++){
//         sumcharVector.push_back(someString[x]);
//     }
//     return sumcharVector;
// }

// int main(int argc, const char * argv[]) {

//     vector<int> vectorofInts = {1, 2, 3};
//     int sumofInts = 6;
//     assert( sum(vectorofInts) == sumofInts);

//     string greet = "Hi";
//     vector<char> sumofgreet = {'H' , 'i'};
//     assert ( stringtoVec(greet) == sumofgreet);

//     vector<int> numbers = {1, 2, 3};
//     vector<int> Rnumbers = {3, 2, 1};
//     assert( reverse(numbers) == Rnumbers);

// If wanted to test in terminal:

//    vector<int> userVector2;
//    cout<< "Please enter a number.\n";
//    cout<< "To terminate this process, input a zero.\n";
//    int z;
//    cin >> z;
//
//

vector<int> revVector(vector<int> somenumVector) {
	vector<int> reversesomenumVector;
	int x = somenumVector.size() - 1;
	for (; x >= 0; x--) {
		reversesomenumVector.push_back(somenumVector[x]);
	}
	return reversesomenumVector;
}

int main() {
	vector<int> userVector2;
	cout << "Please enter a number.\n";
	cout << "To terminate this process, input a zero.\n";
	int z = 1;
	// cin >> z;

	while (z != 0) {
		// get next user input
		cin >> z;
		userVector2.push_back(z);
		// reverse(userVector2.begin(), userVector2.end());
		auto rev = revVector(userVector2);

		if (!z) {
			cout << "Your total reverse vector is ";
			// rev = { 0 5 4 3 2 1 }
			// rev.size() = 6
			for (int a = 0; a < userVector2.size() - 1; a++) {
				cout << userVector2[a + 1] << ' ';
				// cout << "Your total reverse vector is " << rev[a];
			}
			cout << ".\n";
			break;
		}

		// output the reverse vector // visual check
		cout << "The reverse of this vector is ";
		for (int a = 0; a < userVector2.size(); a++) {
			cout << userVector2[a] << ' ';
		}

		cout << "\nPlease enter another number to add to the vector.\n";
		// reverse(userVector2.begin(), userVector2.end());
	}

	return 0;
}

//    int a;
//    for ( ; a < userVector2.size(); a++){
//    cout<< (reverse(userVector2)[a]);
//}

//    string userWord;
//    cout<< "Please put in a word.\n";
//    cin>> userWord;
//
//    int x = 0;
//    for ( ;x < userWord.length(); x++) {
//        cout<< (stringtoVec(userWord)[x]);
//    }
//    cout<< endl;
//
//    vector<int> userVector;
//    int userInt;
//    cout<< "Please input a nonzero integer\n";
//    cout<< "To terminate this process, input a zero.\n";
//    cin>> userInt;
//
//    while (userInt != 0){
//    userVector.push_back (userInt);
//    int answer = sum(userVector);
//    cout<< "Your total vector sum is " << answer << endl;
//    cout<< "Please input another nonzero integer\n";
//    cin>> userInt;
//    }
//
//    cout<< "That is not a nonzero integer. Process terminated.\n";
//    cout<< "Final vector sum: " << sum(userVector) << endl;
//    return 0;
//}
