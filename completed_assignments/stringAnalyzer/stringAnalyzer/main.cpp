#include <iostream>
#include <string>
#include <cmath>
#include "Function_Helpers_Words.hpp"

using namespace std;
//
//bool isTerminator(char t) {
//    if( t == ' '){
//        return true;
//    }
//    else{
//        return false;
//}
//}
//bool isPunctuation(char p){
//    if( p == '.' || p == '?' || p == '!'){
//        return true;
//    }
//    else{
//        return false;
//}
//}
//bool isVowel(char v){
//    if (v < 'a'){
//    v = v + ' ';
//}
//    if(v == 'a' || v == 'e' || v == 'i' || v == 'o' || v == 'u' || v == 'y' ){
//        return true;
//}
//    else {
//        return false;
//}
//}
//bool isConsonant (char c){
//   if (c < 'a') {
//     c = c + ' ';
//}
//   if(isTerminator(c) != true && isPunctuation(c) != true && isVowel(c) != true && c <= 'z' && c >= 'a'){
//       return true;
//}
//  else{
//      return false;
//}
//}
//int numWords (string userSentence) {
//    int userLength = userSentence.length();
//    int usernumWords = 1;
//   for( ; userLength >= 0; userLength--){
//       int x = userSentence[userLength];
//       if (isTerminator(x) == true) {
//           usernumWords = usernumWords + 1;
//       }
//       else {
//       }
//            }
//    return usernumWords;
//}
//int numSentences(string userParagraph){
//    int userLength2 = userParagraph.length();
//    int usernumSentences = 0;
//    for( ; userLength2 >= 0; userLength2--){
//    int y = userParagraph[userLength2];
//    if (isPunctuation(y) == true){
//        usernumSentences = usernumSentences + 1;
//    }
//    else{
//    }
//    }
//    return usernumSentences;
//}
//int numVowels (string userWord) {
//    int userLength3 = userWord.length();
//    int usernumVowels = 0;
//   for( ; userLength3 >= 0; userLength3--){
//       int z = userWord[userLength3];
//       if (isVowel(z)) {
//           usernumVowels = usernumVowels + 1;
//       }
//       else {
//       }
//            }
//    return usernumVowels;
//}
//int numConsonants (string userWord2) {
//    int userLength4 = userWord2.length();
//    int usernumConsonants = 0;
//   for( ; userLength4 >= 0; userLength4--){
//       int x1 = userWord2[userLength4];
//       if (isConsonant(x1)) {
//           usernumConsonants = usernumConsonants + 1;
//       }
//       else {
//       }
//            }
//    return usernumConsonants;
//}
//int readingLevel (string Total){
//    int userreadingLevel =(numVowels(Total) + numConsonants(Total))/numWords(Total);
//    return userreadingLevel;
//}
//double wofcostMetric (string Total2){
//    double userwofcostMetric = (numVowels(Total2) * 1.0)/(numWords(Total2) * 1.0);
//    return userwofcostMetric;
//}
int main(int argc, const char * argv[]) {
    string userInput;
    cout<< "Please enter one or more sentences for evaluation.\n";
    while(userInput != "done"){
    getline(cin, userInput);
    cout<< "The total number of words is: " << numWords(userInput)<< endl;
    cout<< "The total number of sentences is: " << numSentences(userInput) <<endl;
    cout<< "The total number of vowels is: " << numVowels(userInput) << endl;
    cout<< "The total number of consonants is " << numConsonants(userInput) << endl;
    cout<< "The total reading level is " << readingLevel(userInput) <<endl;
    cout<< "The wheel-of-fortune cost metric is " << wofcostMetric(userInput) <<endl;
    cout<< "Please enter another sentence/or set of sentences for evaluation.\n";
    }
    return 0;
}
