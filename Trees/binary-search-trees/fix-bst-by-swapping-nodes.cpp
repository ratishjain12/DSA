void inorderTraversal(struct Node *root, vector<Node *> &inorderTrav)
{
    if (root == NULL)
    {
        return;
    }
    inorderTraversal(root->left, inorderTrav);
    inorderTrav.push_back(root);
    inorderTraversal(root->right, inorderTrav);
}
struct Node *correctBST(struct Node *root)
{
    // code here
    vector<Node *> inorderTrav;
    Node *first = NULL, *second = NULL;
    inorderTraversal(root, inorderTrav);
    for (int i = 1; i < inorderTrav.size(); i++)
    {
        if (inorderTrav[i - 1]->data > inorderTrav[i]->data)
        {
            if (first == NULL)
            {
                first = inorderTrav[i - 1];
            }
            second = inorderTrav[i];
        }
    }

    int temp = first->data;
    first->data = second->data;
    second->data = temp;
    return root;
}

// O(1) space solution

class Solution {
    
  private:
    Node *prev = NULL;
    Node *first = NULL;
    Node *second = NULL;
  public:
    
    void fixBST(Node *root){
        if(root == NULL) return;
        fixBST(root->left);
        if(prev != NULL && root->data < prev->data){
            if(first == NULL){
                first = prev;
            }
            second = root;
        }
        prev = root;
        fixBST(root->right);
    }
    void correctBST( struct Node* root )
    {
        // add code here.
        fixBST(root);
        if(first && second){
            swap(first->data,second->data);
        }
    }
};
