lass Solution
{
    public:
    //Function to remove duplicates from unsorted linked list.
    Node * removeDuplicates( Node *head) 
    {
        if( head == NULL ){
            return head;
        }
        
        Node* curr = head;
        Node* prev = NULL;
        unordered_map< int,bool > visited;
        
        //initializing the map and comparing the data of node, if it's been already  marked or not
        while( curr != NULL ){
            if( visited[ curr->data ] == true ){
                Node* temp = curr;
                curr = curr->next;
                prev->next = curr;
                temp->next = NULL;
                delete( temp );
            }
            else{
                visited[ curr->data ] = true;
                prev = curr;
                curr = curr->next;
            }
        }
        return head;
    }
};
// T.C = O(n)
// S.C = O(n)
