class Solution
{
	public:
	    void solve( string s, vector<string>& ans, int i ){
	        // base case
	        if( i >= s.length()){
	            ans.push_back( s );
	            return;
	        }
	        
	        for( int k = i; k<s.size(); k++ ){
	            swap( s[i],s[k] );  // ek swap khus se hoga, aur ek ek swap jitne bhi next element hain unke saath hoga
	            solve( s, ans, i+1 );  // i+1 becaause next step mein aage wale index par bhi toh jaana hai
	            
	            // backtrack
	            swap( s[i],s[k] );
	        }
	    }
		vector<string>find_permutation(string S)
		{
		    vector<string>ans;  // creating the ans vecctor
		    int index = 0;
		    solve( S, ans, index );
		    sort( ans.begin(), ans.end() );
		    
		    ans.erase( unique( ans.begin(), ans.end() ), ans.end() ); // removing all unique entries in the ans vector
		    return ans;
		    
		}
};
