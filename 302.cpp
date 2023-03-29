char* reverse(char *S, int len)
{
    stack<char>st;
    // putting all string elements into stack
    for( int i=0; i<len; i++ ){
        char ch = S[i];
        st.push( ch );
    }
    
    //string ans = "";
    // popping normally out of stack returns a reversed string
    int i= 0;
    while( !st.empty() ){
        char ch = st.top();
        S[i] = ch;
        st.pop();
        i++;
    }
    
    return S;
}
