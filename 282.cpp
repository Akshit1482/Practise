class Solution {
  public:
    bool isPalindrome( string s, int st, int end ){  // checking th estring is palindrome or nit
        while( st <= end ){
            if( s[st++] != s[end--] ){
                return false;
            }
        }
        return true;
        
    }
    void solve( vector<vector<string>>& ans, string s, vector<string>& partition, int st ){
        // base case
        if( st == s.length() ){
            ans.push_back( partition );
            return;
        }
        
        for( int i = st; i < s.length(); i++ ){  
            if( isPalindrome( s, st, i ) ){  // isko dry run karo
                partition.push_back( s.substr( st, i-st + 1 ));   // carefully explanation dekho, back of classmate spiral
                
                solve( ans, s, partition, i + 1 ); // i+1 for next iteration and not next step
                
                // backtrack
                partition.pop_back();
            }
        }
    }  
    vector<vector<string>> allPalindromicPerms(string S) {
        vector<vector<string>>ans;
        vector<string>partition;
        int st = 0;
        solve( ans, S, partition, st );
        return ans;
    }
};
