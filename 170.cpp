long long  multiplyTwoLists (Node* l1, Node* l2)
{
    long long mod = 1e9+7;
    long long num1 = 0;
    while( l1 ){
        num1 = (num1 * 10) + ( l1->data);
        // iterating li forward
        num1 = num1%mod;
        l1 = l1->next;
    }
    
    long long num2 = 0;
    while( l2 ){
        num2 = ( num2 * 10) + (l2->data);
        // iterating forward
        num2 = num2%mod;
        l2 = l2->next;
    }
    return ( num1 * num2 )%mod;
}
