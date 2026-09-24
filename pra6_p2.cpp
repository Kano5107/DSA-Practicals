#include <iostream>
#include <string>
using namespace std;

struct Node
{
    string page;
    Node* next;
};

class Browser
{
    Node* top;

public:
    Browser()
    {
        top = NULL;
    }

    void visit(string page)
    {
        Node* newNode = new Node;
        newNode->page = page;
        newNode->next = top;
        top = newNode;
    }

    void back()
    {
        if (top == NULL)
        {
            cout << "No history left" << endl;
            return;
        }

        Node* temp = top;
        top = top->next;
        delete temp;
    }

    void currentPage()
    {
        if (top == NULL)
            cout << "No page" << endl;
        else
            cout << top->page << endl;
    }
};

int main()
{
    Browser b;

    b.visit("Google");
    b.currentPage();

    b.visit("YouTube");
    b.currentPage();

    b.visit("GitHub");
    b.currentPage();

    b.back();
    b.currentPage();

    b.back();
    b.currentPage();

    b.back();
    b.currentPage();

    b.back();

    return 0;
}