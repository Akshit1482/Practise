class Solution{
    private:
    pair<bool,int> isBalancedFast( Node* root ){
        //base case
        if( root == NULL ){
            pair<int,int>p = make_pair(true,0);
            return p;
        }
        
        //recursive call
        pair<int,int>leftTree = isBalancedFast( root->left );
        pair<int,int>rightTree = isBalancedFast( root->right );
        
        // checking conditions for particular node, then also checking theem while returning
        bool leftAns = leftTree.first;
        bool rightAns = rightTree.first;
        bool diff = abs( leftTree.second - rightTree.second ) <=1; // this is difference of left subtree and right subtree to check their difference in height
        
        pair<bool,int>ans;
        ans.second = max( leftTree.second,rightTree.second) + 1;
        
        if( leftAns && rightAns && diff ){
            ans.first = true;
        }
        else{
            false;
        }
        return ans;
    }
    
    public:
    //Function to check whether a binary tree is balanced or not.
    bool isBalanced(Node *root)
    {
        return isBalancedFast( root ).first;
    }
};
