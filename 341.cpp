//User function template for C++

class Solution{
    public:
    // arr : given array
    // l : starting index of the array i.e 0
    // r : ending index of the array i.e size-1
    // k : find kth smallest element and return using this function
    int kthSmallest(int arr[], int l, int r, int k) {
        // creating a maxHeap
        priority_queue<int>pq
        ;
        //step1
        // creating a heap for k elements
        for( int i =0; i<k; i++ ){
            pq.push( arr[i] );
        }
        
        //step2: if element is less than top, then pop the top and insert the new element in the heap
        for( int i=k; i<=r; i++ ){
            if( arr[i] < pq.top() ){
                pq.pop();
                pq.push( arr[i] );
            }
        }
        
        //step3: thus the required ans is the top of the maxHeap
        int ans = pq.top();
        return ans;
    }
};
