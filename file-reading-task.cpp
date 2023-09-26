/*
read a file suramulk.txt and find out the following information: 
Number of words
Number of paragraphs
Number of times a word as entered by the user is present in the text
*/

#include <iostream>
#include <fstream>
using namespace std;

int main() {

    ifstream file;
    file.open("suramulk.txt");
    string word;
    int wordCount = 0;
    int paragraphCount = 0;
    int wordFrequency = 0;
    string wordToFind;

    cout << "Enter a word to find: ";
    cin >> wordToFind;

    while (file >> word) {
        wordCount++;
        if (word == wordToFind) {
            wordFrequency++;
        }
        if (word == "\n") {
            paragraphCount++;
        }
    }

    cout << "Number of words: " << wordCount << endl;
    cout << "Number of paragraphs: " << paragraphCount << endl;
    cout << "Number of times " << wordToFind << " is present in the text: " << wordFrequency << endl;

    file.close();

    return 0;
}