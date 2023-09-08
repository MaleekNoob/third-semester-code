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

    if (month > current_month) {
        current_year--;
    }
    else if (month == current_month) {
        if (day > current_day) {
            current_year--;
        }
    }

    return current_year - year;
}

template <class T>
int averageTenure(Employee<T> employee[], int size) {
    int years = 0;
    for (int i = 0; i < size; i++) {
        years += serviceYears(employee[i].getDate());
    }
    return years / size;
}

template <class T>
void distribution(Employee<T> employee[], int size) {
    int software_engineer = 0, data_scientist = 0, product_manager = 0, qa_analyst = 0, ux_designer = 0, senior_data_analyst = 0, business_analyst = 0;
    for (int i = 0; i < size; i++) {
        if (employee[i].getJobTitle() == "Software Engineer" || employee[i].getJobTitle() == "Senior Software Engineer")
        {
            software_engineer++;
        }
        else if (employee[i].getJobTitle() == "Data Scientist") {
            data_scientist++;
        }
        else if (employee[i].getJobTitle() == "Project Manager")
        {
            product_manager++;
        }
        else if (employee[i].getJobTitle() == "Quality Assurance Analyst")
        {
            qa_analyst++;
        }
        else if (employee[i].getJobTitle() == "UX Designer")
        {
            ux_designer++;
        }
        else if (employee[i].getJobTitle() == "Senior Data Analyst") {
            senior_data_analyst++;
        }
    }

    cout << "Software Engineer: " << software_engineer << endl;
    cout << "Data Scientist: " << data_scientist << endl;
    cout << "Product Manager: " << product_manager << endl;
    cout << "Quality Assurance Analyst: " << qa_analyst << endl;
    cout << "UX Designer: " << ux_designer << endl;
    cout << "Senior Data Analyst: " << senior_data_analyst << endl;
}

template <class T>
void searchLongestTenure(Employee<T> employee[], int size) {
    int longest_tenure = 0;
    for (int i = 0; i < size; i++) {
        if (serviceYears(employee[i].getDate()) > longest_tenure) {
            longest_tenure = serviceYears(employee[i].getDate());
        }
    }

    for (int i = 0; i < size; i++) {
        if (serviceYears(employee[i].getDate()) == longest_tenure) {
            employee[i].print();
        }
    }
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

    // Average salary in the company.
    cout << endl << "Average salary in the company: " << averageSalary(employee, index);

    // Total number of employees.
    cout << endl << "Total number of employees: " << index << endl;

    // Average tenure (in years) of employees in the company.
    cout << endl << "Average tenure (in years) of employees in the company: " << averageTenure(employee, index) << endl;

    // Distribution of employees based on their designations (e.g., Software Engineer, Data Scientist, etc.).
    cout << endl << "Distribution of employees based on their designations: " << endl;
    distribution(employee, index);

    // Search Employee with longest tenure
    cout << endl << "Employee with longest tenure: " << endl;
    searchLongestTenure(employee, index);


    return 0;

}