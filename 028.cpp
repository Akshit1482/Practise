class Solution{
public:

    // there are 4 observations to be made
    // 1. all elemnets of the array could be +ve, so ans will be product of all elemnts
    // 2. there are even no. of +ve & -Ve elements in the array, ans is product of all elements
    
    // 3. there will be odd no. of -ve elemnets in array, so we only have to ignore one -ve element
    // we ignore that element in such a way that we can get maximum of left or right side product
    
    // 4. there can be zero in the array, so we consider all the array divided by zero as individual
    // and calculate amximum product from start and end, and when encounter zero, change pre and suc back to 1, to again calculate product of tha divivded array
	// Function to find maximum product subarray
	long long maxProduct(vector<int> arr, int n) {
	    long long pre = 1;
	    long long suc = 1;
	    long long ans = INT_MIN;
	    
	    for( int i=0; i<n; i++ ){
	        if( pre == 0 )  // in case we encounter zero during product
	            pre = 1;
	        if( suc == 0 )
	            suc = 1;
	        
	        pre = pre * arr[i];
	        suc = suc * arr[n-i-1];
	        ans = max(ans,max(pre,suc));
	    }
	    return ans;
	}
};
