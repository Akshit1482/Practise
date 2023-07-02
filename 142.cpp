class Solution
{
    public:
    //Function to remove a loop in the linked list.
    void removeLoop(Node* head)
    {
        Node*temp=head;
        map<Node*,bool> m;
    
        while(temp!=NULL){
            
            if(m[temp->next]==true){
                temp->next=NULL;
            }
            m[temp]=true;
            temp=temp->next;
        }
    }
};
