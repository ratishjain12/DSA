int height(struct Node* node){
    // code here
    if(node == NULL){
        return 0;
    }
    int l = height(node->left);
    int r = height(node->right);
    return 1+max(l,r);
}
