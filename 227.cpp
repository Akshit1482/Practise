class Solution {
private:
    int solve( Node *root, int& i, int k ){
        //base case
        if( root == NULL ){
            return -1;
        }
        
        // going to left part, as smaller elements generrally lies in left
        int left = solve( root->left, i , k );
        
        // for null node
        if( left != -1 ){
            return left;
        }
        // for node
        i++;
        if( i == k ){
            return root->data;
        }
        
        // going right
        return solve( root->right, i,k );
        
    }
 public:
    // Return the Kth smallest element in the given BST
    int KthSmallestElement(Node *root, int K) {
        int i =0;
        int ans = solve( root, i, K );
        return ans;
    }
};
