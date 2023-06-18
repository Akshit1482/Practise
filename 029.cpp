class Solution{
  public:
    // arr[] : the input array
    // N : size of the array arr[]
    
    //Function to return length of longest subsequence of consecutive integers.
    int findLongestConseqSubseq(int arr[], int N)
    {
        sort(arr,arr+N);
        
        int ans = 1;
        int prev = arr[0];
        int cur = 1;  // curr is set to be one as if array contains only one element
        
        for(int i = 1;i <N;i++){
            if(arr[i] == prev+1){  // as sorted, checking if current element isprevious element + 1, to be consecutive 
                cur++;
            }
            else if(arr[i] != prev){ // this is because to check if there is duplicate eleemnt,or the consecutive sequence have broken
                cur = 1;
            }
            prev = arr[i];
            ans = max(ans, cur);
        }
        return ans;
    }
};
