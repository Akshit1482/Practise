class Solution
{
    public:
    struct node *reverse (struct node *head, int k)
    { 
        //base call
        if( head == NULL ){ //agar list empty hai toh reverse karne ki zaroorat nahi hai
            return NULL;
        }
        
        //step1 : Reverse K nodes
        node* forward = NULL;
        node* curr = head;
        node* prev = NULL;
        int count = 0;
        
        while( curr != NULL && count < k){
            forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
            count++;
        }
        //step2 : rcursive call for rest of LL
        if( forward != NULL){
            head->next = reverse( forward,k );
        }
        //step3 : return head of reversed list
        return prev;
    }
};
//T.C = O(n)
//S.C = O(k) or O(1)
