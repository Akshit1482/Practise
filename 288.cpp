class Solution
{
    public:
    void solve( string& max, string& str, int k, int idx ){
        // base case
        if( k == 0 ){
            return;
        }
        
        int n = str.length();
        // finding larger character than maxc ahead of maxc
        char maxc = str[idx];
        for( int i = idx+1; i<n; i++ ){
            if( maxc < str[i] ){
                maxc=str[i];
            }
        }
        
        if( maxc != str[idx] ){
            k -= 1; // swap will take place
        }
        
        for( int i=idx; i<n; i++ ){
            if( str[i] == maxc ){  // iterating with loop till maxc position
                swap( str[i],str[idx] );
                // updating max
                if( str.compare(max) > 0 )
                    max = str;
                
                // recursive call
                solve( max, str, k, idx+1 );  //recursive call on next element from initial idx
                
                // backtrack
                swap(str[i],str[idx]);
            }
        }
    }
    //Function to find the largest number after k swaps.
    string findMaximumNum(string str, int k)
    {
       string max = str;  // considering the initial string as max, to compare with swapped strings
       solve( max, str, k, 0 );
       return max;
    }
};
