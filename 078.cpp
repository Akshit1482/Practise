class Solution{
    public:
    int ans = 0;
    int check( int i, int j, vector<vector<char> > &mat, string &target, int ind ){
        int found = 0;
        if( i>=0 && j>=0 && i<mat.size() && j<mat[0].size() && mat[i][j] == target[ind] ){
            
            char temp = target[ind];
            // making the ccurrent element as 0, so the function won't select it again
            mat[i][j] = 0;
            ind += 1; // incrementing the index of the searching string
            if( ind == target.size() ){
                ans++; // means the ind has incremented from last index of target
            }
            else{
                check( i+1, j, mat, target, ind );
                check( i-1, j, mat, target, ind );
                check( i, j+1, mat, target, ind );
                check( i, j-1, mat, target, ind );
                // we are using recursion
            }
            // after iterating and founding our searching string
            // we need to backtrack, and convert all element to original ehich we have converted to zero during iteration
            mat[i][j] = temp; // that's why we store the current character for every search
        }
        return found;
    }
    
    int findOccurrence(vector<vector<char> > &mat, string target){ 
        // first we are going to start a double loop to start searching for target from every mat's element
        for( int i=0; i<mat.size(); i++ ){
            for( int j=0; j<mat[0].size(); j++ ){
                check( i, j, mat, target, 0 );
            }
        }
        return ans;
    }
};
