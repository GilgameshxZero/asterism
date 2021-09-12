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


std::vector<std::string> OpenFile(const std::string &fileName, const std::string &userWord, std::string &secretKey);
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
std::string DecimalToBinary( const std::string &word ) ;
std::string EncodeWord( const std::string &word, std::string &secretKey);

void makeFile ( const std::string &encodedText, const std::string &fileName, std::string &newFile); //doesn't put out/make a new file but needs to
//IF FILE NAME ISN'T A CONST AND THEN YOU ASSIGN NEWFILE TO FILE NAME THIS BINCH GONNA OVERWRITE EVERYTHING IN FILE NAME LMAOOOOOO
//BYE BYE MOBYDICK.TXT! RIP!
//LOLOLOL

//

//why make &word a const...
//if it weren't, what could change?
//just a good habit to get into, make things you are pointing at/using into const if you aren't going to change them
//this helps mitigate potential undefined behavior


#endif /* BookAnalyzerFunctions_hpp */
