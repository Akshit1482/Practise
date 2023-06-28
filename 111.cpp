class Solution{
    public:
    // arr[] : int input array of integers
    // k : the quadruple sum required
    vector<vector<int> > fourSum(vector<int> &arr, int k) {
        
        vector<vector<int>>ans;
        // sorting the og array
        sort( arr.begin(), arr.end() );
        
        // iterating the array with loop and two pointer to get four eleements
        for( int i=0; i<arr.size(); i++ ){
            for( int j=i+1; j<arr.size(); j++ ){
                
                //now the two pointer4
                int l = j+1;
                int m = arr.size()-1;
                int sum = 0;
                
                while( l < m ){
                    sum = arr[i]+arr[j]+arr[l]+arr[m];
                    if( sum > k ){
                        m = m-1;
                    }
                    else if( sum < k ){
                        l = l+1;
                    }
                    else{
                        vector<int>A;
                        A.push_back(arr[i]);
                        A.push_back(arr[j]);
                        A.push_back(arr[l]);
                        A.push_back(arr[m]);
                        
                        // push the vecor in ans
                        ans.push_back( A );
                        // now moving the pointers
                        l++;
                        m--;
                    }
                }
            }
        }
        // sort the result array
        sort( ans.begin(), ans.end() );
        // erasing the duplicates from answer array
        ans.erase( unique(ans.begin(),ans.end()), ans.end() );
        
        return ans;
    }
};
