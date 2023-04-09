//Function to return a list containing the bottom view of the given tree.

class Solution {
  public:
    vector <int> bottomView(Node *root) {
        vector<int>ans;
        if( root == NULL ){
            return ans;
        }
        map<int,int>bottomnode;  // first int is hd, second is node->data
        queue<pair<Node*,int>>q; // node is the root, int is the hd
        q.push( make_pair(root, 0));
        
        while( !q.empty() ){
            pair<Node*,int>temp = q.front();
            q.pop();
            Node* frontNode = temp.first;
            int hd = temp.second;
            
            //putting the node in map
              // we always push node->data into map, everytime we encounter a hd, if at that hd, in map sommething is present, replace it with new node->data at that hd
                bottomnode[hd] = frontNode->data;  //pushing value of node in map accordinng to that hd
            
            //recursive call
            if( frontNode->left){
                q.push( make_pair( frontNode->left, hd-1) );
            }
            if( frontNode->right){
                q.push( make_pair( frontNode->right, hd+1) );
            }
        }
        //pushing the content of map into vector
        for( auto i:bottomnode ){
            ans.push_back( i.second );
        }
        return ans;
    }
};
