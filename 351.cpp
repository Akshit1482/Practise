//User function Template for C++

/*struct Node {
    int data;
    Node *left, *right;
};*/

class Solution{
private:
    void convert( Node* root, vector<int>& in ){
        //base case
        if( root == NULL ){
            return ;
        }
        // inorder traversal
        convert( root->left, in );
        in.push_back( root->data );
        convert( root->right, in );
    }
    
    void fill_post( Node* root, vector<int>& inorder, int& index ){
        //base case
        if( root == NULL ){
            return ;
        }
        
        // traversing the in array in postOrder way
        fill_post( root->left, inorder, index );
        fill_post( root->right, inorder, index );
        root->data = inorder[ index++ ]; // as the BST is complete, so the maxHeap is also the same 
                                         //size of the BST, so we just have too enter the value of 
                                         //current node in the right position and don't have to create 
                                         //any node
    }
  public:
    
    void convertToMaxHeapUtil(Node* root)
    {
        vector<int>inorder;
        int i = 0;
        
        convert( root, inorder );
        
        fill_post( root, inorder, i );  // as the required maxHeap is the postorder traversal of the
                                        //the inorder array of the given heap
    }    
};
