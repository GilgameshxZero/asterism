//
//  main.cpp
//  BookAnalyzer
//
//  Created by Anna Thomas on 9/5/21.
//

#include "BookAnalyzerFunctions.hpp"

int main(int argc, const char * argv[]) {
    //argc tells how many things are in the array argv[]
    //argv holds the things used to run it + all the tokens after
    
    std::string fileName = "..\\BookAnalyzer\\MobyDick.txt";
    //first thing passed in the command line is the fileName
    
    std::string word = "-encode";
    //second thing passed in the command line is word
    
    std::string secretKey = "3";
    //the third thing passed in the command line is the secretKey, but needs to be in string form
    
    std::vector<std::string> fullBook;
    fullBook = OpenFile(fileName, word, secretKey);
    
    std::string encodedBook;
    int a = 0;
    if( word == "-encode"){
    while(a < fullBook.size()){
            encodedBook += EncodeWord(fullBook[a], secretKey) + " ";
            a++;
    
        }
    }
    
    std::string newFile;
    makeFile(encodedBook, fileName, newFile);
    
    
    return 0;
}


///-----------
//so make secretKey a string

//3 is "3"
//help how fix
//make a function that reads strings to ints
//one already exists, it's std::to_string;
//look into how that works


//    std::string fileName;
//    std::string word;

//    std::cout << "Please enter in a file name containing a book.\n";
//    std::cin >> fileName;
//    std::cout << "Please enter in a word to search within your book.\n";
//    std::cin >> word;
//std::cout << "Please enter in a positive integer for your secret key.\n";
//std::cin >> secretKey;

//std::vector<std::string> userBook = OpenFile(fileName, word);

//encodedUserBook is a vector of strings, but encoded text will be a single string

//makeFile(encodedUserBook, fileName, newFile); //don't need to run in main, have it running in openfile
//evaluates the fileName to determine the name of the new file then reads out the encoded book from said file into the new file

//commented these out, don't need them for part 2

//getTitle(userBook);
//getAuthor(userBook);
//totalNumWords(userBook);

//std::cout<< "The total number of characters is " << totalNumChars(userBook) << ".\n";

//    findLongestWord(userBook);
//    findShortestWord(userBook);
//    KeyWord(userBook, word);

//commented out because encode doesn't need to use this
//but it does work
//findProperNouns(userBook);
