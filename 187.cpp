class Solution
{
    public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    vector<int> topView(Node *root)
    {
        vector<int>ans;
        if( root == NULL ){
            return ans;
        }
        map<int,int>topnode;  // first int is hd, second is node->data
        queue<pair<Node*,int>>q; // node is the root, int is the hd
        q.push( make_pair(root, 0));
        
        while( !q.empty() ){
            pair<Node*,int>temp = q.front();
            q.pop();
            Node* frontNode = temp.first;
            int hd = temp.second;
            
            //putting the node in map
            if( topnode.find(hd) == topnode.end() ){  // if topnode.find(hd) is present, the continue, and if not present it will be equal to the topnode end()
                topnode[hd] = frontNode->data;  //pushing value of node in map accordinng to that hd
            }
            
            //recursive call
            if( frontNode->left){
                q.push( make_pair( frontNode->left, hd-1) );
            }
            if( frontNode->right){
                q.push( make_pair( frontNode->right, hd+1) );
            }
        }
        //pushing the content of map into vector
        for( auto i:topnode ){
            ans.push_back( i.second );
        }
        return ans;
    }

};
