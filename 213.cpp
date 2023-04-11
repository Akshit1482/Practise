class Solution {
  public:
    // using level order traversal to traverse the tree to create the map, and find the target node
    Node* createMapping( Node* root, int target, map<Node*,Node*>&nodeToParent ){
        Node* res = NULL;
        queue<Node*>q;
        q.push( root );
        nodeToParent[ root ] = NULL; // as the root node has no parent
        
        while( !q.empty()){
            Node* front = q.front();
            q.pop();
            
            if( front->data == target ){
                res = front;
            }
            // now we will put child nodes inn map
            //left child
            if( front->left ){
                nodeToParent[ front->left ] = front;
                q.push( front->left );
            }
            //right child
            if( front->right ){
                nodeToParent[ front->right ] = front;
                q.push( front->right );
            }
        }
        // return the tarrget node
        return res;
    }
    
    int burnTree( Node* root, map<Node*,Node*>nodeToParent ){
        // creating a map to track whick element is visited or not
        map<Node*,bool>visited;
        queue<Node*>q;
        
        q.push( root );
        visited[ root ] = true;
        
        int ans = 0;
        
        while( !q.empty() ){
            bool flag = 0;
            int size = q.size();
            for( int i=0; i<size; i++){ // this loop because, we first traverse and check all neighbiuring nodes and then increease time, but for the first time it will iterate 1 time, because it only  have 1 target node inside queue
                // processing all neighbouring nodes
                Node* front = q.front();
                q.pop();
            
                // check for left child
                if( front->left && !visited[ front->left ] ){
                    flag = 1;
                    q.push( front->left );
                    visited[ front-> left ] = 1;
                }
                // check for right child
                if( front->right && !visited[ front->right ] ){
                    flag = 1;
                    q.push( front->right );
                    visited[ front-> right ] = 1;
                }
                // check for parent
                if( nodeToParent[ front ] && !visited[nodeToParent[front]] ){
                    flag =1;
                    q.push( nodeToParent[front] );
                    visited[ nodeToParent[front] ] = 1;
                }
            }
            if( flag == 1 ){
                ans++;
            }
        }
        return ans;
    }
    int minTime(Node* root, int target) 
    {
        //creating a map of child to its parent
        map<Node*, Node*> nodeToParent;
        Node* targetNode = createMapping( root, target, nodeToParent );
        int ans = burnTree( targetNode, nodeToParent);
        return ans;
    }
};
