int countRev (string s)
{
    // balancing will not be possible only when string is of odd length
    if( s.length() % 2 == 1 ){
        return -1;
    }
    
    stack<char>st;
    // initializing the stack
    for( int i=0; i<s.length(); i++ ){
        char ch = s[i];
        if( ch == '{' ){
            st.push( ch );
        }
        else{
            // ch is close brace }
            if( !st.empty() && st.top() == '{' ){
                st.pop();
            }
            else{
                st.push( ch );
            }
        }
    }
    // now stack will only contain inalid expression
    int a=0, b=0;
    while( !st.empty() ){
        if( st.top() == '{' ){
            a++;
        }
        else{
            b++;
        }
        st.pop();
    }
    
    int ans = (a+1)/2 + (b+1)/2;
    return ans;
}
