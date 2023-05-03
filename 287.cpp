class Solution {
  public:
    void solve( vector<int> &A, int B, vector<vector<int>>& ans, vector<int>& nums, int sum, int prev ){
        // base case
        if( sum > B ){
            return;
        }
        
        if( sum == B ){
            ans.push_back( nums );
            return;
        }
      
        for( int i = 0; i<A.size(); i++ ){
            if( prev <= A[i] ){
                nums.push_back( A[i] );
                solve( A, B, ans, nums, sum + A[i], A[i] );
                
                // backtrack if sum is not equal to B
                nums.pop_back();
            }
        }
    }
    //Function to return a list of indexes denoting the required 
    //combinations whose sum is equal to given number.
    vector<vector<int> > combinationSum(vector<int> &A, int B) {
        vector<vector<int>>ans;
        vector<int>nums;
        
        sort( A.begin(),A.end() );
        // remove duplicates int he given  array
        A.erase( unique(A.begin(),A.end()), A.end() );  // mark as imporatant
        
        int sum = 0;
        int prev = 0; // this is the previously added element in the nums
        solve( A, B, ans, nums, sum, prev );
        return ans;
    }
};
