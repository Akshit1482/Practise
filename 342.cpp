//User function Template for C++
class node{
    public:
        int data;
        int i;
        int j;
        
        //constructor
        node( int data, int row, int col ){
            this->data = data;
            i = row;
            j = col;
        }
};
class compare{
    public:
        bool operator()( node* a, node* b ){
            return a->data > b->data;
        }
};

class Solution
{
    public:
    //Function to merge k sorted arrays.
    vector<int> mergeKArrays(vector<vector<int>> arr, int K)
    {
        priority_queue< node*, vector<node*>, compare>minHeap;
        
        // step1: saare arrays ke first elements ko heap mein daal dp
        for( int i =0; i<K; i++ ){
            node* temp = new node( arr[i][0], i, 0 );
            minHeap.push( temp );
        }
        
        // step2: creating vector to store the merged sorted array
        vector<int>ans;
        
        //step3: 
        while( minHeap.size() > 0 ){
            node* temp = minHeap.top();
            //pushing the values in ans array in sorted order
            ans.push_back( temp->data );
            minHeap.pop();
            
            int i = temp->i;
            int j = temp->j;
            
            // checking if there is any next element in the following row from where the top has been popped
            if( j+1 < arr[i].size() ){
                //pushing the next element of the same row
                node* next = new node( arr[i][j+1], i, j+1 );
                minHeap.push( next );  // thus new node will add according to its correct position in heap, and the min elemety will come at the top in heap, and 
                                       // get pushed in ans, and get replaced by its next node of that particular row in original matrix
            }
        }
        return ans;
        
    }
};
