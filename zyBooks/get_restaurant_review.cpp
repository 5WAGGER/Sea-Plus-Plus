#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class Restaurant {
   public:
      void SetName(string restaurantName);      
      void SetRating(int restaurantRating);     
      void Print() const;   
   private:
      string name;
      int rating;
};

void Restaurant::SetName(string restaurantName) {
   name = restaurantName + "'s Buffet";
}

void Restaurant::SetRating(int restaurantRating) {
   rating = restaurantRating;
}


void Restaurant::Print() const {
   cout << "Restaurant: " << name << endl;
   cout << "Rating: " << rating << " stars" << endl;
}

int main() {
   Restaurant restaurant;
   string inputName;
   int inputRating;

   cin >> inputName;
   cin >> inputRating;
   restaurant.SetName(inputName);
   restaurant.SetRating(inputRating);

   restaurant.Print();

   return 0;
}


//input is 
// Meg's Buffet
