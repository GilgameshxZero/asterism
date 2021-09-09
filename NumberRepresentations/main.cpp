//
//  main.cpp
//  NumberRepresentations
//
//  Created by Anna Thomas on 9/8/21.
//

#include "numberRepresentationFunctions.hpp"

int main(int argc, const char * argv[]) {
 
    int a;
    std::cout << sizeof(a) << std::endl; //the output indicates the number of bytes //4 bytes
    
    double b;
    std::cout << sizeof(b) << std::endl; //8 bytes
    
    float c;
    std::cout << sizeof(c) << std::endl; //4 bytes
    
    //int8_t, int16_t, etc for the signed integer types, and names like uint8_t, uint16_t, etc for the unsigned integer types
    //number indicates the number of bits
    
    int8_t d;
    std::cout << sizeof(d) << std::endl; //one bytes
    
    int16_t e;
    std::cout << sizeof(e) << std::endl; //two bytes
    
    uint8_t f;
    std::cout << sizeof(f) << std::endl; //one byte
    
    uint16_t g;
    std::cout << sizeof(g) << std::endl; //two bytes
    
    
    //Define variables and assign them the min/max values using hexadecimal constants and print them out to confirm that you're correct.
    //a hex number is indicated by starting with 0x
    //for one byte:
    int unassignedMax = 0x7F;
    int unassignedMin = 0x00;
    int assignedMax = 0xFF;
    int assignedMin = 0x80;
    //if you print an 8-bit variable, cout will assume you want to print its ASCII value
    //To print its numerical value, add a +
    std::cout << sizeof(+unassignedMax) << std::endl;
    std::cout << sizeof(+assignedMax) << std::endl;
    std::cout << +unassignedMax << std::endl;
    std::cout << +unassignedMin << std::endl;
    std::cout << +assignedMax << std::endl;
    std::cout << +assignedMin << std::endl;
    
    //Try doing the same for the 3 corresponding signed integer types
    //int and float are both 4 bytes:
    int fourBAssignedMax = 0xFFFFFFFF;
    int fourBAssignedMin = 0x80000000;
    
    //double is 8 bytes:
    
    double eightBAssignedMax = 0xFFFFFFFFFFFFFFFF; //16 F's
    double eightBAssignedMin = 0x8000000000000000; //one 8, 15 zeroes
    
    std::cout << +fourBAssignedMax << std::endl;
    std::cout << +fourBAssignedMin << std::endl;
    
    std::cout << +fourBAssignedMax + 1 << std::endl;
    std::cout << +fourBAssignedMin - 1 << std::endl;
    //why does -1 make it it's positive counter +1
    
    //when behaviour sanitizer is turned on in diagnostics of editscheme
    //Error: Signed integer overflow: -2147483648 - 1 cannot be represented in type 'int'
    
    std::cout << +eightBAssignedMax << std::endl;
    std::cout << +eightBAssignedMin << std::endl;
    
    //compute .1 + .2 and store the result in a variable of type double and print it.
    double product = (0.1 + 0.2);
    double totalProduct = 0.3;
    //print numbers to 18 digits of accuracy
    std::cout << std::setprecision(18);
    std::cout << product << std::endl;
    
    //This is an example of the perils of comparing floating point numbers!!
    
    float fProduct = (0.1 + 0.2);
    
    approxEquals(product, totalProduct, 1); //if the difference between the abs value of product and totalProduct is less than 1, it is negligible
    
    assert(approxEquals(product, totalProduct, 1));
    //assert(fProduct == 0.3);
    std::cout << "That worked!\n";
    
    std::string unicodeFile = "unicodeLibrary.txt";
    readFile(unicodeFile);


    return 0;
}
