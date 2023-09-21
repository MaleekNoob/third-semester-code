#pragma once
#include <iostream>
using namespace std;

class Employee
{
private:
    int id;
    string cnic;
    int salary, bonus;

public:
    Employee()
    {
        id = 0;
        cnic = "";
        salary = 0;
        bonus = 0;
    }

    Employee(int id, string cnic, int salary, int bonus)
    {
        this->id = id;
        this->cnic = cnic;
        this->salary = salary;
        this->bonus = bonus;
    }

    void setId(int id)
    {
        this->id = id;
    }

    void setCnic(string cnic)
    {
        this->cnic = cnic;
    }

    void setSalary(int salary)
    {
        this->salary = salary;
    }

    void setBonus(int bonus)
    {
        this->bonus = bonus;
    }

    int getId()
    {
        return id;
    }

    string getCnic()
    {
        return cnic;
    }

    int getSalary()
    {
        return salary;
    }

    int getBonus()
    {
        return bonus;
    }

    void print()
    {
        cout << "ID: " << id << endl;
        cout << "CNIC: " << cnic << endl;
        cout << "Salary: " << salary << endl;
        cout << "Bonus: " << bonus << endl;
    }
};

class Node
{
private:
    Employee record;
    Node *next;

public:
    Node()
    {
        next = NULL;
    }

    Node(Employee record)
    {
        this->record = record;
        next = NULL;
    }

    void setRecord(Employee record)
    {
        this->record = record;
    }

    void setNext(Node *next)
    {
        this->next = next;
    }

    Employee getRecord()
    {
        return record;
    }

    Node *getNext()
    {
        return next;
    }
};

class LinkedList
{
private:
    Node *head;

public:
    LinkedList()
    {
        head = NULL;
    }

    ~LinkedList()
    {
        Node *temp = head;
        while (temp != NULL)
        {
            Node *temp2 = temp;
            temp = temp->getNext();
            delete temp2;
        }
    }

    void insert(const Employee &emp)
    {
        Node *newNode = new Node(emp);
        if (head == NULL)
        {
            head = newNode;
        }
        else
        {
            Node *temp = head;
            while (temp->getNext() != NULL)
            {
                temp = temp->getNext();
            }
            temp->setNext(newNode);
        }
    }

    void remove(int id)
    {
        if (head == NULL)
        {
            cout << "List is empty" << endl;
        }
        else
        {
            Node *temp = head;
            Node *prev = NULL;
            while (temp != NULL)
            {
                if (temp->getRecord().getId() == id)
                {
                    if (prev == NULL)
                    {
                        head = temp->getNext();
                    }
                    else
                    {
                        prev->setNext(temp->getNext());
                    }
                    delete temp;
                    return;
                }
                prev = temp;
                temp = temp->getNext();
            }
            cout << "Record does not exist" << endl;
        }
    }

    void UpdateSalary(const int &salary, int id)
    {
        if (head == NULL)
        {
            cout << "List is empty" << endl;
        }
        else
        {
            Node *temp = head;
            while (temp != NULL)
            {
                if (temp->getRecord().getId() == id)
                {
                    temp->getRecord().setSalary(salary);
                    return;
                }
                temp = temp->getNext();
            }
            cout << "Record does not exist" << endl;
        }
    }

    void UpdateBonus(const int &bonus, int id)
    {
        if (head == NULL)
        {
            cout << "List is empty" << endl;
        }
        else
        {
            Node *temp = head;
            while (temp != NULL)
            {
                if (temp->getRecord().getId() == id)
                {
                    temp->getRecord().setBonus(bonus);
                    return;
                }
                temp = temp->getNext();
            }
            cout << "Record does not exist" << endl;
        }
    }

    void clear()
    {
        Node *temp = head;
        while (temp != NULL)
        {
            Node *temp2 = temp;
            temp = temp->getNext();
            delete temp2;
        }
        head = NULL;
    }

    bool isEmpty()
    {
        return head == NULL;
    }

    void display()
    {
        if (head == NULL)
        {
            cout << "List is empty" << endl;
        }
        else
        {
            Node *temp = head;
            while (temp != NULL)
            {
                temp->getRecord().print();
                cout << endl
                     << endl;
                temp = temp->getNext();
            }
        }
    }

    void sort()
    {
        if (head == NULL)
        {
            cout << "List is empty" << endl;
        }
        else
        {
            Node *temp = head;
            while (temp != NULL)
            {
                Node *temp2 = temp->getNext();
                while (temp2 != NULL)
                {
                    if (temp->getRecord().getSalary() > temp2->getRecord().getSalary())
                    {
                        Employee tempEmp = temp->getRecord();
                        temp->setRecord(temp2->getRecord());
                        temp2->setRecord(tempEmp);
                    }
                    temp2 = temp2->getNext();
                }
                temp = temp->getNext();
            }
        }
    }
};