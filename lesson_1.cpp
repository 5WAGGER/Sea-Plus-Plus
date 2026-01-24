#include <iostream>
using namespace std;

int main() {
    
    int hours; // declaration
    int payRate;
    int total;
    
    /*
    stream extraction operator
    */
    
    cout << "Enter hours worked: ";
    cin >> hours; 
    cout << "Enter hourly payrate: ";
    cin >> payRate;
    total = hours * payRate;
    cout << "Your paycheck is $" 
    << total << "!" << endl;
}
