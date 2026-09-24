#include <iostream>
using namespace std;

class Stack
{
    int arr[100];
    int top;
    int n;

public:

    Stack(int size)
    {
        n = size;
        top = -1;
    }

    void push(int tray)
    {
        if (top == n - 1)
        {
            cout << "Error: Stack is Full" << endl;
            return;
        }

        top++;
        arr[top] = tray;

        cout << "Placed: " << tray << endl;
        cout << "Top Tray: " << arr[top] << endl;
    }

    void pop()
    {
        if (top == -1)
        {
            cout << "Error: Stack is Empty" << endl;
            return;
        }

        cout << "Taken: " << arr[top] << endl;
        top--;

        if (top == -1)
            cout << "Top Tray: Empty" << endl;
        else
            cout << "Top Tray: " << arr[top] << endl;
    }
};

int main()
{
    int n, operations;

    cout << "Enter capacity: ";
    cin >> n;

    Stack s(n);

    cout << "Enter number of operations: ";
    cin >> operations;

    for (int i = 0; i < operations; i++)
    {
        char choice;

        cout << "Enter P for Place or T for Take: ";
        cin >> choice;

        if (choice == 'P' || choice == 'p')
        {
            int tray;
            cout << "Enter tray number: ";
            cin >> tray;

            s.push(tray);
        }
        else if (choice == 'T' || choice == 't')
        {
            s.pop();
        }
        else
        {
            cout << "Invalid operation" << endl;
        }
    }

    return 0;
}