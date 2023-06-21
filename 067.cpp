class Solution {
public:
    int maxSubStr(string str){
        //We are just calculating count of 0 & 1 in string, and 
        // whenever we get both count equal, then we update our substring count
        // as it is substrinng , so we have maintain the order
        
        int count0 = 0;
        int count1 = 0;
        int ans = 0;
        
        for( int i=0; i<str.length(); i++ ){
            
            if( str[i] == '0' ){
                count0++;
            }
            if( str[i] == '1' ){
                count1++;
            }
            if( count0 == count1 ){
                ans++;
            }
        }
        if( ans == 0 || count0 != count1 ){  // overall count of 0 and 1, as to be divided into balanced substrings, no. of 0 & 1 should be equal
            return -1;
        }
        return ans;
    }
};
