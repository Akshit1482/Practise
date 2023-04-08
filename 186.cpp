// Should return  right view of tree
class Solution
{
    private:
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
        solve( root->right, ans, level+1 );
        solve( root->left, ans, level+1 );
        
    }
    public:
    //Function to return list containing elements of right view of binary tree.
    vector<int> rightView(Node *root)
    {
        vector<int>ans;
        solve( root, ans, 0);
        return ans;
    }
};
