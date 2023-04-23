// User function Template for C++

class Solution{
    public:
    // 0 based indexing
    void heapify( vector<int>& arr, int n, int i ){
        int largest = i;
        int left = 2*i + 1;
        int right = 2*i + 2;
        
        if( left<n && arr[largest] <  arr[left] ){
            largest = left;
        }
        if( right<n && arr[largest] < arr[right] ){
            largest = right;
        }
        
        // checking for swap
        if( largest != i ){
            swap( arr[largest], arr[i] );
            heapify( arr, n, largest );
        }
    }
    vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m) {
        // creating a merged vector to form merged heap
        vector<int>ans;
        
        for( auto i:a ){
            ans.push_back( i );
        }
        for( auto i:b ){
            ans.push_back( i );
        }
        
        // step2: build heap from merged array
        int size = ans.size();
        for( int i=size/2-1; i>=0; i-- ){
            heapify( ans, size, i );
        }
        return ans;
    }
};
