class Solution{
public:
    ListNode *moveToFront(ListNode *head){
        
        ListNode* curr = head;
        ListNode* prev = NULL;
        if( curr->next == NULL ){
            return curr;
        }
        
        while( curr->next != NULL ){
            prev = curr;
            curr = curr->next;
        }
        ListNode* temp = curr; // yeh extra node bnane ki bachodi karni padegi, nahi toh test cases nahi chal rahe
        prev->next = NULL;
        temp->next = head;
        return  temp;
    }
};
