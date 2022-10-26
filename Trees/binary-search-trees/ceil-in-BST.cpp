int findCeil(Node *root, int input)
{
    int Ceil = -1;
    while (root)
    {
        if (root->data == input)
        {
            Ceil = input;
            return Ceil;
        }

        if (input > root->data)
        {
            root = root->right;
        }
        else
        {
            Ceil = root->data;
            root = root->left;
        }
    }
    return Ceil;
    // Your code here
}