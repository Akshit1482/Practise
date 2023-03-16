class Solution
{
    //FLOYD's DETECTION ALGORITHM
    public:
    //Function to check if the linked list has a loop.
    bool detectLoop(Node* head)
    {
        Node* slow = head;
        Node* fast = head;
        
        while( slow != NULL && fast != NULL && fast->next != NULL ){ //(v.imp so it doesn't give seg fault),( fast->next!=NULL)
            fast = fast->next->next;
                
            slow = slow->next;
            
            if( slow == fast ){
                return true;
            }
        }
        return false;
    }
};
