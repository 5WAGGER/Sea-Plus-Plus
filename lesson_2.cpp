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
    string color = addWord("Enter a color: ");
    string color2 = addWord("Enter another color: ");
    string message = color + " " + color2;
    cout << "Roses are " << color << ". Violets are "
    << color2 << "." << endl;
}
