#include <iostream>
using namespace std;
class queue
{
    int *arr;
    int front = -1;
    int rear = -1;
    int capacity;
    int size = 0;

public:
    queue(int n)
    {
        arr = new int[n];
        capacity = n;
    }
    void enqueue(int x)
    {
        if (size == capacity)
        {
            cout << "Queue is full";
            return;
        }
        if (front == -1 && rear == -1)
        {
            rear++;
            front++;
            arr[front] = arr[rear] = x;
        }
        else
        {
            rear++;
            arr[rear] = x;
        }
        size++;
    }
    int dequeue()
    {
        int d;
        if (isEmpty())
        {
            cout << "Queue is empty";
            return;
        }
        else if (front == rear)
        {
            front = rear = -1;
        }
        else
        {
            d = arr[front];
            front++;
        }
        size--;
        return d;
    }
    int size()
    {
        return size;
    }

    int top()
    {
        return arr[front];
    }
    bool isEmpty()
    {
        return size == 0;
    }

    void display()
    {
        for (int i = front; i <= rear; i++)
        {
            cout << arr[i] << " ";
        }
    }

} int main()
{
    queue q(5);
    q.enqueue(10);
    q.enqueue(20);

    cout << q.top() << '\n';
    q.dequeue();
    cout << q.top() << '\n';
    if (q.isEmpty())
    {
        cout << "Queue is empty" << '\n';
    }
    else
    {
        cout << "Queue is not empty" << '\n';
    }
    return 0;
}
