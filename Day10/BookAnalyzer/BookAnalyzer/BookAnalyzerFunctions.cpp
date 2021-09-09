//
//  BookAnalyzerFunctions.cpp
//  BookAnalyzer
//
//  Created by Anna Thomas on 9/5/21.
//

#include "BookAnalyzerFunctions.hpp"

std::vector<std::string> OpenFile(std::string &fileName, std::string &userWord, const int &secretKey){
    
    std::ifstream openBook (fileName);
    
    if (openBook.fail()){
        std::cout << "Failed to open file: \n" << fileName << "\n.";
        
        exit ( 1 );
    }
        
    std::vector<std::string> fullBook;
    std::string bookWord;
    
    while (openBook >> bookWord) {

        EncodeWord(bookWord, secretKey); //this is where we do the encoding
        //if the user provides a secretKey of 0, no encryption will happen
        fullBook.push_back(bookWord);
        
    }

    return fullBook;
}

std::string getTitle (std::vector<std::string> &fullBook){
    
    
    std::string title = "Title:";
    std::vector<std::string> totalLine;

    for(int a = 0; a < 101; a++){ //check the first 100 words
    
        if( fullBook[a] == title ){
        
            while (fullBook[a] != "Author:"){
                
            std::cout<< fullBook[a] << " ";
            a++;
            totalLine.push_back(fullBook[a]);
                
            if(totalLine.size() > 10){ //can increase for longer book titles
                std::cout<< "\n" << "\n";
                std::cout << "Error in formatting. Could not define the title properly.\n";
                return title;
                }
            }
            std::cout<< std::endl;
            return title;
    }
        if( fullBook[a] != title && a == 100 ){
            std::cout << "Title unknown.\n";
        }
    }
    return title;
}

std::string getAuthor (std::vector<std::string> &fullBook){

    std::string author = "Author:";
    std::vector<std::string> totalLine;
    
    for(int a = 0; a < 101; a++){
        if( fullBook[a] == author ){

            while (fullBook[a] != "Release"){
                
                std::cout << fullBook[a] << " ";
                a++;
                totalLine.push_back(fullBook[a]);
                
                if(totalLine.size() > 10){ //can increase for longer names
                    std::cout<< "\n" << "\n";
                    std::cout << "Error in formatting. Could not define the author properly.\n";
                    return author;
                }
            }
            std::cout<< std::endl;
            return author;
        }
        if( fullBook[a] != author && a == 100){
            std::cout << "Author unknown.\n";
        }
    }
    return author;
}

int totalNumWords (std::vector<std::string> &fullBook) {
    int count = 0;
    int a = 0;
    while (a < fullBook.size()){
        
        count = count + 1;
        a++;
    }
    
    std::cout<< "The total number of words is " << count << ".\n";
    return count;
}

int totalNumChars (std::vector<std::string> &fullBook){
    int count = 0;
    int a = 0;
    
    while (a < fullBook.size()){
        
        count = count + fullBook[a].size();
        a++;
    }
    return count;
}

std::string findLongestWord (std::vector<std::string> &fullBook) {
    
    int a = 0;
    std::string longestWord = fullBook[a];

    
    while (a < fullBook.size()){
        
        if( longestWord.length() < fullBook[a].length() ){
            
            longestWord = fullBook[a];
        }
        a++;
    }
    std::cout << "The longest word is " << longestWord << "\n";
    
    return longestWord;
}

std::string findShortestWord (std::vector<std::string> &fullBook) {
    
    int a = 0;
    std::string shortestWord = fullBook[a];
  
    while (a < fullBook.size()){
        
        if( shortestWord.length() > fullBook[a].length() ){
            
            shortestWord = fullBook[a];
        }
        a++;
    }
    std::cout << "The shortest word is " << shortestWord << "\n";
    
    return shortestWord;
}

std::string KeyWord (std::vector<std::string> &fullBook, std::string &userWord) {
    
    std::string done;
    std::vector<std::string> userWordAppearances;
    std::string userWordSet;
    std::vector<double> userWordLocations;
    double location = 0;
    double count = 0;
    double count2 = 0;
    
    for( int a = 0; a < fullBook.size(); a++){
        
        if ( fullBook[a] == userWord){
            count2 = 0; //re-assign value in if statement so that the count2 is reset everytime there is another existence of userWord
            count = count + 1;
            
            userWordSet = fullBook[a - 1] + " " + fullBook[a] + " " + fullBook[a+1] + "\n";
            userWordAppearances.push_back(userWordSet);
            
            //have it count until the index a
            for ( int b = 0; b < a; b++){
                
                count2 = count2 + fullBook[b].size(); //count2 accounts for the total number of chars up til b < a
            }
            
            location = count2 /totalNumChars(fullBook) *100; //add one to count2 to account for the first character of the userWord
            userWordLocations.push_back(location);
        }
    }
    std::cout<< "The word " << userWord << " appears " << count << " times:\n";
    
    for (int a = 0; a < userWordLocations.size(); a++){
        
    std::cout<< "at " << userWordLocations[a] << "%:" << " " << userWordAppearances[a];
    }
    return done;
}

void findProperNouns (std::vector<std::string> &fullBook){
    
    std::string word; //the word it's looking at
    std::string pNoun; //for storing a proper noun
    std::string wordSet; //for storing the words around a proper noun
    std::vector<std::string> pWordSet; //stores word sets for proper nouns
    double pCount = 0; //for counting the number of proper nouns
    double charCount = 0; //for counting the total number of chars
    double location; //where the char of a word is in the book as a percentage
    std::vector<int> pWordLocations; //stores all the locations of each pNoun found as an int
    
    for( int a = 0; a < fullBook.size(); a++){
        
        word = fullBook[a];
        std::string previousWord = fullBook[a-1];
        std::string nextWord = fullBook[a+1];
        
        if ( word[0] >= 'A' && word[0] <= 'Z'){ //A is 65, Z is 90
            
        //we need to check the words around it, specifically the last char of the previous word to make sure it's not a terminator
                
                if ( previousWord[previousWord.length()-1] != '.' && previousWord[previousWord.length()-1] != '?' && previousWord[previousWord.length()-1]  != '!'){
                    
                    wordSet = previousWord + " " + word + " " + nextWord + "\n";
                    
                    pWordSet.push_back(wordSet);
                    pCount++;
                }
            for ( int b = 0; b < a; b++){
                
            charCount = charCount + fullBook[b].size(); //charCount accounts for the total number of chars up til b < a
            }
            
            location = charCount /totalNumChars(fullBook) *100;
            pWordLocations.push_back(location);
        }
        }
    
    std::cout<< "Proper nouns appear " << pCount << " times.\n";
    
    for (int a = 0; a < pWordLocations.size(); a++){
        
    std::cout<< "at " << pWordLocations[a] << "%:" << " " << pWordSet[a] << std::endl;
    }
}


bool IsUpper( char c ){
    bool isUpper = false;
    
    if ( c >= 'A' && c <= 'Z'){
        isUpper = true;
    }
    
    return isUpper;
} //Determines whether or not a character is uppercase 'A' through 'Z'.

bool IsLower( char c ) {
    bool isLower = false;
    
    if ( c >= 'a' && c <= 'z'){
        isLower = true;
    }
    
    return isLower;
    
} //Determines whether or not a character is lowercase 'a' through 'z'.
bool IsDigit( char c ) {
    bool isDigit = false;
    
    if ( c >= '0' && c <= '9'){
        isDigit = true;
    }
    return isDigit;
}
//Determines whether or not a character is a decimal digit '0' - '9'.
bool IsDecimalWord( const std::string &word ) {
    bool isDecimalWord = false;
   
    for( int a = 0; a < word.length()-1; a++){
    if ( IsDigit(word[a]) == true ) { //use function for IsDigit here
        isDecimalWord = true;
    }
    }
    
    return isDecimalWord;
}
//Determines whether or not a word contains only digits, and none others.

std::string DecimalToBinary( const std::string &word ) {
    std::string binaryString;
    
    //base 10 --> base 2
    //when changing bases, what changes
    
    return binaryString;
}
//Returns the binary string representation of the decimal string. You probably already wrote this function in your binary converter assignment.


std::string EncodeWord( const std::string &word, const int &secretKey ) {
    std::string encodedText;

    char oldChar; //the initial char
    char newChar; //the char after the encode

    
    for( int a = 0; a < word.length()-1; a++){//break up each string "word" into chars
        oldChar = word[a];
        
        if (IsUpper(oldChar) == true){
            newChar = (oldChar + secretKey) % 26; //the char after the encode //if ascii values are 65 - 90 'A' to 'Z'
        }
        if(IsLower(oldChar) == true){
            newChar = (oldChar + secretKey) % 26; //the char after the encode //if ascii values are 97 - 122 'a' to 'z'
        }
        if(IsDigit(oldChar) == true){
            newChar = (oldChar + secretKey) % 10; //the char after the encode //if ascii values are 48 - 57 '0' to '9'
        }
        
        if (IsDecimalWord(word) == true){ //if receive a word of only digits
            
            oldChar = word[a]; //remember
            newChar = (oldChar + secretKey) % 10; //the char after the encode //if ascii values are 48 - 57 '0' to '9'
            //would this really be treated any differently than IsDigit?
            //if so, why???
            
        }
    }
        
        encodedText.push_back(newChar);
        std::cout << encodedText;
        
        return encodedText;
    }
    
    
    
    //cipher key

    //All words containing decimal numbers should be replaced with their binary representation using '0' and '1' characters. A decimal number in a book is any word that consists of only the characters '0' through '9', and no punctuation.
    //aka just a digit of base10

    //All alphabetical characters ('a' through 'z' and their capital equivalents) should be replaced with a different alphabetical character.
    //can accomplish this by telling it to simply add 1 to the char
    //but then z+1 wouldn't wrap around to a unless i did something else
    //how could i tell it to wrap around to the beginning
    //if char + 1 > 'z', char = 'a' would work
    //Recall that the mod operator (%) returns the remainder after integer division. Also recall that characters are just integers.
    //could also do a bubble sort

    //Our cipher will work by simply adding a fixed constant to each character.
    //If the letters 'a' through 'z' had ASCII values of 0 - 25, then the formula for applying the cipher to lowercase letters would look like this:
    //newChar = (oldChar + 3) % 26; Where 3 in the code above is your secret constant - you would replace this with whatever number you choose.

    //'z' (25) + 3 is 28
    //28 % 26 is 2 (remainder after 28 / 26)
    //2 corresponds to 'c' if assuming 'a' through 'z' had ASCII values of 0 - 25.
    //secret constant you choose can be any positive integer with this method

    //Your cipher should treat lowercase and capital letters as two different classes of characters
    //cause they have different ASCII values

    //All punctuation and other characters should remain the same.
    //don't touch non-latin alphas and non-decimal numbers

    //can't just randomize bc a cipher is reversible by nature

    //Converting decimal numbers to binary is easily undone, so all we need is a reversible way to change alphabetical characters.
    //binary to dec is done by...


    
//Our cipher will work by simply adding a fixed constant to each character.
//If the letters 'a' through 'z' had ASCII values of 0 - 25, then the formula for applying the cipher to lowercase letters would look like this:
    
//newChar = (oldChar + 3) % 26; Where 3 in the code above is your secret constant - you would replace this with whatever number you choose.

//'z' (25) + 3 is 28
//28 % 26 is 2 (remainder after 28 / 26)
//2 corresponds to 'c' if assuming 'a' through 'z' had ASCII values of 0 - 25.
//Returns the encoded version of the input string.


//-------------
//Add one more statistic to the statistics your book analyzer already reports: the number of, and location of, proper nouns

//we will consider a word to be a proper noun if it starts with a capital letter, and does not follow a word ending in a sentence terminator. A sentence terminator is either '.', '?', or '!',

//if ( word[0] >= 65 && word[0] <= 90)
//the char at index 0 of string "word" //aka the first char

//std::string previousWord = fullBook[a - 1];
//if ( previousWord[previousWord.length()-1] != '.' and '?' and '!')
//fullBook is the vector of strings,
//a is the index of the current word
//so a - 1 is the index of the preceeding word (account for if there is no index for a - 1)
//and previousWord's last char will be at index previousWord.length() - 1, since index starts at 0
//if the char found at the end of previousWord is not equal to any of those terminators, and is capital, then it is a proper noun



//The report of proper noun locations should have the same format as the key word locations from your original book analyzer, i.e., it should report each proper noun's location as a percentage, and the previous and next words
//copy this part of keyword function^
//great^^ in this i accounted for if there is no index for a - 1






//Previous Comments:
//--------------------------
//Have book start at (or just spit out?) the title/author attempt
//Will run into errors if Author or Title don't exist
//need to have it spit out unknown, but will it still be able to read the whole book after the beginning spiel?
//-------------------------
//std::vector<std::string> fullBook;
// std::string bookWord;
// //std::getline(openBook, prefaceInfo); //don't have to separate the beginning spiel?
//to start after beginning spiel, do if ( word == "START" ) { done = true;} //because the book starts at *** START OF THE PROJECT GUTENBERG EBOOK MOBY-DICK *** //so look for "START"
//book ends at *** END OF THE PROJECT GUTENBERG EBOOK MOBY-DICK ***
//tell program to stop reading everything after that if you just want the book
//if ( word == "END" ) { done = true; } or something


// //std::getline(openBook, author);
// //std::getline(openBook, releaseDate);
//
// while (openBook >> bookWord) {


//        std::string title = "Title:";
//        std::string author = "Author:";
//
//
//        if( bookWord == title ){
//
//            std::getline(openBook, bookWord);
//            std::cout<< title << " " << bookWord;
//        }
//
//        if( bookWord == author ){
//
//            std::getline(openBook, bookWord);
//            std::cout << author << " " << bookWord;
//        }

//     fullBook.push_back(bookWord);
//
// }

//Prof example
// ------------------------
//bool foundAuthor = false;
//bool foundTitle = false;
//bool done = foundAuthor && foundTitle;

//while ( openBook >> bookWord ) {
//
// had another while loop here
//      if( word == "Title:" ){
//      string title;
//      getline( in, title );
//      //title.pop_back();
//      //title.erase( title.begin () );
//      std::cout << "title: " << title << std::endl;
//      break; //exit this loop immediately
//
//      }
//
//done = foundAuthor && foundTitle;
//}
//char c;
//int totalChars = 0;
//
// while ( openBook >> c) {
//  if ( c == '\n' ) {
//  return 0;
//  }
//else {
//    std::cout<< c << "\n"; //can swap out \n on lines 247 and 251 for \r to just have it cycle through the chars, not just put one on every line
//
//}
//  totalChars++;
//
//}

//--------------------------------
//original way I found the total num chars...instead of just adding the size of every string in each index prior to a //lol
// int count = 0;
//int a = 0;
//std::string totalSubstring;
//std::string oneCharacter;
////each index of the vector fullBook has a string, count each char within the string, excluding whitespaces
//
//while (a < fullBook.size()){ //less sussy way: count = fullBook[a].size() + count
//
//    int b = 0;
//
//    while( fullBook[a].length() != totalSubstring.length()){ //doing length bc who knows if adding oneCharacter to totalSubstring will put it in the same order as fullBook[a]
//
//        oneCharacter = fullBook[a].substr(b, 1); //position is index b, length is 1, designed to give me a string that is one "character" long at a time
//        count = count + 1; //count everytime there is a "character"
//        totalSubstring = totalSubstring + oneCharacter; //add oneCharacter onto the end of
//        b++;
//    }
//    totalSubstring.clear();
//    oneCharacter.clear();
//    a++;
//}
//
//std::cout<< "The total number of characters is " << count << ".\n";
//
//return count;
