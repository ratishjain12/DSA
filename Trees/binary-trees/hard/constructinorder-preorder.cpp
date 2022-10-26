Node *constructTree(int pre[],int preStart,int preEnd,int in[],int inStart,int inEnd,map<int,int>&mp){
        if(preStart>preEnd || inStart>inEnd){
            return NULL;
        }
        Node *root = new Node(pre[preStart]);
        int inRoot = mp[root->data];
        int numsLeft = inRoot - inStart;
        root->left = constructTree(pre,preStart+1,preStart+numsLeft,in,inStart,inRoot-1,mp);
        root->right = constructTree(pre,preStart+numsLeft+1,preEnd,in,inRoot+1,inEnd,mp);
        return root;

        
    }
    Node* buildTree(int in[],int pre[], int n)
    {
        // Code here
        int inStart = 0,inEnd = n-1;
        int preStart = 0,preEnd = n-1;
        map<int,int>mp;
        for(int i = inStart;i<=inEnd;i++){
            mp[in[i]] = i;
        }

        return constructTree(pre,preStart,preEnd,in,inStart,inEnd,mp);

    }
