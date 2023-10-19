#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void displayFileData(fstream& file) {
    while (!file.eof()) {
        string line = "";
        getline(file, line);
        for (int i = 0; i < line.length(); i++) {
            if (line[i] == ',') {
                line[i] = ' ';
            }
        }
        cout << endl << line;
    }
}

int main() {

    fstream file;
    file.open("tiktok_dataset.csv");
    if (!file.is_open()) {
        cout << endl << "Masla";
        exit(1);
    }
    displayFileData(file);
    file.close();

    return 0;
}