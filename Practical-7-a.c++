#include <iostream>
using namespace std;

class Queue {
private:
    int *arr;
    int n;
    int front;
    int rear;
    int count;

public:
    Queue(int size) {
        n = size;
        arr = new int[n];
        front = 0;
        rear = -1;
        count = 0;
    }

    ~Queue() {
        delete[] arr;
    }

    void join(int token) {
        if (count == n) {
            cout << "Error: Queue is full" << endl;
            return;
        }

        rear = (rear + 1) % n;
        arr[rear] = token;
        count++;

        printFront();
    }

    void serve() {
        if (count == 0) {
            cout << "Error: Queue is empty" << endl;
            return;
        }

        front = (front + 1) % n;
        count--;

        if (count == 0) {
            front = 0;
            rear = -1;
        }

        printFront();
    }

    void printFront() {
        if (count == 0)
            cout << "Front: Empty" << endl;
        else
            cout << "Front: " << arr[front] << endl;
    }
};

int main() {
    int n;
    cout << "Enter queue capacity: ";
    cin >> n;

    Queue q(n);

    int operations;
    cout << "Enter number of operations: ";
    cin >> operations;

    cout << "Enter operations (J token for join, S for serve):" << endl;

    for (int i = 0; i < operations; i++) {
        char op;
        cin >> op;

        if (op == 'J' || op == 'j') {
            int token;
            cin >> token;
            q.join(token);
        }
        else if (op == 'S' || op == 's') {
            q.serve();
        }
        else {
            cout << "Error: Invalid operation" << endl;
        }
    }

    return 0;
}
