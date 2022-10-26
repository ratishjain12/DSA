Node *constructTree(int in[],int inStart,int inEnd,int post[],int postStart,int postEnd,map<int,int>&mp){
    if(inStart>inEnd || postStart>postEnd){
        return NULL;
    }

    Node *root = new Node(post[postEnd]);
    int inRoot = mp[root->data];
    int numsLeft = inRoot - inStart;

    root->left = constructTree(in,inStart,inRoot-1,post,postStart,postStart+numsLeft-1,mp);
    root->right = constructTree(in,inRoot+1,inEnd,post,postStart+numsLeft,postEnd-1,mp);
    return root;

}
Node *buildTree(int in[], int post[], int n) {
    // Your code here
    int inStart = 0,inEnd = n-1;
    int postStart = 0,postEnd = n-1;
    map<int,int>mp;
    for(int i = inStart;i<=inEnd;i++){
        mp[in[i]] = i;
    }
    return constructTree(in,inStart,inEnd,post,postStart,postEnd,mp);
}
