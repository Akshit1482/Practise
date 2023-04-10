class Solution{
    public:
    void createMapping( int in[], map<int,int>& nodeToIndex, int n){
        for( int i=0; i<n; i++ ){ 
            nodeToIndex[in[i]] = i;  // enter address of that particular node in map
        }
    }
    
    Node* solve( int in[], int pre[], int& index, int inorderStart, int inorderEnd, int n, map<int,int> &nodeToIndex ){
        //base case
        if( index >= n || inorderStart > inorderEnd ){
            return NULL;
        }
        // create node for that element
        int element = pre[index++]; // traversing inorder from start
        Node* root = new Node( element );
        int position = nodeToIndex[element]; // finding position of elemnt in inorder from map
        
        //recursive call
        root->left = solve( in, pre, index, inorderStart, position-1, n, nodeToIndex );
        root->right = solve( in, pre, index, position+1, inorderEnd, n, nodeToIndex );
        
        return root;
    }
    
    Node* buildTree(int in[],int pre[], int n)
    {
        int preOrderIndex = 0;
        map<int,int>nodeToIndex; // map to connect node to its position in inorder
        createMapping(  in, nodeToIndex, n );
        Node* ans = solve( in, pre, preOrderIndex, 0, n-1, n, nodeToIndex);
        return ans;
    }
};
