int dfsHeight(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int l = dfsHeight(root->left);

    int r = dfsHeight(root->right);
    if (l == -1 || r == -1)
    {
        return -1;
    }

    if (abs(l - r) > 1)
    {
        return -1;
    }
    return 1 + max(l, r);
}
bool isBalanced(Node *root)
{
    //  Your Code here
    return dfsHeight(root) != -1;
}

// bruteforce approach and easy approach
int height(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    return max(height(root->left), height(root->right)) + 1;
}

bool isBalanced(Node *root)
{
    //  Your Code here
    if (root == NULL)
    {
        return true;
    }
    int left = height(root->left);
    int right = height(root->right);

    return (abs(left - right) <= 1) && isBalanced(root->left) && isBalanced(root->right);
}