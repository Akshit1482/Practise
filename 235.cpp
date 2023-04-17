class info{  // we are making new datatype, becausse after every return we need four parameter to find our answer
    public:
        int maxi;
        int mini;
        bool isBST;
        int size;
};
class Solution{
    public:
    info solve( Node* root, int& ans ){
        //base case
        if( root == NULL ){
            return{ INT_MIN, INT_MAX, true, 0 };
        }
        //recursive calls
        info left =  solve( root->left, ans );
        info right = solve( root->right, ans );
        
        // to store ans for current node
        info currNode;
        
        currNode.size = left.size + right.size + 1;
        currNode.maxi = max( root->data, right.maxi ); // maximmum range of a node, every value should be greater in right tree
        currNode.mini = min( root->data, left.mini );  // minimum range of a node, every value should be lesser in left tree
        
        if( left.isBST && right.isBST && ( root->data > left.maxi && root->data < right.mini )){  // condition of a BST
            currNode.isBST = true;
        }
        else{
            currNode.isBST = false;
        }
        // answer update
        if( currNode.isBST ){
            ans = max( ans, currNode.size );
        }
        return currNode;
    }
    /*You are required to complete this method */
    // Return the size of the largest sub-tree which is also a BST
    int largestBst(Node *root)
    {
    	int maxSize = 0;
    	info temp = solve( root, maxSize );
    	return maxSize;
    }
};
