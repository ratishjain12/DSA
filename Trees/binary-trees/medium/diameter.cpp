int height(Node *root,int &diameter){
    if(root == NULL){
        return 0;
    }
    int lh = height(root->left,diameter);
    int rh = height(root->right,diameter);
    diameter = max(diameter,lh+rh+1);
    return 1+max(lh,rh);
}
int diameter(Node* root) {
    // Your code here
    int diameter = 0;
    height(root,diameter);
    return diameter;
}
