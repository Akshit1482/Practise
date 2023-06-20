class Solution{
public:
	string removeDuplicates(string str) {
	    
	    string ans = "";
	    
	    unordered_map<char,int>mp;
	    for( int i=0; i<str.length(); i++ ){
	        mp[str[i]]++;
	        
	        if( mp[str[i]] == 1 ){
	            ans += str[i];
	        }
	    }
	    return ans;
	}   
};
