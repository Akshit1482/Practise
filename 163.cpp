Node* reverseDLLInGroups(Node* head, int k)
{	
	// base condition for recursion
	if( head == NULL || head->next == NULL ){
		return head;
	}

	Node* curr = head;
	Node* next = NULL;
	Node* prev = NULL;
	int count = 0;

	// reversing the double LL
	while( curr != NULL && count<k ){
		next = curr->next;
		curr->next = prev;
		curr->prev = next;
		prev = curr;
		curr = next;
		count++;
	}

	// recursive call
	if( curr != NULL ){
		head->next = reverseDLLInGroups( next,k); 
	}
	return prev;
}
