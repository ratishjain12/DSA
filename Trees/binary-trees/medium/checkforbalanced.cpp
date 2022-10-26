int dfsHeight(Node *root){
    if(root == NULL){
        return 0;
    }
    int l = dfsHeight(root->left);

    int r = dfsHeight(root->right);
    if(l == -1 || r == -1){
        return -1;
    }

    if(abs(l-r)>1){
        return -1;
    }
    return 1+max(l,r);
}
bool isBalanced(Node *root)
{
    //  Your Code here
    return dfsHeight(root)!=-1;
}
