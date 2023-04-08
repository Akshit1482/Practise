class Solution {
   private:
   void helper( Node* &node ){
       //base case
       if( node == NULL ){
           return;
       }
       
       Node* temp = node->left;
       node->left = node->right;
       node->right = temp;
       
       helper( node->left );
       helper( node->right );
   }
   public:
    // Function to convert a binary tree into its mirror tree.
    void mirror(Node* node) {
        helper( node );
    }
};
