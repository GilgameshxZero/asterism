//
//  main.cpp
//  BookAnalyzer
//
//  Created by Anna Thomas on 9/5/21.
//

#include "BookAnalyzerFunctions.hpp"

int main(int argc, const char * argv[]) {
    
    std::string fileName;
    std::string word;
    int secretKey;
    
    std::cout << "Please enter in a file name containing a book.\n";
    std::cin >> fileName;
    std::cout << "Please enter in a word to search within your book.\n";
    std::cin >> word;
    std::cout << "Please enter in a positive integer for your secret key.\n";
    std::cin >> secretKey;
    
    std::vector<std::string> userBook = OpenFile(fileName, word, secretKey);
    getTitle(userBook);
    getAuthor(userBook);
    totalNumWords(userBook);
    
    std::cout<< "The total number of characters is " << totalNumChars(userBook) << ".\n";
    
    findLongestWord(userBook);
    findShortestWord(userBook);
    KeyWord(userBook, word);
    
    findProperNouns(userBook);

    
    return 0;
}
