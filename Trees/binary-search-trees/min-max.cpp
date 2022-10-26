

// for min element
Node *minElem(Node *root)
{
    if (root->left == NULL)
        return root;
    minElem(root->left);
}
int minValue(Node *root)
{
    // Code here
    if (root == NULL)
    {
        return -1;
    }
    return minElem(root)->data;
}

// for max element
Node *maxElem(Node *root)
{
    if (root->right == NULL)
        return root;
    maxElem(root->right);
}
int maxValue(Node *root)
{
    // Code here
    if (root == NULL)
    {
        return -1;
    }
    return maxElem(root)->data;
}
