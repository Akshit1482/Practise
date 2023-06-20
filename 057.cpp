class Solution{
public:	
	
	
	int isPalindrome(string S)
	{
	    int n = S.size();
	    for( int i=0; i<n; i++ ){
	        if( S[i] == S[n-i-1] ){
	            continue;
	        }
	        else{
	            return 0;
	        }
	    } 
	    return 1;
	}

};
