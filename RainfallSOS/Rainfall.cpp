//
//  RainfallAnalysisFunctions.hpp
//  RainfallAnalysis
//
//  Created by Anna Thomas on 9/2/21.
//

#ifndef RainfallAnalysisFunctions_hpp
#define RainfallAnalysisFunctions_hpp

#include <fstream> //library for file stream, used for using the functions output and input
#include <stdlib.h>
#include <vector>
#include <string>
#include <cmath>
#include <iostream>
#include <stdio.h>
#include <iomanip>

struct Stats {
    std::string month;
    int year;
    double rainfall;
};


std::vector<Stats> statsCity (std::string &someFile);
//int monthToInt (std::string someMonth); //helper for taking in a string for month and giving an int

//std::string intToMonth (int a); //helper for taking in a number and spitting out a month
double totalRainfall (std::vector<Stats> &someVector); //helper function for finding the totalRainfall
double totalMonthRainfall(std::vector<Stats> &someVector, std::string monthName);

int findMostWet(std::vector<Stats> &someVector, int startIndex); //function for finding the most wet
void sortPlease (std::vector<Stats> &someVector); //sorts with wettest months in descending order


double averageRainfall (std::vector<Stats> &someVector);
double averageRainfallMonth (std::vector<Stats> &someVector, std::string monthName); //take in the month, helper for calculating monthly rainfall


std::string makeFinalFile(std::vector<Stats> &someVector);
#endif /* RainfallAnalysisFunctions_hpp */


//here are my functions

//
//  RainfallAnalysisFunctions.cpp
//  RainfallAnalysis
//
//  Created by Anna Thomas on 9/2/21.
//

#include "RainfallAnalysisFunctions.hpp"
//functions go here

//std::string Atlanta = "Day9_AtlantaRainfall.txt"; //defined in header file
//std::string Macon = "Day9_MaconRainfall.txt";


std::vector<Stats> statsCity (std::string &someFile) {
    
    
    std::ifstream cityStream(someFile); //variable name is citystream, opens the file city
    
    //std::ifstream() is the syntax
    
    if (cityStream.fail()) {
        
        std::cout << "Failed to open file: \n" << someFile << "\n.";
        
        exit ( 1 );
    }
    
    std::vector<Stats> allCityStats;
    std::string month1;
    int year1;
    double rainfall1;
    
    std::string cityName;
    
    cityStream >> cityName;
    
    while(cityStream >> month1){
        
        cityStream >> year1 >> rainfall1;
        //while cityStream (can) reads in data for month, do {...}
        
        Stats c;
        c.month = month1;
        c.year = year1;
        c.rainfall = rainfall1;
        
        allCityStats.push_back(c);
        //where i'm at in the data
        //std::cout<< c.month;
       
    }
    
    return allCityStats;
    
}

double totalRainfall (std::vector<Stats> &someVector){
   
    double totalRain = 0;
    int a = 0;
    
    for ( ; a < someVector.size(); a++){
        
       totalRain = totalRain + someVector[a].rainfall;
    }
    return totalRain;
}

//wanted to sort via months
double totalMonthRainfall(std::vector<Stats> &someVector, std::string monthName){
    
//    std::vector<Stats> allMonths;
    double totalRain = 0;
    int a = 0;
    
    for ( ; a < someVector.size(); a++){
        
        if (someVector[a].month == monthName){
        
            totalRain = someVector[a].rainfall + totalRain;
            //allMonths[a].rainfall = totalRain;
        }
    }
    //std::cout<< "The total rainfall for " << monthName << " is " << totalRain << " inches.\n";
    return totalRain;
}

std::vector<Stats> allMonthRain (std::string &someMonth, double &a){
    
    
    std::vector<Stats> monthList;
    
    
    
//    a = totalMonthRainfall(Atlantastats, "January");
    
    
    
    return monthList;
}

//most wet rainfall, not most wet month
int findMostWet(std::vector<Stats> &someVector, int startIndex){
    int largestIndex = startIndex;
    
    for(int a = startIndex + 1; a < someVector.size(); a++){
        if( someVector[a].rainfall > someVector[largestIndex].rainfall ){
            largestIndex = a;
        }
    }
    
    return largestIndex;
} //need to sort my vector of month rainfalls in descending order

void sortPlease (std::vector<Stats> &someVector) {
    
    for( int a = 0; a < someVector.size(); a++){
        int largest_Index = findMostWet(someVector, a);
        std::swap( someVector[a], someVector[largest_Index]);

    }
    std::cout<< "Your Atlanta data is now sorted.\n";
}

double averageRainfall (std::vector<Stats> &someVector){
    
    double myAverageRainfall;
    double totalRain = totalRainfall(someVector);
    double allData = someVector.size();
    
    myAverageRainfall = totalRain/allData;
    
    std::cout<< "The overall average rainfall amount is " << myAverageRainfall << " inches.\n";
    
    return myAverageRainfall;
}

double averageRainfallMonth (std::vector<Stats> &someVector, std::string monthName){
    
    double totalRain = totalRainfall(someVector);
    double totalMonth = 0;
    double totalMonthAverage;
    int a = 0;
    
    
    for ( ; a < someVector.size(); a++ ) {
        
        if (someVector[a].month == monthName){
        
            totalMonth = someVector[a].rainfall + totalMonth;
        }
    }
        totalMonthAverage = totalMonth/totalRain;
        
        std::cout<< "The average rainfall amount for " << monthName << " is " << totalMonthAverage << " inches.\n";
    
    return totalMonthAverage;
    
}



std::string makeFinalFile(std::vector<Stats> &someVector){
    
    std::string rainfallResults = "rainfall_results.txt"; //the desired file name
    std::ofstream statsOutput(rainfallResults); //will apply to the string rianfallResults
    statsOutput << std::fixed << std::setprecision(2); //rounds all numbers to two decimal places


    
    if (statsOutput.fail()) {
        
        std::cout << "Failed to output file: \n" << rainfallResults << "\n.";
        
        exit ( 1 );
    }
    
    //statsOutput << someVector; //use operator << for ofstream to "read out", operator >> is for ifstream to "read in"
    //while(statsOutput << someVector){
        
        
    //}
    return rainfallResults;
}



//std::string intToMonth (int a) {
//    std::string month;
//
//    if (a == 1) {
//        month = "January";
//    }
//    if (a == 2) {
//        month = "February";
//    }
//    if (a == 3){
//        month = "March";
//    }
//    if (a == 4){
//        month = "April";
//    }
//    if (a == 5){
//        month = "May";
//    }
//    if (a == 6){
//        month = "June";
//    }
//    if (a == 7){
//        month = "July";
//    }
//    if (a == 8){
//        month = "August";
//    }
//    if (a == 9){
//        month = "September";
//    }
//    if (a == 10){
//        month = "October";
//    }
//    if (a == 11){
//        month = "November";
//    }
//    if (a == 12){
//        month = "December";
//    }
//    return month;
//}
//
////int months[12] {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12}; //an array of 12 ints, initialized to 1-12
////
////for(a = 0; a < 12; a++) {
////
////    int month[a] = intToMont(a);
////}
//
//int monthToInt (std::string someMonth){
//
//    int month = 0;
//
//    if (someMonth == "January"){
//        month = 1;
//    }
//    if (someMonth == "February"){
//        month = 2;
//    }
//    if (someMonth == "March"){
//        month = 3;
//    }
//    if (someMonth == "April"){
//        month = 4;
//    }
//    if (someMonth == "May") {
//        month = 5;
//    }
//    if (someMonth == "June") {
//        month = 6;
//    }
//    if (someMonth == "July") {
//        month = 7;
//    }
//    if (someMonth == "August") {
//        month = 8;
//    }
//    if (someMonth == "September") {
//        month = 9;
//    }
//    if (someMonth == "October") {
//        month = 10;
//    }
//    if (someMonth == "November") {
//        month = 11;
//    }
//    if (someMonth == "December") {
//        month = 12;
//    }
//
//    return month;
//}
//


//here is my main

//
//  main.cpp
//  RainfallAnalysis
//
//  Created by Anna Thomas on 9/2/21.
//

#include "RainfallAnalysisFunctions.hpp"

int main(int argc, const char * argv[]) {
    
    std::string city = "Day9_AtlantaRainfall.txt";
    std::vector<Stats> Atlantastats = statsCity(city);
    //sortPlease(Atlantastats); //now the info in Atlantastats is a sorted vector, with index 0 being the largest rainfall being first
    
    averageRainfall(Atlantastats);
    averageRainfallMonth(Atlantastats, "January");
    averageRainfallMonth(Atlantastats, "February");
    averageRainfallMonth(Atlantastats, "March");
    averageRainfallMonth(Atlantastats, "April");
    averageRainfallMonth(Atlantastats, "May");
    averageRainfallMonth(Atlantastats, "June");
    averageRainfallMonth(Atlantastats, "July");
    averageRainfallMonth(Atlantastats, "August");
    averageRainfallMonth(Atlantastats, "September");
    averageRainfallMonth(Atlantastats, "October");
    averageRainfallMonth(Atlantastats, "November");
    averageRainfallMonth(Atlantastats, "December");
    
    totalMonthRainfall(Atlantastats, "January");
    totalMonthRainfall(Atlantastats, "February");
    totalMonthRainfall(Atlantastats, "March");
    totalMonthRainfall(Atlantastats, "April");
    totalMonthRainfall(Atlantastats, "May");
    totalMonthRainfall(Atlantastats, "June");
    totalMonthRainfall(Atlantastats, "July");
    totalMonthRainfall(Atlantastats, "August");
    totalMonthRainfall(Atlantastats, "September");
    totalMonthRainfall(Atlantastats, "October");
    totalMonthRainfall(Atlantastats, "November");
    totalMonthRainfall(Atlantastats, "December");
    //put these into a vector and sort that because my sort doesn't sort strings...
    //make a vector that takes in ints and gives a std::vector<Stats>
    
    
    
    //go into an array with an int and pull out the string for the month name, then have it run for all 12 months
    //make another struct that shoves all months into a bag?
               
    
    
    
    return 0;
    
}