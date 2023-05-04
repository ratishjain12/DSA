void inorderTrav(Node *root, vector<int> &inorder)
{
    if (root == NULL)
    {
        return;
    }
    inorderTrav(root->left, inorder);
    inorder.push_back(root->data);
    inorderTrav(root->right, inorder);
}
int isPairPresent(struct Node *root, int target)
{
    // add code here.
    vector<int> inorder;
    inorderTrav(root, inorder);
    int l = 0, r = inorder.size() - 1;
    while (l < r)
    {
        if (inorder[l] + inorder[r] > target)
        {
            r -= 1;
        }
        else if (inorder[l] + inorder[r] < target)
        {
            l += 1;
        }
        else
        {
            return 1;
        }
    }
    return 0;
}