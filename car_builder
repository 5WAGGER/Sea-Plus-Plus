#include <iostream>
#include <string>
using namespace std;

void say(string word){
    cout << word << endl;
}

class Car {
public:
    string make;
    string model;
    int year;
    
    string returnInfo() {
        //converting integer to string
        string properYear = to_string(year);
        string output = properYear+" "+make+" "+model+".";
        return output;
    }
    
    void show(){
        
        cout << "A "+to_string(year) + " "+make+" "+model+"!";
    }
};

int main(){
    
    //automatic
    Car myCar;
    myCar.make = "Honda";
    myCar.model = "Civic";
    myCar.year = 2000;
    
    string phrase = myCar.returnInfo();
    say(phrase);

    //dynamic
    Car* thisCar = new Car();
    
    // '->' are pointers
    thisCar->make = "Chevrolet";
    thisCar->model = "Corvette";
    thisCar->year = 2016;
    thisCar->show(); 
}
