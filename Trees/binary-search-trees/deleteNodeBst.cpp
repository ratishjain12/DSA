#include <iostream>
using namespace std;
int minVal(Node *root)
{
    while(root->left){
        root = root->left;
    }
    return root->data;
}
Node *deleteNode(Node *root, int X)
{
    // your code goes here
    if (root == NULL)
    {
        return root;
    }
    if (root->data == X)
    {
        // 0 child
        if (root->left == NULL && root->right == NULL)
        {
            delete root;
            return NULL;
        }

        // 1 child
        if (root->left != NULL && root->right == NULL)
        {
            Node *temp = root->left;
            delete root;
            return temp;
        }
        if (root->left == NULL && root->right != NULL)
        {
            Node *temp = root->right;
            delete root;
            return temp;
        }
        // 2 child
        if (root->left != NULL && root->right != NULL) 
        {
            int mini = minVal(root->right); // inorder successor(closet number greater than root)
            root->data = mini;
            root->right = deleteNode(root->right, mini);
            return root;
        }
    }
    else if (root->data > X)
    {
        root->left = deleteNode(root->left, X);
    }
    else
    {
        root->right = deleteNode(root->right, X);
    }
}
