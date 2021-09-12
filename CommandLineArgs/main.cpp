//
//  main.cpp
//  CommandLineArgs
//
//  Created by Anna Thomas on 9/3/21.
//

#include "CommandLineArgFunctions.hpp"



int main(int argc, const char * argv[]) {
    
    for(int a = 0; a < argc; a++){
        std::cout<< " " << argv[a] << " ";
    }
    //std::string firstElement = argv[0]; //the way with string class

    char firstElement;
    firstElement = *argv[0]; //the way without being able to use std::string
    
    
    return 0;
}
