//
//  BookAnalyzerFunctions.cpp
//  BookAnalyzer
//
//  Created by Anna Thomas on 9/5/21.
//

#include "BookAnalyzerFunctions.hpp"

std::vector<std::string> OpenFile(const std::string &fileName, const std::string &userWord, std::string &secretKey){
    
    std::ifstream openBook (fileName);
    
    if (openBook.fail()){
        std::cout << "Failed to open file: \n" << fileName << "\n.";
        
        exit ( 1 );
    }
        
    std::vector<std::string> fullBook;
    std::string bookWord;
    std::string newFile; //just need to declare
    
    while (openBook >> bookWord) {
        
        fullBook.push_back(bookWord);
        
    }
    
    return fullBook;
}


std::string getTitle (std::vector<std::string> &fullBook){
    
    
    std::string title = "Title:";
    std::vector<std::string> totalLine;

    for(int a = 0; a < 101; a++){ //check the first 100 words
    
        if( fullBook[a] == title ){
        
            while (fullBook[a] != "Author:"){ //turn into a helper function to be easier to read
                
            std::cout<< fullBook[a] << " ";
            a++;
            totalLine.push_back(fullBook[a]);
            
            }
            
        if(totalLine.size() > 10){ //can increase for longer book titles
            std::cout<< "\n" << "\n";
            std::cout << "Error in formatting. Could not define the title properly.\n";
            return title;
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

std::string getAuthor (std::vector<std::string> &fullBook){ //since basically the same as getTitle, don't need a separate function, just need to be able to switch the parameters

    std::string author = "Author:";
    std::vector<std::string> totalLine;
    
    for(int a = 0; a < 101; a++){
        if( fullBook[a] == author ){

            while (fullBook[a] != "Release"){
                
                std::cout << fullBook[a] << " ";
                a++;
                totalLine.push_back(fullBook[a]);
                
            
            }
            
        if(totalLine.size() > 10){ //can increase for longer names
                std::cout<< "\n" << "\n";
                std::cout << "Error in formatting. Could not define the author properly.\n";
                return author;
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

int totalNumWords (std::vector<std::string> &fullBook) { //can just return fullBook.size() because it's a vector of STRINGS!! each string is a word
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
//can parameters be operators so as to condense findLongest and findShortest
//look up functional programming -- pass in functions as a parameter

std::string KeyWord (std::vector<std::string> &fullBook, std::string &userWord) {
    
    std::string done;
    std::vector<std::string> userWordAppearances;
    std::string userWordSet;
    std::vector<double> userWordLocations;
    double location = 0;
    double count = 0; //number of times the userWord occurs
    double count2 = 0; //total chars up to a point
    
    for( int a = 0; a < fullBook.size(); a++){
        
        if ( fullBook[a] == userWord){
            count2 = 0; //re-assign value in if statement so that the count2 is reset everytime there is another existence of userWord
            count = count + 1;
            
            userWordSet = fullBook[a - 1] + " " + fullBook[a] + " " + fullBook[a+1] + "\n";
            userWordAppearances.push_back(userWordSet);
            
            //have it count until the index a
            for ( int b = 0; b < a; b++){ //can extract into separate function
                //aka make a helper function
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
    
    for( int a = 1; a < fullBook.size()-1; a++){
        
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
    //want the output to be a string bc...look down at encode function
    //int can't be stored in a char
    
        std::string Total;
        int exponent = word.length()-1;
        
        for( int a = 0; a < word.length(); a++){
            
            char singleCharacter = word[a];
            int convertedCharacter = 0;
            
            if( singleCharacter <= '9'){
                convertedCharacter = singleCharacter - '0';
            }
            
            else{
                if (singleCharacter < 'a'){
                    singleCharacter = singleCharacter + ' '; //' ' value is 32 on ascii table
                }
                
                convertedCharacter = singleCharacter - 'a' + 10; // -87
            }
            
            Total = Total + std::to_string(convertedCharacter * std::pow(2, exponent));
            //cast convertedCharacter * std::pow(2, exponent) as a string
            //will it still perform the operations inside?
            //if I take an equation and put it in a string, will it still do my equation?
            //NO!!!
            //need to use a function to convert an int to string form
            //where std::stoi converts a string to int,
            //std::to_string converts an int to string
            
            exponent--;
        }
        
        //std::cout << "The value of " << word << " is " << Total << std::endl;
        
        return Total;
    }
//Returns the binary string representation of the decimal string. You probably already wrote this function in your binary converter assignment.


std::string EncodeWord( const std::string &word, std::string &secretKey) {
    
    std::string encodedText;
    std::stoi(secretKey);
    int myNumber = std::stoi(secretKey);
    
    char oldChar; //the initial char
    char newChar; //the char after the encode

    
    for( int a = 0; a < word.length(); a++){//break up each string "word" into chars
        oldChar = word[a];
        
        if (IsUpper(oldChar) == true){
            newChar = (oldChar - 'A' + myNumber) % 26 + 'A'; //the char after the encode //if ascii values are 65 - 90 'A' to 'Z'
        }
        else if(IsLower(oldChar) == true){
            newChar = (oldChar - 'a' + myNumber) % 26 + 'a'; //the char after the encode //if ascii values are 97 - 122 'a' to 'z'
        }
        else if(IsDigit(oldChar) == true){
            newChar = (oldChar - '0' + myNumber) % 10 + '0'; //the char after the encode //if ascii values are 48 - 57 '0' to '9'
        }
        else {
            newChar = oldChar;
        }
       
        
        if (IsDecimalWord(word) == true){ //if receive a word of only digits
            //need to replace that word with the binary equivalent because assignment said so
            std::string converted = DecimalToBinary(word); //this gives a string
            converted[a] = newChar; //this will index into the string converted and receive a char and assign that to newChar
            
            
        }
        
        encodedText.push_back(newChar);
    }
        //std::cout << encodedText;
        
        return encodedText;
    }
    

void makeFile ( const std::string &encodedText, const std::string &fileName, std::string &newFile) { //take the output of EncodeWord function
    //newFile is what the ofstream is outputting it to
    //a parameter doesn't always take just input, it can be output as well;
    
    //std::string newFile = fileName + "_encoded"; //but .txt would be before encoded lol
    //fix by taking the substring .txt out of fileName
    std::string suffix = "_encoded";
    std::string txt; //for substring ".txt"
    std::string name; //fileName without .txt
    
    for( int a = 0; a < fileName.length(); a++){
        
        
        if (fileName.substr(a, a + 4) == ".txt"){ //since .txt is length of 4 char
       
        txt = fileName.substr(a, a + 4);
        }
        
    name = fileName.substr(0, a);
    }
 
    newFile = name + suffix + txt; //take out .txt from the og filename, add the suffix for _encode, then add .txt back in
    //creates this File with the name of those concatenated strings
    
    std::ofstream write (newFile);
    //opens the file newFile, and prepares to put stuff in it
    
    write << encodedText;
    //puts the cout of encoded text in the file write opens to prepare to write to (aka newFile)
    //encodedText is a string,
    //cout "opens" the terminal and std::cout << "hi"; opens the terminal and writes out the string "hi"
   
    
    if (write.fail()){
        std::cout << "Failed to make file: \n" << newFile << "\n.";
        
        exit ( 1 );
    }
    
    write.close();
}
 

//    // std::string word = argv[2]; /
//    //second thing passed in the command line is a string word
//
    //this is where we do the encoding
//if the user provides a secretKey of 0, no encryption will happen
//EncodeWord outputs a giant long string of all the encryption (NOT a vector of strings

//        makeFile(encodedBook, fileName, newFile);

//-----------
//std::string encodeHelper (std::vector<std::string> &fullBook, const int &secretKey){
//
//    std::string encodedBook;
//    int a = 0;
//    while(a < fullBook.size()){
//    if( userWord == "-encode"){ //only do this if the second command line prompt is -encode
//        encodedBook = EncodeWord(fullBook[a], secretKey);
//
//    }
//        a++;
//    }
//    return encodedBook;
//}
//-----------
//    while( makeFile << newFile){ //while reading out to newFile
//        //don't need a loop lol
    //just tell it to read out to newFile
//
//        newFile.push_back(newFile);
//        //while outputting the og File
//        //needs to rename it to newFile
//    }
//    write << newFile; //do std::ofstream write on fileName and write out to the newFile
 

//String containing the substring [pos, pos+count) or [pos, size())
//[ means must be included, ) is optional
//don't literally write it as [pos, pos+count) lol
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

// dealing with paths:

//-------
//thinks that /Users/anna/Desktop/CS6010/GIT/annaThomas myGithhubRepo/Day10/ is part of the file name
//could get rid of this issue by putting the original .txt file in the same directory
//could also get rid of it by dealing with paths
//but paths are HARD
//so just put everything in the same directory
//-------
//or...

//for ( start; start < fileName.length(); start++){
//
//    if (fileName[start] != '/'){
//    name = fileName.substr(start, a);
//    }
//
//    if (fileName[start] == '/'){
//        name.clear();
//    }
//}
//
//if (fileName.substr(a, a + 4) == ".txt"){ //since .txt is length of 4 char
//
//txt = fileName.substr(a, a + 4);
//
//}
//}
//// name = fileName.substr(slash + 1, a); //name will be everything from the start of the string up til point a where the substring .txt was found
////want to change index 0 to be the index of the last /
////parameters --> (recent "/" index, a)
//
////doesn't work for storing the substr at these parameters in string //if "mobydick.txt" is og
////want "mobydick_encoded.txt"
////issue i'm getting:
//// /Users/anna/Desktop/CS6010/GIT/annaThomas myGithhubRepo/Day10/MobyDick.txt
////_encoded.txt
////thinks that /Users/anna/Desktop/CS6010/GIT/annaThomas myGithhubRepo/Day10/ is part of the file name
////could get rid of this issue by putting the original .txt file in the same directory
////could also get rid of it by...
////read after the last /

// name = fileName.substr(slash + 1, a); //name will be everything from the start of the string up til point a where the substring .txt was found
 //want to change index 0 to be the index of the last /
 //parameters --> (recent "/" index, a)

 //doesn't work for storing the substr at these parameters in string //if "mobydick.txt" is og
 //want "mobydick_encoded.txt"
 //issue i'm getting:
// /Users/anna/Desktop/CS6010/GIT/annaThomas myGithhubRepo/Day10/MobyDick.txt
//_encoded.txt
