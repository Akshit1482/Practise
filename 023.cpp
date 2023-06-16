class Solution{   
public:
    int getPairsCount(int arr[], int n, int k) {
        map<int,int>m;
        int ans = 0;
        // a and b sum makes k
        for( int i=0; i<n; i++ ){
            int b = k - arr[i];
            if( m[b] ){    // if is present in the map
                ans += m[b];
            }
            m[arr[i]]++;  // jis element ko sum se minus karke dusra element check kiya, jab usko pass kardo, toh uski frequency map mein increase kardo
        }
        return ans;
    }
};
