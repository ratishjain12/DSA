// A tree can be folded if left and right subtrees of the tree are structure wise mirror/symmetric image of
// each other. An empty tree is considered as foldable.
bool isSym(Node *l, Node *r)
{
    if (l == NULL || r == NULL)
    {
        return l == r;
    }
    return isSym(l->left, r->right) && isSym(l->right, r->left);
}
bool IsFoldable(Node *root)
{
    // Your code goes here
    if (root == NULL)
    {
        return true;
    }
    return isSym(root->left, root->right);
}