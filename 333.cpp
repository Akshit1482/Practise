class Solution{
    
    public:
    vector<int> help_classmate(vector<int> arr, int n) 
    { 
        stack<int>s;
        s.push( -1 );
        vector<int>ans;
        
        for( int i =n-1; i>=0; i--){ // array ko end se traverse karte hain
            int curr = arr[i];
            
            while( !s.empty() && (s.top() >= curr)){ // we are seeing s.top > curr, because we need smaller element
                s.pop();
            }
            if( s.size() == 0){  // stack has got empty, so no next samller element
                ans.push_back( -1 );
            }
            else{
                ans.push_back( s.top() ); // we have got s.top < curr, so s.top is the answer for curr
            }
            s.push( curr ); // we are pushing because , yeh curr kisi aur ka next smaller ho sakta hai
        }
        reverse( ans.begin(), ans.end());
        return ans;
    } 
};
