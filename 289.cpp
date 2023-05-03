class Solution
{
	public:
	    void solve( string s, vector<string>& ans, int i ){
	        // base case
	        if( i == s.length() - 1 ){
	            ans.push_back( s );
	            return;
	        }
	        
	        for( int k = i; k<s.size(); k++ ){
	            swap( s[k],s[i] );
	            solve( s, ans, i+1 );
	            
	            // backtrack
	            swap( s[k],s[i] );
	        }
	    }
		vector<string>find_permutation(string S)
		{
		    vector<string>ans;
		    solve( S, ans, 0 );
		    sort( ans.begin(), ans.end() );
		    
		    ans.erase( unique( ans.begin(), ans.end() ), ans.end() );  // removing all unique entries in the ans vector
		    return ans;
		    
		}
};
