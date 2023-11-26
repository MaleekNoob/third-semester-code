#include <fstream>
#include <iostream>
using namespace std;

int main() {
    fstream file("suramulk.txt");
    string line = "Hello World";
    file << line;
    while (getline(file, line)) {
        cout << line << endl;
    }
    file.close();
    return 0;
}