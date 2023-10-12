#include <iostream>
#include <string>

using namespace std;

class Node {
private:
    string name;
    int id;
    double salary;
    Node *next;

public:
    Node() : name(""), id(0), salary(0.0), next(nullptr) {}

    Node(string name, int id, double salary) : name(name), id(id), salary(salary), next(nullptr) {}

    string getName() {
        return name;
    }

    int getId() {
        return id;
    }

    double getSalary()
    {
        return salary;
    }

    Node* getNext() 
    { 
        return next; 
    }

    void setNext(Node* node)
    { 
        next = node; 
    }

    void printEmployeeData() {
        cout << "Name: " << name << endl;
        cout << "ID: " << id << endl;
        cout << "Salary: " << salary << endl;
    }
};
