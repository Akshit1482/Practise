class Solution{
    public:
    // arr: input array
    // n: size of array
    //Function to find the sum of contiguous subarray with maximum sum.
    long long maxSubarraySum(int arr[], int n){
        
        int sum=0;
        int maxSum=INT_MIN;
        
        //loop for iterating the array
        for( int i=0; i<n; i++){
            sum+= arr[i]; //(or sum= sum + a[i])
            
            if( maxSum < sum){
                maxSum = sum;
            }
            if( sum < 0){
                sum=0;
            }
        }
        return maxSum;
        
    }
};
