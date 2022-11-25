void findPreSuc(Node *root, Node *&pre, Node *&suc, int key)
{
    // Your code goes here
    pre = NULL;
    suc = NULL;
    Node *temp = root;
    while (temp != NULL)
    {
        if (key >= temp->key)
        {
            temp = temp->right;
        }
        else
        {
            suc = temp;
            temp = temp->left;
        }
    }
    temp = root;
    while (temp != NULL)
    {
        if (key > temp->key)
        {
            pre = temp;
            temp = temp->right;
        }
        else
        {
            temp = temp->left;
        }
    }
}