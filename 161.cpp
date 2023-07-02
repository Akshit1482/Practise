class Solution
{
public:
    // function to sort a k sorted doubly linked list
    DLLNode *sortAKSortedDLL(DLLNode *head, int k)
    {
        // take all elements of LL, and sort it and then put it back in linked list in sorted order
        vector<int>arr;
        DLLNode* temp = head;
        while( temp != NULL ){
            arr.push_back( temp->data);
            temp = temp->next;
        }
        //sort the vector
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
