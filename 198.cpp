// Should return true if tree is Sum Tree, else false
class Solution
{
    private:
    pair<bool,int> isSumTreeFast( Node* root ){
        //base case
        if( root == NULL ){
            pair<bool,int>p = make_pair( true,0 );
            return p;
        }
        
        // if the root is a leaf node, so return the root->data and true
        if( root->left == NULL  && root->right == NULL ){
            pair<bool,int>p = make_pair( true,root->data ); // returning that it is true and its value
            return p;
        }
        
        //recursive call
        pair<bool,int>leftTree = isSumTreeFast( root->left );
        pair<bool,int>rightTree = isSumTreeFast( root->right );
        
        // conditions for sum tree
        //1. leftTree should be true, 2. rightsumtree should be true, and condition i.e., leftTreeSum + rightTreeSUm == root;
        bool leftTreeSum = leftTree.first;
        bool rightTreeSum = rightTree.first;
    
        int leftAns = leftTree.second;
        int rightAns = rightTree.second;
        
        bool cond = root->data == leftAns + rightAns; // 3. condition
        
        pair<bool,int>ans;
        if( leftTreeSum && rightTreeSum && cond ){
            ans.first = true;
            ans.second = root->data + leftAns + rightAns;
        }
        else{
            ans.first = false;
        }
        return ans;
    }
    public:
    bool isSumTree(Node* root)
    {
        return isSumTreeFast( root ).first;
    }
};
