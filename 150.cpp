int intersectPoint(Node* head1, Node* head2)
{
    Node* curr1 = head1;
    Node* curr2 = head2;
    int len1 = 0;
    int len2 = 0;
    
    //checking lengths of both linked lists
    while( curr1 != NULL ){
        len1++;
        curr1 = curr1->next;
    }
    while( curr2 != NULL ){
        len2++;
        curr2 = curr2->next;
    }
    //checking the difference in length of both linked lists
    int diff = 0;
    Node* ptr1 = NULL;
    Node* ptr2 = NULL;
    
    //we are comparing lengths,so the difference wouldn't be negative
    if( len1 > len2 ){
        diff = len1 - len2;
        ptr1 = head1;
        ptr2 = head2;
    }
    else{
        diff = len2 - len1;
        ptr1 = head2;
        ptr2 = head1;
    }
    //jitna difference aaya hai, badi wali LL ke utna aage se traversing start karo, taki traverse karte
    //waqt dono list same length  ki ho jaye
    while( diff != 0 ){
        ptr1 = ptr1->next;
        if( ptr1 == NULL ){
            return -1;
        }
        diff--;
    }
    //ab dono list ko travesrse karna shuru karo, jahan eqaul ho jaaye vo inersection point hai
    while( ptr1 != NULL && ptr2 != NULL ){
        if( ptr1 == ptr2 ){
            return ptr1->data;
        }
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }
    // agar koi intersction point  nahi hai toh -1 return kardi jeeye
    return -1;
}
