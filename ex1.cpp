#include <iostream>
#include <stdexcept>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
    Node(int value) : data(value), next(nullptr), prev(nullptr) {}
};

class DoublyLinkedList {
private:
    Node* head;
    Node* tail;

public:
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}

    void AddToEnd(int value) {
        try {
            Node* newNode = new Node(value);
            if (!head) {
                head = tail = newNode;
            } else {
                tail->next = newNode;
                newNode->prev = tail;
                tail = newNode;
            }
        } catch (bad_alloc& e) {
            throw runtime_error("Memory allocation failed: " + string(e.what()));
        }
    }

    void RemoveFromStart() {
        if (!head) {
            throw underflow_error("Cannot remove from an empty list.");
        }

        Node* temp = head;
        head = head->next;
        if (head) {
            head->prev = nullptr;
        } else {
            tail = nullptr;
        }
        delete temp;
    }

    void PrintList() const {
        if (!head) {
            throw runtime_error("List is empty.");
        }
        Node* current = head;
        while (current) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    ~DoublyLinkedList() {
        while (head) {
            RemoveFromStart();
        }
    }
};

int main() {
    DoublyLinkedList list;

    try {
        list.AddToEnd(10);
        list.AddToEnd(20);
        list.PrintList();

        list.RemoveFromStart();
        list.PrintList();

        list.RemoveFromStart();
        list.RemoveFromStart();
    } catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }

    return 0;
}
