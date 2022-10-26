vector<int> findSpiral(TreeNode *root)
{
    //Your code here
    vector<int> ans;

        if(root == NULL)
            return ans;

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()) {

            TreeNode *temp = q.front();
            q.pop();

            if(temp->left != NULL)
                q.push(temp->left);
            if(temp->right != NULL)
                q.push(temp->right);

            ans.push_back(temp->data);
        }
        return ans;
}
