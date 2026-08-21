#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = nullptr;
    }
};

class Queue {
private:
    Node* front;
    Node* rear;

public:
    Queue() {
        front = nullptr;
        rear = nullptr;
    }

    // Insert at rear
    void enqueue(int value) {
        Node* newNode = new Node(value);

        if (front == nullptr) {
            front = rear = newNode;
        }
        else {
            rear->next = newNode;
            rear = newNode;
        }
    }

    // Delete patient by value
    void deleteByValue(int value) {
        if (front == nullptr) {
            cout << "Queue is empty\n";
            return;
        }

        // If first node contains the value
        if (front->data == value) {
            Node* temp = front;
            front = front->next;

            if (front == nullptr)
                rear = nullptr;

            delete temp;
            return;
        }

        Node* current = front;

        while (current->next != nullptr &&
               current->next->data != value) {
            current = current->next;
        }

        // Value not found
        if (current->next == nullptr) {
            cout << "Patient not found\n";
            return;
        }

        Node* temp = current->next;
        current->next = temp->next;

        // If deleting the rear node
        if (temp == rear)
            rear = current;

        delete temp;
    }

    // Forward traversal
    void displayForward() {
        Node* current = front;

        cout << "Front to Back: ";

        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }

        cout << endl;
    }

    // Reverse printing
    void displayReverse(Node* current) {
        if (current == nullptr)
            return;

        displayReverse(current->next);

        cout << current->data << " ";
    }

    void reversePrint() {
        cout << "Back to Front: ";
        displayReverse(front);
        cout << endl;
    }
};

int main() {

    Queue q;

    q.enqueue(101);
    q.enqueue(102);
    q.enqueue(103);
    q.enqueue(104);
    q.enqueue(105);

    q.displayForward();

    // Delete patient 103
    q.deleteByValue(103);

    q.displayForward();

    // Print from last to first
    q.reversePrint();

    return 0;
}