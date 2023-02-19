void inorderTraversal(struct Node *root, vector<Node *> &inorderTrav)
{
    if (root == NULL)
    {
        return;
    }
    inorderTraversal(root->left, inorderTrav);
    inorderTrav.push_back(root);
    inorderTraversal(root->right, inorderTrav);
}
struct Node *correctBST(struct Node *root)
{
    // code here
    vector<Node *> inorderTrav;
    Node *first = NULL, *second = NULL;
    inorderTraversal(root, inorderTrav);
    for (int i = 1; i < inorderTrav.size(); i++)
    {
        if (inorderTrav[i - 1]->data > inorderTrav[i]->data)
        {
            if (first == NULL)
            {
                first = inorderTrav[i - 1];
            }
            second = inorderTrav[i];
        }
    }

    int temp = first->data;
    first->data = second->data;
    second->data = temp;
    return root;
}

// O(1) space solution

class Solution
{
private:
    TreeNode *first;
    TreeNode *prev;
    TreeNode *last;

private:
    void inorder(TreeNode *root)
    {
        if (root == NULL)
        {
            return;
        }
        inorder(root->left);
        if (prev != NULL && root->val < prev->val)
        {
            if (first == NULL)
            {
                first = prev;
            }
            last = root;
        }
        prev = root;
        inorder(root->right);
    }

public:
    void recoverTree(TreeNode *root)
    {
        first = last = NULL;
        prev = new TreeNode(INT_MIN);
        inorder(root);
        if (first && last)
            swap(first->val, last->val);
    }
};