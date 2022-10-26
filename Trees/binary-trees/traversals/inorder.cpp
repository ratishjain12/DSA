void inorder(Node *root,vector<int>&ans){
if(root!=NULL){

  inorder(root->left,ans);
  ans.push_back(root->data);
  inorder(root->right,ans);
  }

}
vector<int> inOrder(Node* root) {
    // Your code here
    vector<int>ans;
    inorder(root,ans);
    return ans;
}
