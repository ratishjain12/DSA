void postorder(Node *root,vector<int>&ans){
if(root!=NULL){

  postorder(root->left,ans);
  postorder(root->right,ans);
  ans.push_back(root->data);
  }

}
vector<int> postOrder(Node* root) {
    // Your code here
    vector<int>ans;
    postorder(root,ans);
    return ans;
}
