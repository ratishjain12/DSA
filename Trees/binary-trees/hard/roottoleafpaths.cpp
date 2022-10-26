void f(Node *root, vector<int> path, vector<vector<int>> &res)
{
    if (root == NULL)
    {
        return;
    }
    path.push_back(root->data);
    if (!root->left && !root->right)
    {
        res.push_back(path);
        return;
    }
    f(root->left, path, res);
    f(root->right, path, res);
}
vector<vector<int>> Paths(Node *root)
{
    // Code here
    vector<vector<int>> res;
    vector<int> path;
    if (root == NULL)
    {
        return res;
    }
    f(root, path, res);
    return res;
}