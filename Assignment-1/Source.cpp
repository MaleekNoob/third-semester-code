#include <iostream>
#include <fstream>
#include <chrono>
#include "Header.h"
using namespace std;

int main()
{
    ifstream file;
    Employee<string> employee;
    employee = getData(employee);
    int choice; 
    cout << "(1 - Scenario 1 | 2 - Scenario 2 | 3 - Scenario 3 | 4 - Scenario 4 | 5 - Scenario 5) Enter your choice: ";
    cin >> choice;
    
    switch (choice)
    {
    case 1:
    {
        ////////////////////////////////////////Scenario 1////////////////////////////////////////
        // Average salary in the company.
        cout << endl << "Average salary in the company: " << averageSalary(employee);

        // Total number of employees.
        cout << endl << "Total number of employees: " << employee.getSize() << endl;

        // Average tenure (in years) of employees in the company.
        cout << endl << "Average tenure (in years) of employees in the company: " << averageTenure(employee) << endl;

        // Distribution of employees based on their designations (e.g., Software Engineer, Data Scientist, etc.).
        cout << endl << "Distribution of employees based on their designations: " << endl;
        distribution(employee);

        // Search Employee with longest tenure
        cout << endl << "Employee with longest tenure: " << endl;
        searchLongestTenure(employee);
        break;
    }

    case 2:
    {
        ////////////////////////////////////////Scenario 2////////////////////////////////////////
        // Highest salary among all employees.
        cout << endl << "Highest salary among all employees: " << highestSalary(employee) << endl;

        // Lowest salary among all employees.
        cout << endl << "Lowest salary among all employees: " << lowestSalary(employee) << endl;

        // Salary range (the difference between the highest and lowest salaries).
        cout << endl << "Salary range (the difference between the highest and lowest salaries): " << highestSalary(employee) - lowestSalary(employee) << endl;

        // Median salary.
        cout << endl << "Median salary: " << medianSalary(employee) << endl;

        // Average salary for each designation category (e.g., Software Engineer, Data Scientist, etc.).
        string designation;
        cout << endl << "Enter designation category: ";
        getline(cin, designation);
        cout << endl << "Average salary for " << designation << ": " << averageDesignationSalary(employee, designation) << endl;

        // Search Employee with highest salary
        cout << endl << "Employee with highest salary: " << endl;
        searchHighestSalary(employee);
        break;
    }

    case 3:
    {
        ////////////////////////////////////////Scenario 3////////////////////////////////////////
        // Employee with longest tenure
        cout << endl << "Employee with longest tenure: " << endl;
        searchLongestTenure(employee);

        // Employee with shortest tenure
        cout << endl << "Employee with shortest tenure: " << endl;
        searchShortestTenure(employee);

        // Average tenure for each designation category
        string designation;
        cout << endl << "Enter designation category: ";
        getline(cin, designation);
        cout << endl << "Average tenure for " << designation << ": " << averageDesignationTenure(employee, designation) << endl;

        // Search the highest paying designation
        highestPayingDesignation(employee);
        break;
    }

    case 4:
    {
        ////////////////////////////////////////Scenario 4////////////////////////////////////////
        // insertion sort
        int comparisons = 0, swaps = 0, choice = 0;
        uint64_t start, end;
        cout << "(1- Bubble sort 2 - Selection sort 3 - Insertion sort) Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
            case 1:
                start = gettime();
                employee = bubble_sort(employee, employee.getSize(), comparisons, swaps);
                end = gettime();
                break;

            case 2:
                start = gettime();
                employee = selection_sort(employee, employee.getSize(), comparisons, swaps);
                end = gettime();
                break;

            case 3:
                start = gettime();
                employee = insertion_sort(employee, employee.getSize(), comparisons, swaps);
                end = gettime();
                break;

            default:
                cout << "Invalid choice" << endl;
                break;
        }
        employee.printAllEmployee();
        cout << endl << "Execution time: " << end - start << " microseconds" << endl;
        cout << "Number of comparisons: " << comparisons << endl;
        cout << "Number of swaps: " << swaps << endl;
        break;
    }

    case 5:
    {
        ////////////////////////////////////////Scenario 5////////////////////////////////////////
        // insertion sort
        int comparisons = 0, swaps = 0, choice = 0;
        uint64_t start, end;
        cout << "(1- Bubble sort 2 - Selection sort 3 - Insertion sort) Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            start = gettime();
            employee = bubble_sort_tenure(employee, employee.getSize(), comparisons, swaps);
            end = gettime();
            break;

        case 2:
            start = gettime();
            employee = selection_sort_tenure(employee, employee.getSize(), comparisons, swaps);
            end = gettime();
            break;

        case 3:
            start = gettime();
            employee = insertion_sort_tenure(employee, employee.getSize(), comparisons, swaps);
            end = gettime();
            break;

        default:
            cout << "Invalid choice" << endl;
            break;
        }
        employee.printAllEmployee();
        cout << endl << "Execution time: " << end - start << " microseconds" << endl;
        cout << "Number of comparisons: " << comparisons << endl;
        cout << "Number of swaps: " << swaps << endl;
        break;
    }


    default:
        cout << "Invalid choice" << endl;
        break;
    }

    return 0;
}