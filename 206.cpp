class Solution{
    private:
    void solve( Node* root, vector<int>ans, int k, int& count ){
        //base case
        if( root == NULL ){
            return;
        }
        // push_back root->data into vector while traverasing the tree
        ans.push_back( root->data );
        
        // recursive call 
        solve( root->left, ans, k , count );
        solve( root->right, ans, k , count );
        // checking in vector, by traversing the vector from behind, if the sum of any nodes int he path is equal to k
        int size = ans.size();
        int sum = 0;
        //loop
        for( int i=size-1; i>=0; i-- ){
            sum += ans[i];
            if( sum == k ){
                count++;
            }
        }
        // after traversing while returning to upper node, pop the last value of ans, as it is the value of cuurent node
        ans.pop_back();
        
    }
    public:
    int sumK(Node *root,int k)
    {
        vector<int>ans;
        int count = 0;
        solve( root, ans, k, count );
        return count;
    }
};
