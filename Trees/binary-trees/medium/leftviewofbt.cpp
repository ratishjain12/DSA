void leftview(Node *root,vector<int>&ans,int level){
    if(root == NULL){
        return;
    }
    if(level == ans.size()){
        ans.push_back(root->data);
    }
    leftview(root->left,ans,level+1);
    leftview(root->right,ans,level+1);
}
vector<int> leftView(Node *root)
{
   // Your code here
   vector<int>ans;
   leftview(root,ans,0);
   return ans;
}
