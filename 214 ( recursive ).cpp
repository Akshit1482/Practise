bool search(Node* root, int x) {
    //base case
    if( root == NULL ){
        return false;
    }
    
    if( root->data == x ){
        return true;
    }
    // recursive calls
    if( root->data > x ){
        return search( root->left, x );
    }
    else{
        return search( root->right, x );
    }
}
