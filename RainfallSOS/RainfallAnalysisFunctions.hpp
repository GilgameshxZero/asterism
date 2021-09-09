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
double totalRainfall (std::vector<Stats> &someVector); //helper function for finding the totalRainfall

double findMax(std::vector<Stats> &someVector, int startIndex); //function for finding the most wet

std::vector<Stats> sortPleaseMostWet (std::vector<Stats> &someVector);

std::vector<double> WettestMonths (std::vector<Stats> &someVector);
std::vector<double> DriestMonths (std::vector<Stats> &someVector);

double averageRainfall (std::vector<Stats> &someVector);
double averageRainfallMonth (std::vector<Stats> &someVector, std::string monthName); //take in the month, helper for calculating monthly rainfall

std::vector<Stats> findMedianMonth (std::vector<Stats> &someVector);

std::string makeFinalFile(std::vector<Stats> &someVector);
#endif /* RainfallAnalysisFunctions_hpp */


//when you try your best but you just can't reeeeead...
//when you make what you want, but not what you neeeeeeed...
//stuck in reverse() -heeeerr, hersssee...

//int monthToInt (std::string someMonth); //helper for taking in a string for month and giving an int
//double totalMonthRainfall(std::vector<Stats> &someVector, std::string monthName);
//std::string intToMonth (int a); //helper for taking in a number and spitting out a month
//int findMin(std::vector<Stats> &someVector, int startIndex);
//std::vector<Stats> sortPleaseLeastWet (std::vector<Stats> &someVector);
