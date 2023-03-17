class Solution
{
    private:
    Node* reverse( Node* head){
    
        Node* curr = head;
        Node* forward = NULL;
        Node* prev = NULL;
        while( curr != NULL ){
            forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
        }
        return prev;
    }
    void insertAtTail( Node* &head, Node* &tail, int value){ //we are passing the referene variable taki ek list mein hi tail change hota jaye
        Node* newNode = new Node(value);
        //empty list
        if( head == NULL ){
            head = newNode;
            tail = newNode;
            return;
        }
        else{                        //list is not empty, but we are adding the node at the end of the tail
            tail->next = newNode;
            tail = newNode;
        }
    }
    
    Node* add( Node* head){
        Node* curr = head;
        int carry = 0;
        int sum = 0;
        Node* ansHead = NULL;
        Node* ansTail = NULL;
        while( curr != NULL || carry != 0){// check even for carry, if not zero create a node
            int val = 0;
            if( curr != NULL ){
                val = curr->data;
            }
            if( curr == head ){
                sum = val + carry + 1;    
            }
            else{
                sum = val + carry;
            }
            
            int digit = sum%10;
            insertAtTail( ansHead, ansTail, digit);
            
            carry = sum/10;
            if( curr != NULL ){ //move curr to next node
                curr = curr->next;
            }
        }
        return ansHead;
    }
    
    public:
    Node* addOne(Node *head) 
    {
        head = reverse( head );
        
        Node* ans = add( head );
        ans = reverse( ans ); //jo list aayegi, usko dobaara reverse karo taki sahi anser recieve ho
        return ans;
    }
};
