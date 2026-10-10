/*
 * Quentin Jeriko
 * COMS 215
 * 3/11/2026
 * Project 16.2 version 16.9.1
 * This program records high-score data for a fictional game.
 * The user enters the number of scores.
 * The program creates two dynamic arrays.
 * The user enters each player's name and score.
 * The program sorts the scores in descending order
 * while keeping each name paired with its score.
 */

#include <iostream>
#include <string>
#include <utility>
using namespace std;

// Function prototypes
void readData(string names[], int scores[], int size);
void sortData(string names[], int scores[], int size);
void displayData(const string names[], const int scores[], int size);

int main() {
    int size;

    cout << "How many scores will you enter?: ";
    cin >> size;

    // Allocate the dynamic arrays
    string* names = new string[size];
    int* scores = new int[size];

    readData(names, scores, size);
    sortData(names, scores, size);
    displayData(names, scores, size);

    // Deallocate the dynamic arrays
    delete[] names;
    delete[] scores;

    return 0;
}

void readData(string names[], int scores[], int size) {
    for (int i = 0; i < size; i++) {
        cout << "Enter the name for score #" << (i + 1) << ": ";
        cin >> names[i];

        cout << "Enter the score for score #" << (i + 1) << ": ";
        cin >> scores[i];
    }
}

void sortData(string names[], int scores[], int size) {
    // Bubble sort in descending order
    for (int i = 0; i < size - 1; i++) {
        for (int z = 0; z < size - 1 - i; z++) {
            if (scores[z] < scores[z + 1]) {
                // Swap adjacent scores and their corresponding names
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
