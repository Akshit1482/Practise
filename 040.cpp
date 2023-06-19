// same as the median of two sorted arrays of different size, with some variation  ////  041.cpp for explanation

class Solution {
public:
    int findMidSum(int ar1[], int ar2[], int n) {
        
        int low = 0; int high = n;
        
        while( low <= high ){
            int cut1 = low + (high-low)/2;
            int cut2 = n - cut1;
            
            int l1 = cut1 == 0 ? INT_MIN : ar1[ cut1 - 1 ];
            int l2 = cut2 == 0 ? INT_MIN : ar2[ cut2 - 1 ];
            
            int r1 = cut1 == n ? INT_MAX : ar1[ cut1 ];
            int r2 = cut2 == n ? INT_MAX : ar2[ cut2 ];
            
            if( l1 <= r2 && l2 <= r1 ){
                return ( max(l1,l2) + min(r1,r2) );
            }
            else if( l1 > r2 ){
                high = cut1-1;
            }
            else{
                low = cut1+1;
            }
        }
        return 0;
    }
};
