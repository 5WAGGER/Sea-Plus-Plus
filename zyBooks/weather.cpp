#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class Tuesday {
   public:
      void SetWeather(string tuesdayWeather);      
      void SetTemperature(double tuesdayTemperature);      
      string GetWeather() const;     
      double GetTemperature() const;        
   private:
      string weather;
      double temperature;
};

void Tuesday::SetWeather(string tuesdayWeather) {
   weather = tuesdayWeather;
}

void Tuesday::SetTemperature(double tuesdayTemperature) {
   temperature = tuesdayTemperature;
}

string Tuesday::GetWeather() const {
   return weather;
}

double Tuesday::GetTemperature() const {
   return temperature;
}

int main() {
   Tuesday weather;
   string inputWeather;
   double inputTemperature;

   cin >> inputWeather;
   cin >> inputTemperature;
   weather.SetWeather(inputWeather);
   weather.SetTemperature(inputTemperature);

   cout << "Tuesday: " << weather.GetWeather() << endl;
   cout << "Temperature: " << fixed << setprecision(1) << weather.GetTemperature() << " degrees Celsius" << endl;

   return 0;
}
