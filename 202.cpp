class Solution
{
    private:
    void solve( Node* root, int len, int& maxLen, int sum, int& maxSum){
        //base case
        if( root == NULL ){
            if( len>maxLen ){ // if new height is greater than previous height
                maxLen = len;
                maxSum = sum;
            }
            else if( len == maxLen ){ // if new height is equal to prev height, then decide whivh sum to choose for answer
                maxSum = max( sum, maxSum);
            }
            return;
        }
        // add root->data to sum, and then call recursively
        sum = sum + root->data;
        
        solve( root->left, len+1, maxLen, sum, maxSum );
        solve( root->right, len+1, maxLen, sum, maxSum );
    }
    public:
    
        int sumOfLongRootToLeafPath(Node *root)
        {
            int len = 0;
            int maxLen = 0;
            int sum = 0;
            int maxSum = 0;
            solve( root, len, maxLen, sum, maxSum);
            return maxSum;
        }
};
