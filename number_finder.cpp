    /*
     * Quentin Jeriko
     * COMS 215
     * 9/12/2026
     * Project 12.2
     * This program plays a number guessing game with a person.
     * The person will think of a number between LOWER_LIMIT and UPPER_LIMIT, inclusive.
     * The program allows for versatility so that the programmer can change these limits.
     * For zyBooks they are set to 1 and 100.
     * The UPPER_LIMIT is greater than (>) LOWER_LIMIT.
     * This program will make accurate guesses and the user will type in response to have the program guess higher or lower.
     */

#include <iostream>
#include <string>
using namespace std;

const int UPPER_LIMIT = 100;
const int LOWER_LIMIT = 1;

int getMidpoint(int low, int high){
    return ((high + low) / 2);
}

// the '&' means that it changes the value passed into the function
// meaning that it's going to use the same input variable as the same output variable just with the value changed.
// this is called pass by reference

void getUserResponseToGuess(int guess, char& result) {
    cout << "My guess is " << guess
    << ". Enter \'l\' if your number is lower, \'h\' if it is higher, "
    << "\'c\' if it is correct: ";

    cin >> result;
}

void playOneGame(){
    //creating local variables

    int low = LOWER_LIMIT;
    int high = UPPER_LIMIT;
    char result = ' ';
    int guess;

    cout << "Think of a number between " << LOWER_LIMIT << " and " << UPPER_LIMIT << "." << endl;

    while (result != 'c') {

        guess = getMidpoint(low, high);
        getUserResponseToGuess(guess, result);

        if (result == 'l'){
            high = guess - 1;
        }
        else if (result == 'h'){
            low = guess + 1;
        }
        //end conditinal branch

    }//end while loop (guess is correct)

}// end playOneGame


int main() {
    char response;
    
    cout << "Ready to play (y/n)? ";
    cin >> response;
    while (response == 'y') {
        playOneGame();
        cout << "Great! Do you want to play again (y/n)? ";
        cin >> response;
    }
}
