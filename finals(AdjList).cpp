#include <iostream>
using namespace std;

struct Neighbor {
    int id;
    Neighbor* next;

    Neighbor(int id) {
        this->id = id;
        next = nullptr;
    }
};

class Weight {
    int src, dest;
    float weight;

    Weight(int src, int dest, float weight) {
        this->src = src;
        this->dest = dest;
        this->weight = weight;
    }
};

struct Vertex {
    int id;
    Vertex* next;
    Neighbor* head;

    Vertex(int id) {
        this->id = id;
        next = nullptr;
        head = nullptr;
    }

    void addNeighborInList(int neighborId, float weight) {
        if (head == nullptr) {
            head = new Neighbor(neighborId);
            return;
        }
        Neighbor* traverse = head;
        while (traverse->next != nullptr) {
            traverse = traverse->next;
        }
        traverse->next = new Neighbor(neighborId);
    }
};

class Graph {
    Vertex* head;
};

int main() {



    return 0;
}