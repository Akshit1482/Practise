class Solution
{
    public:
    //Function to evaluate a postfix expression.
    int evaluatePostfix(string S) // postfix mein jo no. ke baad operator hota hain, usse pechle do no. par operation perform hota hai
    {
        int n = S.size();
        stack<int>s;
        for( int i= 0; i<n; i++){
            // checking if it is a operator or operand
            char ch = S[i];
            if( ch == '*' | ch == '+' || ch == '-' || ch == '/' ){
                int a = s.top();
                s.pop();
                
                int b = s.top();
                s.pop();
                
                if( ch == '*'){
                    s.push( a*b );
                }
                else if( ch == '+' ){
                    s.push( a+b );
                }
                else if( ch == '-' ){
                    s.push( b-a );
                }
                else{
                    s.push( b/a );
                }
            }
            else{
                int num = S[i] - 48; // converting str to int ( -48), small letter ( -97 ), capital letter( -65)
                s.push( num );
            }
        }
        return s.top();
    }
};
