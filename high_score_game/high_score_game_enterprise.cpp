#include <iostream>
#include <string>
using namespace std;

// Function prototypes - arrays decay to pointers (pass-by-reference semantics)
void readData(string names[], int scores[], int size);
void sortData(string names[], int scores[], int size);
void displayData(const string names[], const int scores[], int size);

int main() {
    int size;
    cout << "How many scores will you enter?: ";
    cin >> size;
    
    // Allocate dynamic arrays
    string* names = new string[size];
    int* scores = new int[size];
    
    // Call the three functions
    readData(names, scores, size);
    sortData(names, scores, size);
    displayData(names, scores, size);
    
    // Deallocate arrays
    delete[] names;
    delete[] scores;
    
    return 0;
}

void readData(string names[], int scores[], int size) {
    for (int i = 0; i < size; i++) {
        cout << "Enter the name for score #" << (i+1) << ": ";
        cin >> names[i];  // Single word names OK for this assignment
        cout << "Enter the score for score #" << (i+1) << ": ";
        cin >> scores[i];
    }
}

void sortData(string names[], int scores[], int size) {
    // Bubble sort - descending order by score
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - 1 - i; j++) {
            if (scores[j] < scores[j + 1]) {
                // Use std::swap - internally passes objects by reference (Style 7d compliant)
                std::swap(scores[j], scores[j + 1]);
                std::swap(names[j], names[j + 1]);
            }
        }
    }
}

void displayData(const string names[], const int scores[], int size) {
    cout << "\nTop Scorers:\n";  // Fixed escape sequences
    for (int i = 0; i < size; i++) {
        cout << names[i] << ": " << scores[i] << endl;
    }
}
