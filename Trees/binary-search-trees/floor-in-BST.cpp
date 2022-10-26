int findFloor(Node *root, int input)
{
    int Floor = -1;
    while (root)
    {
        if (root->data == input)
        {
            Floor = input;
            return Ceil;
        }

        if (input < root->data)
        {
            root = root->left;
        }
        else
        {
            Floor = root->data;
            root = root->right;
        }
    }
    return Floor;
    // Your code here
}