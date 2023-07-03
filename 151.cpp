class Solution{
  public:
    Node* findMid( Node* head ){
        Node* slow = head;
        Node* fast = head;
        while( slow != NULL && fast->next != NULL && fast->next->next != NULL ){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    
    Node* merge( Node* left, Node* right ){
        
        // base case
        if( left == NULL ){
            return right;
        }
        if( right == NULL ){
            return left;
        }
        
        Node* ans = new Node( -1 );
        Node* temp = ans;
        
        // merge 2 sorted LL
        while( left != NULL && right != NULL ){
            if( left->data < right->data ){
                temp->next = left;
                temp = left;
                left = left->next; // iterating left
            }
            else{
                temp->next = right;
                temp = right;
                right = right->next; // iterating right
            }
        }
        
        // if left is remaining
        while( left != NULL ){
            temp->next = left;
            temp = left;
            left = left->next;
        }
        
        //if right is remaining
        while( right != NULL ){
            temp->next = right;
            temp = right;
            right = right->next;
        }
        ans = ans->next; // move to next node after dummy node
        return ans;
    }
    //Function to sort the given linked list using Merge Sort.
    Node* mergeSort(Node* head) {
        // int three steps
        if( head == NULL || head->next == NULL ){
            return head;
        }
        // first find the mid of LL,and break LL into 2 parts
        Node* mid = findMid( head );
        
        Node* left = head;
        Node* right = mid->next;
        mid->next = NULL;
        
        // recursive calls for both side
        left = mergeSort( left );
        right = mergeSort( right );
        // merge both  sides
        
        Node* result = merge( left, right );
        return result;
    }
};
