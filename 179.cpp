//User function template for C++

/*
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
*/
class Solution{
    public:
    //Function to find the height of a binary tree.
    int height(struct Node* node){
        
        //base case
        if( node == NULL ){
            return 0;
        }
        
        int leftAns = height( node->left );
        int rightAns = height( node->right );
        
        int ans = max( leftAns, rightAns ) + 1;
        return ans;
    }
};
