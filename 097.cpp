class Solution
{
    public:
    //Function to check if two strings are isomorphic.
    bool areIsomorphic(string str1, string str2)
    {
        // if both strings are of unequal length, then they are not isomorphic
        int n = str1.length();
        int m = str2.length();
        if( n!=m ){
            return false;
        }
        
        // now whe we traverse both strring, if we encounnter new char in both string, we hash both with each other
        // if one chhar is still present, and in other string at same index if there is an char which is not previously hash with one we are at now, return false
        int m1[256] = {0};
        int m2[256] = {0};
        for( int i=0; i<n; i++ ){
            if( !m1[str1[i]] && !m2[str2[i]] ){  // means if both are not present in arrays, then we hash both with each other
            
                m1[str1[i]] = str2[i];
                m2[str2[i]] = str1[i];
            }
            else if( m1[str1[i]] != str2[i] ){ // there is a char we have already traversed, but in otherstring at same index, there is a char, which is not hashed to our traversing char
                return false;
            }
        }
        return true;
        
    }
};
