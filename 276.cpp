class Solution{
    public:
    bool isSafe( int newx, int newy, vector<vector<bool>>& vis, vector<vector<int>>& m, int n)
    {
        if(( newx >= 0 && newx < n ) && ( newy >= 0 && newy < n ) && vis[newx][newy] != 1 &&
            m[newx][newy] == 1 ){
                return true;
            }
        else{
            return false;
        }
    }
    void solve( int x, int y, vector<vector<int>>& m, int n, vector<string>& ans, vector<vector<bool>>& vis,
    string path ){
        
        //base case
        if( x == n-1 && y == n-1 ){  // destination
            ans.push_back( path );
            return;
        }
        //4 movement
        // D L R U
        vis[x][y] = 1;  // vis pos. par ho, wahan visited 1 mark karo
        
        //Down
        if( isSafe( x + 1, y, vis, m, n) ){
            solve( x + 1, y, m, n, ans, vis, path + 'D' );
        }
        //Left
        if( isSafe( x, y - 1, vis, m, n) ){
            solve( x, y - 1, m, n, ans, vis, path + 'L' );
        }
        //Right
        if( isSafe( x, y + 1, vis, m, n) ){
            solve( x, y + 1, m, n, ans, vis, path + 'R' );
        }
        //Up
        if( isSafe( x - 1, y, vis, m, n) ){
            solve( x - 1, y, m, n, ans, vis, path + 'U' );
        }
        // backtrack karte waqt vis ko zero kardo
        vis[x][y] = 0;
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        
        vector<string>ans;
        vector<vector<bool>>visited(n,vector<bool>(n,0));
        
        string path = "";
        
        if(m[0][0] == 0 ){
            return ans;
        }
        
        solve( 0, 0, m, n, ans, visited, path);
        return ans;
    }
};
