class Solution
{
    public:
    //Function to find the smallest window in the string s consisting
    //of all the characters of string p.
    string smallestWindow (string s, string p)
    {
        if( s.length() == 0 || p.length() == 0 || s.length() < p.length() ){
            return "-1";
        }
        
        vector<int>v(256,0);
        for( int i=0; i<p.length(); i++ ){  // initializing the vector wrt to p
            v[p[i]]++;
        }
        
        int start=0; int end = 0;
        int ans_start = 0;
        int count = 0;
        int len = INT_MAX;
        
        while( end < s.length() ){
            
            if( v[s[end]] > 0 ){ // yahan par sirf vo hi element positive hoga joh p mein hoga
                count++;
            }
            v[s[end]]--; // as we iterate through any char, we decreaseits frequency, because if it is present in p, it will have to appear one less time
                        // and if doesn't appear in p, it will not considered in increasing count
            
            // if we found a substring with required string int it
            while( count == (int)p.length() ){
                
                if( len > end-start+1 ){
                    len = end-start+1;
                    ans_start = start;
                }
                
                // now restoring the initial count of string s, when we traveresed the first time, we decreased, their count
                v[s[start]]++;
                if( v[s[start]] > 0 ){ // only those present in p string will have frequency greater than 0, as they inly been increased once at the start
                    count--;
                }
                start++;
            }
            end++; // if count is not equal to p;
        }
        if( len == INT_MAX ){
            return "-1";
        }
        return s.substr( ans_start, len );
    }
};
