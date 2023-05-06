    /*
    If there are multiple nodes passing through a vertical line, then they should be printed as they 
    appear in level order traversal of the tree.
    */

    //Gfg
    vector<int> verticalOrder(Node *root){
        //Your code here
        queue<pair<Node*,int>>q;
        map<int,vector<int>>mp;
        q.push({root,0});
        while(!q.empty()){
            auto p = q.front();
            Node *front = p.first;
            int line = p.second;
            mp[line].push_back(front->data);
            q.pop();
            if(front->left){
                q.push({front->left,line-1});
            }
            if(front->right){
                q.push({front->right,line+1});
            }
            
        }
        vector<int>ans;
        for(auto i:mp){
            for (auto j:i.second){
                ans.push_back(j);
            }
        }
        return ans;
    }