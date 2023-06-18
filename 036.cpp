class Solution{
  public:

    int smallestSubWithSum(int arr[], int n, int x)
    {
        int start = 0; int end = 0;
        int minLen = INT_MAX;
        int currSum = 0;
        
        while( end < n ){
            // summing all the elemnets till we get summation greater or equal than x
            while( currSum <= x && end < n ){
                currSum += arr[end++];  // end is the element where sum exeeds x
            }
            
            // moving start forward to get the smallest subarray
            while( currSum > x && start < n ){   // we move start till sum is still greater than x
                if (end - start < minLen)   
                    minLen = end - start;  // updating the minLen
                
                currSum -= arr[start++];  // reducing the sum by the element which we are removing as start
            }
        }
        return minLen;
    }
};
