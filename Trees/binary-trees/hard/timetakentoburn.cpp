Node *createNodeToParent(Node *root, int target, map<Node *, Node *> &mp)
{
    Node *res = NULL;
    mp[root] = NULL;
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        Node *front = q.front();
        q.pop();
        if (front->data == target)
        {
            res = front;
        }
        if (front->left)
        {
            q.push(front->left);
            mp[front->left] = front;
        }
        if (front->right)
        {
            q.push(front->right);
            mp[front->right] = front;
        }
    }
    return res;
}
int burnTree(Node *root, map<Node *, Node *> &mp)
{
    int ans = 0;
    map<Node *, bool> visited;
    queue<Node *> q;
    visited[root] = true;
    q.push(root);
    while (!q.empty())
    {
        int flag = 0;
        int size = q.size();
        for (int i = 0; i < size; i++)
        {
            Node *front = q.front();
            q.pop();
            if (front->left && !visited[front->left])
            {
                flag = 1;
                q.push(front->left);
                visited[front->left] = 1;
            }
            if (front->right && !visited[front->right])
            {
                flag = 1;
                q.push(front->right);
                visited[front->right] = 1;
            }
            if (mp[front] && !visited[mp[front]])
            {
                flag = 1;
                q.push(mp[front]);
                visited[mp[front]] = 1;
            }
        }
        if (flag)
        {
            ans++;
        }
    }
    return ans;
}
int minTime(Node *root, int target)
{
    // Your code goes here
    map<Node *, Node *> mp;
    Node *targetNode = createNodeToParent(root, target, mp);
    return burnTree(targetNode, mp);
}