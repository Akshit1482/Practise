//User function template for C++

/* The Node structure is
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
}; 
*/

class Solution{
private:
    void inorder( Node* root, vector<int>& in ){
        //base case
        if( root == NULL ){
            return;
        }
        //recursive calls
        inorder( root->left, in );
        in.push_back( root->data );
        inorder( root->right, in );
    }
    Node* inorderToBST( int s, int e, vector<int>& in ){
        //base case
        if( s>e ){
            return NULL;
        }
        int mid = (s+e)/2;
        Node* root = new Node( in[mid] );
        root->left = inorderToBST( s, mid - 1, in );
        root->right = inorderToBST( mid + 1, e, in );
        return root;
    }
public:
    // The given root is the root of the Binary Tree
    // Return the root of the generated BST
    Node *binaryTreeToBST (Node *root)
    {
        vector<int>BST;
        inorder( root, BST );
        
        sort( BST.begin(), BST.end() );
        
        int s = 0;
        int e = BST.size() - 1;
        return inorderToBST( s, e, BST );
    }
};
