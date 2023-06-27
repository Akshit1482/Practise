class Solution
{
  public:
    bool isPossible( int arr[], long long n, long long k, long long mid ){
        long long painterCount = 1;
        long long pairSum = 0;
        
        for( int i=0; i<n; i++ ){
            if( pairSum + arr[i] <= mid ){
                pairSum += arr[i];
            }
            else{
                painterCount++;
                if( painterCount > k || arr[i] > mid ){
                    return false;
                }
                // restore the pairSum for next painter
                pairSum = arr[i];
            }
            if( painterCount > k ){
                return false;
            }
        }
        return true;
    }
    long long minTime(int arr[], int n, int k)
    {
        // code here
        // return minimum time
        long long s = 0;
        long long sum = 0;
        for( long long i=0; i<n; i++ ){
            sum += arr[i];
        }
        long long e = sum;
        long long ans = -1;
        long long mid = s+(e-s)/2;
        
        while( s<=e ){
            if( isPossible( arr, n, k, mid ) ){
                ans = mid; // update the answer
                e = mid-1;
            }
            else{
                s = mid+1;
            }
            mid = s+(e-s)/2;
        }
        return ans;
    }
};
