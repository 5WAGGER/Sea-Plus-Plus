 /*
  * Quentin Jeriko
  * COMS 215
  * 2/23/2026
  * Project 13.1 with More Modified Constants
  * This program is like a simplified game of poker where it verifies 
  * which winning hand the player has.
  * For version 13.26.1 HIGHEST_NUM is set to 13, HAND_SIZE is set to 8, and LOWEST_NUM is set to 1.
  * Winning poker hands available for this program:
  * four of a kind, full house, straight, 
  * three of a kind,two pairs, pair, high card.
  * 
  */

#include <iostream>

using namespace std;

const int HAND_SIZE = 8;
const int LOWEST_NUM = 1;
const int HIGHEST_NUM = 13;

/*
This is a helpful function that is reused by more functions.
This function counts how many recurrences of card numbers
and stores them in each index of the counts[] array

pre: hand array, counts array, LOWEST_NUM integer, and HIGHEST_NUM integer
post: none.
instead of returning a value is modifies the counts[] array.
*/

void frequencyFinder(const int hand[], int counts[], int lowest, int highest){

    int range = highest - lowest + 1;
    
    for (int i = 0; i < range; ++i) {
        counts[i] = 0;
    }

    for (int i = 0; i < HAND_SIZE; ++i) {
        counts[hand[i] - lowest]++;
    }

    int maxCount = 0;
    for (int i = 0; i < range; ++i){
        if (counts[i] > maxCount) {
            maxCount = counts[i];
        }
    }
}

/*
This function sees if there is 1 pair of matching cards.

pre: hand array
post: returns a boolean value based if the given cards has a pair
*/

bool containsPair(const int hand[]) {
    int range = HIGHEST_NUM - LOWEST_NUM + 1;
    int counts[range];
    frequencyFinder(hand, counts, LOWEST_NUM, HIGHEST_NUM);

    int pairCount = 0;

    for (int i = 0; i < range; ++i){
        if (counts[i] == 2) {pairCount++;}
        if (counts[i] > 2) {return false;}
    }
    return (pairCount == 1);
}

/*
This function sees if there is 2 pairs of matching cards.

pre: hand array
post: returns a boolean value based if the given cards has two pairs
*/

bool containsTwoPair(const int hand[]) {
    int counts[HIGHEST_NUM - LOWEST_NUM + 1];
    frequencyFinder(hand, counts, LOWEST_NUM, HIGHEST_NUM);

    int pairAmount = 0;
    for (int i = 0; i < (HIGHEST_NUM - LOWEST_NUM + 1); ++i) {
        if (counts[i] == 2) pairAmount++;
    }
    return 2 <= pairAmount;
}

bool containsThreeOfaKind(const int hand[]) {

    int counts[HIGHEST_NUM - LOWEST_NUM + 1];

    frequencyFinder(hand, counts, LOWEST_NUM, HIGHEST_NUM);

    for (int i = 0; i < (HIGHEST_NUM - LOWEST_NUM + 1); ++i) {
        if (counts[i] == 3) {return true;}
    }
    return false;
}

/*
This function sees if there are still 5 numbers going up in order when rearranged.
example: 4, 2, 6, 8, 7, 5, 2, 2

pre: hand array
post: returns a boolean value based if the given cards is a straight
*/

bool containsStraight(const int hand[]){
    int counts[HIGHEST_NUM - LOWEST_NUM + 1];

    frequencyFinder(hand, counts, LOWEST_NUM, HIGHEST_NUM);

    int flowForward = 0;

    for (int i = 0; i < (HIGHEST_NUM - LOWEST_NUM + 1); ++i) {
        if (counts[i] > 0) {
            flowForward++;
            if (5 <= flowForward) {
                return true;
            }
        }
        else {
            flowForward = 0;
        }
    }
    return false;
}

/*
This function sees if there is a two of kind and a 3 of kind.
example: 2, 2, 3, 3, 3, 7, 1, 5

pre: hand array
post: returns a boolean value based if the given cards is a full house
*/

bool containsFullHouse(const int hand[]){
    int counts[HIGHEST_NUM - LOWEST_NUM + 1];

    frequencyFinder(hand, counts, LOWEST_NUM, HIGHEST_NUM);

    // bugfix for bigger hand 

    int areThreeOfaKinds = 0;
    int areTwoPairs = 0;

    for (int i = 0; i < (HIGHEST_NUM - LOWEST_NUM + 1); ++i){
        if (counts[i] == 3){
            areThreeOfaKinds++;
        }
        else if (counts[i] == 2){
            areTwoPairs++;
        }
    }
    if (areThreeOfaKinds == 1 && areTwoPairs == 1){
        return true;
    }
    else {
        return false;
    }
}

/*
This function sees if there is a four of kind.
example: 2, 3, 3, 3, 3, 7, 1, 6

pre: hand array
post: returns a boolean value based if the given cards is a four of a kind.
*/

bool containsFourOfaKind(const int hand[]){

    int counts[HIGHEST_NUM - LOWEST_NUM + 1];

    frequencyFinder(hand, counts, LOWEST_NUM, HIGHEST_NUM);

    for (int i = 0; i < (HIGHEST_NUM - LOWEST_NUM + 1); ++i) {
        if (4 <= counts[i]) {
            return true;
        }
    }
    return false;
}

//Program starts and uses functions to see which is the winning hand.
//Also it gets input from the player to see which cards are pulled.

int main() {

    int hand[HAND_SIZE];

    cout << "Enter " << HAND_SIZE << " numeric cards, no face cards. "
    << "Use " << LOWEST_NUM << " - " << HIGHEST_NUM << "." << endl;
    
    for (int cardIndex = 0; cardIndex < HAND_SIZE; ++cardIndex){
        cout << "Card " << (cardIndex + 1) << ": ";
        cin >> hand[cardIndex];
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
