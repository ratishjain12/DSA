TreeNode *invertTree(TreeNode *root)
{
    if (root == NULL)
    {
        return NULL;
    }
    invertTree(root->left);
    invertTree(root->right);
    swap(root->left, root->right);
    return root;
}
// gfg
void mirror(Node *node)
{
    // code here
    if (node == NULL)
    {
        return;
    }
    Node *temp = node->left;
    node->left = node->right;
    node->right = temp;
    mirror(node->left);
    mirror(node->right);
}