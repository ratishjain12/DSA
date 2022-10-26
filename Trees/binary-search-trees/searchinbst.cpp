bool search(Node *root, int x)
{
    // Your code here
    if (root == NULL)
    {
        return false;
    }
    while (root)
    {
        if (root->data == x)
        {
            return true;
        }
        if (root->data < x)
        {
            root = root->right;
        }
        else
        {
            root = root->left;
        }
    }
}