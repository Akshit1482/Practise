/*Linked list Node structure

struct Node
{
	int data;
	Node* next;
	
	Node(int x){
	    data = x;
	    next = NULL;
	}
	
};
*/ 
class compare{
    public:
        bool operator()( Node* a, Node* b ){
            return a->data > b->data;
        }
};
class Solution{
  public:
    //Function to merge K sorted linked list.
    // same as merge k sorted arrays
    Node * mergeKLists(Node *arr[], int K)
    {
        //  creating a minHeap
        priority_queue< Node*, vector<Node*>, compare >minHeap;
        
        // base case
        if( K == 0 ){
            return NULL;
        }
        
        // step1 : pushing head of all linked lists in an minHeap
        for( int i = 0; i<K; i++ ){
            if( arr[i] != NULL ){
                minHeap.push( arr[i] );
            }
        }
        
        Node* head = NULL;
        Node* tail = NULL;
        
        while( minHeap.size() > 0 ){
            Node* top = minHeap.top();
            minHeap.pop();
            
            // checking for the next element in linked list from ehre the top has been popped
            if( top->next != NULL ){
                minHeap.push( top->next );  // it will get pushed in minHeap at its correct position
            }
            
            //for first case
            if( head == NULL ){
                head =  top;
                tail = top;
            }
            else{  // for all next elements
                tail->next = top;  // inserting a new elemnet after the tail
                tail = top;  // for insertion the next element
            }
        }
        return head;
    }
};
