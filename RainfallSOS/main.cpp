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
    
    averageRainfall(Atlantastats);
    std::cout<< " " << std::endl;
    averageRainfallMonth(Atlantastats, "January");
    std::cout<< " " << std::endl;
    averageRainfallMonth(Atlantastats, "February");
    std::cout<< " " << std::endl;
    averageRainfallMonth(Atlantastats, "March");
    std::cout<< " " << std::endl;
    averageRainfallMonth(Atlantastats, "April");
    std::cout<< " " << std::endl;
    averageRainfallMonth(Atlantastats, "May");
    std::cout<< " " << std::endl;
    averageRainfallMonth(Atlantastats, "June");
    std::cout<< " " << std::endl;
    averageRainfallMonth(Atlantastats, "July");
    std::cout<< " " << std::endl;
    averageRainfallMonth(Atlantastats, "August");
    std::cout<< " " << std::endl;
    averageRainfallMonth(Atlantastats, "September");
    std::cout<< " " << std::endl;
    averageRainfallMonth(Atlantastats, "October");
    std::cout<< " " << std::endl;
    averageRainfallMonth(Atlantastats, "November");
    std::cout<< " " << std::endl;
    averageRainfallMonth(Atlantastats, "December");
    std::cout<< " " << std::endl;
    
    WettestMonths(Atlantastats);
    std::cout<< " " << std::endl;
    DriestMonths(Atlantastats);
    std::cout<< " " << std::endl;
            
    findMedianMonth(Atlantastats);
    //std::cout<< "The median month is: " << findMedianMonth(Atlantastats) << ".\n";
    
    makeFinalFile(Atlantastats);
    
    return 0;
    
}

//    totalMonthRainfall(Atlantastats, "January");
//    totalMonthRainfall(Atlantastats, "February");
//    totalMonthRainfall(Atlantastats, "March");
//    totalMonthRainfall(Atlantastats, "April");
//    totalMonthRainfall(Atlantastats, "May");
//    totalMonthRainfall(Atlantastats, "June");
//    totalMonthRainfall(Atlantastats, "July");
//    totalMonthRainfall(Atlantastats, "August");
//    totalMonthRainfall(Atlantastats, "September");
//    totalMonthRainfall(Atlantastats, "October");
//    totalMonthRainfall(Atlantastats, "November");
//    totalMonthRainfall(Atlantastats, "December");
    //put these into a vector and sort that because my sort doesn't sort strings...
    //make a vector that takes in ints and gives a std::vector<Stats>
    
    
    
    //go into an array with an int and pull out the string for the month name, then have it run for all 12 months
    //make another struct that shoves all months into a bag?
