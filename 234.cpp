/*The Node structure is
struct Node {
int data;
Node * right, * left;
};*/

/*You are required to complete below method */
bool solve( Node* root, int s, int e ){
    //base case
    if( root == NULL ){
        return false;
    }
    if( s == e  ){
        return true;  // if dead end exists
    }
    bool left = solve( root->left, s, (root->data) - 1 );  // as in leftSubtree all elemnets are less than root, so range of root->left will be min to root->data - 1, becuse of less than root
    bool right = solve( root->right, (root->data) + 1, e );// as in righttSubtree all elemnets are greater than root, so range of root->right will be root->data + 1 to max, becuse of greater than root
    if( left || right ){ // agar left or right mein kahin bhi dead end aa gya to samaj jao, pura answer true hain
        return true;
    }
    else{
        false;
    }
}
bool isDeadEnd(Node *root)
{
    int s = 1; // as BST ki range sirf positive numbers hain
    int e = INT_MAX;
    return solve( root, s, e );
}
