//
//  main.cpp
//  PoliStructs
//
//  Created by Anna Thomas on 8/31/21.
//

#include "PoliStructs.h"
#include <cassert>

using namespace std;

int main(int argc, const char * argv[]) {
    
    PoliticianType Ben{"Ben", "Javacan", "federal"}; //when declaring a variable of PoliticianType, must store all values for PoliticianType. Cannot leave values empty
    PoliticianType Alex{"Alex", "Cpluser", "federal"}; //structure variable.field
    PoliticianType Gurt{"Gurt", "Cpluser", "local"};
    vector<PoliticianType> Test {Ben, Alex, Gurt};
    vector<PoliticianType> CorrectforJavacans {Ben};
    vector<PoliticianType> CorrectforCplusers {Alex};
    
    vector<PoliticianType> results = isJavacans( Test );
    vector<PoliticianType> results2 = isCplusersFed( Test );
    
//assert is not that intelligent. It cannot do "math" with vectors, but it CAN evaluate a vector at an index and see if those values match
//    assert(results2[0].name == CorrectforCplusers[0].name); //potential corner/fringe case: you have two politicians with the same name from difference parties. account for this by matching up .party instead
    
    assert(results[0].party == CorrectforJavacans[0].party ); //party values will always match up, but the same name could be associated with different parties
    assert(results2[0].party == CorrectforCplusers[0].party && results2[0].level == CorrectforCplusers[0].level); //must work for BOTH party and level (be cpluser and federal)
//    assert((isJavacans(Test) == CorrectforJavacans));
//    assert((isCplusers(Test) == CorrectforCplusers));
    cout<< "All tests passed.\n";
    return 0;
}
