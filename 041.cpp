class Solution{
    public:
    double MedianOfArrays(vector<int>& array1, vector<int>& array2)
    {
        // as the arrrays are sorted we can use binary search
        // alsoo median lies in the first half of the memrged array, so we need to perform operation on only half array
        // if total are n elements we ar going to cut the array into 2 halves of n/2 size
        // keep in mind, we make cuts in such way, that all lements in left part will be smaller than elemnets in right part, and also the og array i sorted
        
        if( array1.size() > array2.size() ){
            return MedianOfArrays( array2, array1 );
        }
        // checking the size of both arrays
        int n1 = array1.size();  // it is the smaller array, which we use to decide cuts
        int n2 = array2.size();
        
        int low = 0; int high = n1;  // low and hig are indexes
        while( low <= high )
        {
            int cut1 = low + ( high - low )/2.0; //calculating first cut( elemnet from which previous one will be chosen) from smaller array, y just taking cut as half
            int cut2 = ( n1+n2+1 )/2 - cut1; // as we said length of first half can only be half of the total array length
            
            int l1 = cut1 == 0 ? INT_MIN : array1[ cut1 - 1 ]; // l1 is the last element of first half of smaller array after the cut has been made, 
                                                               // if the cut left nithing on in the first hallf then replace it by INT_MIN, 
                                                               //as last element of first must be smaller than first element of second half
            int l2 = cut2 == 0 ? INT_MIN : array2[ cut2 - 1 ]; // l2 is the last element of first half of smaller array after the cut has been made
            
            int r1 = cut1 == n1 ? INT_MAX : array1[ cut1 ];
            int r2 = cut2 == n2 ? INT_MAX : array2[ cut2 ];
            
            // checking the conditions
            // last elemnet of first half of array1 must be smaller than first element of second part of array2
            if( l1 <= r2 && l2 <= r1 ){
                if( (n1+n2)%2 == 0 ){ // checking if merge darray is even or odd
                    return ( (max(l1,l2) + min(r1,r2) )/2.0 ); // as after being sorted max of l1,l2 will be at the end of first half, and min of r1,r2 will be at the  
                                                               // start of second half, and median of even array is average of both middle element
                }
                else{
                    return max( l1,l2 );
                }
            }
            else if( l1 > r2 ){ // means we have to decrease the first half array, by making the smaller cut1, as cut2 depends on cut1
                high = cut1-1; // like in binary seaarch search i left part only
            }
            else{
                low = cut1+1;
            }
        }
        return 0.0;
    
    }
};
