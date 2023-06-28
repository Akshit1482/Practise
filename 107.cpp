class Solution{
public:
    vector<int> findTwoElement(vector<int> arr, int n) {
        // create a vector to store frequency of elements
        int fr[n+1] = {0};
        
        for( int i=0; i<n; i++ ){
            fr[arr[i]]++;
        }
        int a=0;
        int b=0;
        
        for( int i=1; i<=n; i++ ){
            if( fr[i] == 0 ){
                a = i;
            }
            else if( fr[i] == 2 ){
                b = i;
            }
        }
        return {b,a};
    }
};
