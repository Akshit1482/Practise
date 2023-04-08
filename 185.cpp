//Function to return a list containing elements of left view of the binary tree.
void solve( Node*root, vector<int>& ans, int level ){
    //base case
    if( root == NULL ){
        return;
    }
    
    // checking condition for inserting in ans
    if( level == ans.size() ){  // as at certain level there is that no. of elements in vector as equal to that level
        ans.push_back( root->data );
    }
    
    // recursive call
    solve( root->left, ans, level+1 );
    solve( root->right, ans, level+1 );
}
vector<int> leftView(Node *root)
{
   vector<int>ans;
   solve( root, ans, 0);
   return ans;
}
