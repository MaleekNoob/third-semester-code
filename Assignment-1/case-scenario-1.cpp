#include <iostream>
#include <fstream>
using namespace std;


int main() {
    ifstream file;
    file.open("Employeedata.txt");
    if (!file) {
        cout << "File not found!" << endl;
        return 0;
    }
    else {
        cout << "File found!" << endl;
    }

    while(!file.eof()) {
        string name;
        int age;
        file >> name >> age;
        cout << name << " " << age << endl;
    }
}