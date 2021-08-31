//
//  Function_Helpers_Words.cpp
//  stringAnalyzer
//

//I used all of my letter helper functions to make my word helper functions more efficient, so I could not create two separate header files without rewriting my code.
//  Created by Anna Thomas on 8/30/21.
//

#include "Function_Helpers_Words.hpp"

bool isTerminator(char t) {
    if( t == ' '){
        return true;
    }
    else{
        return false;
}
}
bool isPunctuation(char p){
    if( p == '.' || p == '?' || p == '!'){
        return true;
    }
    else{
        return false;
}
}
bool isVowel(char v){
    if (v < 'a'){
    v = v + ' ';
}
    if(v == 'a' || v == 'e' || v == 'i' || v == 'o' || v == 'u' || v == 'y' ){
        return true;
}
    else {
        return false;
}
}
bool isConsonant (char c){
   if (c < 'a') {
     c = c + ' ';
}
   if(isTerminator(c) != true && isPunctuation(c) != true && isVowel(c) != true && c <= 'z' && c >= 'a'){
       return true;
}
  else{
      return false;
}
}
int numWords (string userSentence) {
    int userLength = userSentence.length();
    int usernumWords = 1;
   for( ; userLength >= 0; userLength--){
       int x = userSentence[userLength];
       if (isTerminator(x) == true) {
           usernumWords = usernumWords + 1;
       }
            }
    return usernumWords;
}
int numSentences(string userParagraph){
    int userLength2 = userParagraph.length();
    int usernumSentences = 0;
    for( ; userLength2 >= 0; userLength2--){
    int y = userParagraph[userLength2];
    if (isPunctuation(y) == true){
        usernumSentences = usernumSentences + 1;
    }
    }
    return usernumSentences;
}
int numVowels (string userWord) {
    int userLength3 = userWord.length();
    int usernumVowels = 0;
   for( ; userLength3 >= 0; userLength3--){
       int z = userWord[userLength3];
       if (isVowel(z)) {
           usernumVowels = usernumVowels + 1;
       }
            }
    return usernumVowels;
}
int numConsonants (string userWord2) {
    int userLength4 = userWord2.length();
    int usernumConsonants = 0;
   for( ; userLength4 >= 0; userLength4--){
       int x1 = userWord2[userLength4];
       if (isConsonant(x1)) {
           usernumConsonants = usernumConsonants + 1;
       }
            }
    return usernumConsonants;
}
int readingLevel (string Total){
    int userreadingLevel =(numVowels(Total) + numConsonants(Total))/numWords(Total);
    return userreadingLevel;
}
double wofcostMetric (string Total2){
    double userwofcostMetric = double(numVowels(Total2))/double(numWords(Total2));
    return userwofcostMetric;
}
