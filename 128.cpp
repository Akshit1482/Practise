class Solution{
public:
    int inSequence(int A, int B, int C){
        
        if( C==0 ){
            return A == B; // as common difference is 0
        }
        
        if( ( B - A ) % C == 0 && (B - A) / C >= 0 ){
            return true;
        }
        else{
            return false;
        }
    }
};
