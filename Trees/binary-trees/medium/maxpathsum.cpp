int maxPath(Node *root,int &maxi){
    if(root == NULL){
        return 0;
    }
    int lmax = max(0,maxPath(root->left,maxi));
    int rmax = max(0,maxPath(root->right,maxi));
    int val = root->data;
    maxi = max(maxi,val+lmax+rmax);
    return val + max(lmax,rmax);
}
int findMaxSum(Node* root)
{

    // Your code goes here
    int maxi = INT_MIN;
    maxPath(root,maxi);
    return maxi;
}
