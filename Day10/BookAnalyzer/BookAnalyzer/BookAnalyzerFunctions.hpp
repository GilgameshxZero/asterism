//
//  BookAnalyzerFunctions.hpp
//  BookAnalyzer
//
//  Created by Anna Thomas on 9/5/21.
//

#ifndef BookAnalyzerFunctions_hpp
#define BookAnalyzerFunctions_hpp

#include <fstream> //library for file stream, used for using the functions output and input
#include <stdlib.h>
#include <vector>
#include <string>
#include <cmath>
#include <iostream>
#include <stdio.h>
#include <iomanip>


std::vector<std::string> OpenFile(std::string &fileName, std::string &userWord, const int &secretKey);
std::string getTitle (std::vector<std::string> &fullBook);
std::string getAuthor (std::vector<std::string> &fullBook);
int totalNumWords (std::vector<std::string> &fullBook);
int totalNumChars (std::vector<std::string> &fullBook);
std::string findLongestWord (std::vector<std::string> &fullBook);
std::string findShortestWord (std::vector<std::string> &fullBook);
std::string KeyWord (std::vector<std::string> &fullBook, std::string &userWord);

void findProperNouns (std::vector<std::string> &fullBook);
bool IsUpper( char c );
bool IsLower( char c );
bool IsDigit( char c );
bool IsDecimalWord( const std::string &word );
std::string DecimalToBinary( const std::string &word );
std::string EncodeWord( const std::string &word, const int &secretKey);

#endif /* BookAnalyzerFunctions_hpp */
