// watch to anuj bhaiya video for complete understanding
// convert in inorder fashion
Node *head = NULL, *prev = NULL;
void convertToCDLL(Node *root)
{
    if (root == NULL)
        return;
    convertToCDLL(root->left); // process left subtree
    if (prev == NULL)          // process root
        head = root;
    else
    {
        root->left = prev;
        prev->right = root;
    }
    prev = root;
    convertToCDLL(root->right); // process right subtree
    prev->right = head;
    head->left = prev;
}
Node *bToDLL(Node *root)
{
    // your code hereNode *curr = root;
    convertToCDLL(root);
    return head;
}