Node* solve( Node* root, int& k, int node ){
    //base case
    if( root == NULL ){
        return NULL;
    }
    // checking condition
    if( root->data == node ){
        return root;
    }
    // recursive calls
    Node* leftAns = solve( root->left, k, node );
    Node* rightAns = solve( root->right, k, node );
    
    // checking conditonns while returning
    if( leftAns != NULL && rightAns == NULL ){
        k--;
        if( k<=0){
            k = INT_MAX;
            return root;
        }
        return leftAns;
    }
    if( leftAns == NULL && rightAns != NULL ){
        k--;
        if( k<=0){
            k = INT_MAX;
            return root;
        }
        return rightAns;
    }
    //agar dono NUll hai to return NULL
    return NULL;
}
int kthAncestor(Node *root, int k, int node)
{
    Node* ans = solve( root, k, node);
    //base case
    if( ans == NULL || ans->data == node ){ // if root is node , then it doesn't have any ancestors, so we return -1;
        return -1;
    }
    else{
        return ans->data;
    }    
}
