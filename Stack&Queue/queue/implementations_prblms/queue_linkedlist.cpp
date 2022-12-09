#include <iostream>
using namespace std;
class Node
{
    int data;
    Node *next;
    Node(int d)
    {
        this->data = d;
        this->next = NULL;
    }
}

class queue
{
    Node *front;
    Node *rear;
    int size = 0;

public:
    queue()
    {
        front = NULL;
        rear = NULL;
    }

    void enqueue(int x)
    {
        Node *temp = new Node(x);
        if (front == NULL && rear == NULL)
        {
            front = rear = temp;
        }
        else
        {
            rear->next = temp;
            rear = temp;
        }
        size++;
    }

    int dequeue()
    {
        Node *temp;
        int d;
        if (front == NULL)
        {
            cout << "Queue is empty";
            return -1;
        }
        temp = front;
        front = front->next;
        if (front == NULL)
            rear = NULL;
        d = temp->data;
        free(temp);
        size--;
        return d;
    }
    int Size()
    {
        return size;
    }

    bool isEmpty()
    {
        return front == NULL;
    }
    int top()
    {
        return front->data;
    }
    void display()
    {
        Node *temp = front;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }
};