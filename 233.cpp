class Solution{
private:
    Node* solve( int pre[], int mini, int maxi, int& i, int size ){
        //base case
        if( i >= size ){
            return NULL;
        }
        //condition for BST
        if( pre[i] < mini || pre[i] > maxi ){
            return NULL;
        }
        
        Node* root = newNode( pre[i++] );
        
        root->left = solve( pre, mini, root->data, i, size );
        root->right = solve( pre, root->data, maxi, i, size );
        return root;
    }
    
public:
    //Function that constructs BST from its preorder traversal.
    Node* post_order(int pre[], int size)
    {
        int mini = INT_MIN;
        int maxi = INT_MAX;
        int i = 0;
        Node* ans = solve( pre, mini, maxi, i, size );
        return ans;
    }
};
