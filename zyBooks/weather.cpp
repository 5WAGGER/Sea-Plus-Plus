#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class Tuesday {
   public:
      void SetWeather(string tuesdayWeather); 
      void SetHumidity(double tuesdayHumidity);      
      string GetWeather() const;                        
      double GetHumidity() const;                        
      void Print() const;              
   private:
      string weather;
      double humidity;
};

void Tuesday::SetWeather(string tuesdayWeather) {
   weather = tuesdayWeather;
}

void Tuesday::SetHumidity(double tuesdayHumidity) {
   humidity = tuesdayHumidity;
}

string Tuesday::GetWeather() const {
   return weather;
}

double Tuesday::GetHumidity() const {
   return humidity;
}

int main() {
   Tuesday weather;
   string inputWeather;
   double inputHumidity;

   cin >> inputWeather;
   cin >> inputHumidity;
   
   weather.SetWeather(inputWeather);
   weather.SetHumidity(inputHumidity);
 
   cout << "Today's weather is " << weather.GetWeather();
   cout << ", " << fixed << setprecision(1) << weather.GetHumidity() << "%" << endl;

   return 0;
}
