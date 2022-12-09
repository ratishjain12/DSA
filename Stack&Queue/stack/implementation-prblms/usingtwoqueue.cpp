class Stack
{
    queue<int> q1;
    queue<int> q2;

public:
    void push(int x)
    {
        while (!q1.empty())
        {
            q2.push(q1.front());
            q1.pop();
        }
        q1.push(x);
        while (!q2.empty())
        {
            q1.push(q2.front());
            q2.pop();
        }
    }

    int pop()
    {
        if (q1.empty())
        {
            return -1;
        }
        int d = q1.front();
        q1.pop();
        return d;
    }
    int top()
    {
        return q1.front();
    }
    int size()
    {
        return q1.size();
    }
    bool isEmpty()
    {
        return q1.empty();
    }
}