bool isSym(TreeNode *root1,TreeNode *root2){
    if(root1 == NULL || root2 == NULL){
        return root1 == root2;
    }
    return (root1->val == root2->val) && isSym(root1->left,root2->right) && isSym(root1->right,root2->left);
}
bool isSymmetric(TreeNode* root) {
    if(root == NULL){
      return true;
    }
     return isSym(root->left,root->right);
}
