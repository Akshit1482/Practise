// Brute Force

class Solution
{
public:
    string numbersToString(int n) {
            string result = "";
            for (int i = 1; i <= n; i++) {
                result += to_string(i) + " ";
            }
            return result;
    }
    
    void solve( string s, vector<string>& ans, int i ){
        // base case
        if( i >= s.length() ){
            ans.push_back( s );
            return;
        }
        
        for( int k=i; k<s.size(); k++ ){
            swap( s[i],s[k] ); // ek swap khus se hoga, aur ek ek swap jitne bhi next element hain unke saath hoga
            solve( s, ans, i+1); // i+1 becaause next step mein aage wale index par bhi toh jaana hai
            
            // backtrack
            swap( s[i],s[k] );
        }
    }
    string kthPermutation(int n, int k)
    {
       
        string s = numbersToString(n);
        
        vector<string>ans;
        int index = 0;
        solve( s, ans, index);
        
        sort( ans.begin(), ans.end() );
        auto it = unique(ans.begin(), ans.end());
        ans.erase(it, ans.end());
        
        string res = ans[k-1];
        return res;
        
    }
};




/// OPTIMIZE
class Solution
{
public:
    string kthPermutation(int n, int k)
    {
        int fact = 1;
        vector<int>numbers;
        for( int i=1; i<n; i++ ){
            fact=fact*i; // fact is total no. of permutation possible for n elements
            numbers.push_back(i);  // n natural no. ka DS bnao
        }
        numbers.push_back(n);
        
        string ans = "";
        k=k-1;  // due to zero based indexing
        
        while( true ){
            ans = ans + to_string( numbers[k/fact] ); // as fact is total permutation after the first digit
            
            numbers.erase( numbers.begin() + k/fact ); // erase the added digit
            
            // base case
            if( numbers.size() == 0 ){
                break;
            }
            
            // upadating k
            k = k%fact; 
            
            // updating the total permutation after placing a digit
            fact = fact/numbers.size();
            
        }
        return ans;
    }
};
