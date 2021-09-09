//
//  numberRepresentationFunctions.hpp
//  NumberRepresentations
//
//  Created by Anna Thomas on 9/8/21.
//

#ifndef numberRepresentationFunctions_hpp
#define numberRepresentationFunctions_hpp

#include <fstream> //library for file stream, used for using the functions output and input
#include <stdlib.h>
#include <vector>
#include <string>
#include <cmath>
#include <iostream>
#include <stdio.h>
#include <iomanip> //to print with higher accuracy
#include <cstdint>
#include <cassert>



bool approxEquals ( double a, double b, double tolerance);
void readFile (std::string &fileName);

#endif /* numberRepresentationFunctions_hpp */
