class Solution
{
public:
    bool isSafe( int i, int j, int n, int m ){
        if( (i>=0 && i<n) && (j>=0 && j<m) ){
            return true;
        }
        return false;
    }
    void solve( int x, int y, vector<int>& curr, vector<vector<int>>& ans, int n, int m, vector<vector<int>> &grid )
    {
        if( x == n-1 && y == m -1 ){
            curr.push_back( grid[x][y] ); // this is the for the last iteration as at n-1 & m-1 base case is reached, and the the last iteration doesm't get pushed in curr
            ans.push_back( curr );
            
            // backtrack for last iteration
            curr.pop_back();
            return;
        }
        
        curr.push_back( grid[x][y] );
        //Down
        if( isSafe( x+1, y, n, m ) ){
            solve( x+1, y, curr, ans, n, m, grid );
        }
        //Right
        if( isSafe( x, y+1, n, m ) ){
            solve( x, y+1, curr, ans, n, m, grid );
        }
        
        // backtrack
        curr.pop_back();
    }
    vector<vector<int>> findAllPossiblePaths(int n, int m, vector<vector<int>> &grid)
    {
        vector<vector<int>>ans;
        vector<int>curr;
        
        solve( 0, 0, curr, ans, n, m, grid );
        return ans;
    }
};
