#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node(int d)
    {
        this->data = d;
        this->next = NULL;
    }
};

class myStack
{
private:
    Node *top;
    int size = 0;
    int capacity = 5;

public:
    myStack()
    {
        top = NULL;
    }
    void push(int x)
    {
        if (size >= capacity)
        {
            cout << "stack overflow";
            return;
        }
        Node *newNode;
        newNode = (Node *)malloc(sizeof(Node));
        newNode->data = x;
        newNode->next = top;
        top = newNode;
        size++;
    }

    int pop()
    {
        Node *temp;
        int data;
        if (size <= 0)
        {
            cout << "stack underflow";
            return;
        }
        temp = top;
        data = top->data;
        top = top->next;
        free(temp);
        size--;
        return data;
    }

    bool isEmpty()
    {
        return size <= 0;
    }

    int peek()
    {
        if (!isEmpty())
        {
            return top->data;
        }
        else
        {
            cout << "Stack is empty.";
        }
    }
    void display()
    {
        Node *temp = top;
        while (top != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }
};
