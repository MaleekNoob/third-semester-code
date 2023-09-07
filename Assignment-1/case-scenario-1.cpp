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
        string name, id, salary, date, job_title, temp;
        getline(file, name, '\n');
        getline(file, id, '\n');
        getline(file, salary, '\n');
        getline(file, date, '\n');
        getline(file, job_title, '\n');
        getline(file, temp, '\n');

        cout << endl << endl << "Name: " << name << endl;
        cout << "ID: " << id << endl;
        cout << "Salary: " << salary << endl;
        cout << "Date: " << date << endl;
        cout << "Job Title: " << job_title << endl;
    }
}