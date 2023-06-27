class Solution 
{
    public:
    bool isPossible( int A[], int N, int M, int mid ){
        int studentCount = 1;
        int pageSum = 0;
        // now checcking for mid
        for( int i=0; i<N; i++ ){
            if( pageSum + A[i] <= mid ){ // checking whether page allocated is within the mid
                pageSum += A[i];
            }
            else{
                studentCount++;
                if( studentCount > M || A[i] > mid ){
                    return false;
                }
                // thus we need to start allocating pages to new student from zero, sarting from no. of pages e are currently at
                pageSum = A[i];
            }
            if( studentCount > M ){
                return false;
            }
        }
        return true;
    }
    //Function to find minimum number of pages.
    int findPages(int A[], int N, int M) 
    {
        // finding the search space for binary search
        int s = 0;
        int sum=0;
        if( N < M ){
            return -1;
        }
        for( int i=0; i<N; i++ ){
            sum += A[i];
        }
        int e = sum;
        
        int ans = -1;
        int mid = s+(e-s)/2; // here mid is not the index, but mid is the no. of pages
        
        // binary search
        while( s <= e ){
            if( isPossible( A, N, M, mid ) ){ // thus partition is possible at that index, so it will be possible for indexes more than that
                ans = mid;
                e = mid-1;
            }
            else{
                s = mid+1;
            }
            mid = s+(e-s)/2;
        }
        return ans;
    }
};
