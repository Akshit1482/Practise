vector<int> diagonal(Node *root)
{
    vector<int>ans;
   //creating a queue
   queue<Node*>q;
   q.push( root );
   
   while(!q.empty()){
       Node* frontNode = q.front();
       q.pop();
       
       ans.push_back( frontNode->data );
       // calling for child 
       // if left then push it in queue, and if right push it into ans, till we ecounter NULL
       if( frontNode -> left ){
           q.push( frontNode->left );
       }
       //for right traverse till NULL
       while( frontNode->right != NULL ){
           frontNode = frontNode->right;  // if right are not NULL, then move to next right
           ans.push_back( frontNode->data );
           //if we encounter left, while traversing right till NULL
           if( frontNode->left ){
               q.push( frontNode->left );
           }
       }
   }
   return ans;
}
