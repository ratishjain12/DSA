Node *insert(Node *root, int Key)
{
    // Your code here
    if (root == NULL)
    {
        return new Node(Key);
    }
    Node *curr = root;
    while (true)
    {
        if (curr->data == Key)
        {
            break;
        }
        else if (curr->data < Key)
        {
            if (curr->right != NULL)
            {
                curr = curr->right;
            }
            else
            {
                curr->right = new Node(Key);
                break;
            }
        }
        else
        {
            if (curr->left != NULL)
            {
                curr = curr->left;
            }
            else
            {
                curr->left = new Node(Key);
                break;
            }
        }
    }
    return root;
}