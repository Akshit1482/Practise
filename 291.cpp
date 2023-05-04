class Solution {
public:
    int ans;
    bool isSafe( vector<vector<int>>& matrix, int x, int y, vector<vector<bool>>& vis,
                int n, int m )
    {
        if( (x>=0 && x<n) && (y>=0 && y<m) && vis[x][y] != true && matrix[x][y] == 1 ){
            return true;
        }
        return false;
    }            
    
    void solve( vector<vector<int>>& matrix, int xd, int yd, vector<vector<bool>>& vis,
                int n, int m, int cnt, int x, int y )
    {            
        // base case
        if( x == xd && y == yd ){
            ans = max( cnt, ans );
            return;
        }
        
        vis[x][y] = true;
        // recursive call
        // 4 movements
        
        // Right
        if( isSafe( matrix, x, y+1, vis, n, m ) ){
            solve( matrix, xd, yd, vis, n, m, cnt+1, x, y+1 );
        }
        // Down
        if( isSafe( matrix, x+1, y, vis, n, m ) ){
            solve( matrix, xd, yd, vis, n, m, cnt+1, x+1, y );
        }
        // Up
        if( isSafe( matrix, x-1, y, vis, n, m ) ){
            solve( matrix, xd, yd, vis, n, m, cnt+1, x-1, y );
        }
        // Left
        if( isSafe( matrix, x, y-1, vis, n, m ) ){
            solve( matrix, xd, yd, vis, n, m, cnt+1, x, y-1 );
        }
        
        // Bactrack while returning
        vis[x][y] = false;
        
    }    
    int longestPath(vector<vector<int>> matrix, int xs, int ys, int xd, int yd)
    {
        if( matrix[xs][ys] == 0 || matrix[xd][yd] == 0 ){
            return -1;
        }
        
        ans = -1;
        int cnt = 0;
        int n = matrix.size();
        int m = matrix[0].size();
        
        vector<vector<bool>>vis(n, vector<bool>(m,false));
        solve( matrix, xd, yd, vis, n, m, cnt, xs, ys );
        return ans;
    }
};
