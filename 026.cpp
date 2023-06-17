class Solution{
    public:
    //Complete this function
    //Function to check whether there is a subarray present with 0-sum or not.
    bool subArrayExists(int arr[], int n)
    {
        int sum;
        unordered_map<int,int>m;
        m[0] = true; // this case is for the one if any subarray starting from oth index index sums to 0
        
        for( int i=0; i<n; i++ ){
            sum += arr[i];  // we are gradually summing the elements into sum
            
            if( m[sum] ){   // if sum of subarray starting from start, again gets equal to any sum of subarray before that element, that means there exist a part whose sum is zero 
                return true;
            }
            else{
                m[sum] = true; // nahi toh jitna array traverse karliya hai utne tak ka sum map par true kardo
            }
        }
        return false;
    }
};
