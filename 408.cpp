/*You are required to complete this function*/
vector<vector<int>> uniqueRow(int M[MAX][MAX],int row,int col)
{
    vector<vector<int>>ans;
    unordered_set<string>set;
    
    // loop to traverese the matrix
    for( int i=0; i<row; i++ ){
        string s = "";
        for( int j=0; j<col; j++ ){
            if( M[i][j] == 1 ){
                s.push_back( '1' );
            }
            else{
                s.push_back( '0' );
            }
        }
        // checking if the string s is present in set or not
        if( set.find(s) == set.end() ){
            vector<int>temp;  // as we have to return int, so to store string in int temp
            for( auto k : s){
                if( k == '1' ){
                    temp.push_back(1);
                }
                else{
                    temp.push_back(0);
                }
            }
            // pushing the temp into the ans matrix
            ans.push_back( temp );
        }
        set.insert( s );  // putting string s into set, to hold checck of duplicacy
    }
    return ans;
}
