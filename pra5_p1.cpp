#include <iostream>
using namespace std;

class Node
{
public:
    string song;
    Node* prev;
    Node* next;

    Node(string name)
    {
        song = name;
        prev = NULL;
        next = NULL;
    }
};

class Playlist
{
private:
    Node* head;
    Node* tail;

public:

    Playlist()
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
        }
        else
        {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    void addEnd(string name)
    {
        Node* newNode = new Node(name);

        if (tail == NULL)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
    }

    void insertAfter(string target, string name)
    {
        Node* curr = head;

        while (curr != NULL)
        {
            if (curr->song == target)
            {
                Node* newNode = new Node(name);

                newNode->prev = curr;
                newNode->next = curr->next;

                curr->next = newNode;

                if (newNode->next == NULL)
                {
                    tail = newNode;
                }
                else
                {
                    newNode->next->prev = newNode;
                }

                return;
            }

            curr = curr->next;
        }

        cout << "Song not found." << endl;
    }

    void removeFirst()
    {
        if (head == NULL)
        {
            cout << "Playlist is empty." << endl;
            return;
        }

        Node* temp = head;

        head = head->next;

        if (head == NULL)
        {
            tail = NULL;
        }
        else
        {
            head->prev = NULL;
        }

        delete temp;
    }

    int count()
    {
        int count = 0;
        Node* curr = head;

        while (curr != NULL)
        {
            count++;
            curr = curr->next;
        }

        return count;
    }

    void display()
    {
        Node* curr = head;

        if (curr == NULL)
        {
            cout << "Playlist is empty." << endl;
            return;
        }

        while (curr != NULL)
        {
            cout << curr->song;

            if (curr->next != NULL)
            {
                cout << " -> ";
            }

            curr = curr->next;
        }

        cout << endl;
    }
};

int main()
{
    Playlist p;

    p.addBeg("A");
    p.display();

    p.addEnd("B");
    p.display();

    p.addEnd("D");
    p.display();

    p.insertAfter("B", "C");
    p.display();

    p.removeFirst();
    p.display();

    cout << "Count: " << p.count() << endl;

    return 0;
}

