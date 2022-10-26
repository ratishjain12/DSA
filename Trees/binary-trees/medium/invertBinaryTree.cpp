TreeNode* invertTree(TreeNode* root) {
    if(root == NULL){
        return NULL;
    }
    invertTree(root->left);
    invertTree(root->right);
    swap(root->left,root->right);
    return root;
}
