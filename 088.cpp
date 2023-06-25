class Solution{
    public:
    int findSubString(string str)
    {
        // we will first count the total number if sistinct characters in a string
        set<char>st;
        for( int i=0; i<str.length(); i++ ){
            st.insert( str[i] );
        }
        int n = st.size(); // no. of distinct characters
        
        // now we are going to use two pointers i and j, to find string that contains all characters
        // first we traverse end, to find a string, which cntains all distinct characters
        // the we move start forward to minimize that string
        unordered_map<char,int>mp;
        int end = 1;
        int start = 0;
        // initializing the first char, as it will always be in first attempt
        mp[str[start]]++;
        int count = 0;
        
        count++; // as we have entered a distinct char in our test string
        int len = INT_MAX; // to find minnimum sub sequence
        
        while( start <= end && end < str.length() ){
            if( count < n ){ // it means we have not found a subsequence with all distinct char
                if( mp[str[end]] == 0 ){ // it is an distinct char
                    count++;
                }
                mp[str[end]]++;
                end++; // iterating towards next char
            }
            else if( count == n ){  // we have a subsequence with all distinct char, and we need to minimize it
                len = min( len, end-start );
                
                if( mp[str[start]] == 1 ){ // this is because if mp is 1, the we only have that char one time in our substring, and
                                           // if we remove it to check rest of og string, than our substring won't have that distinct char 
                    count--;
                }
                
                mp[str[start]]--; // as we are starting to remove char from start
                start++;
            }
        }
        
        // this case is to be preventive
        // if we found the last distinct char at the end of str, then we don't get to minimize the string
        while( count == n ){
            len = min( len, end-start );
            
            if( mp[str[start]] == 1 ){
                count--;
            }
            
            mp[str[start]]--;
            start++;
        }
        return len;
        
    }
};
