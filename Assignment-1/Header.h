#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <chrono>
using namespace std;

template <class t>
int stringToInt(t str)
{
    int num = 0;
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == ',')
            continue;
        num = num * 10 + (str[i] - '0');
    }
    return num;
}

template <class T>
class Person
{
private:
    T name;
    T id;
    T salary;
    T date;
    T job_title;

public:
    Person() {}

    Person(T name, T id, T salary, T date, T job_title)
    {
        this->name = name;
        this->id = id;
        this->salary = salary;
        this->date = date;
        this->job_title = job_title;
    }

    Person(Person<T> &person)
    {
        name = person.getName();
        id = person.getId();
        salary = person.getSalary();
        date = person.getDate();
        job_title = person.getJobTitle();
    }

    void setName(T name)
    {
        this->name = name;
    }

    void setId(T id)
    {
        this->id = id;
    }

    void setSalary(T salary)
    {
        this->salary = salary;
    }

    void setDate(T date)
    {
        this->date = date;
    }

    void setJobTitle(T job_title)
    {
        this->job_title = job_title;
    }

    T getName()
    {
        return name;
    }

    T getId()
    {
        return id;
    }

    T getSalary()
    {
        return salary;
    }

    T getDate()
    {
        return date;
    }

    T getJobTitle()
    {
        return job_title;
    }

    void print()
    {
        cout << "------------------------------------" << endl;
        cout << "Name: " << name << endl;
        cout << "ID: " << id << endl;
        cout << "Salary: " << salary << endl;
        cout << "Date: " << date << endl;
        cout << "Job Title: " << job_title << endl;
    }

    void operator=(Person<T> person)
    {
        name = person.getName();
        id = person.getId();
        salary = person.getSalary();
        date = person.getDate();
        job_title = person.getJobTitle();
    }
};

template <class T>
class Employee
{
private:
    Person<T> *person;
    int size, capacity;

public:
    Employee()
    {
        person = new Person<T>[1];
        size = 0;
        capacity = 1;
    }

    Employee(T name, T id, T salary, T date, T job_title)
    {
        if (size == capacity)
        {
            Person<T> *temp = new Person[capacity * 2];
            for (int i = 0; i < capacity; i++)
            {
                temp[i] = person[i];
            }
            delete[] person;
            person = temp;
            capacity *= 2;
        }
        person[size] = Person(name, id, salary, date, job_title);
        size++;
    }

    Employee(Employee<T> &employee)
    {
        size = employee.getSize();
        capacity = employee.getCapacity();
        person = new Person<T>[capacity];
        for (int i = 0; i < size; i++)
        {
            person[i] = employee[i];
        }
    }

    ~Employee()
    {
        delete[] person;
    }

    void addEmployee(T name, T id, T salary, T date, T job_title)
    {
        if (size == capacity)
        {
            Person<T> *temp = new Person<T>[capacity * 2];
            for (int i = 0; i < capacity; i++)
            {
                temp[i] = person[i];
            }
            delete[] person;
            person = temp;
            capacity *= 2;
        }
        person[size] = Person(name, id, salary, date, job_title);
        size++;
    }

    int getSize()
    {
        return size;
    }

    int getCapacity()
    {
        return capacity;
    }

    Person<T> getPerson(int index)
    {
        return person[index];
    }

    void setPerson(int index, Person<T> person)
    {
        this->person[index] = person;
    }

    void printAllEmployee()
    {
        for (int i = 0; i < size; i++)
        {
            person[i].print();
        }
    }

    void operator=(Employee<T> employee)
    {
        size = employee.getSize();
        capacity = employee.getCapacity();
        person = new Person<T>[capacity];
        for (int i = 0; i < size; i++)
        {
            person[i] = employee[i];
        }
    }

    Person<T> operator[](int index)
    {
        return person[index];
    }
};

template <class T>
double averageSalary(Employee<T> employee)
{
    double sum = 0;
    for (int i = 0; i < employee.getSize(); i++)
    {
        sum += stringToInt(employee[i].getSalary());
        cout << "Salary of " << employee[i].getName() << ": " << stringToInt(employee[i].getSalary()) << endl;
    }
    return sum / employee.getSize();
}

template <class T>
float serviceYearsFloat(T date)
{
    float year = 0, month = 0, day = 0, current_day = 7, current_month = 9, current_year = 2023, delta = 0;
    for (int i = 0; i < 4; i++)
    {
        year = year * 10 + (date[i] - '0');
    }

    for (int i = 5; i < 7; i++)
    {
        month = month * 10 + (date[i] - '0');
    }

    for (int i = 8; i < 10; i++)
    {
        day = day * 10 + (date[i] - '0');
    }

    if (month > current_month)
    {
        current_year--;
    }
    else if (month == current_month)
    {
        if (day > current_day)
        {
            current_year--;
        }
    }

    if (month < current_month) {
        delta = 0.9 - (month / 10.0);
    }
    else {
        delta = 2.1 - (month / 10.0);
    }

    return (current_year - year) + delta;
}

template <class T>
int serviceYears(T date)
{
    int year = 0, month = 0, day = 0, current_day = 7, current_month = 9, current_year = 2023;
    for (int i = 0; i < 4; i++)
    {
        year = year * 10 + (date[i] - '0');
    }

    for (int i = 5; i < 7; i++)
    {
        month = month * 10 + (date[i] - '0');
    }

    for (int i = 8; i < 10; i++)
    {
        day = day * 10 + (date[i] - '0');
    }

    if (month > current_month)
    {
        current_year--;
    }
    else if (month == current_month)
    {
        if (day > current_day)
        {
            current_year--;
        }
    }

    return current_year - year;
}

template <class T>
float averageTenure(Employee<T> employee)
{
    float years = 0;
    for (int i = 0; i < employee.getSize(); i++)
    {
        years += serviceYears(employee[i].getDate());
    }
    return years / employee.getSize();
}

template <class T>
void distribution(Employee<T> employee)
{
    int software_engineer = 0, data_scientist = 0, product_manager = 0, qa_analyst = 0, ux_designer = 0, senior_data_analyst = 0, business_analyst = 0;
    for (int i = 0; i < employee.getSize(); i++)
    {
        if (employee[i].getJobTitle() == "Software Engineer" || employee[i].getJobTitle() == "Senior Software Engineer")
        {
            software_engineer++;
        }
        else if (employee[i].getJobTitle() == "Data Scientist")
        {
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
        else if (employee[i].getJobTitle() == "Senior Data Analyst")
        {
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
void searchLongestTenure(Employee<T> employee)
{
    int longest_tenure = 0;
    for (int i = 0; i < employee.getSize(); i++)
    {
        if (serviceYears(employee[i].getDate()) > longest_tenure)
        {
            longest_tenure = serviceYears(employee[i].getDate());
        }
    }

    for (int i = 0; i < employee.getSize(); i++)
    {
        if (serviceYears(employee[i].getDate()) == longest_tenure)
        {
            employee[i].print();
        }
    }
}

template <class T>
void searchShortestTenure(Employee<T> employee)
{
    int shortest_tenure = 100;
    for (int i = 0; i < employee.getSize(); i++)
    {
        if (serviceYears(employee[i].getDate()) < shortest_tenure)
        {
            shortest_tenure = serviceYears(employee[i].getDate());
        }
    }

    for (int i = 0; i < employee.getSize(); i++)
    {
        if (serviceYears(employee[i].getDate()) == shortest_tenure)
        {
            employee[i].print();
        }
    }
}

template <class T>
T popFirstCharactor(T str)
{
    T temp = "";
    for (int i = 1; i < str.length(); i++)
    {
        temp += str[i];
    }
    return temp;
}

template <class T>
Employee<T> getData(Employee<T> &employee)
{
    ifstream file;
    file.open("Employeedata.txt");
    if (!file)
    {
        cout << "File not found!" << endl;
        exit(1);
    }
    else
    {
        cout << "File found!" << endl;
    }

    while (!file.eof())
    {
        string name, id, salary, date, job_title, temp;
        getline(file, temp, '\t');
        file >> temp >> temp;
        getline(file, name, '\n');
        name = popFirstCharactor(name);
        file >> temp >> temp;
        getline(file, id, '\n');
        id = popFirstCharactor(id);
        file >> temp;
        getline(file, salary, '\n');
        salary = popFirstCharactor(salary);
        salary = popFirstCharactor(salary);
        file >> temp >> temp >> temp;
        getline(file, date, '\n');
        date = popFirstCharactor(date);
        file >> temp;
        getline(file, job_title, '\n');
        job_title = popFirstCharactor(job_title);
        getline(file, temp, '\n');

        employee.addEmployee(name, id, salary, date, job_title);
    }

    file.close();

    return employee;
}

template <class T>
int highestSalary(Employee<T> employee)
{
    int highest_salary = stringToInt(employee[0].getSalary());
    for (int i = 1; i < employee.getSize(); i++)
    {
        if (stringToInt(employee[i].getSalary()) > highest_salary)
        {
            highest_salary = stringToInt(employee[i].getSalary());
        }
    }
    return highest_salary;
}

template <class T>
int lowestSalary(Employee<T> employee)
{
    int lowest_salary = stringToInt(employee[0].getSalary());
    for (int i = 1; i < employee.getSize(); i++)
    {
        if (stringToInt(employee[i].getSalary()) < lowest_salary)
        {
            lowest_salary = stringToInt(employee[i].getSalary());
        }
    }
    return lowest_salary;
}

template <class T>
Employee<T> insertion_sort(Employee<T> employee, int size, int &comparisons = 0, int &swaps = 0)
{
    int i, j;
    Person<T> key;
    for (i = 1; i < size; i++)
    {
        bool swapped = false;
        key = employee.getPerson(i);
        j = i - 1;

        while (j >= 0 && stringToInt(employee.getPerson(j).getSalary()) > stringToInt(key.getSalary()))
        {
            comparisons++;
            employee.setPerson(j + 1, employee.getPerson(j));
            j = j - 1;
            swaps++;
            swapped = true;
        }
        comparisons++;
        employee.setPerson(j + 1, key);
    }

    return employee;
}

template <class T>
Employee<T> bubble_sort(Employee<T> employee, int size, int &comparisons = 0, int &swaps = 0)
{
    for (int i = 0; i < size - 1; i++)
    {
        bool swapped = false;
        for (int j = 0; j < size - i - 1; j++)
        {
            comparisons++;
            if (stringToInt(employee.getPerson(j).getSalary()) > stringToInt(employee.getPerson(j + 1).getSalary()))
            {
                swaps++;
                Person<T> temp = employee.getPerson(j);
                employee.setPerson(j, employee.getPerson(j + 1));
                employee.setPerson(j + 1, temp);
                swapped = true;
            }
        }
        if (swapped == false)
        {
            break;
        }
    }
    return employee;
}

template <class T>
Employee<T> selection_sort(Employee<T> employee, int size, int &comparisons = 0, int &swaps = 0)
{
    int min_index;
    for (int i = 0; i < size - 1; i++)
    {
        min_index = i;
        for (int j = i + 1; j < size; j++)
        {
            comparisons++;
            if (stringToInt(employee.getPerson(j).getSalary()) < stringToInt(employee.getPerson(min_index).getSalary()))
            {
                min_index = j;
            }
        }
        swaps++;
        Person<T> temp = employee.getPerson(min_index);
        employee.setPerson(min_index, employee.getPerson(i));
        employee.setPerson(i, temp);
    }
    return employee;
}

template <class T>
int medianSalary(Employee<T> employee)
{
    int swap = 0, comparison = 0;
    employee = insertion_sort(employee, employee.getSize(), comparison, swap);
    if (employee.getSize() % 2 == 0)
    {
        return (stringToInt(employee[employee.getSize() / 2].getSalary()) + stringToInt(employee[employee.getSize() / 2 - 1].getSalary())) / 2;
    }
    else
    {
        return stringToInt(employee[employee.getSize() / 2].getSalary());
    }
}

template <class T>
int averageDesignationSalary(Employee<T> employee, T designation)
{
    int sum = 0, count = 0;
    for (int i = 0; i < employee.getSize(); i++)
    {
        if (employee[i].getJobTitle() == designation)
        {
            sum += stringToInt(employee[i].getSalary());
            count++;
        }
    }
    return sum / count;
}

template <class T>
float averageDesignationTenure(Employee<T> employee, T designation)
{
    float sum = 0, count = 0;
    for (int i = 0; i < employee.getSize(); i++)
    {
        if (employee[i].getJobTitle() == designation)
        {
            sum += serviceYears(employee[i].getDate());
            count++;
        }
    }
    return sum / count;
}

template <class T>
void searchHighestSalary(Employee<T> employee)
{
    int highest_salary = stringToInt(employee[0].getSalary());
    for (int i = 1; i < employee.getSize(); i++)
    {
        if (stringToInt(employee[i].getSalary()) > highest_salary)
        {
            highest_salary = stringToInt(employee[i].getSalary());
        }
    }

    for (int i = 0; i < employee.getSize(); i++)
    {
        if (stringToInt(employee[i].getSalary()) == highest_salary)
        {
            employee[i].print();
        }
    }
}

template <class T>
void highestPayingDesignation(Employee<T> employee)
{
    int highest_salary = highestSalary(employee);

    for (int i = 0; i < employee.getSize(); i++)
    {
        if (stringToInt(employee[i].getSalary()) == highest_salary)
        {
            cout << "Highest paying designation: " << employee[i].getJobTitle() << endl;
        }
    }
}

uint64_t gettime() // function returns time in microseconds
{
    uint64_t ms = chrono::duration_cast<chrono::microseconds>(chrono::system_clock::now().time_since_epoch()).count();
    return ms;
}

template <class T>
Employee<T> insertion_sort_tenure(Employee<T> employee, int size, int &comparisons = 0, int &swaps = 0)
{
    int i, j;
    Person<T> key;
    for (i = 1; i < size; i++)
    {
        bool swapped = false;
        key = employee.getPerson(i);
        j = i - 1;

        while (j >= 0 && serviceYearsFloat(employee.getPerson(j).getDate()) > serviceYearsFloat(key.getDate()))
        {
            comparisons++;
            employee.setPerson(j + 1, employee.getPerson(j));
            j = j - 1;
            swaps++;
            swapped = true;
        }
        comparisons++;
        employee.setPerson(j + 1, key);
    }

    return employee;
}

template <class T>
Employee<T> bubble_sort_tenure(Employee<T> employee, int size, int &comparisons = 0, int &swaps = 0)
{
    for (int i = 0; i < size - 1; i++)
    {
        bool swapped = false;
        for (int j = 0; j < size - i - 1; j++)
        {
            comparisons++;
            if (serviceYearsFloat(employee.getPerson(j).getDate()) > serviceYearsFloat(employee.getPerson(j + 1).getDate()))
            {
                swaps++;
                Person<T> temp = employee.getPerson(j);
                employee.setPerson(j, employee.getPerson(j + 1));
                employee.setPerson(j + 1, temp);
                swapped = true;
            }
        }
        if (swapped == false)
        {
            break;
        }
    }
    return employee;
}

template <class T>
Employee<T> selection_sort_tenure(Employee<T> employee, int size, int &comparisons = 0, int &swaps = 0)
{
    int min_index;
    for (int i = 0; i < size - 1; i++)
    {
        min_index = i;
        for (int j = i + 1; j < size; j++)
        {
            comparisons++;
            if (serviceYearsFloat(employee.getPerson(j).getDate()) < serviceYearsFloat(employee.getPerson(min_index).getDate()))
            {
                min_index = j;
            }
        }
        swaps++;
        Person<T> temp = employee.getPerson(min_index);
        employee.setPerson(min_index, employee.getPerson(i));
        employee.setPerson(i, temp);
    }
    return employee;
}