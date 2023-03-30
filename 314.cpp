class Solution {
  public:
    int checkRedundancy(string s) {
        stack<char>st;
        
        for( int i=0; i<s.length(); i++){
            char ch = s[i];
            
            if( ch == '(' || ch == '+' || ch == '-' || ch == '*' || ch == '/' ){
                st.push( ch );  // if its a open bracket then just push into stack
            }
            else{
                if( ch == ')'){
                bool isRedundant = true;
                    while( st.top() != '('){
                        char top = st.top();
                        if(  top == '+' || top == '-' || top == '*' || top == '/' ){
                            isRedundant = false; // as we have encounterd operator, so its not a redundant pair till that moment
                        }
                        st.pop(); // popping the operator, so we can get to next element in stack
                    }
                    
                    if( isRedundant == true){
                        return 1; // if we have not found any operator between ( and  )
                    }    
                    st.pop(); // popping the open bracket, as it has maid pair with )
                }
            }
        }
        return 0; //if there were no redundant pair
    }
};
