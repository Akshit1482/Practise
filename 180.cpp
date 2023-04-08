class Solution {
    // solution op1 if answer is in the left subtree, then ans is the height of left subtree
    //op2 if answer is in the right subtree, then ans is the height of right subtree
    //op3  if one node lies in left tree and second node in right tree, then ans is height of left tree+ right tree + 1( root node)
    private:
    // first: diameter , second: height
    pair<int,int> diameterFast( Node* root ){
        //base case
        if( root == NULL ){
            pair<int,int>p = make_pair(0,0);
            return p;
        }
        
        //recursive call
        pair<int,int>leftTree = diameterFast( root->left );
        pair<int,int>rightTree = diameterFast( root->right );
        
        int op1 = leftTree.first;
        int op2 = rightTree.first;
        int op3 = leftTree.second + rightTree.second + 1;
        
        pair<int,int>ans;
        ans.first = max( op1, max(op2,op3));
        ans.second = max( leftTree.second, rightTree.second )+ 1;
        
        return ans;
    }
    public:
    // Function to return the diameter of a Binary Tree.
    int diameter(Node* root) {
        return diameterFast( root ).first;
    }
};
