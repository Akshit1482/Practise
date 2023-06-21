class Solution
{
  public:
    string lookandsay(int n) {
        
        if( n==1 ) return "1";
        if( n==2 ) return "11";
        string s = "11";
        
        // now we start loop from 3 iteration
        for( int i=3; i<=n; i++ ){
            string t = "";
            int c = 1; // as count of each char present in string will be default 1
            s = s + "$"; // adding just to differentiate last char with this
            
            for( int j=1; j<s.length(); j++ ){
                if( s[j] != s[j-1] ){
                    t = t + to_string(c); // first write counnt
                    t = t + s[j-1];
                    c = 1; // setting count to 1 for next element
                }
                else{
                    c++; // previous eleement is same
                }
            }
            s = t; // setting new string as base string
        }
        return s;
    }   
};
