#include <iostream>
#include "LinkedList.h"
using namespace std;

int main()
{
    int id, salary, bonus;
    string nic;
    cout << "Enter ID: ";
    cin >> id;
    cout << "Enter CNIC: ";
    cin >> nic;
    cout << "Enter Salary: ";
    cin >> salary;
    cout << "Enter Bonus: ";
    cin >> bonus;

    LinkedList l1;
    cout << l1.isEmpty() << endl;
    Employee E1(id, nic, salary, bonus);
    Employee E2(id, nic, salary, bonus);
    Employee E3(id, nic, salary, bonus);
    l1.insert(E1);
    l1.insert(E2);
    l1.insert(E3);
    l1.display();
    l1.remove(2);
    l1.display();
    l1.UpdateSalary(200, 2);
    l1.UpdateBonus(150, 1);
    l1.display();
    cout << l1.isEmpty();
    cout << endl;
    l1.sort();
    l1.display();
    return 0;
}