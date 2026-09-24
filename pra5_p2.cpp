#include <iostream>
using namespace std;

class Node
{
public:
    string name;
    Node* next;

    Node(string x)
    {
        name = x;
        next = NULL;
    }
};

class Circle
{
private:
    Node* head;
    Node* tail;

public:

    Circle()
    {
        head = NULL;
        tail = NULL;
    }

    void addBeg(string name)
    {
        Node* newNode = new Node(name);

        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
            newNode->next = head;
        }
        else
        {
            newNode->next = head;
            head = newNode;
            tail->next = head;
        }
    }

    void addEnd(string name)
    {
        Node* newNode = new Node(name);

        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
            newNode->next = head;
        }
        else
        {
            newNode->next = head;
            tail->next = newNode;
            tail = newNode;
        }
    }

    void insertAfter(string target, string name)
    {
        if (head == NULL)
            return;

        Node* curr = head;

        do
        {
            if (curr->name == target)
            {
                Node* newNode = new Node(name);

                newNode->next = curr->next;
                curr->next = newNode;

                if (curr == tail)
                    tail = newNode;

                return;
            }

            curr = curr->next;

        } while (curr != head);

        cout << "Student not found." << endl;
    }

    void remove(string name)
    {
        if (head == NULL)
        {
            cout << "Circle is empty." << endl;
            return;
        }

        Node* curr = head;
        Node* prev = tail;

        do
        {
            if (curr->name == name)
            {
                if (head == tail)
                {
                    head = NULL;
                    tail = NULL;
                }
                else
                {
                    prev->next = curr->next;

                    if (curr == head)
                        head = curr->next;

                    if (curr == tail)
                        tail = prev;

                    tail->next = head;
                }

                delete curr;
                return;
            }

            prev = curr;
            curr = curr->next;

        } while (curr != head);

        cout << "Student not found." << endl;
    }

    void display()
    {
        if (head == NULL)
        {
            cout << "Circle is empty." << endl;
            return;
        }

        Node* curr = head;

        do
        {
            cout << curr->name << " -> ";
            curr = curr->next;

        } while (curr != head);

        cout << "(back to " << head->name << ")" << endl;
    }
};

int main()
{
    Circle c;

    c.addEnd("A");
    c.display();

    c.addEnd("B");
    c.display();

    c.addEnd("C");
    c.display();

    c.insertAfter("B", "D");
    c.display();

    c.remove("C");
    c.display();

    c.remove("A");
    c.display();

    return 0;
}

