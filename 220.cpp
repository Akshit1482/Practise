class Solution
{
private:
    void inorder( Node* &root, vector<Node*>& ans ){
        // base case
        if( root == NULL ){
            return;
        }
        inorder( root->left, ans );
        ans.push_back( root );
        inorder( root->right, ans );
    }
public:

    void populateNext(Node *root)
    {
        vector<Node*>ans;
        inorder( root, ans );
        
        // loop to point all next pointer to next value in inorder 
        int n = ans.size();
        for( int i=0; i<n-1; i++ ){
            ans[i]->next = ans[i+1];
        }
        Node* temp = NULL;
        ans[n-1]->next = temp;
    }
};
