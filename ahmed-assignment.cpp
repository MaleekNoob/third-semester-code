/*
Implement a linked list to store a path (can be a path or a shape) on earth’s surface. A point on earth’s surface is defined by three values, altitude, latitude and longitude.

For linked list, use the following structure for a Node:

struct tagPOE {
   float alt;
   double lat;
   double long;
   struct tagPOE* pNext;
};

struct tagPOE* pShape;

 
Write the code for following functions for the linked list. Decide on their arguments and return values appropriately.

S#	Function Name	Description
1	AddHead	Add Head Node
2	AddTail	Remove Tail Node
3	AddNodeAt	Add Node at index. Index is the number of node from head. Head is at index 0. Just like an array’s index.
4	RemHead	Remove Head Node
5	RemTail	Remove Tail Node
6	RemNodeAt	Remove Node at index
7	RemAll	Remove All Nodes
8	ShowList	Outputs the whole list, one node on one line after showing index
9	Search	Searches for a specific value (within an acceptable range)
*/

#include <iostream>
#include <string>
using namespace std;

struct tagPOE {
   float alt;
   double lat;
   double _long;
   struct tagPOE* pNext;
};

struct tagPOE* pShape;

void AddHead(float alt, double lat, double _long) {
    tagPOE* temp = new tagPOE;
    temp->alt = alt;
    temp->lat = lat;
    temp->_long = _long;
    if (pShape == NULL) {
        pShape = temp;
        pShape->pNext = NULL;
        return;
    }
    temp->pNext = pShape;
    pShape = temp;
}

void AddTail(float alt, double lat, double _long) {
    tagPOE* temp = new tagPOE;
    temp->alt = alt;
    temp->lat = lat;
    temp->_long = _long;
    if (pShape == NULL) {
        pShape = temp;
        pShape->pNext = NULL;
        return;
    }
    tagPOE* temp2 = pShape;
    while (temp2->pNext != NULL) {
        temp2 = temp2->pNext;
    }
    temp2->pNext = temp;
    temp->pNext = NULL;
}

void AddNodeAt(float alt, double lat, double _long, int index) {
    tagPOE* temp = new tagPOE;
    temp->alt = alt;
    temp->lat = lat;
    temp->_long = _long;
    if (pShape == NULL) {
        pShape = temp;
        pShape->pNext = NULL;
        return;
    }
    tagPOE* temp2 = pShape;
    for (int i = 0; i < index - 1; i++) {
        temp2 = temp2->pNext;
    }
    temp->pNext = temp2->pNext;
    temp2->pNext = temp;
}

void RemHead() {
    if (pShape == NULL) {
        return;
    }
    tagPOE* temp = pShape;
    pShape = pShape->pNext;
    delete temp;
}

void RemTail() {
    if (pShape == NULL) {
        return;
    }
    tagPOE* temp = pShape;
    while (temp->pNext->pNext != NULL) {
        temp = temp->pNext;
    }
    delete temp->pNext;
    temp->pNext = NULL;
}

void RemNodeAt(int index) {
    if (pShape == NULL) {
        return;
    }
    tagPOE* temp = pShape;
    for (int i = 0; i < index - 1; i++) {
        temp = temp->pNext;
    }
    tagPOE* temp2 = temp->pNext;
    temp->pNext = temp->pNext->pNext;
    delete temp2;
}

void RemAll() {
    if (pShape == NULL) {
        return;
    }
    tagPOE* temp = pShape;
    while (temp != NULL) {
        pShape = pShape->pNext;
        delete temp;
        temp = pShape;
    }
}

void ShowList() {
    if (pShape == NULL) {
        return;
    }
    tagPOE* temp = pShape;
    int i = 0;
    while (temp != NULL) {
        cout << i << " " << temp->alt << " " << temp->lat << " " << temp->_long << endl;
        temp = temp->pNext;
        i++;
    }
}

void Search(float alt, double lat, double _long) {
    if (pShape == NULL) {
        return;
    }
    tagPOE* temp = pShape;
    while (temp != NULL) {
        if (temp->alt == alt && temp->lat == lat && temp->_long == _long) {
            cout << "Found" << endl;
            return;
        }
        temp = temp->pNext;
    }
    cout << "Not Found" << endl;
}

int main() {
    AddHead(1, 1, 1);
    AddHead(2, 2, 2);
    AddHead(3, 3, 3);
    AddTail(4, 4, 4);
    AddTail(5, 5, 5);
    AddTail(6, 6, 6);
    AddNodeAt(7, 7, 7, 3);
    AddNodeAt(8, 8, 8, 5);
    ShowList();
    cout << endl;
    RemHead();
    RemTail();
    RemNodeAt(3);
    ShowList();
    cout << endl;
    Search(1, 1, 1);
    Search(2, 2, 2);
    Search(3, 3, 3);
    Search(4, 4, 4);
    Search(5, 5, 5);
    Search(6, 6, 6);
    Search(7, 7, 7);
    Search(8, 8, 8);
    Search(9, 9, 9);
    RemAll();
    ShowList();
    return 0;
}