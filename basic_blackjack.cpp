 /* 
  * 5WAGGER
  * COMS 215
  * 2/9/2026
  * basic_blackjack

  * This program allows the player to play a simple version of blackjack.
  * The program generates a random number between 1 and 10 each time the player gets a card. 
  * Each of the values (1 through 10) are equally likely. 
  * It keeps the running total of the player's cards, and ask the player whether or not it should deal another card. 
  * When the player hits 21 exactly, the program should print "Congratulations!" and then ask if the player wants to play again.
  * When player exceeds 21, the program should print "Bust." and then ask if the player wants to play again. 
  */

#include <iostream>
#include <string>
#include <iomanip>
#include <ctime>
#include <cstdlib>
using namespace std;

int main(){
    //This function call uses the clock time to initialize the random number generator
    //srand(static_cast<unsigned>(time(nullptr)));

    //initializing all variables
    int range = 10;
    int firstCard;
    int secondCard;
    int nextCard;
    bool hasWon;
    char input;
    
    char answer;
    int total;
    bool busted;
    answer = 'y';
    
    //start asking to play (potentially multiple) round(s)
    while (answer == 'y') {
        //starting round (game is Going)
        // start of round
        total = 0;
        hasWon = false;
        busted = false;
        firstCard = rand() % range + 1;
        secondCard = rand() % range + 1;
        cout << "First cards: " << firstCard << ", " << secondCard << endl;
        total = firstCard + secondCard;
        cout << "Total: " << total << endl;
        
        //start of round
        // start gameIsGoing loop
        while (total < 21) {
            cout << "Do you want another card (y/n)? ";
            cin >> input;
            if (input == 'n') {
                total = 86;
            }
            if (input == 'y') {
                nextCard = rand() % range + 1;
                cout << "Card: " << nextCard << endl;
                total += nextCard;
                cout << "Total: " << total << endl;
            }
            if (total == 21){
                hasWon = true;
            }
            if (total > 21){
                busted = true;
            }
        }// round is finished

    //finishing round

    if (busted){
        cout << "Bust." << endl;
    }
    if (hasWon) {
        cout << "Congratulations!" << endl;
    }
    
    //finished round 

    cout << "Would you like to play again (y/n)? ";
    cin >> answer;


    }//done askingToPlayMore
return 0;
}// program complete

