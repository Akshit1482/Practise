class Solution {
  public:
    string longestPalin (string S) {
        
        int start = 0;
        int end = 0;  // this end represents the length of longest palindromic subsequence
        int low, high;
        for( int i=0; i<S.length(); i++ ){
            
            // if its is of even length
            // then palindrome have 2 elements in the middle that are equal
            // so we take two pointers adjacent, to check around every adjacent equal elements
            low = i - 1;
            high = i;
            while( low>=0 && high<S.length() && S[low] == S[high] ){
                
                int length = high - low + 1; // as high and low are indices, and minimum palindromic length will be 0, for even
                if( length > end ){
                    end = length; // length of current longgest palindrome
                    start = low;
                }
                // now we ttraverse around high and low to check if more elements are in palindrome or not
                low--;
                high++;
            }
            
            // if its is of odd length
            // then palindrome only have one element in middle, and the elemnts left and right of middle will be equal
            // so we take two pointers, with a gap in them for middle element
            low = i-1;
            high = i+1;
            while( low>=0 && high<S.length() && S[low] == S[high] ){
                
                int length = high - low + 1;
                if( length > end ){
                    end = length;
                    start = low;
                }
                low--;
                high++;
            }
        }
        
        if( end == 0 ){
            return S.substr( start,1 ); // no palindrome at all
        }
        return S.substr( start,end ); // as end is the length, and start is the index
    }
};
