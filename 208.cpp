class Solution{
    private:
    Node* lca( Node* root, int a, int b ){
        //base case
        if( root == NULL ){
            return NULL;
        }
        //if nose is the answer node
        if( root->data == a || root->data == b ){
            return root;
        }
        // recuersive call for left and right tree
        Node* leftAns = lca( root->left, a, b );
        Node* rightAns = lca( root->right, a, b );
        
        // checking conditions
        if( leftAns != NULL && rightAns != NULL ){
            return root;
        }
        if( leftAns != NULL && rightAns == NULL ){
            return leftAns;
        }
        if( leftAns == NULL && rightAns != NULL ){
            return rightAns;
        }
        if( leftAns == NULL && rightAns == NULL ){
            return NULL;
        }
    }
    void solve( Node* root, int key, int len, int& maxLen ){  // finding distance of key from lca
        if( root == NULL ){
            return;
        }
        // we found the key
        if( root->data == key ){
            maxLen = len;
        }
        // recursive calls
        solve( root->left, key, len+1, maxLen);
        solve( root->right, key, len+1, maxLen );
    }
    
    public:
    /* Should return minimum distance between a and b
    in a tree with given root*/
    int findDist(Node* root, int a, int b) {
        if( root == NULL ){
            return -1;
        }
        Node* anc = lca( root, a, b);
        int len1 = 0;
        int len2 = 0;
        int maxLen1 = 0;
        int maxLen2 = 0;
        solve( anc, a, len1, maxLen1 );
        solve( anc, b, len2, maxLen2 );
        int res = maxLen1 + maxLen2;
        return res;
    }
};
