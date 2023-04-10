class Solution
{
    public:
    //Function to return the lowest common ancestor in a Binary Tree.
    Node* lca(Node* root ,int n1 ,int n2 )
    {
       //base case
       if( root == NULL ){
           return NULL;
       }
       // if the root is the n1 or n2;
       if( root->data == n1 || root->data == n2 ){
           return root;
       }
       // recursive calls for left and right tree
       Node* leftAns = lca( root->left , n1, n2 );
       Node* rightAns = lca( root->right, n1, n2 );
       
       //now while returning we check four conditions
       if( leftAns != NULL && rightAns != NULL ){ // it means wee have found our lca
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
};
