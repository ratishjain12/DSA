vector<vector<int>> zigzagLevelOrder(TreeNode *root)
{
    vector<vector<int>> ans;
    if (root == NULL)
    {
        return ans;
    }
    queue<TreeNode *> q;
    bool leftToRight = true;
    q.push(root);
    while (!q.empty())
    {
        int size = q.size();
        vector<int> row(size);
        for (int i = 0; i < size; i++)
        {
            TreeNode *node = q.front();
            q.pop();
            int index = (leftToRight) ? i : size - 1 - i;
            row[index] = node->val;
            if (node->left)
            {
                q.push(node->left);
            }
            if (node->right)
            {
                q.push(node->right);
            }
        }
        leftToRight = !leftToRight;
        ans.push_back(row);
    }
    return ans;
}
// another one gfg portal
vector<int> zigZagTraversal(Node *root)
{
    // Code here
    vector<int> ans;
    if (root == NULL)
    {
        return ans;
    }
    queue<Node *> q;
    bool leftToRight = true;
    q.push(root);

    while (!q.empty())
    {
        int size = q.size();
        vector<int> row(size);
        for (int i = 0; i < size; i++)
        {
            Node *node = q.front();
            q.pop();
            int index = (leftToRight) ? i : size - 1 - i;
            row[index] = node->data;
            if (node->left)
            {
                q.push(node->left);
            }
            if (node->right)
            {
                q.push(node->right);
            }
        }
        leftToRight = !leftToRight;
        for (auto it : row)
        {
            ans.push_back(it);
        }
    }

    return ans;
}