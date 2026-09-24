#include <iostream>
using namespace std;

class Queue {
private:
    struct Node {
        int data;
        Node* next;

        Node(int value) {
            data = value;
            next = nullptr;
        }
    };

    Node* front;
    Node* rear;

public:
    Queue() {
        front = nullptr;
        rear = nullptr;
    }

    ~Queue() {
        while (front != nullptr) {
            Node* temp = front;
            front = front->next;
            delete temp;
        }
    }

    void arrive(int patient) {
        Node* newNode = new Node(patient);

        if (rear == nullptr) {
            front = rear = newNode;
        }
        else {
            rear->next = newNode;
            rear = newNode;
        }

        printFront();
    }

    void attend() {
        if (front == nullptr) {
            cout << "Error: Ward is empty" << endl;
            return;
        }

        Node* temp = front;
        front = front->next;
        delete temp;

        if (front == nullptr)
            rear = nullptr;

        printFront();
    }

    void printFront() {
        if (front == nullptr)
            cout << "Front: Empty" << endl;
        else
            cout << "Front: " << front->data << endl;
    }
};

int main() {
    Queue q;

    int operations;
    cout << "Enter number of operations: ";
    cin >> operations;

    cout << "Enter operations (A patient for arrive, T for attend):" << endl;

    for (int i = 0; i < operations; i++) {
        char op;
        cin >> op;

        if (op == 'A' || op == 'a') {
            int patient;
            cin >> patient;
            q.arrive(patient);
        }
        else if (op == 'T' || op == 't') {
            q.attend();
        }
        else {
            cout << "Error: Invalid operation" << endl;
        }
    }

    return 0;
}
