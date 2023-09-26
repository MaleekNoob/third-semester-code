#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;

struct Student {
    int rollNo;
    string name;
    string city;
    string phone;
};

void addStudent() {
    ofstream file;
    file.open("student.txt", ios::app);
    Student student;
    cout << "Enter roll number: ";
    cin >> student.rollNo;
    cout << "Enter name: ";
    getline(cin, student.name);
    cout << "Enter city: ";
    getline(cin, student.city);
    cout << "Enter phone: ";
    getline(cin, student.phone);
    file << student.rollNo << " " << student.name << " " << student.city << " " << student.phone << endl;
    file.close();
}

void viewStudents() {
    ifstream file;
    file.open("student.txt");
    Student student;
    while (file >> student.rollNo >> student.name >> student.city >> student.phone) {
        cout << "Roll No: " << student.rollNo << endl;
        cout << "Name: " << student.name << endl;
        cout << "City: " << student.city << endl;
        cout << "Phone: " << student.phone << endl;
        cout << endl;
    }
    file.close();
}

int main() {

    int choice;

    while (true) {
        cout << "1) Enter new student" << endl;
        cout << "2) View all students" << endl;
        cout << "3) Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
        case 1:
            addStudent();
            break;
        case 2:
            viewStudents();
            break;
        case 3:
            exit(0);
        default:
            cout << "Invalid choice" << endl;
        }
    }

    return 0;
}