class Solution
{
    public:
    //Function to find the next greater element for each element of the array.
    vector<long long> nextLargerElement(vector<long long> arr, int n){
        stack<int>s;
        s.push( -1 ); // starting mein stack mein -1 push kardo
        vector<long long>ans;
        
        for( int i= n-1; i>=0; i--){  // arr ko last se traverse karna shuru karo, kyunki  humme next element nikalna hai
            int curr = arr[i];
            while( !s.empty() && s.top() <= curr){ // check is the top element is next element or not
                s.pop();
            }
            //ans is stack ka top();
           if( s.size() == 0){  // if stack is empty, then no bigger element i present at next
               ans.push_back( -1 );
           }
           else{
               ans.push_back( s.top());  // bigger element is found
           }
           
           s.push( arr[i]); // always pus curr back into stack
        }
        reverse(ans.begin(), ans.end());  // as we have pushed elemnets from back, so they are in reverse order
        return ans;
    }
};
