//
//  main.cpp
//  VectorPractice
//
//  Created by Anna Thomas on 8/30/21.
//

#include <iostream>
#include <vector>
#include <cmath>
#include <string>

using namespace std;

int sum( vector<int> someVector){
    
    int sumsomeVector = 0;
    
    for ( int x : someVector ) {
        sumsomeVector = sumsomeVector + x;
    }
    
    return sumsomeVector;
}

vector<char> stringtoVec( string someString) {

    int x = someString.size() - someString.size();
    vector<char> sumcharVector;
    
    for ( ; x < someString.size(); x++){
        sumcharVector.push_back(someString[x]);
    }
    return sumcharVector;
}

vector<int> reverse( vector<int> somenumVector){
    
    vector<int> reversesomenumVector;
    int x = somenumVector.size()-1;
    for( ; x >= 0; x--){
      reversesomenumVector.push_back(somenumVector[x]);
}
    return reversesomenumVector;
}

int main(int argc, const char * argv[]) {
    
    vector<int> vectorofInts = {1, 2, 3};
    int sumofInts = 6;
    assert( sum(vectorofInts) == sumofInts);
    
    string greet = "Hi";
    vector<char> sumofgreet = {'H' , 'i'};
    assert ( stringtoVec(greet) == sumofgreet);
    
    vector<int> numbers = {1, 2, 3};
    vector<int> Rnumbers = {3, 2, 1};
    assert( reverse(numbers) == Rnumbers);
    
    
    
    
    
// If wanted to test in terminal:

//    vector<int> userVector2;
//    cout<< "Please enter a number.\n";
//    cout<< "To terminate this process, input a zero.\n";
//    int z;
//    cin >> z;
//
//
//    while(z != 0)
//    for ( int a = 0; a < userVector2.size(); a++){
//      userVector2.push_back(z);
    
    //cout<< "The reverse of this vector is " <<(reverse(userVector2)[a]) << endl;
//        }
////
//        cout<< "Please enter another number to add to the vector.\n";
//        cin>> z;
    //}
    
    
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
//
}
