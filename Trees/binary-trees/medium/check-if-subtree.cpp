bool isSame(Node *T, Node *S) // for every root and check with subtroot
{
    if (T == NULL && S == NULL)
    {
        return true;
    }
    if (T == NULL || S == NULL)
    {
        return false;
    }
    if (T->data != S->data)
    {
        return false;
    }
    return isSame(T->left, S->left) && isSame(T->right, S->right);
}
bool isSubTree(Node *T, Node *S)
{
    // Your code here
    if (T == NULL && S == NULL)
    {
        return true;
    }
    if (T == NULL || S == NULL)
    {
        return false;
    }

    return isSame(T, S) || isSubTree(T->left, S) || isSubTree(T->right, S);
}