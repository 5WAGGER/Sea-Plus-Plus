#include <iostream>
using namespace std;



/*
============================================================
 Project 13.1 – Poker Hand Classifier
 Author: [Your Name]
 Course: COMS 215 – Programming Concepts & Methodology I
 Instructor: Dave Harden
 Description:
     Program reads numeric “cards” from the user (values between
     LOWEST_NUM and HIGHEST_NUM) and determines the poker
     hand type represented. Supports variable hand sizes
     for Parts A, B, and C.
============================================================
*/



// ============================================================
// CONFIGURATION SECTION
// ============================================================
//
// Part A configuration (default):
//   HAND_SIZE = 5
//   LOWEST_NUM = 2
//   HIGHEST_NUM = 9
//
// Part B configuration:
//   HAND_SIZE = 6
//   LOWEST_NUM = 1
//   HIGHEST_NUM = 13
//
// Part C configuration:
//   HAND_SIZE = 8
//   LOWEST_NUM = 1
//   HIGHEST_NUM = 13
//
// ------------------------------------------------------------
// INSTRUCTIONS:
// Uncomment the group labeled “Part A”, “Part B”, or “Part C”
// depending on which version you are submitting or testing.
// ------------------------------------------------------------


// ---------- Part A ----------
// const int HAND_SIZE = 5;
// const int LOWEST_NUM = 2;
// const int HIGHEST_NUM = 9;


// ---------- Part B ----------
// const int HAND_SIZE = 6;
// const int LOWEST_NUM = 1;
// const int HIGHEST_NUM = 13;


// ---------- Part C ----------
const int HAND_SIZE = 8;
const int LOWEST_NUM = 1;
const int HIGHEST_NUM = 13;
// ----------------------------





// ============================================================
// HELPER FUNCTION
// ============================================================

/*
============================================================
 Function: countValues
 Purpose:
     Builds an integer frequency table that counts how many
     times each card value appears in the input hand array.
 Parameters:
     hand[]   – array of cards
     counts[] – array storing frequency of each value
     lowest   – minimum possible card
     highest  – maximum possible card
============================================================
*/
void countValues(const int hand[], int counts[], int lowest, int highest) {
    int range = highest - lowest + 1;
    for (int i = 0; i < range; ++i) {
        counts[i] = 0;
    }

    for (int i = 0; i < HAND_SIZE; ++i) {
        counts[hand[i] - lowest]++;
    }
}








/*
============================================================
 Function: containsPair
 Purpose:
     Returns true if there is exactly one pair of matching
     card values and no triples or quads of any single value.
============================================================
*/
bool containsPair(const int hand[]) {
    int counts[HIGHEST_NUM - LOWEST_NUM + 1];
    countValues(hand, counts, LOWEST_NUM, HIGHEST_NUM);

    int pairCount = 0;
    for (int i = 0; i < (HIGHEST_NUM - LOWEST_NUM + 1); ++i) {
        if (counts[i] == 2) pairCount++;
        if (counts[i] > 2) return false;
    }
    return pairCount == 1;
}








/*
============================================================
 Function: containsTwoPair
 Purpose:
     Returns true if two or more distinct pairs of values
     appear in the hand.
============================================================
*/
bool containsTwoPair(const int hand[]) {
    int counts[HIGHEST_NUM - LOWEST_NUM + 1];
    countValues(hand, counts, LOWEST_NUM, HIGHEST_NUM);

    int pairCount = 0;
    for (int i = 0; i < (HIGHEST_NUM - LOWEST_NUM + 1); ++i) {
        if (counts[i] == 2) pairCount++;
    }
    return pairCount >= 2;
}








/*
============================================================
 Function: containsThreeOfaKind
 Purpose:
     Returns true if any value appears exactly three times.
============================================================
*/
bool containsThreeOfaKind(const int hand[]) {
    int counts[HIGHEST_NUM - LOWEST_NUM + 1];
    countValues(hand, counts, LOWEST_NUM, HIGHEST_NUM);

    for (int i = 0; i < (HIGHEST_NUM - LOWEST_NUM + 1); ++i) {
        if (counts[i] == 3) return true;
    }
    return false;
}








/*
============================================================
 Function: containsStraight
 Purpose:
     Returns true if five consecutive numeric values appear
     anywhere in the hand (order does not matter).
 Notes:
     Works for any card range; does not sort hand[].
============================================================
*/
bool containsStraight(const int hand[]) {
    int counts[HIGHEST_NUM - LOWEST_NUM + 1];
    countValues(hand, counts, LOWEST_NUM, HIGHEST_NUM);

    int consecutive = 0;
    for (int i = 0; i < (HIGHEST_NUM - LOWEST_NUM + 1); ++i) {
        if (counts[i] > 0) {
            consecutive++;
            if (consecutive >= 5) return true;
        } else {
            consecutive = 0;
        }
    }
    return false;
}








/*
============================================================
 Function: containsFullHouse
 Purpose:
     Returns true if a hand contains both "exactly three of one
     value" and "exactly two of another" card value.
============================================================
*/
bool containsFullHouse(const int hand[]) {
    int counts[HIGHEST_NUM - LOWEST_NUM + 1];
    countValues(hand, counts, LOWEST_NUM, HIGHEST_NUM);

    bool hasThree = false;
    bool hasPair = false;

    for (int i = 0; i < (HIGHEST_NUM - LOWEST_NUM + 1); ++i) {
        if (counts[i] == 3) hasThree = true;
        else if (counts[i] == 2) hasPair = true;
    }
    return hasThree && hasPair;
}








/*
============================================================
 Function: containsFourOfaKind
 Purpose:
     Returns true if four or more identical card values appear
     in the hand. Supports larger hands (6, 8, etc.).
============================================================
*/
bool containsFourOfaKind(const int hand[]) {
    int counts[HIGHEST_NUM - LOWEST_NUM + 1];
    countValues(hand, counts, LOWEST_NUM, HIGHEST_NUM);

    for (int i = 0; i < (HIGHEST_NUM - LOWEST_NUM + 1); ++i) {
        if (counts[i] >= 4) return true;
    }
    return false;
}








/*
============================================================
 Function: main
 Purpose:
     Prompts for user input, evaluates the hand by calling
     classification functions, and prints the highest-value
     hand type found.
============================================================
*/
int main() {
    int hand[HAND_SIZE];

    cout << "Enter " << HAND_SIZE << " numeric cards, no face cards. "
         << "Use " << LOWEST_NUM << " - " << HIGHEST_NUM << "." << endl;

    
    int i = HAND_SIZE;  
    while (i > 0) {
        cout << "Card " << (HAND_SIZE - i + 1) << ": ";
        cin >> hand[HAND_SIZE - i];
        i--; 
    }


    if (containsFourOfaKind(hand)) {
        cout << "Four of a kind!" << endl;
    }
    else if (containsFullHouse(hand)) {
        cout << "Full House!" << endl;
    }
    else if (containsStraight(hand)) {
        cout << "Straight!" << endl;
    }
    else if (containsThreeOfaKind(hand)) {
        cout << "Three of a kind!" << endl;
    }
    else if (containsTwoPair(hand)) {
        cout << "Two Pair!" << endl;
    }
    else if (containsPair(hand)) {
        cout << "Pair!" << endl;
    }
    else {
        cout << "High card!" << endl;
    }

    return 0;
}
