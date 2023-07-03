class Solution{
public:
    int getNthFromLast(Node *head, int n)
    {
       int len = 0;
       Node* curr = head;
           while( curr != NULL ){
            len++;
            curr = curr->next;
       }
       if( n > len ){
           return -1;
       }
        
        int k = len - n ;
        Node* temp = head;
        while( k ){
            temp = temp->next;
            k--;
        }
        return temp->data;
    }
};
