void connect(Node *root)

{

    // Your Code Here

    queue<Node *> q;

    q.push(root);

    while (!q.empty())
    {

        Node *temp = NULL;
        int n = q.size();

        for (int i = 0; i < n; i++)
        {
            Node *front = q.front();
            q.pop();
            front->nextRight = temp;
            if (front->right)
                q.push(front->right);
            if (front->left)
                q.push(front->left);
            temp = front;
        }
    }
}