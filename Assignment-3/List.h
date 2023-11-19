#pragma once
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include "ListNode.h"
using namespace std;

// Define a linked list class
template <class T>
class list
{
private:
    listNode<T> *head;

public:
    // Constructor
    list() : head(nullptr) {}

    // Function to insert a new node at the end of the list
    void push_back(T value)
    {
        listNode<T> *newNode = new listNode<T>(value);
        if (head == nullptr)
        {
            head = newNode;
        }
        else
        {
            listNode<T> *current = head;
            while (current->next != nullptr)
            {
                current = current->next;
            }
            current->next = newNode;
        }
    }

    // Function to remove a node from the list
    void remove(T value)
    {
        listNode<T> *current = head;
        listNode<T> *prev = nullptr;
        while (current != nullptr)
        {
            if (current->data == value)
            {
                if (prev == nullptr)
                {
                    head = current->next;
                }
                else
                {
                    prev->next = current->next;
                }
                delete current;
                return;
            }
            prev = current;
            current = current->next;
        }
    }

    // Function to display the linked list
    void displayList()
    {
        listNode<T> *current = head;
        while (current != nullptr)
        {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    // Destructor to free memory
    ~list()
    {
        listNode<T> *current = head;
        listNode<T> *next;
        while (current != nullptr)
        {
            next = current->next;
            delete current;
            current = next;
        }
    }

    // Function to get the head of the list
    listNode<T> *getHead()
    {
        return head;
    }

    // Function to get the tail of the list
    listNode<T> *getTail()
    {
        listNode<T> *current = head;
        while (current->next != nullptr)
        {
            current = current->next;
        }
        return current;
    }
};
