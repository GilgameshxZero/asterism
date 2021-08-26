
#include <iostream>
#include <cmath>

using namespace std;

int main(int argc, const char * argv[]) {
    
    string date = " ";
    
    cout<< "Please enter a date in mm/dd/yyyy format.\n";
    cin>> date;
    
    int month [12] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
    
    int day [31];
    for (int x = 1; x <=31; x++) {
        day[x-1] = x; //do day[x-1] because arrays start at 0, but here x will start at 1
    }
    //if want day == 3, index day[2] (since arrays start at 0)
    
    int year [121];
    for (int x = 1900; x <=2021; x++){
        year[x-1] = x;
    
    }