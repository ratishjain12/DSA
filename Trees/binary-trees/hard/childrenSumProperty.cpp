
//sum of children is equal to parent

bool checkChildrenSum(Node *root){
        if(root == NULL){
            return true;
        }
        if(!root->left && !root->right){
            return true;
        }

        int sum = 0;
        if(root->left) sum+=root->left->data;
        if(root->right) sum+=root->right->data;

        return (root->data == sum) && checkChildrenSum(root->left) && checkChildrenSum(root->right);
    }
    int isSumProperty(Node *root)
    {
     // Add your code here
        if(checkChildrenSum(root)){
            return 1;
        }
        return 0;
    }
    
