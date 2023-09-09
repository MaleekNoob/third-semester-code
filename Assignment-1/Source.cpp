#include <iostream>
#include <fstream>
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
class Employee
{
private:
    T name;
    T id;
    T salary;
    T date;
    T job_title;

public:
    Employee() {}

    Employee(T name, T id, T salary, T date, T job_title)
    {
        this->name = name;
        this->id = id;
        this->salary = salary;
        this->date = date;
        this->job_title = job_title;
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
        cout << "Name: " << name << endl;
        cout << "ID: " << id << endl;
        cout << "Salary: " << salary << endl;
        cout << "Date: " << date << endl;
        cout << "Job Title: " << job_title << endl;
    }
};

template <class T>
double averageSalary(Employee<T> employee[], int size)
{
    double sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += stringToInt(employee[i].getSalary());
    }
    return sum / size;
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
float averageTenure(Employee<T> employee[], int size)
{
    float years = 0;
    for (int i = 0; i < size; i++)
    {
        years += serviceYears(employee[i].getDate());
    }
    return years / size;
}

template <class T>
void distribution(Employee<T> employee[], int size)
{
    int software_engineer = 0, data_scientist = 0, product_manager = 0, qa_analyst = 0, ux_designer = 0, senior_data_analyst = 0, business_analyst = 0;
    for (int i = 0; i < size; i++)
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
void searchLongestTenure(Employee<T> employee[], int size)
{
    int longest_tenure = 0;
    for (int i = 0; i < size; i++)
    {
        if (serviceYears(employee[i].getDate()) > longest_tenure)
        {
            longest_tenure = serviceYears(employee[i].getDate());
        }
    }

    for (int i = 0; i < size; i++)
    {
        if (serviceYears(employee[i].getDate()) == longest_tenure)
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
void getData(Employee<T> employee[], int size) {
    ifstream file;
    int index = 0;
    file.open("Employeedata.txt");
    if (!file)
    {
        cout << "File not found!" << endl;
        return;
    }
    else
    {
        cout << "File found!" << endl;
    }

    while (!file.eof())
    {
        if (index == size) {
            cout << endl << "Array is full!" << endl;
            break;
        }
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


        employee[index] = Employee<string>(name, id, salary, date, job_title);
        index++;
    }

    file.close();
}

template <class T>
int highestSalary(Employee<T> employee[], int size) {
    int highest_salary = stringToInt(employee[0].getSalary());
    for (int i = 1; i < size; i++)
    {
        if (stringToInt(employee[i].getSalary()) > highest_salary)
        {
            highest_salary = stringToInt(employee[i].getSalary());
        }
    }
    return highest_salary;
}

template <class T>
int lowestSalary(Employee<T> employee[], int size) {
    int lowest_salary = stringToInt(employee[0].getSalary());
    for (int i = 1; i < size; i++)
    {
        if (stringToInt(employee[i].getSalary()) < lowest_salary)
        {
            lowest_salary = stringToInt(employee[i].getSalary());
        }
    }
    return lowest_salary;
}

template <class T>
void insertion_sort(Employee<T> employee[], int size) {
    for (int i = 1; i < size; i++)
    {
        Employee<T> temp = employee[i];
        int j;
        for (j = i; j > 0 && stringToInt(temp.getSalary()) > stringToInt(employee[j - 1].getSalary()); j--) {
            employee[j] = employee[j - 1];
        }
        employee[j] = temp;
    }
}

template <class T>
int medianSalary(Employee<T> employee[], int size) {
    Employee<T> sorted_employee[size];
    for (int i = 0; i < size; i++)
    {
        sorted_employee[i] = employee[i];
    }
    insertion_sort(sorted_employee, size);

    if (size % 2 == 0) {
        return (stringToInt(sorted_employee[size / 2].getSalary()) + stringToInt(sorted_employee[size / 2 - 1].getSalary())) / 2;
    }
    else {
        return stringToInt(sorted_employee[size / 2].getSalary());
    }
}

template <class T>
int averageDesignationSalary(Employee<T> employee[], int size, T designation) {
    int sum = 0, count = 0;
    for (int i = 0; i < size; i++)
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
void searchHighestSalary(Employee<T> employee[], int size) {
    int highest_salary = stringToInt(employee[0].getSalary());
    for (int i = 1; i < size; i++)
    {
        if (stringToInt(employee[i].getSalary()) > highest_salary)
        {
            highest_salary = stringToInt(employee[i].getSalary());
        }
    }

    for (int i = 0; i < size; i++)
    {
        if (stringToInt(employee[i].getSalary()) == highest_salary)
        {
            employee[i].print();
        }
    }
}

int main()
{
    ifstream file;
    int size = 10;
    Employee<string> employee[size];
    
    
    getData(employee, size);

    ////////////////////////////////////////Scenario 1////////////////////////////////////////
    /*
    // Average salary in the company.
    cout << endl << "Average salary in the company: " << averageSalary(employee, size);

    // Total number of employees.
    cout << endl << "Total number of employees: " << size << endl;

    // Average tenure (in years) of employees in the company.
    cout << endl << "Average tenure (in years) of employees in the company: " << averageTenure(employee, size) << endl;

    // Distribution of employees based on their designations (e.g., Software Engineer, Data Scientist, etc.).
    cout << endl << "Distribution of employees based on their designations: " << endl;
    distribution(employee, size);

    // Search Employee with longest tenure
    cout << endl << "Employee with longest tenure: " << endl;
    searchLongestTenure(employee, size);
    */

    ////////////////////////////////////////Scenario 2////////////////////////////////////////
    /*

    // Highest salary among all employees.
    cout << endl << "Highest salary among all employees: " << highestSalary(employee, size) << endl;

    // Lowest salary among all employees.
    cout << endl << "Lowest salary among all employees: " << lowestSalary(employee, size) << endl;

    // Salary range (the difference between the highest and lowest salaries).
    cout << endl << "Salary range (the difference between the highest and lowest salaries): " << highestSalary(employee, size) - lowestSalary(employee, size) << endl;

    // Median salary.
    cout << endl << "Median salary: " << medianSalary(employee, size) << endl;

    // Average salary for each designation category (e.g., Software Engineer, Data Scientist, etc.).
    string designation;
    cout << endl << "Enter designation category: ";
    getline(cin, designation);
    cout << endl << "Average salary for " << designation << ": " << averageDesignationSalary(employee, size, designation) << endl;

    // Search Employee with highest salary
    cout << endl << "Employee with highest salary: " << endl;
    searchHighestSalary(employee, size);

    */
    ////////////////////////////////////////Scenario 3////////////////////////////////////////
    return 0;
}