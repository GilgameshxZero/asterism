//
//  RainfallAnalysisFunctions.cpp
//  RainfallAnalysis
//
//  Created by Anna Thomas on 9/2/21.
//

#include "RainfallAnalysisFunctions.hpp"
//functions go here


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


//most wet rainfall, not most wet month
double findMax(std::vector<Stats> &someVector, int startIndex){
    int largestIndex = startIndex;
    
    for(int a = startIndex + 1; a < someVector.size(); a++){
        if( someVector[a].rainfall > someVector[largestIndex].rainfall ){
            largestIndex = a;
        }
    }
    
    return largestIndex;
}//need to sort my vector of month rainfalls in descending order

std::vector<Stats> sortPleaseMostWet (std::vector<Stats> &someVector) {
    
    std::vector<Stats> sortedVector;
    for( int a = 0; a < someVector.size(); a++){
        
        int largest_Index = findMax(someVector, a);
        
        std::swap( someVector[a], someVector[largest_Index]);
        sortedVector = someVector;
    }
    std::cout<< "Your Atlanta data is now sorted.\n";
    return sortedVector;
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


std::vector<double> WettestMonths (std::vector<Stats> &someVector){
    
    std::vector<double> ListofMonths(4);
    std::vector<Stats> sortedVector = sortPleaseMostWet(someVector);
    
    for (int a = ListofMonths.size()-1; a >= 0; a--){
        
        ListofMonths[a] = (sortedVector[a].rainfall);
        
    }
    std::cout<< "The rain amount, in inches, of the four wettest months is: " << ListofMonths[0] << " " << ListofMonths[1] << " " << ListofMonths[2] <<  " " << ListofMonths[3] << std::endl;
    
    return ListofMonths;
}

std::vector<double> DriestMonths (std::vector<Stats> &someVector){
    
    std::vector<double> ListofMonths(4);
    std::vector<Stats> sortedVector = sortPleaseMostWet(someVector);
    
    for (int a = someVector.size(); a >= someVector.size() - ListofMonths.size(); a--){
        
        ListofMonths[someVector.size() - (a+1)] = (someVector[a].rainfall); //pushback will keep the empy vector of 4 and just add indexes onto it
        
    }
    std::cout<< "The rain amount, in inches, of the four driest months is: " << ListofMonths[0] << " " << ListofMonths[1] << " " << ListofMonths[2] <<  " " << ListofMonths[3] << std::endl;
    
    return ListofMonths;
}

std::vector<Stats> findMedianMonth (std::vector<Stats> &someVector){
    
    std::vector<Stats> monthStats(1);
    std::vector<Stats> sortedVector = sortPleaseMostWet(someVector);
    
    int middle = sortedVector.size()/2;
    monthStats[0] = sortedVector[middle];
    

    return monthStats;
}

std::string makeFinalFile(std::vector<Stats> &someVector){
    
    std::string rainfallResults = "rainfall_results.txt"; //the desired file name
    std::ofstream statsOutput(rainfallResults); //will apply to the string rianfallResults
    statsOutput << std::fixed << std::setprecision(2); //rounds all numbers to two decimal places
    
    if (statsOutput.fail()) {
        
        std::cout << "Failed to output file: \n" << rainfallResults << "\n.";
        
        exit ( 1 );
    }
    
    std::string City;
    City = "Atlanta";
    
    statsOutput << "CS 6010 Rainfall Analysis" << std::endl;
    statsOutput << "Rainfall data for " << City << std::endl;
    statsOutput << " " << std::endl;
    
    std::string city = "Day9_AtlantaRainfall.txt";
    std::vector<Stats> Atlantastats = statsCity(city);
    
    
    statsOutput << "The overall average rainfall amount is " << averageRainfall(Atlantastats) << " inches.\n";
    statsOutput << " " << std::endl;
    statsOutput << "The average rainfall amount for January" << " is " << averageRainfallMonth(Atlantastats, "January") << " inches.\n";
    statsOutput << "The average rainfall amount for February" << " is " << averageRainfallMonth(Atlantastats, "February") << " inches.\n";
    statsOutput << "The average rainfall amount for March" << " is " << averageRainfallMonth(Atlantastats, "March") << " inches.\n";
    statsOutput << "The average rainfall amount for April" << " is " << averageRainfallMonth(Atlantastats, "April") << " inches.\n";
    statsOutput << "The average rainfall amount for May" << " is " << averageRainfallMonth(Atlantastats, "May") << " inches.\n";
    statsOutput << "The average rainfall amount for June" << " is " << averageRainfallMonth(Atlantastats, "June") << " inches.\n";
    statsOutput << "The average rainfall amount for July" << " is " << averageRainfallMonth(Atlantastats, "July") << " inches.\n";
    statsOutput << "The average rainfall amount for August" << " is " << averageRainfallMonth(Atlantastats, "August") << " inches.\n";
    statsOutput << "The average rainfall amount for September" << " is " << averageRainfallMonth(Atlantastats, "September") << " inches.\n";
    statsOutput << "The average rainfall amount for October" << " is " << averageRainfallMonth(Atlantastats, "October") << " inches.\n";
    statsOutput << "The average rainfall amount for November" << " is " << averageRainfallMonth(Atlantastats, "November") << " inches.\n";
    statsOutput << "The average rainfall amount for December" << " is " << averageRainfallMonth(Atlantastats, "December") << " inches.\n";
    statsOutput <<  " " << std::endl;
    
    WettestMonths(Atlantastats);
    statsOutput << "The rain amount, in inches, of the four wettest months is: " << WettestMonths(Atlantastats)[0] << " " << WettestMonths(Atlantastats)[1] << " " << WettestMonths(Atlantastats)[2] <<  " " << WettestMonths(Atlantastats)[3] << std::endl;
    statsOutput <<  " " << std::endl;
    DriestMonths(Atlantastats);
    statsOutput << "The rain amount, in inches, of the four driest months is: " << DriestMonths(Atlantastats)[0] << " " << DriestMonths(Atlantastats)[1] << " " << DriestMonths(Atlantastats)[2] <<  " " << DriestMonths(Atlantastats)[3] << std::endl;
    statsOutput <<  " " << std::endl;
            
    std::vector<Stats> midMonth = findMedianMonth(Atlantastats);
    statsOutput << "The median month is: " << "\n" << midMonth[0].month << " " << midMonth[0].year << " " << midMonth[0].rainfall << "\n";
 
    
    return rainfallResults;
}


//when you try your best but you just can't reeeeead...
//when you make what you want, but not what you neeeeeeed...
//stuck in reverse() -heeeerr, hersssee...

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


//wanted to sort via months
//double totalMonthRainfall(std::vector<Stats> &someVector, std::string monthName){
//
////    std::vector<Stats> allMonths;
//    double totalRain = 0;
//    int a = 0;
//
//    for ( ; a < someVector.size(); a++){
//
//        if (someVector[a].month == monthName){
//
//            totalRain = someVector[a].rainfall + totalRain;
//            //allMonths[a].rainfall = totalRain;
//        }
//    }
//    //std::cout<< "The total rainfall for " << monthName << " is " << totalRain << " inches.\n";
//    return totalRain;
//}

//std::vector<Stats> allMonthRain (std::string &someMonth, double &a){
//
//
//    std::vector<Stats> monthList;
//
//
    
//    a = totalMonthRainfall(Atlantastats, "January");
    
    
    
//    return monthList;
//}

//std::string Atlanta = "Day9_AtlantaRainfall.txt"; //defined in header file
//std::string Macon = "Day9_MaconRainfall.txt";

//
//std::vector<Stats> sortPleaseLeastWet (std::vector<Stats> &someVector) {
//
//    std::vector<Stats> sortedVector;
//    for( int a = 0; a < someVector.size(); a++){
//
//        int smallest_Index = findMin(someVector, a);
//
//        std::swap( someVector[a], someVector[smallest_Index]);
//        sortedVector = someVector;
//    }
//    std::cout<< "Your Atlanta data is now sorted.\n";
//    return sortedVector;
//}


//double findMin(std::vector<Stats> &someVector, int startIndex){
//    int smallestIndex = startIndex;
//
//    for(int a = startIndex + 1; a < someVector.size(); a++){
//        if( someVector[a].rainfall > someVector[smallestIndex].rainfall ){
//            smallestIndex = a;
//        }
//    }
//
//    return smallestIndex;
//}
