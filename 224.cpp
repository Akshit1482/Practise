void inorder( Node* root, vector<int>& ans ){
    // basee case
    if( root == NULL ){
        return;
    }
    inorder( root->left, ans );
    ans.push_back( root->data );
    inorder( root->right, ans );
}
Node* binaryToBST( vector<int>& ans, int s, int e ){
   //base case
   if( s>e ){
       return NULL;
   }
   int mid = (s+e)/2;
   Node* root = new Node( ans[mid] );
   
   // recursive calls
   root->left = binaryToBST( ans, s, mid-1 );
   root->right = binaryToBST( ans, mid+1, e );
   
   return root;
}
Node* buildBalancedTree(Node* root)
{
    // step 1 -> pehle vector create karo
	vector<int>ans;
	// step 2 -> vector mein inorderly store karo traversal  
	inorder( root, ans );
	int s = 0;
	int e = ans.size()-1;
	// step 3-> ab us vector se, using mid, BST create karte jao
	return binaryToBST( ans, s, e );
}
