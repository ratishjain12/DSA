int empty = -1;
int index = 0;

void helper(Node *root, vector<int> &ans)
{
    if (root == NULL)
    {
        ans.push_back(empty);
        return;
    }
    ans.push_back(root->data);
    helper(root->left, ans);
    helper(root->right, ans);
}
vector<int> serialize(Node *root)
{
    // Your code here
    vector<int> ans;
    helper(root, ans);
    return ans;
}

// Function to deserialize a list and construct the tree.
Node *deSerialize(vector<int> &A)
{
    // Your code here
    if (index == A.size())
        return NULL;
    int val = A[index];
    index++;
    if (val == empty)
        return NULL;
    Node *root = new Node(val);
    root->left = deSerialize(A);
    root->right = deSerialize(A);
    return root;
}