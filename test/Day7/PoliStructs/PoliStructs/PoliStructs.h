//h files for specifications, .cpp for implementations
//  PoliStructs.h
//  PoliStructs
//
//  Created by Anna Thomas on 8/31/21.
//

#ifndef PoliStructs_h
#define PoliStructs_h
#include <string>
#include <vector>
#include <iostream>
#include <cmath>

//struct PartyType{ //these are obsolete because they will be declared in the party field
//    std::string Javacan;
//    std::string Cpluser;
//};
//struct OfficeType{
//    std::string state;
//    std::string federal;
//};

struct PoliticianType {
    std::string name; //name of politician
    std::string party; //Javacans or Cplusers
    std::string level; //state or federal
}; //do NOT forget semi-colon after establishing struct

//List all functions here - just the first line of each so the header file knows how to work with it
std::vector<PoliticianType> isJavacans(std::vector<PoliticianType> politicians);
std::vector<PoliticianType> isCplusersFed(std::vector<PoliticianType> politicians);

#endif /* PoliStructs_h */
