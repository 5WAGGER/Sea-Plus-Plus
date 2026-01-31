
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

int main() {
   string inputFile;

   // Get the name of the input file
   cin >> inputFile;

   // Open the input file
   ifstream file(inputFile);

   // Print contents of input file
   if (file.is_open()) {
      cout << file.rdbuf();
   }

   // Close the input file
   file.close();

   return 0;
}

// type hello.txt into console to print what's in the hello.txt file
