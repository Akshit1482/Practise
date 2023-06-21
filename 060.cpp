class Solution
{
    public:
    //Function to check if two strings are rotations of each other or not.
    bool areRotations(string s1,string s2)
    {
        // making the first char of s2 to last and checking if new s2 == s1
        bool check = false;
        
        for( int i=0; i<s1.size(); i++ ){
            if( s1 == s2 ){
                check = true;
                break;
            }
             // they are not yet equal
            char element = s2[0];
            s2.erase(0,1);
            s2+=element;
        }
        return check;
    }
};
