class Solution{
    public:
    // arr : given array
    // l : starting index of the array i.e 0
    // r : ending index of the array i.e size-1
    // k : find kth smallest element and return using this function
    int kthSmallest(int arr[], int l, int r, int k) {
        int n= r+1-l;
        sort( arr, arr+n);
       
        
        int ans= arr[k-1];
        return ans;
    }
};
