    /*
     * Quentin Jeriko
     * COMS 215
     * 9/3/2026
     * Project 7.4
     * This program allows the player to play a modified version of blackjack.
     * This program generates a random number between 1 and 10 each time the player gets a card.
     * Each of the numbers are equally likely
     * It keeps the total of the player's cards, and asks the player whether or not it should deal another card.
     * When the player hits 21 exactly, the program will print "Congratulations!" and then ask if the player wants to play again.
     * When the player exceeds 21m the program will print "Bust" and then ask if the player wants to play again. 
     */

#include <iostream>
#include <string>
#include <iomanip>
#include <ctime>
#include <cstdlib>
using namespace std;

int main(){
    //this fuction call uses the clock time to initatialize the random number generator
    //srand(static_cast<unsigned>(time(nullptr)));
    //initializing all variables

    int range = 10;
    int firstCard;
    int secondCard;
    int nextCard;
    bool hasWon;
    char input;
    bool roundIsGoing;
    char answer;
    int total;
    bool busted;
    answer = 'y';

    //start asking to play (potentially multiple) round(s)
    while (answer == 'y') {
        //start of game

        total = 0;
        hasWon = false;
        busted = false;
        roundIsGoing = true; 
        firstCard = rand() % range + 1;
        secondCard = rand() % range + 1;
        cout << "First cards: " << firstCard << ", " << secondCard << endl;
        total = firstCard + secondCard;
        cout << "Total: " << total << endl;

        // start roundIsGoing loop
        while (total < 21 && roundIsGoing) {
            //start of round
            cout << "Do you want another card (y/n)? ";
            cin >> input;

            if (input == 'n') {
                roundIsGoing = false;
            }

            if (input == 'y'){
                nextCard = rand() % range;
                nextCard++;
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

        }//round is finished

    //output of finished round

    if (busted){
        cout << "Bust." << endl;
    }
    if (hasWon) {
        cout << "Congratulations!" << endl;
    }

    //asking for another round

    cout << "Would you like to play again (y/n)? ";
    cin >> answer;

    }//done asking for another round / end of while (answer == 'y')

return 0;
}//program complete
