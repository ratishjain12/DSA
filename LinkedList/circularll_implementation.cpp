#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        this->data = 0;
        this->next = NULL;
    }
    Node(int x)
    {
        this->data = x;
        this->next = NULL;
    }
}

class cll
{
    Node *head;
    Node *tail;

public:
    cll()
    {
        this->head = NULL;
        this->tail = NULL;
    }
    void insert(int x)
    {
        Node *newNode = newNode(x);
        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
            return;
        }
        tail->next = newNode;
        newNode->next = head;
        tail = newNode;
    }

    void delNode(int x)
    {
        Node *temp = head;
        if (head == tail)
        {
            head = NULL;
            tail = NULL;
            return;
        }
        if (temp->data == x)
        {
            head = head->next;
            tail->next = head;
            return;
        }
        do
        {
            Node *n = temp->next;
            if (n->data == x)
            {
                temp->next = n->next;
                break;
            }
            temp = temp->next;
        } while (temp != head);
    }

    void display()
    {
        Node *temp = head;
        if (head != NULL)
        {
            do
            {
                cout << temp->data << "-->";
                if (temp->next != NULL)
                {
                    temp = temp->next;
                }
            } while (temp != head);
        }
    }
}