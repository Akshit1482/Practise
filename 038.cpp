class Solution
{
public:
    int minSwap(int arr[], int n, int k) {
        // we are using the sliding window concept
        // first we find how uch are the good( numbers less than k) numberss in array
        // and bad will be the swaps to be done for bad eleemnets to get required subaaray
        // min swaps is the answeer
        int good = 0;
        int bad = 0;
        for( int i=0; i<n; i++ ){
            if( arr[i] <= k ){
                good++;
            }
        }
        
        // calculating for the first window
        for( int i=0; i<good; i++ ){
            if( arr[i] > k ){
                bad++;
            }
        }
        // calculating for rest of the windowsin the array
        int i=0;
        int j=good; // window size, and end index of second window, as first window was from 0 to < than good
        int ans = bad; // answer of the first window
        while( j < n ){
            //we are now moving the window forward
            // if first elemnt is greater than k, which has to be removed from the window, 
            //  than it has to reduced from bad, as it is not part of the next window
            if( arr[i] > k ){ 
                bad--;
            }
            // if in next window the new element ehich has to be added is greater than k, than it will contribute to one more swap for ans
            if( arr[j] > k ){  
                bad++;
            }
            // update the ans, as bad might have changed
            ans = min( ans,bad );
            i++; j++; // moving window by 1;
        }
        return ans;
    }
};
