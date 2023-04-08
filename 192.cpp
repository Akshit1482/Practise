class Solution {
private:
void traverseLeft( Node* root, vector<int>& ans ){ // we are printing left subtree except  leaf nodes
    //base case
    if( (root == NULL) || (root->left == NULL && root->right == NULL) ){
        return;
    }
    //pushing the root in vector
    ans.push_back( root->data );
    
    if( root->left ){
        traverseLeft( root->left, ans );
    }
    else{  // as there is no left node, so we are consedering the right node as boundary node
        traverseLeft( root->right, ans );
    }
}

void traverseLeaf( Node* root, vector<int>& ans ){
    //base case
    if( root == NULL ){
        return;
    }
    // pushing into vector only if its a leaf node
    if( root->left == NULL && root->right == NULL ){
        ans.push_back( root->data );
        return;
    }
    
    // reursive call
    traverseLeaf( root->left, ans );
    traverseLeaf( root->right, ans );
}

void traverseRight( Node* root, vector<int>& ans ){
    // base case or leaf node
    if( root == NULL || root->left == NULL && root->right == NULL ){
        return;
    }
    ///recursive call
    if( root->right ){
        traverseRight( root->right, ans );
    }
    else{  // as there is no right node, so we are consedering the left node as boundary  node
        traverseRight( root->left, ans );
    }
    //pushing root into vector
    ans.push_back( root->data );
}
public:
    vector <int> boundary(Node *root)
    {
        vector<int>ans;
        //base case
        if( root == NULL ){
            return ans;
        }
        ans.push_back( root->data );
        
        //call for left subtree
        traverseLeft( root->left, ans );
        // call for leaf nodes in left subtree
        traverseLeaf( root->left, ans );
        //call for leaf nodes on right subtree
        traverseLeaf( root->right, ans);
        //call for right subtree
        traverseRight( root->right, ans );
        
        return ans;
    }
};
