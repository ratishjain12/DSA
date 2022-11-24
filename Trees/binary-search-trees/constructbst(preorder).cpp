Node *post_order(int pre[], int size)
{
    // code here
    int i = 0;
    return construct(pre, i, INT_MAX, size);
}

Node *construct(int pre[], int &i, int bound, int size)
{
    if (i == size || pre[i] > bound)
        return NULL;
    Node *root = newNode(pre[i++]);
    root->left = construct(pre, i, root->data, size);
    root->right = construct(pre, i, bound, size);
    return root;
}