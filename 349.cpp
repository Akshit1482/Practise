// User Function template for C++

// Structure of node
/*struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};*/

class Solution {
  public:
    int countNodes( struct Node* root ){
        //base case
        if( root == NULL ){
            return 0;
        }
        int ans = 1 + countNodes( root->left) + countNodes( root->right );
        return ans;
    }
    bool isCBT( struct Node* root, int index, int cnt ){
        //base case
        if( root == NULL ){
            return true;
        }
        
        if( index >= cnt ){  // false condition
            return false;
        }
        else{   // else check for its child nodes
            // recursive condition
            bool left = isCBT( root->left, 2*index + 1, cnt );
            bool right = isCBT( root->right, 2*index + 2, cnt );
        
            return( left && right );
        }
    }
    
    bool ismaxOrder( struct Node* root ){
        // leaf node || base case
        if( root->left == NULL && root->right == NULL ){
            return true;
        }
        // only left child
        if( root->right == NULL ){
            return( root->data > root->left->data );
        }
        else{ // has both child
            bool left = ismaxOrder( root->left );
            bool right = ismaxOrder( root->right );
            
            return( left && right && ( root->data > root->left->data) && 
                    (root->data > root->right->data ) );
        }            
        
    }
    bool isHeap(struct Node* tree) {
        // counting the number of nodes in the tree
        int index = 0;
        int totalCount = countNodes( tree );
        
        //checking conditions
        if( isCBT( tree, index, totalCount) && ismaxOrder( tree ) ){
            return true;
        }
        else{
            return false;
        }
    }
};
