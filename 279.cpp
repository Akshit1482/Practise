class Solution {
  public:
    vector<string> res;
    unordered_map<string,int> mp;
    
    // creating stack to check the number of invalid parenthesis at first time
    int getMinInValid(string s)
    {
        stack<char> stck;
        int i = 0;
        while(i < s.size())
        {
            if(s[i] == '(')
                stck.push('(');
            else if(s[i] == ')')
            {
                if(stck.size() > 0 && stck.top() == '(')
                    stck.pop();
                else
                    stck.push(')');
            }
            i++;
        }
        return stck.size();
    }
    
    void solve(string s,int minInv){

        if(mp[s] != 0) // its is the map to track, that one string should not get processed more than one time
            return;
        else
            mp[s]++; //mp[s] = 1
        //base case
        if(minInv < 0){
            return;
        }
        if(minInv == 0)
        {
            if(!getMinInValid(s))  // checking after removing all invalid paranthesis, that the the result is valid or not
                res.push_back(s);  // it will be valid, if it don't have any invalid parenthesis
            return;
        }
        
        for(int i=0; i<s.size(); i++)  // llop to check each  and every paranthesis
        {
            string left = s.substr(0,i);
            string right = s.substr(i+1);
            solve(left+right, minInv-1);
        }
        return;
    }
    
    vector<string> removeInvalidParentheses(string s) 
    {
        solve(s, getMinInValid(s));
        sort( res.begin(), res.end() );
        return res;
    }
};
