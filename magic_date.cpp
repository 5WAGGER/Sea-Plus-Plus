 /* 
  * 5WAGGER
  * 1/28/2026
  * This program asks the user for any date in the format specified above (month/day/2-digit-year). 
  * This program can determine if the month times the day is equal to year.  if (month * day == year) {*magic*}
  * If so, it should display a message saying the date is magic. 
  * Otherwise it should display a message saying the date is not magic. else {*lol*}
  */

#include <iostream>
#include <string>
using namespace std;

int main(){
    
    // declaring integer variables 
    int day;
    int month;
    int year;

    //declaring character variables
    char in_between1;
    char in_between2;

    cout << "Enter a date in the format month/day/2-digit-year: ";
    cin >> day >> in_between1 >> month >> in_between2 >> year;

    if (month * day == year){
        cout << "That is a magic date!" << endl;
    }
    else{
        cout << "That is not a magic date!" << endl;
    }
    return 0;
}
