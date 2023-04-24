unordered_map<Node *, int> mp; // for optimization
int getMaxSum(Node *root)
{
    // Add your code here
    if (root == NULL)
        return 0;

    if (mp[root])
        return mp[root];
    // take the node
    int take = root->data;
    if (root->left)
    {
        take += getMaxSum(root->left->left);
        take += getMaxSum(root->left->right);
    }
    if (root->right)
    {
        take += getMaxSum(root->right->right);
        take += getMaxSum(root->right->left);
    }
    // do not take the node
    int notTake = getMaxSum(root->left) + getMaxSum(root->right);
    return mp[root] = max(take, notTake);
}