Node *createTree(int parent[], int N)
{
    // Your code here
    Node *root = NULL;
    map<int, Node *> mp; // make nodes for each index
    for (int i = 0; i < N; i++)
    {
        Node *temp = new Node(i);
        mp[i] = temp;
    }

    for (int i = 0; i < N; i++)
    {
        if (parent[i] == -1) // parent is -1 make that node root
        {
            root = mp[i];
            continue;
        }
        if (mp[parent[i]]->left == NULL) // check parents left is null assign left to current index node
        {
            mp[parent[i]]->left = mp[i];
        }
        else
        {
            mp[parent[i]]->right = mp[i]; // else assign right to current index node
        }
    }
    return root; // return root node
}