class Solution {
	public:
		string FirstNonRepeating(string A){
		    
		    // make an map to check count
		    unordered_map<char,int>count;
		    queue<int>q;
		    string ans = "";
		    
		    // traversing the string
		    for( int i =0; i< A.size(); i++){
		        int ch = A[i];
		        
		        count[ch]++; // incrementing the count of character
		        
		        q.push( ch );
		        
		        // check if q is empty or not
		        while( !q.empty() ){
		            if( count[q.front()] > 1){  // repeating character
		                q.pop();
		            }
		            else{  // non repeating character
		                ans.push_back( q.front() );
		                break;  // break out of the loop as we got the desired current element an we dont have to pop anything
		            }
		        }
		        if( q.empty() ){
		            ans.push_back( '#' );
		        }
		    }
		    return ans;
		}

};
