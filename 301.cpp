class Solution
{
    public:
    //Function to check if brackets are balanced or not.
    bool ispar(string x)
    {
        stack<char>s;
        
        for(int i=0; i<x.length(); i++ ){
            char ch = x[i];
            
            if( ch == '(' || ch == '{' || ch == '[' ){
                s.push( ch );
            }
            else{  // we have encountered a closing bracket
                if( !s.empty() ){ //checking if stack is empty
                    char top = s.top();
                    
                    if( (ch == ')' && top == '(') ||
                        (ch == '}' && top == '{') ||
                        (ch == ']' && top == '[')){
                        s.pop();
                    }
                    else{
                        return false;
                    }
                }
                else{ // stack is empty and wee have a closing paranthesis, so ofc its an unbalanced string
                    return false;
                }
            }
        }
        
        if( s.empty()){
            return true;
        }
        else{
            false;
        }
    }
    

};
