bool isIdentical(Node *r1, Node *r2)
{
    //Your Code here
    if(r1 == NULL || r2 == NULL){
        return r1 == r2;
    }

    return (r1->data == r2->data) && isIdentical(r1->left,r2->left) && isIdentical(r1->right,r2->right);
}
