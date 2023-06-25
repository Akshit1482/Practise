class Solution{
    public:
    string removeConsecutiveCharacter(string S)
    {
        string ans = "";
        int n = S.length();
        for( int i=0; i<n-1; i++ ){
            if( S[i] != S[i+1] ){
                ans += S[i] ;
            }
            
        }
        // last character
            ans += S[n-1];
        return ans;
    }
};
