class Solution{
    private:
    Node* reverse( Node* &head ){
        Node* curr = head;
        Node* prev = NULL;
        Node* next = NULL;
        
        while( curr != NULL ){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    Node* findMiddle( Node* head ){
        Node* slow = head;
        Node* fast = head->next;
        
        while( fast != NULL && fast->next != NULL ){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
  public:
    //Function to check whether the list is palindrome.
    bool isPalindrome(Node *head)
    {
         if( head == NULL ){
            return true;
        }
        //step1: Find Middle
        Node* middle = findMiddle( head );
        Node* temp = middle->next;
        middle->next = NULL; // pointing end of first  half to NULL;
        
        // Step2: reverse the second half;
        Node* head2 = reverse( temp );
        Node* curr = head;
        
        //Step3: compare both halves
        while( curr != NULL && head2 != NULL ){
            if( curr->data != head2->data ){
                return false;
            }
            curr = curr->next;
            head2 = head2-> next;
        }
        //step4: repeat step2 (give original array)
        temp = middle->next;
        middle->next = reverse( temp );
        return true;
    }
};
