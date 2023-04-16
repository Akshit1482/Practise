// Function to delete a node from BST.
Node* minVal( Node* root ){
    Node* temp = root;
    while( temp->left != NULL ){
        temp = temp->left;
    }
    return temp;
}
Node* deleteBST ( Node* &root, int key ){
    //base case
    if( root == NULL ){
        return NULL;
    }
    
    // deletion 
    if( root->data == key ){
        // 0 child
        if( root->left == NULL && root->right == NULL ){
            delete root;
            return NULL;
        }
        // 1 child
        if( root->left != NULL && root->right == NULL ){
            Node* temp = root->left;
            delete root;
            return temp; 
        }
        if( root->left == NULL && root->right != NULL ){
            Node* temp = root->right;
            delete root;
            return temp;
        }
        //2 child
        if( root->left != NULL && root->right != NULL ){
            int mini = minVal( root->right )->data;
            root->data = mini;
            // now we are deleting the min val in right subtree with which we have exchanged the root
            root->right = deleteBST( root->right , mini );
            return root;
        }
    }
    
    else if( root->data > key ){
        // left part me jao
        root->left = deleteBST( root->left, key );
        return root;
    }
    else{// right part me jao
        root->right = deleteBST( root->right , key);
        return root;
    }
    
    
    
}

Node *deleteNode(Node *root, int X) {
    return deleteBST ( root, X );
}
