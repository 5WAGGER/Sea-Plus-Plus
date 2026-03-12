
/*
  * Quentin Jeriko
  * COMS 215
  * 3/11/2026
  * Project 16.2 version 16.9.1
  * This program records high-score data for a fictional game. 
  * The player will input how many scores total.
  * The program will create two dynamic arrays.
  * Then the player will input each score per name.
  * Then program will sort the score in descending order (highest to lowest).
  */

#include <iostream>
#include <string>
using namespace std;

// Initializing prototype functions (pass-by-reference)
void readData(string names[], int scores[], int size);
void sortData(string names[], int scores[], int size);
void displayData(const string names[], const int scores[], int size);

int main(){
    int size;
    cout << "How many scores will you enter?: ";
    cin >> size;

    // Allocating dynamic arrays
    string* names = new string[size];
    int* scores = new int[size];

    // Using functions
    readData(names, scores, size);
    sortData(names, scores, size);
    displayData(names, scores, size);

    // Freeing up memory for added efficiency 
    delete[] names;
    delete[] scores;

    return 0;
}

void readData(string names[], int scores[], int size) {
    for (int i = 0; i < size; i++) {
        cout << "Enter the name for score #" << (i+1) << ": ";
        cin >> names[i];
        cout << "Enter the score for score #" << (i+1) << ": ";
        cin >> scores[i];
    }
}

void sortData(string names[], int scores[], int size) {
    // Bubble sort in descending order
    for (int i = 0; i < size -1; i++) {
        for (int z = 0; z < size - 1 - i; z++){
            if(scores[z] < scores[z+1]) {
                // passing pointer as parameter
                std::swap(scores[z], scores[z + 1]);
                std::swap(names[z], names[z + 1]);
            }
        }
    }
}

void displayData(const string names[], const int scores[], int size) {
    cout << "\nTop Scorers:\n";
    for (int i = 0; i < size; i++) {
        cout << names[i] << ": " << scores[i] << endl;
    }
}
