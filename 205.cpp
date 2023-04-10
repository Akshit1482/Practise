class Solution{
private:
    pair<int,int> solve( Node* root ){
        //base case
        if( root == NULL ){
            pair<int,int>p = make_pair( 0,0 ); // pair< icluding that root, excluding that root 
            return p;
        }
        
        //recursive call
        pair<int,int>left = solve( root->left );
        pair<int,int>right = solve( root->right );
        
        // while returning storing the answer
        pair<int,int>res;
        
        //while including root
        res.first = root->data + left.second + right.second;
        // while excluding the root, we have 4 values to choose from
        res.second = max( left.first,left.second ) + max( right.first,right.second );
        
        return res;
    }
public:
    //Function to return the maximum sum of non-adjacent nodes.
    int getMaxSum(Node *root) 
    {
        pair<int,int>ans = solve( root );
        return max( ans.first,ans.second );
    }
};
