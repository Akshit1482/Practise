class Solution{
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    void merge( long long arr[], long long start, long long mid, long long end, long long& ans ){
        // creating a temp array to store the sorted array
        vector<long long>temp;
        long long left = start;
        long long right = mid+1;
        
        while( left<=mid && right<=end ){
            if( arr[left] <= arr[right] ){
                temp.push_back( arr[left] );
                left++;
            }
            else{
                temp.push_back( arr[right] );
                right++;
                // if element on right is smaller than element of left, then the right will be smallerthan all
                // elements on left
                ans += mid-left+1; // (m+1)is length of left part
            }
        }
        // if left array gets remained
        while( left <= mid ){
            temp.push_back( arr[left] );
            left++;
        }
        // if right array gets remained
        while( right <= end ){
            temp.push_back( arr[right] );
            right++;
        }
        // copuing the sorted temp into og arr
        long long n = temp.size();
        for( long long i=0; i<n; i++ ){
            arr[i+start] = temp[i];
        }
    }
    
    void mergeSort( long long arr[], long long start, long long end, long long& ans ){
        // base case
        if( start == end ){
            return;
        }
        long long mid = (end+start)/2;
        // recursive call
        mergeSort( arr, start, mid, ans);
        mergeSort( arr, mid+1, end, ans);
        // merging the both array
        merge( arr, start, mid, end, ans );
    }
    
    long long int inversionCount(long long arr[], long long N)
    {
        long long ans = 0;
        mergeSort( arr, 0, N-1, ans);
        return ans;
    }

};
