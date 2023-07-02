class Solution
{
    public:
    //Function to sort a linked list of 0s, 1s and 2s.
    Node* segregate(Node *head) {
        
        vector<int>arr;
        Node* temp = head;
        while( temp != NULL ){
            arr.push_back( temp->data );
            temp = temp->next;
        }
        
        sort( arr.begin(), arr.end() );
        temp = head;
        int i=0;
        while( temp != NULL ){
            temp->data = arr[i];
            temp = temp->next;
            i++;
        }
        return head;
    }
};
