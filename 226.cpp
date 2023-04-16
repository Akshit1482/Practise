class Solution
{
    private:
    void inorder( Node* root, vector<int>& ans ){
        //base case
        if( root == NULL ){
            return;
        }
        inorder( root->left, ans );
        ans.push_back( root->data );
        inorder( root->right , ans );
    }
    public:
    int kthLargest(Node *root, int K)
    {
        vector<int>ans;
        inorder( root, ans );
        int n = ans.size()-1;
        int i = (n-K)+1;
        int sol = ans[i];
        return sol;
    }
};
