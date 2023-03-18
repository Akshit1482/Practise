class Solution
{
    private:
    Node* reverse( struct Node* head){
        struct Node* curr = head;
        struct Node* forward = NULL;
        struct Node* prev = NULL;
        
        while( curr != NULL ){
            forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
        }
        return prev;
    }
    void insertAtTail( struct Node* &head, struct Node* &tail, int value){
        struct Node* temp = new struct Node( value );
        if( head == NULL ){
            head = temp;
            tail = temp;
            return;
        }
        else{
            tail->next = temp;
            tail = temp; // humne isme null ko point isiliye nahi kiya, because node creation mein naext null ko hi point karta hai
        }
    }
    
    struct Node* add( struct Node* first, struct Node* second ){
        struct Node* ansHead = NULL;
        struct Node* ansTail = NULL;
        int carry = 0;
        int sum = 0;
        
        while( first != NULL || second != NULL || carry != 0 ){
            int val1 = 0;
            if( first != NULL ){
            val1 = first->data;
            }
            int val2 = 0;
            if( second != NULL ){
            val2 = second->data;
            }
            sum = val1 + val2 + carry;
            int digit = sum%10;
            insertAtTail( ansHead, ansTail, digit);
            
            carry = sum/10;
            //moving the pointers to next positions
            if( first != NULL ){
                first = first->next;
            }
            if( second != NULL ){
                second = second->next;
            }
        }return ansHead;    
    }
    
    public:
    //Function to add two numbers represented by linked list.
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
        //Step:1 Reverse the linked lists
        first = reverse( first );
        second = reverse( second );
        
        // step 2: add both linked lists
        struct Node* ans = add( first, second );
        // step:3 revrse the ans linked list
        ans = reverse( ans);
        return ans;
        
    }
};
