class Solution
{
    public:
    int transform (string A, string B)
    {
        // creating an unordered map
        unordered_map<char,int>mp;
        
        // checking if A and B have same char of same frequency
        for( int i=0; i<A.length(); i++ ){
            mp[A[i]]++;
        }
        for( int i=0; i<B.length(); i++ ){
            mp[B[i]]--;
        }
        // if there is any char present in map, then A and B are not equal
        for( auto i:mp ){
            if( i.second != 0 ){
                return -1;
            }
        }
        
        // now traversing the strings from end, and checking them continuosly
        int i = A.length();
        int j = B.length();
        int count = 0;
        while( i>=0 && j>=0 ){
            if( A[i] == B[j] ){
                i--;
                j--;
            }
            else{  // the char are not equal, then we decrement the the string to be searched, to find the next common char in both
                count++;
                i--;
            }
        }
        return count;
    }
};
