// watch to anuj bhaiya video for complete understanding
// convert in inorder fashion 
Node *head = NULL, *prev = NULL;
void convertToDLL(Node *root)
{
    if (root == NULL)
        return;
    convertToDLL(root->left); // process left subtree
    if (prev == NULL)         // process root
        head = root;
    else
    {
        root->left = prev;
        prev->right = root;
    }
    prev = root;
    convertToDLL(root->right); // process right subtree
}
Node *bToDLL(Node *root)
{
    // your code hereNode *curr = root;
    convertToDLL(root);
    return head;
}