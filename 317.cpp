class Solution{
public:
    int isStackPermutation(int N,vector<int> &A,vector<int> &B){
        stack<int>s;
        int j =0; // creating a variable to track the output array
        
        for( int i=0; i<N; i++){
            
            int curr = A[i];
            s.push( curr );  // firstly push all elements into stack for comaparison between curr and stack top
            
            if( s.top() == B[j] ){  // first step- checking the pushed element is the required element of output array
                while( !s.empty() && s.top() == B[j] ){ // second step - checking the stack top is the required element of output array
                    s.pop();
                    j++;  // incrementing j to traverse the output array
                }
            }
        }
        
        if( s.empty() ){
            return 1;   // if stack is empty, then output is the permutation of input array
        }
        else{
            return 0;
        }
    }
};
