class Solution
{
    public:
    //Function to return the level order traversal of a tree.
    vector<int> levelOrder(Node* node)
    {
        vector<int>ans;
      //makong queue
      queue<Node*>q;
      q.push( node );
      q.push( NULL ); // pushing null after one lvl
      
      while( !q.empty() ){
          Node* temp = q.front();
          q.pop();
          
          if( temp == NULL ){
              if( !q.empty() ){
                  // queue still has child nodes
                  q.push( NULL ); // pushing null after current child nodes
              }
          }
          else{
              ans.push_back( temp->data );
              if( temp->left ){
                  q.push( temp->left );
              }
              if( temp->right ){
                  q.push( temp->right );
              }
          }
      }
      return ans;
    }
};
