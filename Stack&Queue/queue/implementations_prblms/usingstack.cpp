class Queue
{
    stack<int> s1, s2;

public:
    void enqueue(int x)
    {
        while (!s1.empty())
        {
            s2.push(s1.top());
            s1.pop();
        }
        s1.push(x);
        while (!s2.empty())
        {
            s1.push(s2.top());
            s2.pop();
        }
    }

    int dequeue()
    {
        if (s1.empty())
        {
            return -1;
        }
        int d = s1.top();
        s1.pop();
        return d;
    }
    int Size()
    {
        return s1.size();
    }
    int top()
    {
        return s1.top();
    }

    bool isEmpty()
    {
        return s1.empty();
    }
};