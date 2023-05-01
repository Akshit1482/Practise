class Solution{
public:
    void addSolution( vector<vector<int>>& ans, vector<vector<int>>& board, int n ){
        // creating a temp vector
        vector<int>temp;
        
        for( int j=0; j<n; j++ ){
            for( int i=0; i<n; i++ ){
                if( board[i][j] == 1 ){
                    temp.push_back( i + 1 );
                }
            }
        }
        ans.push_back( temp );
    }
    
    bool isSafe( int row, int col, vector<vector<int>>& board, int n ){
        int x = row;
        int y = col;
        
        // we don,t check for col as we only place one queen in one row, and not in right in row, as we inserting queen from left to right
        // check for same row
        while( y >= 0 ){
            if( board[x][y] == 1 )
                return false;
            y--;    
        }
        
        // check for left-up diagonal
        x = row;
        y = col;
        while( x >= 0 && y >= 0 ){
            if( board[x][y] == 1 )
                return false;
            x--;
            y--;
        }
         // check for left-down diagonal
        x = row;
        y = col;
        while( x < n && y >= 0 ){
            if( board[x][y] == 1 )
                return false;
            x++;
            y--;
        }
        // if no condition matches
        return true;
    }
    
    void solve( int col, vector<vector<int>>& ans, vector<vector<int>>& board, int n ){
        //base case
        if( col == n ){  // if the current col is last coloumn
            addSolution( ans, board, n );
            return;
        }
        // solve 1 and recursion will handle other
        for( int row = 0; row < n; row++ ){
            if( isSafe( row, col, board, n ) ){
                //if placing queen is safe
                board[row][col] = 1;
                solve( col + 1, ans, board, n );
                
                // backtrack
                board[row][col] = 0;
            }
        }
    }
    vector<vector<int>> nQueen(int n) {
        vector<vector<int>>board( n, vector<int>(n, 0 ));  // initialize a matrix of n*n size initializing with zero;
        vector<vector<int>>ans;
        
        solve( 0, ans, board, n );
        return ans;
    }
};
