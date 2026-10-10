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
