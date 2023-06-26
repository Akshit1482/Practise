class Solution{
    public:
    void sol( vector<vector<string>>&ans, vector<string>&a, vector<vector<string>>&list, int i ){
        // base case
        if( i == list.size() ){
            ans.push_back( a );
            return;
        }
        
        // we are just traversing a 2-D vector and inserting sting to form a sentence
        for( int k=0; k<list[i].size(); k++ ){
            a.push_back( list[i][k] );
            // recursive call
            sol( ans, a, list, i+1 );
            
            // we need to bactrack from one iteration of a row, to consider the next iteration of that row
            // as we can only take one string from one row
            a.pop_back();
        }
    }
    
    vector<vector<string>> sentences(vector<vector<string>>&list){
        vector<vector<string>>ans;
        vector<string>a;
        
        sol( ans, a, list, 0 );
        return ans;
    }
};
