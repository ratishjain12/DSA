TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
{
    while (root != NULL)
    {
        if (root->val < p->val && root->val < q->val)
        {
            root = root->right;
        }
        else if (root->val > p->val && root->val > q->val)
        {
            root = root->left;
        }
        else
        {
            return root;
        }
    }
    return NULL;
}