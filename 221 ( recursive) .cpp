Node* LCA(Node *root, int n1, int n2)
{
   //base case
   if( root == NULL ){
       return NULL;
   }
   
   // if both nodes are on left
   if( root->data > n1 && root->data > n2 ){
       return LCA( root->left, n1, n2 );
   }
   // if both nodes are on right of root
   if( root->data < n1 && root->data < n2 ){
       return LCA( root->right, n1, n2 );
   }
   return root;
   
}
