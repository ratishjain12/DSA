
Node *minVal(Node *root)
{
    if (root->left == NULL)
        return root;
    minVal(root->left);
}
Node *deleteNode(Node *root, int X)
{
    // your code goes here
    if (root == NULL)
    {
        return root;
    }
    if (root->data == X)
    {
        // 0 child
        if (root->left == NULL && root->right == NULL)
        {
            delete root;
            return NULL;
        }

        // 1 child
        if (root->left != NULL && root->right == NULL)
        {
            Node *temp = root->left;
            delete root;
            return temp;
        }
        if (root->left == NULL && root->right != NULL)
        {
            Node *temp = root->right;
            delete root;
            return temp;
        }
        // 2 child
        if (root->left != NULL && root->right != NULL)
        {
            int mini = minVal(root->right)->data;
            root->data = mini;
            root->right = deleteNode(root->right, mini);
            return root;
        }
    }
    else if (root->data > X)
    {
        root->left = deleteNode(root->left, X);
        return root;
    }
    else
    {
        root->right = deleteNode(root->right, X);
        return root;
    }
}
