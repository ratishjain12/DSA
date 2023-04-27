// lca algorithm-

// case 1: root is either of the two values or root is null than return root
// case 2: call for left subtree and rightsubtree if left is null that is no element found in left return right similarly if right is null return left
// case 3: if neither left nor right is null then root will be the lca

Node *lca(Node *root, int n1, int n2)
{
    // Your code here
    if (root == NULL || root->data == n1 || root->data == n2)
    {
        return root;
    }

    Node *leftTree = lca(root->left, n1, n2);
    Node *rightTree = lca(root->right, n1, n2);

    if (leftTree == NULL)
    {
        return rightTree;
    }
    else if (rightTree == NULL)
    {
        return leftTree;
    }

    return root;
}
