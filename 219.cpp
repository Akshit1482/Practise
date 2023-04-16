class Solution
{
    public:
    bool isBST( Node* root, int mini, int maxi ){ // mini and maxi are the ranges in which the current root can lie betwee
                                                // as move left, range shortens to previous min and max to crrent root->dat
                                                // as move right, range shortens to prviuos maxi and mini to current node dta
                                                // as in BST, all nodes before root are smaller and at right are larger than root nodes
        //base case
        if( root == NULL ){
            return true;
        }
        // recursuve calls
        if( root->data > mini && root->data < maxi ){
            bool leftans = isBST( root->left, mini, root->data );
            bool rightans = isBST( root->right, root->data, maxi );
            
            return leftans && rightans;
        }
        else{
            return false;
        }
    }
    //Function to check whether a Binary Tree is BST or not.
    bool isBST(Node* root) 
    {
        return isBST( root, INT_MIN, INT_MAX );
    }
};


