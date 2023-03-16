class Solution
{
    private:
    //checking if there is loop or not, it gives the point of intersection of fast and slow
    Node* floydDetect( Node* head){
        if( head == NULL ){
            return NULL;
        }
        Node* slow = head;
        Node* fast = head;
        while( slow != NULL && fast != NULL && fast->next != NULL){
            fast = fast->next->next;
            slow = slow->next;
            
            if( slow == fast ){
                return slow;
            }
        }
        return NULL;
    }
    
    public:
     //Function to find first node if the linked list has a loop.
    int findFirstNode(Node* head)
    {
        if( head == NULL ){
            return NULL;
        }
        Node* intersection = floydDetect( head );
        
        if( intersection == NULL ){
            return -1;
        }
        Node* slow = head;
        while( slow != intersection ){
            intersection = intersection->next;
            slow = slow->next;
        }
        return slow->data;
    }
};
