bool checkBST(Node *root, int min, int max)
{
    if (root == NULL)
    {
        return true;
    }
    if (root->data > min && root->data < max)
    {
        bool left = checkBST(root->left, min, root->data);
        bool right = checkBST(root->right, root->data, max);
        return left && right;
    }
    return false;
}
bool isBST(Node *root)
{
    // Your code here
    return checkBST(root, INT_MIN, INT_MAX);
}