class Solution {
public:
    vector<vector<int>> overlappedInterval(vector<vector<int>>& intervals) {
         int n = intervals.size();
        // sorting the matrix
        sort( intervals.begin(), intervals.end() );

        vector<vector<int>>ans;
        // iterating the matrix
        for( int i=0; i<n; i++ ){
            // pushing the first interval or the next interval that is to be pushed
            if( ans.empty() || intervals[i][0] > ans.back()[1] ){
                ans.push_back( intervals[i] );
            }
            else{ // if the new interval that is to be pushed arrived
                // updating the end interval
                ans.back()[1] = max( ans.back()[1], intervals[i][1] );
            }
        }
        return ans;
    }
};
