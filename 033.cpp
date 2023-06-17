class Solution{
    public:
    //Function to find if there exists a triplet in the 
    //array A[] which sums up to X.
    bool find3Numbers(int A[], int n, int X)
    {
        sort( A, A+n );
        for( int i=0; i<n; i++ ){
            int a = A[i];
            int target = X - a;
            int s = i+1;
            int e =n-1;
            
            while( s<e ){
                if( A[s] + A[e] == target ){
                    return true;
                }
                else if( A[s] + A[e] > target ){
                    e--;
                }
                else{
                    s++;
                }
                
            }
        }
        return false;
    }

};
