class Solution {
  public:
    int getMinDiff(int arr[], int n, int k) {
        
        sort( arr, arr+n);
        int maxi= arr[n-1];
        int mini= arr[0];
        
        int ans= arr[n-1]-arr[0];// can be a possible solution
        
        for (int i=1; i<n; i++){
             if( arr[i]-k < 0){
                 continue;
             }
             maxi= max( arr[i-1]+k, arr[n-1]-k);//(in this statement arr[n-1]is constant and we are comparing it with all elements from arr[0] to arr[n-1] + k; to find the largest height
             mini= min( arr[0]+k, arr[i]-k); //in this statement arr[0] is constant and we are comparing it with  all elements from arr[1] to arr[n-1] - k; to find the smallest height
             
             ans= min( ans, maxi-mini);
        }
        return ans;
    }
};
