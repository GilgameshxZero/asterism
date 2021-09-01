//
//  PoliStructsFunctions.cpp
//  PoliStructs
//
//  Created by Anna Thomas on 8/31/21.
//
//for( ; a < politician.size(); a++){
    //for(std::int i = 0; i < p.size(); i++)
    //p = politician[a]
    
//for(std::string "p" : politician) //don't need to initialize "p" here, because a for each loop structure will enter the loop first, look at what "p" means (put declaration inside) and then execute the code after
    //p == Javacan
#include "PoliStructs.h"

//this header already includes strings, vectors, and iostream -don't need to redeclare
//int main(){}

std::vector<PoliticianType> isJavacans (std::vector<PoliticianType> politicians){
    
    std::vector<PoliticianType> onlyJavacans;
    
    for(PoliticianType p : politicians){ // for each loops will ALWAYS start at someVector[0] (said sub zero) and look at each value stored at every index after the starting point vs for loops start at some index that the programmer defines and they go until the condition is "untrue"
        
        //for loop structure  for( initialization; condition; increment/updation){ do this }
        //for each loop structure  for( variable : someVector) { do this }
    

        if (p.party == "Javacan"){ //structure variable.field, if the .party of somevariable PoliticianType p is equal to the string "Javacan"
            onlyJavacans.push_back( p ); //take the whole PoliticianType p variable that has its "party" field equal to "Javacan" and add it to the vector<PoliticianType> variable "onlyJavacans"
    
        }
    }
    return onlyJavacans; //output the brandnew vector<PoliticianType> variable "onlyJavacans" that will only have PoliticianType variables whose party is Javacan
}

std::vector<PoliticianType> isCplusersFed (std::vector<PoliticianType> politicians){
    
    std::vector<PoliticianType> onlyCplusers;
    
    for(PoliticianType p : politicians){
        if (p.party == "Cpluser" && p.level == "federal"){ //structure variable.field
            onlyCplusers.push_back( p );
    
        }
    }
    return onlyCplusers;
}
