class Solution{
    public:
    //Function to return the count of number of elements in union of two arrays.
    int doUnion(int a[], int n, int b[], int m)  {
        unordered_set<int>s;
        
        // as set dont contain any duplicate elemnets
        for( int i=0; i<n; i++ ){
            s.insert( a[i] );
        }
        for( int j=0; j<m; j++ ){
            s.insert( b[j] );
        }
        
        return s.size();
    }
};
