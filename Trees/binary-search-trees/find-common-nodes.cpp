void inorder(Node *root,vector<int>&res){
        if(root == NULL){
            return;
        }
        
        inorder(root->left,res);
        res.push_back(root->data);
        inorder(root->right,res);
}
vector <int> findCommon(Node *root1, Node *root2){
     //Your code here
     vector<int>inorderTrav1;
     vector<int>inorderTrav2;
     inorder(root1,inorderTrav1);
     inorder(root2,inorderTrav2);
     vector<int>ans;
     set<int>st(inorderTrav1.begin(),inorderTrav1.end());
     for(int i : inorderTrav2){
         if(st.find(i) != st.end()){
             ans.push_back(i);
         }
     }
     
     return ans;
} 

// another way to find common nodes

void inorder(Node *root,map<int,int>&mp){
        if(root == NULL){
            return;
        }
        
        inorder(root->left,mp);
        mp[root->data]++;
        inorder(root->right,mp);
        
}
vector <int> findCommon(Node *root1, Node *root2){
     //Your code here
     map<int,int>mp;
     vector<int>ans;
     inorder(root1,mp);
     inorder(root2,mp);
     for(auto it : mp){
         if(it.second>1){
             ans.push_back(it.first);
         }
     }
     
 
     return ans;
}