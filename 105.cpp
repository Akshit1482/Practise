class Solution{
  public:
    int middle(int A, int B, int C){
        //code here//Position this line where user code will be pasted.
        int mini = min( A, min( B, C ) );
        int maxi = max( A, max( B, C ) );
        
        if( A == maxi ){
            return max( B, C );
        }
        else if( B == maxi ){
            return max( A, C);
        }
        else{
            return max( A, B);
        }
    }
};
