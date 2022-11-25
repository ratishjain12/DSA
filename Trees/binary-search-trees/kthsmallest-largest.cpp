class Solution
{
public:
    int ans;
    int count = 0;
    int kthSmallest(TreeNode *root, int k)
    {
        if (root != NULL)
        {
            kthSmallest(root->left, k);
            count++;
            if (count == k)
            {
                ans = root->val;
            }
            kthSmallest(root->right, k);
        }
        return ans;
    }
};