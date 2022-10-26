
// for a complete binary
// case 1 : if left height is equal to right height than  nodes count is  2^(leftHieght/rightHeight) - 1
// case 2 : else if not equal than height is 1 + left subtree height and right subtree height
int countNodes(TreeNode* root) {

    if(root == NULL){
        return 0;
    }
    int lh = findLeftHeight(root);
    int rh = findRightHeight(root);
    if(lh == rh) return pow(2,lh) - 1;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

int findLeftHeight(TreeNode *root){
    TreeNode *curr = root;
    int cnt = 0;
    while(curr){
        cnt++;
        curr = curr->left;
    }
    return cnt;
}
   int findRightHeight(TreeNode *root){
    TreeNode *curr = root;
    int cnt = 0;
    while(curr){
        cnt++;
        curr = curr->right;
    }
    return cnt;
}
