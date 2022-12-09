
// kth-smallest
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


//kth-largest 
class Solution {
public:
    int ans;
    int count = 0;
    int kthSmallest(TreeNode* root, int k) {
        if(root != NULL){
            kthSmallest(root->right,k);
            count++;
            if(count == k){
                ans = root->val;
            }
            kthSmallest(root->left,k);
        }
        return ans;
    }
};