int getMaxWidth(Node *root)
{

    // Your code here
    if (root == NULL)
    {
        return 0;
    }
    int res = 0;
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        int size = q.size();
        res = max(res, size);

        for (int i = 0; i < size; i++)
        {
            Node *front = q.front();
            q.pop();
            if (front->left)
            {
                q.push(front->left);
            }
            if (front->right)
            {
                q.push(front->right);
            }
        }
    }
    return res;
}