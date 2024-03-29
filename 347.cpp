// you are required to complete this function 
// function should print the required range
class node{
    public:
        int data;
        int row;
        int col;
        
        node( int data, int row, int col ){
            this->data = data;
            this->row = row;
            this->col = col;
        }
};

class compare{
    public:
        bool operator()( node* a, node* b ){
            return a->data > b->data;
        }
};

class Solution{
    public:
    pair<int,int> findSmallestRange(int KSortedArray[][N], int n, int k)
    {
        int mini = INT_MAX;
        int maxi = INT_MIN;
        
        // declaring a minHeap because we have to find the smallest range
        priority_queue< node*, vector<node*>, compare > minHeap;
        
        // pushing all starting element of all K arrays into minHeap
        for( int i = 0; i<k; i++ ){
            int element = KSortedArray[i][0];
            mini = min( mini , element );
            maxi = max( maxi , element );
            minHeap.push( new node( element, i, 0 ));
        }
        
        // for comparison of range if we get a smaller range than original
        int start = mini;
        int end = maxi;
        
        // now we are processing all the possible ranges and comparing it with original, to find the smallest one
        while( !minHeap.empty()){
            node* temp = minHeap.top();
            minHeap.pop();
            // updating mini to new mini
            mini = temp->data; // it will be min as top is smallest in minHeap
            
            //range update if possible
            if( (maxi - mini) < (end - start) ){
                end = maxi;
                start = mini;
            }
             // if the range doesn't gets change, we enter a elemnt from same row from where thr top has been popped
            if( (temp -> col + 1) < n ){
                int x = KSortedArray[temp->row][temp->col + 1];
                maxi = max( maxi, x );  // updating maxi everytime a new element is pushed in heap 
                minHeap.push( new node( x, temp->row, temp->col + 1 ));
            }
            else{  // next element in the row doesn't exist
                break;
            }
        }
        return {start,end};
    }
        
};
