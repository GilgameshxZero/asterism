//
//  main.cpp
//  MakeYourOwnVector
//
//  Created by Anna Thomas on 9/13/21.
//

#include "MakeYourOwnVectorFunctions.hpp"
#include <cassert>

int main(int argc, const char * argv[]) {
    
    //Write a set of tests that demonstrate that your functions work properly. The quality/thoroughness of your tests is an important part of this assignment.
    //uwu
    
    vectorStruct<int> myVec(2); //calls the constructor that takes a single int argument and names it myVec, type T is int
    assert( myVec.getCapacity() == 2); //capacity is set to the variable data
    assert( myVec.getSize() == 0);
    myVec.growVector();
    assert( myVec.getCapacity() == 4); //capacity is set to the variable data
    assert( myVec.getSize() == 0);
    myVec.pushBack(69); //can't use myVec.set(0, 69); because it is designed to throw an error if the index equals the size
    //since size HAS to start at 0 for this HW, then we will need to use pushBack first
    assert( myVec.get(0) == 69 );
    myVec.set(0, 5);
    assert( myVec.get(0) == 5 );
    myVec.pushBack(71);
    assert( myVec.get(1) == 71 );
    myVec.popBack();
    assert( myVec.getSize() == 1 ); //there should be just one value in myVec right now and that is 5 at index 0
    //thus the size of myVec should be 1
    //myVec.freeVector(myVec); //now is my destructor


    
    return 0;
}
/*


Demonstrate that your vector works with at least 2 different element types.

Add operator overloads for all the comparison operators (==, !=, <, <=, >=, >). 
//for the non-int types e.g. string, char* array 
These should compare vectors lexicographically (which means in dictionary order). 
Remember, only 2 of the comparison operators need "real code" in them - the others can just those two.

*/
