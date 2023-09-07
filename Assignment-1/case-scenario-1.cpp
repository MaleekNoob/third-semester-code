#include <iostream>
#include <fstream>
using namespace std;

template <class t>
int stringToInt(t str) {
    int num = 0;
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == ',')
            continue;
        num = num * 10 + (str[i] - '0');
    }
    return num;
}

template <class T>
class Employee {
    private:
        T name;
        T id;
        T salary;
        T date;
        T job_title;

    public:
    Employee() {}

    Employee(T name, T id, T salary, T date, T job_title) {
        this->name = name;
        this->id = id;
        this->salary = salary;
        this->date = date;
        this->job_title = job_title;
    }

    void setName(T name) {
        this->name = name;
    }

    void setId(T id) {
        this->id = id;
    }

    void setSalary(T salary) {
        this->salary = salary;
    }

    void setDate(T date) {
        this->date = date;
    }

    void setJobTitle(T job_title) {
        this->job_title = job_title;
    }

    T getName() {
        return name;
    }

    T getId() {
        return id;
    }

    T getSalary() {
        return salary;
    }

    T getDate() {
        return date;
    }

    T getJobTitle() {
        return job_title;
    }

    void print() {
        cout << "Name: " << name << endl;
        cout << "ID: " << id << endl;
        cout << "Salary: " << salary << endl;
        cout << "Date: " << date << endl;
        cout << "Job Title: " << job_title << endl;
    }
};

template <class T>
double averageSalary(Employee<T> employee[], int size) {
    double sum = 0;
    for (int i = 0; i < size; i++) {
        sum += stringToInt(employee[i].getSalary());
    }
    return sum / size;
}

template <class T>
int serviceYears(T date) {
    int year = 0, month = 0, day = 0, current_day = 7, current_month = 9, current_year = 2023;
    for (int i = 0; i < 4; i++) {
        year = year * 10 + (date[i] - '0');
    }

    for (int i = 5; i < 7; i++) {
        month = month * 10 + (date[i] - '0');
    }

    for (int i = 8; i < 10; i++) {
        day = day * 10 + (date[i] - '0');
    }

    if (current_day < day) {
        current_day += 30;
        current_month--;
    }

    if (current_month < month) {
        current_month += 12;
        current_year--;
    }

    year = current_year - year;

    return year;
}

template <class T>
int averageTenure(Employee<T> employee[], int size) {
    int years = 0;
    for (int i = 0; i < size; i++) {
        years += serviceYears(employee[i].getDate());
    }
    return years / size;
}

int main() {
    ifstream file;
    Employee<string> employee[10];
    int index = 0;

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

        employee[index] = Employee<string>(name, id, salary, date, job_title);
        index++;
    }

    file.close();

    /*
    Analysis: Compute and report the following performance metrics for all employees:
    - Average salary in the company.
    - Total number of employees.
    - Average tenure (in years) of employees in the company.
    - Distribution of employees based on their designations (e.g., Software Engineer, Data Scientist, etc.).
    - Search Employee with longest tenure
    */

    // Average salary in the company.
    cout << "Average salary in the company: " << averageSalary(employee, index) << endl;

    // Total number of employees.
    cout << "Total number of employees: " << index << endl;

    // Average tenure (in years) of employees in the company.

    return 0;

}