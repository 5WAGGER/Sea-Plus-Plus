#include <iostream>
#include <string>
using namespace std;

string addWord(string prompt = "Enter a word: ") {
    string word;
    cout << prompt;
    getline(cin, word); // allows words with spaces
    return word;
}

int main() {
    //initializing array
    string words[5];  
    
    words[0] = addWord("Enter a funny town name: ");
    words[1] = addWord("Enter an adjective: ");
    words[2] = addWord("Enter a funny school name: ");
    words[3] = addWord("Enter a student's name: ");
    words[4] = addWord("Enter an adjective: ");
    words[5] = addWord("Enter a number: ");
    
    /* Iterate and print each item (if needed)
    
    for (int i = 0; i < 5; i++) {
        cout << "Word " << i << ": " << words[i] << endl;
    }
    
    */
    
    string story = "In the town of "+words[0]+ ", there was a(n) " + words[1] + " school called " + words[2] + ". A student named " + words[3] + " attended this school and loved (his/her) "+ words[4] + " teachers and " + words[5] + " classmates!";
    
    cout << story << endl;
}
