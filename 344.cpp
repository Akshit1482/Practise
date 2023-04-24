//User function Template for C++

class Solution{
public:
    int kthLargest(vector<int> &Arr,int N,int K){
        // we are creating a heap of n size, with  first n subarray sum in minHeap
        // thus if we get a sum for a singlr iteration, greater tha than the top(), then we pop our top
        // as it is the greeatest  among all in heap, and put our sum in its correct position
        
        // heaap declaration
        priority_queue< int, vector<int>, greater<int> > mini;
        
        int n = Arr.size();
        for( int i=0; i<n; i++){
            //sum declaration
            int sum = 0;
            // pushing all possible subarray sum  in the array
            for( int j = i; j<n; j++ ){
                sum += Arr[j];
                
                if( mini.size() < K ){
                    mini.push( sum );  // heap creation
                }
                else{
                    if( sum > mini.top() ){
                        mini.pop();
                        mini.push( sum );
                    }
                }
            }
        }
        return mini.top();
    }
};
