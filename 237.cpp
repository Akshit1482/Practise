//User function Template for C++

/* 
//Linked List
struct LNode
{
    int data;
    struct LNode* next;
    
    LNode(int x){
        data = x;
        next = NULL;
    }
};

//Tree
struct TNode  
{  
    
    int data;  
    struct TNode* left;  
    struct TNode* right; 
    TNode(int x)
    {
        data=x;
        left=right=NULL;
    }
}; */
class Solution{
  public:
    TNode* solve( LNode* Lhead, LNode* tail ){
        //base case
        if( Lhead == tail ){
            return NULL;
        }
        // finding mid in linked list
        LNode* slow = Lhead;
        LNode* fast = Lhead;
        while( fast != tail && fast->next != tail ){
            slow = slow->next;
            fast = fast->next->next;  /// when loop ends mid is the slow pointer
        }
        // cretaing the node and it's children
        TNode* root = new TNode( slow->data );
        root->left = solve( Lhead, slow );
        root->right = solve( slow->next, tail );
        return root;
    }  
    
    TNode* sortedListToBST(LNode *head) {
        if( head == NULL ){
            return NULL;
        }
        // if only one node
        if( head->next == NULL ){
            TNode* root = new TNode( head->data );
            return root;
        }
        // if moe than one node
        return solve( head, NULL );
    }
};
