class Solution{
  public:
    vector<int> duplicates(int arr[], int n) {
        // sort the array
        sort( arr, arr+n );
        
        // initialize the result vector
        vector<int>ans;
        for( int i=1; i<n; i++ ){
            if( arr[i] == arr[i-1] && arr[i] != arr[i+1] ){ // this is because to add an element only oe time if it is repeatead more than one
                ans.push_back( arr[i] );
            }
        }
        if( ans.size() == 0 ){
            ans.push_back( -1 );
        }
        return ans;
    }
};
