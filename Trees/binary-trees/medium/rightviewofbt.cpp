void rv(TreeNode *root,vector<int>&ans,int level){
    if(root == NULL){
        return;
    }
    if(level == ans.size()){
        ans.push_back(root->val);
    }
    rv(root->right,ans,level+1);
    rv(root->left,ans,level+1);
}
vector<int> rightSideView(TreeNode* root) {
    vector<int>ans;
    rv(root,ans,0);
    return ans;
}
