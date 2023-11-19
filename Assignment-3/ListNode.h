#pragma once

// Define a structure for a linked list node
template <class T>
class listNode
{
public:
    T data;
    listNode *next;

    // Constructor for creating a new node
    listNode(T value) : data(value), next(nullptr) {}
};
