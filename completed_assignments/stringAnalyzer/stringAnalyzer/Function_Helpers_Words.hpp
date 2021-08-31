//
//  Function_Helpers_Words.hpp
//  stringAnalyzer
//
//  Created by Anna Thomas on 8/30/21.
//

#ifndef Function_Helpers_Words_hpp
#define Function_Helpers_Words_hpp

#include <stdio.h>
#include <iostream>
#include <string>
#include <cmath>

using namespace std;

bool isTerminator(char t);
bool isPunctuation(char p);
bool isVowel (char v);
bool isConsonant (char c);
int numWords (string userSentence);
int numSentences(string userParagraph);
int numVowels (string userWord);
int numConsonants (string userWord2);
int readingLevel (string Total);
double wofcostMetric (string Total2);

#endif /* Function_Helpers_Words_hpp */
