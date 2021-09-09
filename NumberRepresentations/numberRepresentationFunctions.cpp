//
//  numberRepresentationFunctions.cpp
//  NumberRepresentations
//
//  Created by Anna Thomas on 9/8/21.
//

#include "numberRepresentationFunctions.hpp"

//Write a function approxEquals that takes 3 doubles: the two numbers you want to compare with ==, and a tolerance that specifies how close they must be to be considered equal.
//bool approxEquals( double a, double b, double tolerance );

//hint: you'll want to use the std::abs function from the <cmath> header.


//Verify that your function works for the example above involving .1 + .2 and .3
bool approxEquals ( double a, double b, double tolerance){
    
    bool result = false;
    
    if( abs(a - b) < tolerance){
        std::cout << "True!";
        result = true;
    }
    
    std::cout << "The result is " << result << std::endl;
    return result;
}


//Write a function that loads this file character by character and prints each character on its own line.
//Count the number of standard ASCII characters, and the number of Unicode characters, and display these counts after reading the file.

void readFile (std::string &fileName){
    
    std::ifstream read(fileName);
    char c;
    int countStandard = 0;
    int countUnicode = 0;
    
    if (read.fail()){
        std::cout << "Failed to open file: \n" << fileName << "\n.";
        
        exit ( 1 );
    }
    
    while( read >> c){
        
        std::cout << c << "\n";
        
        if( c < 128 && c >= 0){ //255 --> 128 are unsigned, ASCII chars (from 0 to 127, including 0)
            
            countStandard++;
        }
        //UTF-8 unicode using 8 bits
        //8 bits can only represent 256 characters
        //first 127 are ASCII chars
        
        if( c < 0){ //255 - 128 = last 127 are signed, unicode chars (from -1 to -127, including -1)
            //signed min constant for one byte (8 bits) is 0x80 (8* 16^1 + 0* 16^0) --> 128 in dec
            //signed max constant for one byte (8 bits) is 0xFF (15* 16^1 + 15* 16^0) --> 255
            
            countUnicode++;
        }
    }
    
    std::cout << "The total number of standard ASCII characters is: " << countStandard << std::endl;
    std::cout << "The total number of unicode characters is: " << countUnicode << std::endl;
}
//You can read character by character with the following:
// Assuming you have an std::ifstream named ins:

//char c;
//
//while( ins >> c ){
//
//  // Print c on its own line.
//
//}


//Call your function from main().
//What do you see? What text is printed in a readble form? What text is garbled? Does this match your expectations? Why or why not?

//only the ASCII values are readable form
//all the unicode values are garbled
//makes sense, char would only be able to store the ASCII values
//must need a different type to store unicode values

//ah yes,
//"Note: Support of Unicode identifiers is limited in most implementations, e.g. gcc (until 10)."
//https://en.cppreference.com/w/cpp/language/identifiers
