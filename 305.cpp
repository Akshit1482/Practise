class Solution 
{
    private:
    bool knows( vector<vector<int> >& M, int a, int b, int n){
        if( M[a][b] == 1)
            return true; // checking if a knows b, if element of row a,columb b == 1
        else
            return false;
    }
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        stack<int>s;
        
        for( int i=0; i<n; i++){ //push all person to stack
            s.push(i);
        }
        
        while( s.size() > 1){
            int a = s.top();
            s.pop();
            
            int b = s.top();
            s.pop();
            
            if( knows( M, a, b, n)){ // if a knows b, so n can be a celbrity
                s.push(b);
            }
            else{ // else a can be a celebrity
                s.push(a);
            }
        }
        int ans = s.top();  // because ek hi no. bacha hai stack mein
        
        // ans can be a possible celebrity
        
        // row check
        int zeroCount = 0;
        for( int i=0; i<n; i++){ // there all zereos in celebrity row, as he don't know anyone
            if( M[ans][i] == 0){
                zeroCount++;
            }
        }
        if( zeroCount != n){
            return -1;
        }
        
        // coloumn check
        int oneCount = 0;
        for( int i=0; i<n; i++){ // there are all one in this coloumn, as everyone knows him except him
            if( M[i][ans] == 1){
                oneCount++;
            }
        }
        if( oneCount != n-1){
            return -1;
        }
        return ans;
    }
};
